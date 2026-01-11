/*
 * File:   IQS9151.c
 * Author: ShiniNet
 */
#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/drivers/i2c.h>
#include <zephyr/input/input.h>
#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include <zephyr/sys/byteorder.h>
#include <zephyr/sys/util.h>

#include "iqs9151_init.h"
#include "iqs9151_regs.h"

#include <stdbool.h>
#include <stdint.h>
#include <string.h>

LOG_MODULE_REGISTER(iqs9151, LOG_LEVEL_DBG /*CONFIG_INPUT_LOG_LEVEL*/);

#define DT_DRV_COMPAT azoteq_iqs9151

#define IQS9151_I2C_CHUNK_SIZE 30
#define IQS9151_RSTD_DELAY_MS 100
#define IQS9151_RESET_PULSE_US 200
#define IQS9151_ATI_TIMEOUT_MS 1000
#define IQS9151_ATI_POLL_INTERVAL_MS 10
#define INERTIA_INTERVAL_MS 10
#define INERTIA_MAX_DURATION_MS 3000
#define INERTIA_AVG_FRAMES 5
#define INERTIA_DECAY_NUM 985
#define INERTIA_DECAY_DEN 1000
#define INERTIA_FP_SHIFT 8
#define INERTIA_START_THRESHOLD 1
#define INERTIA_MIN_VELOCITY 1

struct iqs9151_config {
    struct i2c_dt_spec bus;
    struct gpio_dt_spec irq_gpio;
    struct gpio_dt_spec reset_gpio;
};
struct iqs9151_frame {
    int16_t rel_x;
    int16_t rel_y;
    int16_t gesture_x;
    int16_t gesture_y;
    uint16_t single_gestures;
    uint16_t two_finger_gestures;
    uint16_t info_flags;
    uint16_t trackpad_flags;
    uint8_t finger_count;
    uint16_t finger1_x;
    uint16_t finger1_y;
};
struct iqs9151_data {
    const struct device *dev;
    struct gpio_callback gpio_cb;
    struct k_work work;
    struct k_work_delayable inertia_work;
    struct iqs9151_frame prev_frame;
    bool inertia_active;
    int32_t inertia_vx_fp;
    int32_t inertia_vy_fp;
    int32_t inertia_accum_x_fp;
    int32_t inertia_accum_y_fp;
    int64_t inertia_last_ms;
    uint32_t inertia_elapsed_ms;
    int16_t scroll_hist_x[INERTIA_AVG_FRAMES];
    int16_t scroll_hist_y[INERTIA_AVG_FRAMES];
    uint8_t scroll_hist_pos_x;
    uint8_t scroll_hist_pos_y;
    uint8_t scroll_hist_count_x;
    uint8_t scroll_hist_count_y;
};

