#pragma once

#include <stdint.h>

uint16_t zmk_zip_dynamic_scaler_get_scale_x10(void);
int zmk_zip_dynamic_scaler_set_scale_x10(uint16_t scale_x10);
int zmk_zip_dynamic_scaler_step(int delta);
int zmk_zip_dynamic_scaler_reset(void);
