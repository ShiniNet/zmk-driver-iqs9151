/*
 * IQS9151 driver implementation
 */

#include <zephyr/device.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/drivers/i2c.h>
#include <zephyr/input/input.h>
#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include <zephyr/pm/device.h>
#include <zephyr/sys/byteorder.h>
#include <string.h>

#include "iqs9151_init.h"
#include "iqs9151_regs.h"

/* Use generic input log level; no driver-specific Kconfig is required. */
LOG_MODULE_REGISTER(input_iqs9151, CONFIG_INPUT_LOG_LEVEL);

#define DT_DRV_COMPAT azoteq_iqs9151


#define IQS9151_MAX_FINGERS             7
#define IQS9151_I2C_MAX_RETRIES         3
#define IQS9151_I2C_RETRY_DELAY_MS      2
#define IQS9151_RSTD_DELAY_MS           2
#define IQS9151_RESET_PULSE_US          200

struct iqs9151_config {
	struct i2c_dt_spec bus;
	struct gpio_dt_spec irq_gpio;
	struct gpio_dt_spec reset_gpio;
	struct gpio_dt_spec enable_gpio;
};

struct iqs9151_data {
	const struct device *dev;
	struct gpio_callback irq_cb;
	struct k_work work;
	bool touch_down;
};

#define IQS9151_TWO_FINGER_GESTURES_OFFSET (IQS9151_ADDR_TWO_FINGER_GESTURES - IQS9151_COORD_BLOCK_START)

static const uint8_t iqs9151_alp_compensation[] = {
	ALP_COMPENSATION_RX0_0, ALP_COMPENSATION_RX0_1, ALP_COMPENSATION_RX1_0, ALP_COMPENSATION_RX1_1,
	ALP_COMPENSATION_RX2_0, ALP_COMPENSATION_RX2_1, ALP_COMPENSATION_RX3_0, ALP_COMPENSATION_RX3_1,
	ALP_COMPENSATION_RX4_0, ALP_COMPENSATION_RX4_1, ALP_COMPENSATION_RX5_0, ALP_COMPENSATION_RX5_1,
	ALP_COMPENSATION_RX6_0, ALP_COMPENSATION_RX6_1, ALP_COMPENSATION_RX7_0, ALP_COMPENSATION_RX7_1,
	ALP_COMPENSATION_RX8_0, ALP_COMPENSATION_RX8_1, ALP_COMPENSATION_RX9_0, ALP_COMPENSATION_RX9_1,
	ALP_COMPENSATION_RX10_0, ALP_COMPENSATION_RX10_1, ALP_COMPENSATION_RX11_0, ALP_COMPENSATION_RX11_1,
	ALP_COMPENSATION_RX12_0, ALP_COMPENSATION_RX12_1,
};

/* The driver reports relative movement, so the X/Y resolution entries
 * in the init sequence are unused and left at their default values.
 */