static const uint8_t iqs9151_alp_compensation[] = {
    ALP_COMPENSATION_RX0_0,  ALP_COMPENSATION_RX0_1,  ALP_COMPENSATION_RX1_0,
    ALP_COMPENSATION_RX1_1,  ALP_COMPENSATION_RX2_0,  ALP_COMPENSATION_RX2_1,
    ALP_COMPENSATION_RX3_0,  ALP_COMPENSATION_RX3_1,  ALP_COMPENSATION_RX4_0,
    ALP_COMPENSATION_RX4_1,  ALP_COMPENSATION_RX5_0,  ALP_COMPENSATION_RX5_1,
    ALP_COMPENSATION_RX6_0,  ALP_COMPENSATION_RX6_1,  ALP_COMPENSATION_RX7_0,
    ALP_COMPENSATION_RX7_1,  ALP_COMPENSATION_RX8_0,  ALP_COMPENSATION_RX8_1,
    ALP_COMPENSATION_RX9_0,  ALP_COMPENSATION_RX9_1,  ALP_COMPENSATION_RX10_0,
    ALP_COMPENSATION_RX10_1, ALP_COMPENSATION_RX11_0, ALP_COMPENSATION_RX11_1,
    ALP_COMPENSATION_RX12_0, ALP_COMPENSATION_RX12_1,
};
static const uint8_t iqs9151_main_config[] = {
    MINOR_VERSION,
    MAJOR_VERSION,
    TP_ATI_MULTDIV_L,
    TP_ATI_MULTDIV_H,
    ALP_ATI_COARSE_RX0_L,
    ALP_ATI_COARSE_RX0_H,
    ALP_ATI_COARSE_RX1_L,
    ALP_ATI_COARSE_RX1_H,
    ALP_ATI_COARSE_RX2_L,
    ALP_ATI_COARSE_RX2_H,
    ALP_ATI_COARSE_RX3_L,
    ALP_ATI_COARSE_RX3_H,
    ALP_ATI_COARSE_RX4_L,
    ALP_ATI_COARSE_RX4_H,
    ALP_ATI_COARSE_RX5_L,
    ALP_ATI_COARSE_RX5_H,
    ALP_ATI_COARSE_RX6_L,
    ALP_ATI_COARSE_RX6_H,
    ALP_ATI_COARSE_RX7_L,
    ALP_ATI_COARSE_RX7_H,
    ALP_ATI_COARSE_RX8_L,
    ALP_ATI_COARSE_RX8_H,
    ALP_ATI_COARSE_RX9_L,
    ALP_ATI_COARSE_RX9_H,
    ALP_ATI_COARSE_RX10_L,
    ALP_ATI_COARSE_RX10_H,
    ALP_ATI_COARSE_RX11_L,
    ALP_ATI_COARSE_RX11_H,
    ALP_ATI_COARSE_RX12_L,
    ALP_ATI_COARSE_RX12_H,
    TP_ATI_TARGET_0,
    TP_ATI_TARGET_1,
    ALP_ATI_TARGET_0,
    ALP_ATI_TARGET_1,
    ALP_BASE_TARGET_0,
    ALP_BASE_TARGET_1,
    TP_NEG_DELTA_REATI_0,
    TP_NEG_DELTA_REATI_1,
    TP_POS_DELTA_REATI_0,
    TP_POS_DELTA_REATI_1,
    TP_REF_DRIFT_LIMIT,
    ALP_LTA_DRIFT_LIMIT,
    ACTIVE_MODE_SAMPLING_PERIOD_0,
    ACTIVE_MODE_SAMPLING_PERIOD_1,
    IDLE_TOUCH_MODE_SAMPLING_PERIOD_0,
    IDLE_TOUCH_MODE_SAMPLING_PERIOD_1,
    IDLE_MODE_SAMPLING_PERIOD_0,
    IDLE_MODE_SAMPLING_PERIOD_1,
    LP1_MODE_SAMPLING_PERIOD_0,
    LP1_MODE_SAMPLING_PERIOD_1,
    LP2_MODE_SAMPLING_PERIOD_0,
    LP2_MODE_SAMPLING_PERIOD_1,
    STATIONARY_TOUCH_TIMEOUT_0,
    STATIONARY_TOUCH_TIMEOUT_1,
    IDLE_TOUCH_MODE_TIMEOUT_0,
    IDLE_TOUCH_MODE_TIMEOUT_1,
    IDLE_MODE_TIMEOUT_0,
    IDLE_MODE_TIMEOUT_1,
    LP1_MODE_TIMEOUT_0,
    LP1_MODE_TIMEOUT_1,
    ACTIVE_MODE_TIMEOUT_0,
    ACTIVE_MODE_TIMEOUT_1,
    REATI_RETRY_TIME,
    REF_UPDATE_TIME,
    I2C_TIMEOUT_0,
    I2C_TIMEOUT_1,
    SNAP_TIMEOUT,
    OPEN_TIMING,
    SYSTEM_CONTROL_0,
    SYSTEM_CONTROL_1,
    CONFIG_SETTINGS_0,
    CONFIG_SETTINGS_1,
    OTHER_SETTINGS_0,
    OTHER_SETTINGS_1,
    ALP_SETUP_0,
    ALP_SETUP_1,
    ALP_SETUP_2,
    ALP_SETUP_3,
    ALP_TX_ENABLE_0,
    ALP_TX_ENABLE_1,
    ALP_TX_ENABLE_2,
    ALP_TX_ENABLE_3,
    ALP_TX_ENABLE_4,
    ALP_TX_ENABLE_5,
    TRACKPAD_TOUCH_SET_THRESHOLD,
    TRACKPAD_TOUCH_CLEAR_THRESHOLD,
    ALP_THRESHOLD,
    ALP_AUTOPROX_THRESHOLD,
    ALP_SET_DEBOUNCE,
    ALP_CLEAR_DEBOUNCE,
    SNAP_SET_THRESHOLD,
    SNAP_CLEAR_THRESHOLD,
    ALP_COUNT_BETA_LP1,
    ALP_LTA_BETA_LP1,
    ALP_COUNT_BETA_LP2,
    ALP_LTA_BETA_LP2,
    TP_FRAC,
    TP_PERIOD1,
    TP_PERIOD2,
    ALP_FRAC,
    ALP_PERIOD1,
    ALP_PERIOD2,
    TRACKPAD_HARDWARE_SETTINGS_0,
    TRACKPAD_HARDWARE_SETTINGS_1,
    ALP_HARDWARE_SETTINGS_0,
    ALP_HARDWARE_SETTINGS_1,
    TRACKPAD_SETTINGS_0_0,
    TRACKPAD_SETTINGS_0_1,
    TRACKPAD_SETTINGS_1_0,
    TRACKPAD_SETTINGS_1_1,
    X_RESOLUTION_0,
    X_RESOLUTION_1,
    Y_RESOLUTION_0,
    Y_RESOLUTION_1,
    XY_DYNAMIC_FILTER_BOTTOM_SPEED_0,
    XY_DYNAMIC_FILTER_BOTTOM_SPEED_1,
    XY_DYNAMIC_FILTER_TOP_SPEED_0,
    XY_DYNAMIC_FILTER_TOP_SPEED_1,
    XY_DYNAMIC_FILTER_BOTTOM_BETA,
    XY_DYNAMIC_FILTER_STATIC_FILTER_BETA,
    STATIONARY_TOUCH_MOV_THRESHOLD,
    FINGER_SPLIT_FACTOR,
    X_TRIM_VALUE,
    Y_TRIM_VALUE,
    JITTER_FILTER_DELTA,
    FINGER_CONFIDENCE_THRESHOLD,
};
static const uint8_t iqs9151_gesture_config[] = {
    GESTURE_ENABLE_0,
    GESTURE_ENABLE_1,
    GESTURE_ENABLE_2F_0,
    GESTURE_ENABLE_2F_1,
    TAP_TOUCH_TIME_0,
    TAP_TOUCH_TIME_1,
    TAP_WAIT_TIME_0,
    TAP_WAIT_TIME_1,
    TAP_DISTANCE_0,
    TAP_DISTANCE_1,
    HOLD_TIME_0,
    HOLD_TIME_1,
    SWIPE_TIME_0,
    SWIPE_TIME_1,
    SWIPE_X_DISTANCE_0,
    SWIPE_X_DISTANCE_1,
    SWIPE_Y_DISTANCE_0,
    SWIPE_Y_DISTANCE_1,
    SWIPE_X_CONS_DIST_0,
    SWIPE_X_CONS_DIST_1,
    SWIPE_Y_CONS_DIST_0,
    SWIPE_Y_CONS_DIST_1,
    SWIPE_ANGLE,
    SCROLL_ANGLE,
    ZOOM_INIT_DIST_0,
    ZOOM_INIT_DIST_1,
    ZOOM_CONSECUTIVE_DIST_0,
    ZOOM_CONSECUTIVE_DIST_1,
    SCROLL_INIT_DIST_0,
    SCROLL_INIT_DIST_1,
    SCROLL_CONSECUTIVE_DIST_0,
    SCROLL_CONSECUTIVE_DIST_1,
    PALM_GESTURE_THRESHOLD_0,
    PALM_GESTURE_THRESHOLD_1,
};
static const uint8_t iqs9151_rxtx_map[] = {
    RX_TX_MAP_0,  RX_TX_MAP_1,  RX_TX_MAP_2,  RX_TX_MAP_3,  RX_TX_MAP_4,
    RX_TX_MAP_5,  RX_TX_MAP_6,  RX_TX_MAP_7,  RX_TX_MAP_8,  RX_TX_MAP_9,
    RX_TX_MAP_10, RX_TX_MAP_11, RX_TX_MAP_12, RX_TX_MAP_13, RX_TX_MAP_14,
    RX_TX_MAP_15, RX_TX_MAP_16, RX_TX_MAP_17, RX_TX_MAP_18, RX_TX_MAP_19,
    RX_TX_MAP_20, RX_TX_MAP_21, RX_TX_MAP_22, RX_TX_MAP_23, RX_TX_MAP_24,
    RX_TX_MAP_25, RX_TX_MAP_26, RX_TX_MAP_27, RX_TX_MAP_28, RX_TX_MAP_29,
    RX_TX_MAP_30, RX_TX_MAP_31, RX_TX_MAP_32, RX_TX_MAP_33, RX_TX_MAP_34,
    RX_TX_MAP_35, RX_TX_MAP_36, RX_TX_MAP_37, RX_TX_MAP_38, RX_TX_MAP_39,
    RX_TX_MAP_40, RX_TX_MAP_41, RX_TX_MAP_42, RX_TX_MAP_43, RX_TX_MAP_44,
    RX_TX_OPEN,
};
static const uint8_t iqs9151_channel_disable[] = {
    TPCHANNELDISABLE_0,  TPCHANNELDISABLE_1,  TPCHANNELDISABLE_2,
    TPCHANNELDISABLE_3,  TPCHANNELDISABLE_4,  TPCHANNELDISABLE_5,
    TPCHANNELDISABLE_6,  TPCHANNELDISABLE_7,  TPCHANNELDISABLE_8,
    TPCHANNELDISABLE_9,  TPCHANNELDISABLE_10, TPCHANNELDISABLE_11,
    TPCHANNELDISABLE_12, TPCHANNELDISABLE_13, TPCHANNELDISABLE_14,
    TPCHANNELDISABLE_15, TPCHANNELDISABLE_16, TPCHANNELDISABLE_17,
    TPCHANNELDISABLE_18, TPCHANNELDISABLE_19, TPCHANNELDISABLE_20,
    TPCHANNELDISABLE_21, TPCHANNELDISABLE_22, TPCHANNELDISABLE_23,
    TPCHANNELDISABLE_24, TPCHANNELDISABLE_25, TPCHANNELDISABLE_26,
    TPCHANNELDISABLE_27, TPCHANNELDISABLE_28, TPCHANNELDISABLE_29,
    TPCHANNELDISABLE_30, TPCHANNELDISABLE_31, TPCHANNELDISABLE_32,
    TPCHANNELDISABLE_33, TPCHANNELDISABLE_34, TPCHANNELDISABLE_35,
    TPCHANNELDISABLE_36, TPCHANNELDISABLE_37, TPCHANNELDISABLE_38,
    TPCHANNELDISABLE_39, TPCHANNELDISABLE_40, TPCHANNELDISABLE_41,
    TPCHANNELDISABLE_42, TPCHANNELDISABLE_43, TPCHANNELDISABLE_44,
    TPCHANNELDISABLE_45, TPCHANNELDISABLE_46, TPCHANNELDISABLE_47,
    TPCHANNELDISABLE_48, TPCHANNELDISABLE_49, TPCHANNELDISABLE_50,
    TPCHANNELDISABLE_51, TPCHANNELDISABLE_52, TPCHANNELDISABLE_53,
    TPCHANNELDISABLE_54, TPCHANNELDISABLE_55, TPCHANNELDISABLE_56,
    TPCHANNELDISABLE_57, TPCHANNELDISABLE_58, TPCHANNELDISABLE_59,
    TPCHANNELDISABLE_60, TPCHANNELDISABLE_61, TPCHANNELDISABLE_62,
    TPCHANNELDISABLE_63, TPCHANNELDISABLE_64, TPCHANNELDISABLE_65,
    TPCHANNELDISABLE_66, TPCHANNELDISABLE_67, TPCHANNELDISABLE_68,
    TPCHANNELDISABLE_69, TPCHANNELDISABLE_70, TPCHANNELDISABLE_71,
    TPCHANNELDISABLE_72, TPCHANNELDISABLE_73, TPCHANNELDISABLE_74,
    TPCHANNELDISABLE_75, TPCHANNELDISABLE_76, TPCHANNELDISABLE_77,
    TPCHANNELDISABLE_78, TPCHANNELDISABLE_79, TPCHANNELDISABLE_80,
    TPCHANNELDISABLE_81, TPCHANNELDISABLE_82, TPCHANNELDISABLE_83,
    TPCHANNELDISABLE_84, TPCHANNELDISABLE_85, TPCHANNELDISABLE_86,
    TPCHANNELDISABLE_87,
};
static const uint8_t iqs9151_snap_enable[] = {
    SNAPCHANNELENABLE_0,  SNAPCHANNELENABLE_1,  SNAPCHANNELENABLE_2,
    SNAPCHANNELENABLE_3,  SNAPCHANNELENABLE_4,  SNAPCHANNELENABLE_5,
    SNAPCHANNELENABLE_6,  SNAPCHANNELENABLE_7,  SNAPCHANNELENABLE_8,
    SNAPCHANNELENABLE_9,  SNAPCHANNELENABLE_10, SNAPCHANNELENABLE_11,
    SNAPCHANNELENABLE_12, SNAPCHANNELENABLE_13, SNAPCHANNELENABLE_14,
    SNAPCHANNELENABLE_15, SNAPCHANNELENABLE_16, SNAPCHANNELENABLE_17,
    SNAPCHANNELENABLE_18, SNAPCHANNELENABLE_19, SNAPCHANNELENABLE_20,
    SNAPCHANNELENABLE_21, SNAPCHANNELENABLE_22, SNAPCHANNELENABLE_23,
    SNAPCHANNELENABLE_24, SNAPCHANNELENABLE_25, SNAPCHANNELENABLE_26,
    SNAPCHANNELENABLE_27, SNAPCHANNELENABLE_28, SNAPCHANNELENABLE_29,
    SNAPCHANNELENABLE_30, SNAPCHANNELENABLE_31, SNAPCHANNELENABLE_32,
    SNAPCHANNELENABLE_33, SNAPCHANNELENABLE_34, SNAPCHANNELENABLE_35,
    SNAPCHANNELENABLE_36, SNAPCHANNELENABLE_37, SNAPCHANNELENABLE_38,
    SNAPCHANNELENABLE_39, SNAPCHANNELENABLE_40, SNAPCHANNELENABLE_41,
    SNAPCHANNELENABLE_42, SNAPCHANNELENABLE_43, SNAPCHANNELENABLE_44,
    SNAPCHANNELENABLE_45, SNAPCHANNELENABLE_46, SNAPCHANNELENABLE_47,
    SNAPCHANNELENABLE_48, SNAPCHANNELENABLE_49, SNAPCHANNELENABLE_50,
    SNAPCHANNELENABLE_51, SNAPCHANNELENABLE_52, SNAPCHANNELENABLE_53,
    SNAPCHANNELENABLE_54, SNAPCHANNELENABLE_55, SNAPCHANNELENABLE_56,
    SNAPCHANNELENABLE_57, SNAPCHANNELENABLE_58, SNAPCHANNELENABLE_59,
    SNAPCHANNELENABLE_60, SNAPCHANNELENABLE_61, SNAPCHANNELENABLE_62,
    SNAPCHANNELENABLE_63, SNAPCHANNELENABLE_64, SNAPCHANNELENABLE_65,
    SNAPCHANNELENABLE_66, SNAPCHANNELENABLE_67, SNAPCHANNELENABLE_68,
    SNAPCHANNELENABLE_69, SNAPCHANNELENABLE_70, SNAPCHANNELENABLE_71,
    SNAPCHANNELENABLE_72, SNAPCHANNELENABLE_73, SNAPCHANNELENABLE_74,
    SNAPCHANNELENABLE_75, SNAPCHANNELENABLE_76, SNAPCHANNELENABLE_77,
    SNAPCHANNELENABLE_78, SNAPCHANNELENABLE_79, SNAPCHANNELENABLE_80,
    SNAPCHANNELENABLE_81, SNAPCHANNELENABLE_82, SNAPCHANNELENABLE_83,
    SNAPCHANNELENABLE_84, SNAPCHANNELENABLE_85, SNAPCHANNELENABLE_86,
    SNAPCHANNELENABLE_87,
};

