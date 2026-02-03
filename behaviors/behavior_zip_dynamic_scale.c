#define DT_DRV_COMPAT zmk_behavior_zip_dynamic_scale

#include <drivers/behavior.h>
#include <zmk/behavior.h>

#include <dt-bindings/zmk/zip_dynamic_scale.h>
#include <zmk/zip_dynamic_scaler.h>

static int behavior_zip_dynamic_scale_binding_pressed(struct zmk_behavior_binding *binding,
                                                      struct zmk_behavior_binding_event event) {
    ARG_UNUSED(event);
    int ret = 0;

    switch (binding->param1) {
    case ZIP_DYNAMIC_SCALE_INC:
        ret = zmk_zip_dynamic_scaler_step(1);
        break;
    case ZIP_DYNAMIC_SCALE_DEC:
        ret = zmk_zip_dynamic_scaler_step(-1);
        break;
    case ZIP_DYNAMIC_SCALE_RESET:
        ret = zmk_zip_dynamic_scaler_reset();
        break;
    default:
        return -EINVAL;
    }

    return ret < 0 ? ret : ZMK_BEHAVIOR_OPAQUE;
}

static int behavior_zip_dynamic_scale_binding_released(struct zmk_behavior_binding *binding,
                                                       struct zmk_behavior_binding_event event) {
    ARG_UNUSED(binding);
    ARG_UNUSED(event);
    return 0;
}

static const struct behavior_driver_api behavior_zip_dynamic_scale_driver_api = {
    .binding_pressed = behavior_zip_dynamic_scale_binding_pressed,
    .binding_released = behavior_zip_dynamic_scale_binding_released,
};

#define ZIP_DYN_SCALE_INST(n)                                                                      \
    BEHAVIOR_DT_INST_DEFINE(n, NULL, NULL, NULL, NULL, POST_KERNEL,                                \
                            CONFIG_KERNEL_INIT_PRIORITY_DEFAULT,                                  \
                            &behavior_zip_dynamic_scale_driver_api);

DT_INST_FOREACH_STATUS_OKAY(ZIP_DYN_SCALE_INST)