static const uint8_t iqs9151_main_config[] = {
	MINOR_VERSION, MAJOR_VERSION,
	TP_ATI_MULTDIV_L, TP_ATI_MULTDIV_H,
	ALP_ATI_COARSE_RX0_L, ALP_ATI_COARSE_RX0_H, ALP_ATI_COARSE_RX1_L, ALP_ATI_COARSE_RX1_H,
	ALP_ATI_COARSE_RX2_L, ALP_ATI_COARSE_RX2_H, ALP_ATI_COARSE_RX3_L, ALP_ATI_COARSE_RX3_H,
	ALP_ATI_COARSE_RX4_L, ALP_ATI_COARSE_RX4_H, ALP_ATI_COARSE_RX5_L, ALP_ATI_COARSE_RX5_H,
	ALP_ATI_COARSE_RX6_L, ALP_ATI_COARSE_RX6_H, ALP_ATI_COARSE_RX7_L, ALP_ATI_COARSE_RX7_H,
	ALP_ATI_COARSE_RX8_L, ALP_ATI_COARSE_RX8_H, ALP_ATI_COARSE_RX9_L, ALP_ATI_COARSE_RX9_H,
	ALP_ATI_COARSE_RX10_L, ALP_ATI_COARSE_RX10_H, ALP_ATI_COARSE_RX11_L, ALP_ATI_COARSE_RX11_H,
	ALP_ATI_COARSE_RX12_L, ALP_ATI_COARSE_RX12_H,
	TP_ATI_TARGET_0, TP_ATI_TARGET_1, ALP_ATI_TARGET_0, ALP_ATI_TARGET_1,
	ALP_BASE_TARGET_0, ALP_BASE_TARGET_1, TP_NEG_DELTA_REATI_0, TP_NEG_DELTA_REATI_1,
	TP_POS_DELTA_REATI_0, TP_POS_DELTA_REATI_1, TP_REF_DRIFT_LIMIT, ALP_LTA_DRIFT_LIMIT,
	ACTIVE_MODE_SAMPLING_PERIOD_0, ACTIVE_MODE_SAMPLING_PERIOD_1,
	IDLE_TOUCH_MODE_SAMPLING_PERIOD_0, IDLE_TOUCH_MODE_SAMPLING_PERIOD_1,
	IDLE_MODE_SAMPLING_PERIOD_0, IDLE_MODE_SAMPLING_PERIOD_1,
	LP1_MODE_SAMPLING_PERIOD_0, LP1_MODE_SAMPLING_PERIOD_1,
	LP2_MODE_SAMPLING_PERIOD_0, LP2_MODE_SAMPLING_PERIOD_1,
	STATIONARY_TOUCH_TIMEOUT_0, STATIONARY_TOUCH_TIMEOUT_1,
	IDLE_TOUCH_MODE_TIMEOUT_0, IDLE_TOUCH_MODE_TIMEOUT_1,
	IDLE_MODE_TIMEOUT_0, IDLE_MODE_TIMEOUT_1,
	LP1_MODE_TIMEOUT_0, LP1_MODE_TIMEOUT_1,
	ACTIVE_MODE_TIMEOUT_0, ACTIVE_MODE_TIMEOUT_1,
	REATI_RETRY_TIME, REF_UPDATE_TIME,
	I2C_TIMEOUT_0, I2C_TIMEOUT_1, SNAP_TIMEOUT, OPEN_TIMING,
	SYSTEM_CONTROL_0, SYSTEM_CONTROL_1, CONFIG_SETTINGS_0, CONFIG_SETTINGS_1,
	OTHER_SETTINGS_0, OTHER_SETTINGS_1,
	ALP_SETUP_0, ALP_SETUP_1, ALP_SETUP_2, ALP_SETUP_3,
	ALP_TX_ENABLE_0, ALP_TX_ENABLE_1, ALP_TX_ENABLE_2, ALP_TX_ENABLE_3, ALP_TX_ENABLE_4, ALP_TX_ENABLE_5,
	TRACKPAD_TOUCH_SET_THRESHOLD, TRACKPAD_TOUCH_CLEAR_THRESHOLD,
	ALP_THRESHOLD, ALP_AUTOPROX_THRESHOLD, ALP_SET_DEBOUNCE, ALP_CLEAR_DEBOUNCE,
	SNAP_SET_THRESHOLD, SNAP_CLEAR_THRESHOLD,
	ALP_COUNT_BETA_LP1, ALP_LTA_BETA_LP1, ALP_COUNT_BETA_LP2, ALP_LTA_BETA_LP2,
	TP_FRAC, TP_PERIOD1, TP_PERIOD2, ALP_FRAC, ALP_PERIOD1, ALP_PERIOD2,
	TRACKPAD_HARDWARE_SETTINGS_0, TRACKPAD_HARDWARE_SETTINGS_1,
	ALP_HARDWARE_SETTINGS_0, ALP_HARDWARE_SETTINGS_1,
	TRACKPAD_SETTINGS_0_0, TRACKPAD_SETTINGS_0_1,
	TRACKPAD_SETTINGS_1_0, TRACKPAD_SETTINGS_1_1,
	X_RESOLUTION_0, X_RESOLUTION_1, Y_RESOLUTION_0, Y_RESOLUTION_1,
	XY_DYNAMIC_FILTER_BOTTOM_SPEED_0, XY_DYNAMIC_FILTER_BOTTOM_SPEED_1,
	XY_DYNAMIC_FILTER_TOP_SPEED_0, XY_DYNAMIC_FILTER_TOP_SPEED_1,
	XY_DYNAMIC_FILTER_BOTTOM_BETA, XY_DYNAMIC_FILTER_STATIC_FILTER_BETA,
	STATIONARY_TOUCH_MOV_THRESHOLD, FINGER_SPLIT_FACTOR,
	X_TRIM_VALUE, Y_TRIM_VALUE, JITTER_FILTER_DELTA, FINGER_CONFIDENCE_THRESHOLD,
};