static int iqs9151_i2c_write(const struct iqs9151_config *cfg, uint16_t reg, const uint8_t *buf, size_t len) {
    uint8_t tx[2 + IQS9151_I2C_CHUNK_SIZE];

    if (len > (sizeof(tx) - 2)) {
        return -EINVAL;
    }

    sys_put_le16(reg, tx);
    memcpy(&tx[2], buf, len);
    return i2c_write_dt(&cfg->bus, tx, len + 2);
}

static int iqs9151_i2c_read(const struct iqs9151_config *cfg, uint16_t reg, uint8_t *buf, size_t len) {
    uint8_t addr_buf[2];

    sys_put_le16(reg, addr_buf);
    return i2c_write_read_dt(&cfg->bus, addr_buf, sizeof(addr_buf), buf, len);
}

static void iqs9151_wait_for_ready(const struct device *dev, uint16_t timeout_ms) {
    const struct iqs9151_config *cfg = dev->config;
    uint16_t elapsed = 0;

    while (!gpio_pin_get_dt(&cfg->irq_gpio) && elapsed < timeout_ms) {
        k_sleep(K_MSEC(1));
        elapsed++;
    }

    if (elapsed >= timeout_ms) {
        LOG_WRN("RDY timeout after %dms", timeout_ms);
    }
    LOG_DBG("IRQGPIO=%d,TIME=%dms", gpio_pin_get_dt(&cfg->irq_gpio), elapsed);
}

static int iqs9151_write_chunks(const struct device *dev, const struct iqs9151_config *cfg
                                    , uint16_t start_reg, const uint8_t *buf, size_t len) {
    size_t offset = 0U;

    while (offset < len) {
        const size_t chunk_len = MIN(IQS9151_I2C_CHUNK_SIZE, len - offset);
        
        iqs9151_wait_for_ready(dev, 200);

        const int ret = iqs9151_i2c_write(cfg, start_reg + offset, buf + offset, chunk_len);
        if (ret != 0) {
            return ret;
        }
        offset += chunk_len;
    }
    return 0;
}

static int checkProductNumber(const struct device *dev) {
    const struct iqs9151_config *cfg = dev->config;
    uint8_t product[2];
    int ret;
    
    ret = iqs9151_i2c_read(cfg, IQS9151_ADDR_PRODUCT_NUMBER, product, sizeof(product));
    if (ret != 0) {
        return ret;
    }

    uint16_t product_num = sys_get_le16(product);
    if (ret == 0 && product_num != IQS9151_PRODUCT_NUMBER) {
        LOG_ERR("unexpected product number 0x%04x", product_num);
        return -ENODEV;
    }

    LOG_DBG("product number 0x%04x", product_num);
    return ret;
}

static void iqs9151_parse_frame(const uint8_t *raw, struct iqs9151_frame *frame) {
    frame->rel_x = (int16_t)sys_get_le16(&raw[0]);
    frame->rel_y = (int16_t)sys_get_le16(&raw[2]);
    frame->gesture_x = (int16_t)sys_get_le16(&raw[4]);
    frame->gesture_y = (int16_t)sys_get_le16(&raw[6]);
    frame->single_gestures = sys_get_le16(&raw[8]);
    frame->two_finger_gestures = sys_get_le16(&raw[10]);
    frame->info_flags = sys_get_le16(&raw[12]);
    frame->trackpad_flags = sys_get_le16(&raw[14]);
    frame->finger_count =
        (uint8_t)(frame->trackpad_flags & IQS9151_TP_FINGER_COUNT_MASK);
    frame->finger1_x = sys_get_le16(&raw[16]);
    frame->finger1_y = sys_get_le16(&raw[18]);
}