static const uint8_t iqs9151_gesture_config[] = {
	GESTURE_ENABLE_0, GESTURE_ENABLE_1, GESTURE_ENABLE_2F_0, GESTURE_ENABLE_2F_1,
	TAP_TOUCH_TIME_0, TAP_TOUCH_TIME_1, TAP_WAIT_TIME_0, TAP_WAIT_TIME_1,
	TAP_DISTANCE_0, TAP_DISTANCE_1, HOLD_TIME_0, HOLD_TIME_1,
	SWIPE_TIME_0, SWIPE_TIME_1, SWIPE_X_DISTANCE_0, SWIPE_X_DISTANCE_1,
	SWIPE_Y_DISTANCE_0, SWIPE_Y_DISTANCE_1, SWIPE_X_CONS_DIST_0, SWIPE_X_CONS_DIST_1,
	SWIPE_Y_CONS_DIST_0, SWIPE_Y_CONS_DIST_1, SWIPE_ANGLE, SCROLL_ANGLE,
	ZOOM_INIT_DIST_0, ZOOM_INIT_DIST_1, ZOOM_CONSECUTIVE_DIST_0, ZOOM_CONSECUTIVE_DIST_1,
	SCROLL_INIT_DIST_0, SCROLL_INIT_DIST_1, SCROLL_CONSECUTIVE_DIST_0, SCROLL_CONSECUTIVE_DIST_1,
	PALM_GESTURE_THRESHOLD_0, PALM_GESTURE_THRESHOLD_1,
};

static const uint8_t iqs9151_rxtx_map[] = {
	RX_TX_MAP_0, RX_TX_MAP_1, RX_TX_MAP_2, RX_TX_MAP_3, RX_TX_MAP_4, RX_TX_MAP_5,
	RX_TX_MAP_6, RX_TX_MAP_7, RX_TX_MAP_8, RX_TX_MAP_9, RX_TX_MAP_10, RX_TX_MAP_11,
	RX_TX_MAP_12, RX_TX_MAP_13, RX_TX_MAP_14, RX_TX_MAP_15, RX_TX_MAP_16, RX_TX_MAP_17,
	RX_TX_MAP_18, RX_TX_MAP_19, RX_TX_MAP_20, RX_TX_MAP_21, RX_TX_MAP_22, RX_TX_MAP_23,
	RX_TX_MAP_24, RX_TX_MAP_25, RX_TX_MAP_26, RX_TX_MAP_27, RX_TX_MAP_28, RX_TX_MAP_29,
	RX_TX_MAP_30, RX_TX_MAP_31, RX_TX_MAP_32, RX_TX_MAP_33, RX_TX_MAP_34, RX_TX_MAP_35,
	RX_TX_MAP_36, RX_TX_MAP_37, RX_TX_MAP_38, RX_TX_MAP_39, RX_TX_MAP_40, RX_TX_MAP_41,
	RX_TX_MAP_42, RX_TX_MAP_43, RX_TX_MAP_44, RX_TX_OPEN,
};