static void iqs9151_update_prev_frame(struct iqs9151_data *data,
                                      const struct iqs9151_frame *frame,
                                      const struct iqs9151_frame *prev_frame) {
    const bool finger1_confident =
        (frame->trackpad_flags & IQS9151_TP_FINGER1_CONFIDENCE) != 0U;
    const bool finger1_coord_valid =
        (frame->finger1_x != UINT16_MAX) && (frame->finger1_y != UINT16_MAX);

    data->prev_frame = *frame;

    if (frame->finger_count == 0U) {
        data->prev_frame.finger1_x = 0;
        data->prev_frame.finger1_y = 0;
        return;
    }

    if (!finger1_confident || !finger1_coord_valid) {
        data->prev_frame.finger1_x = prev_frame->finger1_x;
        data->prev_frame.finger1_y = prev_frame->finger1_y;
    }
}

static int32_t iqs9151_abs32(int32_t value) {
    return (value < 0) ? -value : value;
}

static void iqs9151_scroll_hist_reset(struct iqs9151_data *data) {
    data->scroll_hist_pos_x = 0U;
    data->scroll_hist_pos_y = 0U;
    data->scroll_hist_count_x = 0U;
    data->scroll_hist_count_y = 0U;
}

static void iqs9151_scroll_hist_push(int16_t *buf, uint8_t *pos, uint8_t *count, int16_t val) {
    buf[*pos] = val;
    *pos = (uint8_t)((*pos + 1U) % INERTIA_AVG_FRAMES);
    if (*count < INERTIA_AVG_FRAMES) {
        (*count)++;
    }
}

static int32_t iqs9151_scroll_hist_weighted_avg(const int16_t *buf, uint8_t pos, uint8_t count) {
    if (count == 0U) {
        return 0;
    }

    uint32_t weight_sum = 0U;
    int32_t sum = 0;
    uint8_t start = (uint8_t)((pos + INERTIA_AVG_FRAMES - count) % INERTIA_AVG_FRAMES);

    for (uint8_t i = 0U; i < count; i++) {
        uint8_t idx = (uint8_t)((start + i) % INERTIA_AVG_FRAMES);
        uint32_t weight = (uint32_t)(i + 1U);
        sum += (int32_t)buf[idx] * (int32_t)weight;
        weight_sum += weight;
    }

    return sum / (int32_t)weight_sum;
}

static void iqs9151_inertia_cancel(struct iqs9151_data *data) {
    data->inertia_active = false;
    data->inertia_vx_fp = 0;
    data->inertia_vy_fp = 0;
    data->inertia_accum_x_fp = 0;
    data->inertia_accum_y_fp = 0;
    data->inertia_elapsed_ms = 0U;
    k_work_cancel_delayable(&data->inertia_work);
}

static void iqs9151_inertia_start(struct iqs9151_data *data, int32_t avg_x, int32_t avg_y) {
    data->inertia_vx_fp = (int32_t)(avg_x << INERTIA_FP_SHIFT);
    data->inertia_vy_fp = (int32_t)(avg_y << INERTIA_FP_SHIFT);
    data->inertia_accum_x_fp = 0;
    data->inertia_accum_y_fp = 0;
    data->inertia_elapsed_ms = 0U;
    data->inertia_last_ms = k_uptime_get();
    data->inertia_active = true;
    k_work_schedule(&data->inertia_work, K_MSEC(INERTIA_INTERVAL_MS));
}

static void iqs9151_inertia_work_cb(struct k_work *work) {
    struct k_work_delayable *dwork = k_work_delayable_from_work(work);
    struct iqs9151_data *data = CONTAINER_OF(dwork, struct iqs9151_data, inertia_work);
    const struct device *dev = data->dev;
    int64_t now;
    int64_t dt_ms;
    uint32_t steps;

    if (!data->inertia_active) {
        return;
    }

    now = k_uptime_get();
    dt_ms = now - data->inertia_last_ms;
    if (dt_ms <= 0) {
        dt_ms = INERTIA_INTERVAL_MS;
    }
    steps = (uint32_t)((dt_ms + INERTIA_INTERVAL_MS - 1) / INERTIA_INTERVAL_MS);
    if (steps == 0U) {
        steps = 1U;
    }

    for (uint32_t i = 0U; i < steps; i++) {
        data->inertia_accum_x_fp += data->inertia_vx_fp;
        data->inertia_accum_y_fp += data->inertia_vy_fp;
        data->inertia_vx_fp =
            (data->inertia_vx_fp * INERTIA_DECAY_NUM) / INERTIA_DECAY_DEN;
        data->inertia_vy_fp =
            (data->inertia_vy_fp * INERTIA_DECAY_NUM) / INERTIA_DECAY_DEN;
    }

    data->inertia_last_ms = now;
    data->inertia_elapsed_ms += steps * INERTIA_INTERVAL_MS;

    int32_t out_x = data->inertia_accum_x_fp >> INERTIA_FP_SHIFT;
    int32_t out_y = data->inertia_accum_y_fp >> INERTIA_FP_SHIFT;
    data->inertia_accum_x_fp -= out_x << INERTIA_FP_SHIFT;
    data->inertia_accum_y_fp -= out_y << INERTIA_FP_SHIFT;

    if (out_x > INT16_MAX) {
        out_x = INT16_MAX;
    } else if (out_x < INT16_MIN) {
        out_x = INT16_MIN;
    }
    if (out_y > INT16_MAX) {
        out_y = INT16_MAX;
    } else if (out_y < INT16_MIN) {
        out_y = INT16_MIN;
    }

    const bool have_x = out_x != 0;
    const bool have_y = out_y != 0;
    if (have_x) {
        input_report_rel(dev, INPUT_REL_HWHEEL, (int16_t)out_x, !have_y, K_NO_WAIT);
    }
    if (have_y) {
        input_report_rel(dev, INPUT_REL_WHEEL, (int16_t)out_y, true, K_NO_WAIT);
    }

    const int32_t min_v_fp = (int32_t)(INERTIA_MIN_VELOCITY << INERTIA_FP_SHIFT);
    if (data->inertia_elapsed_ms >= INERTIA_MAX_DURATION_MS ||
        (iqs9151_abs32(data->inertia_vx_fp) < min_v_fp &&
         iqs9151_abs32(data->inertia_vy_fp) < min_v_fp)) {
        iqs9151_inertia_cancel(data);
        return;
    }

    k_work_schedule(&data->inertia_work, K_MSEC(INERTIA_INTERVAL_MS));
}

static void iqs9151_work_cb(struct k_work *work) {
    struct iqs9151_data *data = CONTAINER_OF(work, struct iqs9151_data, work);
    const struct device *dev = data->dev;
    const struct iqs9151_config *cfg = dev->config;
    uint8_t raw_frame[20];
    struct iqs9151_frame frame;
    struct iqs9151_frame prev_frame;
    bool movement_valid = false;
    int ret;

    /* Read RelativeX(0x1014) .. Finger1Y(0x1026) in one transaction. */
    ret = iqs9151_i2c_read(cfg, IQS9151_ADDR_RELATIVE_X, raw_frame, sizeof(raw_frame));
    if (ret != 0) {
        LOG_ERR("frame read failed (%d)", ret);
        return;
    }

    iqs9151_parse_frame(raw_frame, &frame);
    prev_frame = data->prev_frame;

    // Cancel Inertial Scrolling
    const bool prev_hscroll = (prev_frame.two_finger_gestures & BIT(7)) != 0U;
    const bool prev_vscroll = (prev_frame.two_finger_gestures & BIT(6)) != 0U;
    const bool curr_hscroll = (frame.two_finger_gestures & BIT(7)) != 0U;
    const bool curr_vscroll = (frame.two_finger_gestures & BIT(6)) != 0U;
    const bool scroll_started = (!prev_hscroll && !prev_vscroll) && (curr_hscroll || curr_vscroll);
    const bool scroll_ended   = (prev_hscroll || prev_vscroll) && !curr_hscroll && !curr_vscroll;
    if (scroll_started || frame.finger_count == 2U) {
        iqs9151_scroll_hist_reset(data);
        if (data->inertia_active) {
            iqs9151_inertia_cancel(data);
        }
    }

    if (frame.info_flags & IQS9151_INFO_SHOW_RESET) {
        /* TODO: handle reset indication if needed */
        return;
    }

    if (frame.single_gestures != 0U || frame.two_finger_gestures != 0U) {
        // SingleFingerGestures
        if (frame.single_gestures != 0U) {
            const uint16_t single = frame.single_gestures;
            const bool single_tap = (single & BIT(0)) != 0U;
            const bool press_hold = (single & BIT(3)) != 0U;

            if (single_tap) {
                LOG_DBG("Single Tap Event occurred!");
                input_report_key(dev, INPUT_BTN_0, true, true, K_FOREVER);
                input_report_key(dev, INPUT_BTN_0, false, true, K_FOREVER);

            } else if (press_hold) {
                LOG_DBG("Press Hold Event occurred!");
                const bool prev_press_hold =
                    ((data->prev_frame.single_gestures & BIT(3)) != 0U);

                if (!prev_press_hold) {
                    input_report_key(dev, INPUT_BTN_0, true, true, K_FOREVER);
                } else if ((frame.gesture_x != 0) || (frame.gesture_y != 0)) {
                    input_report_rel(dev, INPUT_REL_X, frame.gesture_x, false, K_NO_WAIT);
                    input_report_rel(dev, INPUT_REL_Y, frame.gesture_y, true, K_NO_WAIT);
                }
            }
        }
        // TwoFinger Gestures
        if (frame.two_finger_gestures != 0U) {

            if ((frame.two_finger_gestures & BIT(0)) != 0U) {
                input_report_key(dev, INPUT_BTN_1, true, true, K_FOREVER);
                input_report_key(dev, INPUT_BTN_1, false, true, K_FOREVER);
            }
            if (curr_hscroll) {
                input_report_rel(dev, INPUT_REL_HWHEEL, frame.gesture_x, !curr_vscroll, K_NO_WAIT);
                iqs9151_scroll_hist_push(data->scroll_hist_x, &data->scroll_hist_pos_x,
                                         &data->scroll_hist_count_x, frame.gesture_x);
            }
            if (curr_vscroll) {
                input_report_rel(dev, INPUT_REL_WHEEL, frame.gesture_y, true, K_NO_WAIT);
                iqs9151_scroll_hist_push(data->scroll_hist_y, &data->scroll_hist_pos_y,
                                         &data->scroll_hist_count_y, frame.gesture_y);
            }

            // TODO ピンチインピンチアウト処理を実装する
            // OS依存するのでやるならイベントを起こしてZMKで処理したい
        }
        // TODO ThreeFinger Gesturesを実装する （ICに機能が無いので自前実装
        /* ThreeFinger Gestures
            IFタッチしている指の本数が3本
                ThreeFinger Gestures開始フラグON
                指1の移動量（Finger1X/Y-Coordinate）を取得し、バッファに加算
            
            IF タッチしている指の本数がゼロ＆ ThreeFinger Gestures開始フラグON
                スワイプが確定したということで、イベント処理開始
                IF バッファを参照し、移動量が閾値を超えている
                    IF 移動が右方向
                        進むボタンをレポート
                    IF 移動が左方向
                        戻るボタンをレポート
                
                ThreeFinger Gestures開始フラグOFFにする
                バッファをクリアする
        */

    // TP Movement to XY Relative
    } else if (frame.trackpad_flags & IQS9151_TP_MOVEMENT_DETECTED) {

        const bool finger1_confident = (frame.trackpad_flags & IQS9151_TP_FINGER1_CONFIDENCE) != 0U;
        const bool finger1_coord_valid = (frame.finger1_x != UINT16_MAX) && (frame.finger1_y != UINT16_MAX);

        movement_valid = finger1_confident && finger1_coord_valid;

        if (movement_valid) {
            input_report_rel(dev, INPUT_REL_X, frame.rel_x, false, K_NO_WAIT);
            input_report_rel(dev, INPUT_REL_Y, frame.rel_y, true, K_NO_WAIT);

        }
    } else {
        /* TODO: no movement/gesture; optionally handle idle state */
    }

    LOG_DBG("rel x=%d y=%d ges x=%d y=%d info=0x%04x tp=0x%04x finger=%d f1x=%u f1y=%u",
            frame.rel_x, frame.rel_y, frame.gesture_x, frame.gesture_y, frame.info_flags,
            frame.trackpad_flags, frame.finger_count, frame.finger1_x, frame.finger1_y);
    
    // Release Button for Press And Hold
    if (frame.finger_count == 0U &&
        ((data->prev_frame.single_gestures & BIT(3)) != 0U)) {
        input_report_key(dev, INPUT_BTN_0, false, true, K_NO_WAIT);
    }

    // Inertial Scrolling
    if (scroll_ended) {
        int32_t avg_x = iqs9151_scroll_hist_weighted_avg(
            data->scroll_hist_x, data->scroll_hist_pos_x, data->scroll_hist_count_x);
        int32_t avg_y = iqs9151_scroll_hist_weighted_avg(
            data->scroll_hist_y, data->scroll_hist_pos_y, data->scroll_hist_count_y);
        int32_t start_x = (iqs9151_abs32(avg_x) >= INERTIA_START_THRESHOLD) ? avg_x : 0;
        int32_t start_y = (iqs9151_abs32(avg_y) >= INERTIA_START_THRESHOLD) ? avg_y : 0;

        if (start_x != 0 || start_y != 0) {
            iqs9151_inertia_start(data, start_x, start_y);
        }
        iqs9151_scroll_hist_reset(data);
    }
    iqs9151_update_prev_frame(data, &frame, &prev_frame);
}