static const uint8_t iqs9151_channel_disable[] = {
	TPCHANNELDISABLE_0, TPCHANNELDISABLE_1, TPCHANNELDISABLE_2, TPCHANNELDISABLE_3,
	TPCHANNELDISABLE_4, TPCHANNELDISABLE_5, TPCHANNELDISABLE_6, TPCHANNELDISABLE_7,
	TPCHANNELDISABLE_8, TPCHANNELDISABLE_9, TPCHANNELDISABLE_10, TPCHANNELDISABLE_11,
	TPCHANNELDISABLE_12, TPCHANNELDISABLE_13, TPCHANNELDISABLE_14, TPCHANNELDISABLE_15,
	TPCHANNELDISABLE_16, TPCHANNELDISABLE_17, TPCHANNELDISABLE_18, TPCHANNELDISABLE_19,
	TPCHANNELDISABLE_20, TPCHANNELDISABLE_21, TPCHANNELDISABLE_22, TPCHANNELDISABLE_23,
	TPCHANNELDISABLE_24, TPCHANNELDISABLE_25, TPCHANNELDISABLE_26, TPCHANNELDISABLE_27,
	TPCHANNELDISABLE_28, TPCHANNELDISABLE_29, TPCHANNELDISABLE_30, TPCHANNELDISABLE_31,
	TPCHANNELDISABLE_32, TPCHANNELDISABLE_33, TPCHANNELDISABLE_34, TPCHANNELDISABLE_35,
	TPCHANNELDISABLE_36, TPCHANNELDISABLE_37, TPCHANNELDISABLE_38, TPCHANNELDISABLE_39,
	TPCHANNELDISABLE_40, TPCHANNELDISABLE_41, TPCHANNELDISABLE_42, TPCHANNELDISABLE_43,
	TPCHANNELDISABLE_44, TPCHANNELDISABLE_45, TPCHANNELDISABLE_46, TPCHANNELDISABLE_47,
	TPCHANNELDISABLE_48, TPCHANNELDISABLE_49, TPCHANNELDISABLE_50, TPCHANNELDISABLE_51,
	TPCHANNELDISABLE_52, TPCHANNELDISABLE_53, TPCHANNELDISABLE_54, TPCHANNELDISABLE_55,
	TPCHANNELDISABLE_56, TPCHANNELDISABLE_57, TPCHANNELDISABLE_58, TPCHANNELDISABLE_59,
	TPCHANNELDISABLE_60, TPCHANNELDISABLE_61, TPCHANNELDISABLE_62, TPCHANNELDISABLE_63,
	TPCHANNELDISABLE_64, TPCHANNELDISABLE_65, TPCHANNELDISABLE_66, TPCHANNELDISABLE_67,
	TPCHANNELDISABLE_68, TPCHANNELDISABLE_69, TPCHANNELDISABLE_70, TPCHANNELDISABLE_71,
	TPCHANNELDISABLE_72, TPCHANNELDISABLE_73, TPCHANNELDISABLE_74, TPCHANNELDISABLE_75,
	TPCHANNELDISABLE_76, TPCHANNELDISABLE_77, TPCHANNELDISABLE_78, TPCHANNELDISABLE_79,
	TPCHANNELDISABLE_80, TPCHANNELDISABLE_81, TPCHANNELDISABLE_82, TPCHANNELDISABLE_83,
	TPCHANNELDISABLE_84, TPCHANNELDISABLE_85, TPCHANNELDISABLE_86, TPCHANNELDISABLE_87,
};

static const uint8_t iqs9151_snap_enable[] = {
	SNAPCHANNELENABLE_0, SNAPCHANNELENABLE_1, SNAPCHANNELENABLE_2, SNAPCHANNELENABLE_3,
	SNAPCHANNELENABLE_4, SNAPCHANNELENABLE_5, SNAPCHANNELENABLE_6, SNAPCHANNELENABLE_7,
	SNAPCHANNELENABLE_8, SNAPCHANNELENABLE_9, SNAPCHANNELENABLE_10, SNAPCHANNELENABLE_11,
	SNAPCHANNELENABLE_12, SNAPCHANNELENABLE_13, SNAPCHANNELENABLE_14, SNAPCHANNELENABLE_15,
	SNAPCHANNELENABLE_16, SNAPCHANNELENABLE_17, SNAPCHANNELENABLE_18, SNAPCHANNELENABLE_19,
	SNAPCHANNELENABLE_20, SNAPCHANNELENABLE_21, SNAPCHANNELENABLE_22, SNAPCHANNELENABLE_23,
	SNAPCHANNELENABLE_24, SNAPCHANNELENABLE_25, SNAPCHANNELENABLE_26, SNAPCHANNELENABLE_27,
	SNAPCHANNELENABLE_28, SNAPCHANNELENABLE_29, SNAPCHANNELENABLE_30, SNAPCHANNELENABLE_31,
	SNAPCHANNELENABLE_32, SNAPCHANNELENABLE_33, SNAPCHANNELENABLE_34, SNAPCHANNELENABLE_35,
	SNAPCHANNELENABLE_36, SNAPCHANNELENABLE_37, SNAPCHANNELENABLE_38, SNAPCHANNELENABLE_39,
	SNAPCHANNELENABLE_40, SNAPCHANNELENABLE_41, SNAPCHANNELENABLE_42, SNAPCHANNELENABLE_43,
	SNAPCHANNELENABLE_44, SNAPCHANNELENABLE_45, SNAPCHANNELENABLE_46, SNAPCHANNELENABLE_47,
	SNAPCHANNELENABLE_48, SNAPCHANNELENABLE_49, SNAPCHANNELENABLE_50, SNAPCHANNELENABLE_51,
	SNAPCHANNELENABLE_52, SNAPCHANNELENABLE_53, SNAPCHANNELENABLE_54, SNAPCHANNELENABLE_55,
	SNAPCHANNELENABLE_56, SNAPCHANNELENABLE_57, SNAPCHANNELENABLE_58, SNAPCHANNELENABLE_59,
	SNAPCHANNELENABLE_60, SNAPCHANNELENABLE_61, SNAPCHANNELENABLE_62, SNAPCHANNELENABLE_63,
	SNAPCHANNELENABLE_64, SNAPCHANNELENABLE_65, SNAPCHANNELENABLE_66, SNAPCHANNELENABLE_67,
	SNAPCHANNELENABLE_68, SNAPCHANNELENABLE_69, SNAPCHANNELENABLE_70, SNAPCHANNELENABLE_71,
	SNAPCHANNELENABLE_72, SNAPCHANNELENABLE_73, SNAPCHANNELENABLE_74, SNAPCHANNELENABLE_75,
	SNAPCHANNELENABLE_76, SNAPCHANNELENABLE_77, SNAPCHANNELENABLE_78, SNAPCHANNELENABLE_79,
	SNAPCHANNELENABLE_80, SNAPCHANNELENABLE_81, SNAPCHANNELENABLE_82, SNAPCHANNELENABLE_83,
	SNAPCHANNELENABLE_84, SNAPCHANNELENABLE_85, SNAPCHANNELENABLE_86, SNAPCHANNELENABLE_87,
};

static int iqs9151_i2c_write(const struct iqs9151_config *config, uint16_t reg,
			     const uint8_t *buf, size_t len)
{
	uint8_t tx[2 + 16];
	int ret = 0;

	if (len > sizeof(tx) - 2) {
		return -EINVAL;
	}

	sys_put_be16(reg, tx);
	memcpy(&tx[2], buf, len);

	for (int i = 0; i < IQS9151_I2C_MAX_RETRIES; i++) {
		ret = i2c_write_dt(&config->bus, tx, len + 2);
		if (!ret) {
			break;
		}

		k_msleep(IQS9151_I2C_RETRY_DELAY_MS);
	}

	return ret;
}

static int iqs9151_i2c_read(const struct iqs9151_config *config, uint16_t reg,
			    uint8_t *buf, size_t len)
{
	uint8_t addr_buf[2];
	int ret = 0;

	sys_put_be16(reg, addr_buf);
	for (int i = 0; i < IQS9151_I2C_MAX_RETRIES; i++) {
		ret = i2c_write_read_dt(&config->bus, addr_buf, sizeof(addr_buf), buf, len);
		if (!ret) {
			break;
		}

		k_msleep(IQS9151_I2C_RETRY_DELAY_MS);
	}

	return ret;
}