static void iqs9151_gpio_cb(const struct device *port, struct gpio_callback *cb, uint32_t pins) {
    struct iqs9151_data *data = CONTAINER_OF(cb, struct iqs9151_data, gpio_cb);
    k_work_submit(&data->work);
}

static int set_interrupt(const struct device *dev, const bool en) {
    const struct iqs9151_config *config = dev->config;
    int ret = gpio_pin_interrupt_configure_dt( &config->irq_gpio, en ? GPIO_INT_EDGE_TO_ACTIVE : GPIO_INT_DISABLE);
    if (ret < 0) {
        LOG_ERR("can't set interrupt");
    }
    return ret;
}

static int iqs9151_run_ati(const struct iqs9151_config *config) {
    uint8_t ctrl[2] = {
        SYSTEM_CONTROL_0,
        SYSTEM_CONTROL_1 | IQS9151_SYS_CTRL_ALP_RE_ATI | IQS9151_SYS_CTRL_TP_RE_ATI,
    };
    return iqs9151_i2c_write(config, IQS9151_ADDR_SYSTEM_CONTROL, ctrl, sizeof(ctrl));
}

static int iqs9151_wait_for_ati(const struct device *dev, uint16_t timeout_ms) {
    const struct iqs9151_config *cfg = dev->config;
    int64_t start_ms = k_uptime_get();

    while ((k_uptime_get() - start_ms) < timeout_ms) {
        uint8_t ctrl[2];
        int ret;

        iqs9151_wait_for_ready(dev, 100);
        ret = iqs9151_i2c_read(cfg, IQS9151_ADDR_SYSTEM_CONTROL, ctrl, sizeof(ctrl));
        if (ret != 0) {
            return ret;
        }

        if ((sys_get_le16(ctrl) &
             (IQS9151_SYS_CTRL_ALP_RE_ATI | IQS9151_SYS_CTRL_TP_RE_ATI)) == 0U) {
            return 0;
        }

        k_sleep(K_MSEC(IQS9151_ATI_POLL_INTERVAL_MS));
    }

    LOG_ERR("ATI timeout after %dms", timeout_ms);
    return -EIO;
}

static int iqs9151_ack_reset(const struct device *dev) {
    const struct iqs9151_config *cfg = dev->config;
    uint8_t ctrl[2];
    int ret;

    ret = iqs9151_i2c_read(cfg, IQS9151_ADDR_SYSTEM_CONTROL, ctrl, sizeof(ctrl));
    if (ret != 0) {
        return ret;
    }

    uint16_t config = sys_get_le16(ctrl);
    config |= IQS9151_SYS_CTRL_ACK_RESET;
    sys_put_le16(config, ctrl);

    iqs9151_wait_for_ready(dev, 500);

    ret = iqs9151_i2c_write(cfg, IQS9151_ADDR_SYSTEM_CONTROL, ctrl, sizeof(ctrl));
    if (ret != 0) {
        return ret;
    }

    k_msleep(IQS9151_RSTD_DELAY_MS);
    return ret;
}

static int iqs9151_setEventMode(const struct device *dev) {
    const struct iqs9151_config *cfg = dev->config;
    uint8_t config_settings[2];

    int ret = iqs9151_i2c_read(cfg, IQS9151_ADDR_CONFIG_SETTINGS, config_settings, sizeof(config_settings));
    if (ret != 0) {
        return ret;
    }

    uint16_t settings = sys_get_le16(config_settings);
    settings |= IQS9151_CFG_EVENT_MODE;
    sys_put_le16(settings, config_settings);

    iqs9151_wait_for_ready(dev, 500);

    return iqs9151_i2c_write(cfg, IQS9151_ADDR_CONFIG_SETTINGS, config_settings, sizeof(config_settings));
}

static int iqs9151_hw_reset(const struct device *dev) {
    const struct iqs9151_config *cfg = dev->config;

    if (!cfg->reset_gpio.port) {
        return -ENODEV;
    }

    int ret = gpio_pin_set_dt(&cfg->reset_gpio, 1); // reset_gpio=ACTIVE_LOW
    if (ret) {
        return ret;
    }

    k_busy_wait(IQS9151_RESET_PULSE_US);

    ret = gpio_pin_set_dt(&cfg->reset_gpio, 0);
    if (ret) {
        return ret;
    }

    k_msleep(IQS9151_RSTD_DELAY_MS);

    return 0;
}