static int iqs9151_write_block(const struct iqs9151_config *config, uint16_t start,
			       const uint8_t *buf, size_t len)
{
	/* block write with base address */
	uint8_t *tx = k_malloc(len + 2);
	int ret;

	if (!tx) {
		return -ENOMEM;
	}

	sys_put_be16(start, tx);
	memcpy(&tx[2], buf, len);

	for (int i = 0; i < IQS9151_I2C_MAX_RETRIES; i++) {
		ret = i2c_write_dt(&config->bus, tx, len + 2);
		if (!ret) {
			break;
		}
		k_msleep(IQS9151_I2C_RETRY_DELAY_MS);
	}

	k_free(tx);
	return ret;
}

static int iqs9151_reset(const struct device *dev)
{
	const struct iqs9151_config *config = dev->config;

	if (!config->reset_gpio.port) {
		return 0;
	}

	int ret = gpio_pin_set_dt(&config->reset_gpio, 0);
	if (ret) {
		return ret;
	}

	k_busy_wait(IQS9151_RESET_PULSE_US);

	ret = gpio_pin_set_dt(&config->reset_gpio, 1);
	if (ret) {
		return ret;
	}

	k_msleep(IQS9151_RSTD_DELAY_MS);
	return 0;
}

static int iqs9151_check_id(const struct device *dev)
{
	const struct iqs9151_config *config = dev->config;
	uint8_t buf[2];
	int ret = iqs9151_i2c_read(config, IQS9151_ADDR_PRODUCT_NUMBER, buf, sizeof(buf));

	if (ret) {
		LOG_ERR("Failed to read product number (%d)", ret);
		return ret;
	}

	uint16_t product = sys_get_be16(buf);

	if (product != IQS9151_PRODUCT_NUMBER) {
		LOG_ERR("Unexpected product number 0x%04x", product);
		return -ENODEV;
	}

	return 0;
}

static int iqs9151_clear_reset_flag(const struct iqs9151_config *config)
{
	uint8_t ctrl[2] = {
		SYSTEM_CONTROL_0,
		SYSTEM_CONTROL_1 | IQS9151_SYS_CTRL_ACK_RESET,
	};

	return iqs9151_i2c_write(config, IQS9151_ADDR_SYSTEM_CONTROL, ctrl, sizeof(ctrl));
}

static int iqs9151_run_ati(const struct iqs9151_config *config)
{
	uint8_t ctrl[2] = {
		SYSTEM_CONTROL_0,
		SYSTEM_CONTROL_1 | IQS9151_SYS_CTRL_ALP_RE_ATI | IQS9151_SYS_CTRL_TP_RE_ATI,
	};

	return iqs9151_i2c_write(config, IQS9151_ADDR_SYSTEM_CONTROL, ctrl, sizeof(ctrl));
}

static int iqs9151_write_init_sequence(const struct iqs9151_config *config)
{
	int ret;

	ret = iqs9151_write_block(config, IQS9151_ADDR_ALP_COMPENSATION,
				  iqs9151_alp_compensation, ARRAY_SIZE(iqs9151_alp_compensation));
	if (ret) {
		return ret;
	}

	ret = iqs9151_write_block(config, IQS9151_ADDR_SETTINGS_MINOR,
				  iqs9151_main_config, ARRAY_SIZE(iqs9151_main_config));
	if (ret) {
		return ret;
	}

	ret = iqs9151_write_block(config, IQS9151_ADDR_GESTURE_ENABLE,
				  iqs9151_gesture_config, ARRAY_SIZE(iqs9151_gesture_config));
	if (ret) {
		return ret;
	}

	ret = iqs9151_write_block(config, IQS9151_ADDR_RX_TX_MAPPING,
				  iqs9151_rxtx_map, ARRAY_SIZE(iqs9151_rxtx_map));
	if (ret) {
		return ret;
	}

	ret = iqs9151_write_block(config, IQS9151_ADDR_CHANNEL_DISABLE,
				  iqs9151_channel_disable, ARRAY_SIZE(iqs9151_channel_disable));
	if (ret) {
		return ret;
	}

	return iqs9151_write_block(config, IQS9151_ADDR_SNAP_ENABLE,
				   iqs9151_snap_enable, ARRAY_SIZE(iqs9151_snap_enable));
}

static int iqs9151_configure(const struct device *dev)
{
	const struct iqs9151_config *config = dev->config;
	uint8_t cfg_settings[2] = {
		CONFIG_SETTINGS_0,
		CONFIG_SETTINGS_1,
	};
	int ret;

	ret = iqs9151_write_init_sequence(config);
	if (ret) {
		LOG_ERR("Init block write failed (%d)", ret);
		return ret;
	}

	/* The driver is interrupt-driven, so keep the RDY line event-driven as well. */
	cfg_settings[0] |= (uint8_t)(IQS9151_CFG_EVENT_MODE >> 8);

	ret = iqs9151_i2c_write(config, IQS9151_ADDR_CONFIG_SETTINGS, cfg_settings,
				sizeof(cfg_settings));
	if (ret) {
		LOG_ERR("Config settings write failed (%d)", ret);
		return ret;
	}

	ret = iqs9151_run_ati(config);
	if (ret) {
		LOG_ERR("ATI request failed (%d)", ret);
		return ret;
	}

	ret = iqs9151_clear_reset_flag(config);
	if (ret) {
		LOG_ERR("Reset flag clear failed (%d)", ret);
		return ret;
	}

	return 0;
}

static void iqs9151_report_coords(const struct device *dev, int16_t dx, int16_t dy,
				  bool left_click, bool right_click, uint8_t fingers)
{
	struct iqs9151_data *data = dev->data;
	bool touch_active = left_click || right_click;

	input_report_rel(dev, INPUT_REL_X, dx, false, K_NO_WAIT);
	input_report_rel(dev, INPUT_REL_Y, dy, false, K_NO_WAIT);
	input_report_key(dev, INPUT_BTN_0, left_click, false, K_NO_WAIT);
	input_report_key(dev, INPUT_BTN_1, right_click, false, K_NO_WAIT);
	if (touch_active != data->touch_down) {
		input_report_key(dev, INPUT_BTN_TOUCH, touch_active, false, K_NO_WAIT);
		data->touch_down = touch_active;
	}
	input_report_key(dev, INPUT_BTN_TOUCH, fingers > 0, true, K_NO_WAIT);
}

static int iqs9151_read_irq_data(const struct device *dev)
{
	const struct iqs9151_config *config = dev->config;
	uint8_t info_flags[2];
	uint8_t tp_flags[2];
	uint8_t coord[IQS9151_COORD_BLOCK_LENGTH];
	int ret;

	ret = iqs9151_i2c_read(config, IQS9151_ADDR_INFO_FLAGS, info_flags,
			       sizeof(info_flags));
	if (ret) {
		return ret;
	}

	ret = iqs9151_i2c_read(config, IQS9151_ADDR_TRACKPAD_FLAGS, tp_flags,
			       sizeof(tp_flags));
	if (ret) {
		return ret;
	}

	ret = iqs9151_i2c_read(config, IQS9151_COORD_BLOCK_START, coord,
			       sizeof(coord));
	if (ret) {
		return ret;
	}

	uint16_t info = sys_get_be16(info_flags);
	uint16_t flags = sys_get_be16(tp_flags);
	int16_t rel_x = (int16_t)sys_get_be16(&coord[0]);
	int16_t rel_y = (int16_t)sys_get_be16(&coord[2]);
	uint8_t fingers = flags & IQS9151_TP_FINGER_COUNT_MASK;
	uint16_t two_finger_gestures =
		sys_get_be16(&coord[IQS9151_TWO_FINGER_GESTURES_OFFSET]);
	bool pressed = (info & IQS9151_INFO_GLOBAL_TP_TOUCH) || fingers;
	bool right_click = pressed && (fingers > 1 || two_finger_gestures != 0);
	bool left_click = pressed && !right_click;

	iqs9151_report_coords(dev, rel_x, rel_y, left_click, right_click, fingers);

	return 0;
}