static int iqs9151_configure(const struct device *dev) {
    const struct iqs9151_config *cfg = dev->config;
    int ret;

    iqs9151_wait_for_ready(dev, 500);

    LOG_DBG("Initial configuration start");
    ret = iqs9151_write_chunks(dev, cfg, IQS9151_ADDR_ALP_COMPENSATION,
                                    iqs9151_alp_compensation,
                                    ARRAY_SIZE(iqs9151_alp_compensation));
    if (ret) {
        return ret;
    }
    ret = iqs9151_write_chunks(dev, cfg, IQS9151_ADDR_SETTINGS_MINOR,
                                    iqs9151_main_config,
                                    ARRAY_SIZE(iqs9151_main_config));
    if (ret) {
        return ret;
    }
    ret = iqs9151_write_chunks(dev, cfg, IQS9151_ADDR_GESTURE_ENABLE,
                                    iqs9151_gesture_config,
                                    ARRAY_SIZE(iqs9151_gesture_config));
    if (ret) {
        return ret;
    }
    ret = iqs9151_write_chunks(dev, cfg, IQS9151_ADDR_RX_TX_MAPPING,
                                    iqs9151_rxtx_map,
                                    ARRAY_SIZE(iqs9151_rxtx_map));
    if (ret) {
        return ret;
    }
    ret = iqs9151_write_chunks(dev, cfg, IQS9151_ADDR_CHANNEL_DISABLE,
                                    iqs9151_channel_disable,
                                    ARRAY_SIZE(iqs9151_channel_disable));
    if (ret) {
        return ret;
    }
    ret = iqs9151_write_chunks(dev, cfg, IQS9151_ADDR_SNAP_ENABLE,
                                    iqs9151_snap_enable,
                                    ARRAY_SIZE(iqs9151_snap_enable));
    if (ret) {
        return ret;
    }
    LOG_DBG("Initial configuration complete");
    return ret;
}

static int iqs9151_init(const struct device *dev) {
    const struct iqs9151_config *cfg = dev->config;
    struct iqs9151_data *data = dev->data;
    int ret;
    data->dev = dev;

    if (!device_is_ready(cfg->bus.bus)) {
        LOG_ERR("I2C bus not ready");
        return -ENODEV;
    }

    if (!cfg->irq_gpio.port) {
        LOG_ERR("IRQ GPIO not defined");
        return -ENODEV;
    }
    if (!device_is_ready(cfg->irq_gpio.port)) {
        LOG_ERR("IRQ GPIO not ready");
        return -ENODEV;
    }
    ret = gpio_pin_configure_dt(&cfg->irq_gpio, GPIO_INPUT);
    if (ret) {
        return ret;
    }

    if (!cfg->reset_gpio.port) {
        LOG_ERR("Reset GPIO not defined");
        return -ENODEV;
    }
    if (!device_is_ready(cfg->reset_gpio.port)) {
        LOG_ERR("Reset GPIO not ready");
        return -ENODEV;
    }
    ret = gpio_pin_configure_dt(&cfg->reset_gpio, GPIO_OUTPUT_ACTIVE);
    if (ret) {
        return ret;
    }

    // HW_RESET
    ret = iqs9151_hw_reset(dev);
    if (ret != 0) {
        LOG_ERR("HW Reset failed (%d)", ret);
        return ret;
    }
    LOG_DBG("Hardware RESET complete");

    iqs9151_wait_for_ready(dev, 1000);

    // Check Product Number
    ret = checkProductNumber(dev);
    if (ret != 0) {
        return ret;
    }

    iqs9151_wait_for_ready(dev, 500);

    // ACK Reset
    ret = iqs9151_ack_reset(dev);
    if (ret) {
        LOG_ERR("Reset flag clear failed (%d)", ret);
        return ret;
    }
    LOG_DBG("ACK Reset complete");

    iqs9151_wait_for_ready(dev, 500);

    // Setup Initial Config
    ret = iqs9151_configure(dev);
    if (ret != 0) {
        LOG_ERR("Device configuration failed: %d", ret);
        return ret;
    }
    LOG_DBG("Setup Initial Config complete");

    iqs9151_wait_for_ready(dev, 100);

    // ATI
    ret = iqs9151_run_ati(cfg);
    if (ret) {
        LOG_ERR("ATI request failed (%d)", ret);
        return ret;
    }
    LOG_DBG("ATI requested");

    ret = iqs9151_wait_for_ati(dev, IQS9151_ATI_TIMEOUT_MS);
    if (ret != 0) {
        LOG_ERR("ATI failed (%d)", ret);
        return ret;
    }
    LOG_DBG("ATI complete");

    // Setup IRQ Call Back
    k_work_init(&data->work, iqs9151_work_cb);
    k_work_init_delayable(&data->inertia_work, iqs9151_inertia_work_cb);
    iqs9151_scroll_hist_reset(data);
    data->inertia_active = false;
    gpio_init_callback(&data->gpio_cb, iqs9151_gpio_cb,
                        BIT(cfg->irq_gpio.pin));
    ret = gpio_add_callback(cfg->irq_gpio.port, &data->gpio_cb);
    if (ret < 0) {
        LOG_ERR("Failed to set DR callback: %d", ret);
        return -EIO;
    }

    iqs9151_wait_for_ready(dev, 100);

    // Set Event Mode
    ret = iqs9151_setEventMode(dev);
    if (ret) {
        LOG_ERR("Set Event Mode failed (%d)", ret);
        return ret;
    }
    LOG_DBG("Set Event Mode complete complete");

    // start IRQ
    set_interrupt(dev, true);
    LOG_DBG("Initialization complete");
    return 0;
}

#define IQS9151_INIT(inst)                                                \
    static const struct iqs9151_config iqs9151_config_##inst = {    \
        .bus = I2C_DT_SPEC_INST_GET(inst),                                      \
        .irq_gpio = GPIO_DT_SPEC_INST_GET(inst, irq_gpios),                     \
        .reset_gpio = GPIO_DT_SPEC_INST_GET_OR(inst, reset_gpios, {0}),         \
  };                                                                          \
  static struct iqs9151_data iqs9151_data_##inst;                 \
  DEVICE_DT_INST_DEFINE(inst, iqs9151_init, NULL,                       \
                        &iqs9151_data_##inst,                           \
                        &iqs9151_config_##inst, POST_KERNEL,            \
                        CONFIG_INPUT_IQS9151_INIT_PRIORITY, NULL);

DT_INST_FOREACH_STATUS_OKAY(IQS9151_INIT);