static void iqs9151_work_handler(struct k_work *work)
{
	struct iqs9151_data *data = CONTAINER_OF(work, struct iqs9151_data, work);
	const struct device *dev = data->dev;
	const struct iqs9151_config *config = dev->config;

	int ret = iqs9151_read_irq_data(dev);
	if (ret) {
		LOG_ERR("IRQ read failed (%d)", ret);
	}

	gpio_pin_interrupt_configure_dt(&config->irq_gpio, GPIO_INT_EDGE_TO_ACTIVE);
}

static void iqs9151_irq_handler(const struct device *gpiodev, struct gpio_callback *cb,
				uint32_t pins)
{
	ARG_UNUSED(gpiodev);
	ARG_UNUSED(pins);

	struct iqs9151_data *data = CONTAINER_OF(cb, struct iqs9151_data, irq_cb);
	const struct iqs9151_config *config = data->dev->config;

	gpio_pin_interrupt_configure_dt(&config->irq_gpio, GPIO_INT_DISABLE);
	k_work_submit(&data->work);
}

static int iqs9151_init_gpio(const struct device *dev)
{
	const struct iqs9151_config *config = dev->config;
	struct iqs9151_data *data = dev->data;
	int ret;

	if (!device_is_ready(config->irq_gpio.port)) {
		LOG_ERR("IRQ GPIO not ready");
		return -ENODEV;
	}

	ret = gpio_pin_configure_dt(&config->irq_gpio, GPIO_INPUT);
	if (ret) {
		return ret;
	}

	if (config->reset_gpio.port) {
		if (!device_is_ready(config->reset_gpio.port)) {
			return -ENODEV;
		}
		ret = gpio_pin_configure_dt(&config->reset_gpio, GPIO_OUTPUT_ACTIVE);
		if (ret) {
			return ret;
		}
	}

	if (config->enable_gpio.port) {
		if (!device_is_ready(config->enable_gpio.port)) {
			return -ENODEV;
		}
		ret = gpio_pin_configure_dt(&config->enable_gpio, GPIO_OUTPUT_ACTIVE);
		if (ret) {
			return ret;
		}
	}

	gpio_init_callback(&data->irq_cb, iqs9151_irq_handler, BIT(config->irq_gpio.pin));
	ret = gpio_add_callback(config->irq_gpio.port, &data->irq_cb);
	if (ret) {
		return ret;
	}

	ret = gpio_pin_interrupt_configure_dt(&config->irq_gpio, GPIO_INT_EDGE_TO_ACTIVE);
	if (ret) {
		return ret;
	}

	return 0;
}

static int iqs9151_init(const struct device *dev)
{
	const struct iqs9151_config *config = dev->config;
	struct iqs9151_data *data = dev->data;

	if (!device_is_ready(config->bus.bus)) {
		LOG_ERR("I2C bus not ready");
		return -ENODEV;
	}

	k_work_init(&data->work, iqs9151_work_handler);
	data->dev = dev;

	int ret = iqs9151_init_gpio(dev);
	if (ret) {
		return ret;
	}

	ret = iqs9151_reset(dev);
	if (ret) {
		return ret;
	}

	ret = iqs9151_check_id(dev);
	if (ret) {
		return ret;
	}

	return iqs9151_configure(dev);
}


#define IQS9151_DEFINE(inst) \
	static struct iqs9151_data iqs9151_data_##inst; \
	static const struct iqs9151_config iqs9151_config_##inst = { \
	.bus = I2C_DT_SPEC_INST_GET(inst), \
	.irq_gpio = GPIO_DT_SPEC_INST_GET(inst, irq_gpios), \
	.reset_gpio = GPIO_DT_SPEC_INST_GET_OR(inst, reset_gpios, {0}), \
	.enable_gpio = GPIO_DT_SPEC_INST_GET_OR(inst, enable_gpios, {0}), \
	}; \
	INPUT_DEVICE_DT_INST_DEFINE(inst, iqs9151_init, NULL, \
				 &iqs9151_data_##inst, &iqs9151_config_##inst, \
				 POST_KERNEL, CONFIG_INPUT_IQS9151_INIT_PRIORITY, \
				 NULL);

DT_INST_FOREACH_STATUS_OKAY(IQS9151_DEFINE)
