#ifndef FND_INPUT_H_
#define FND_INPUT_H_

#include "stm32f4xx_hal.h"
#include "cmsis_os.h"

void fnd_input_peripheral_init(void);
void fnd_input_update_value(void);
void fnd_input_update_sht_value(void);

void fnd_input_adc_init(void);
void fnd_input_adc_read_ntc_temp(float *values);
void fnd_input_adc_read_rhi_temp_humi(float *values);
void fnd_input_adc_read_valve_feedback(float *values);

void fnd_input_gpio_read_di(uint8_t *values);

void fnd_input_tim_input_capture_init(void);
void fnd_input_tim_input_read_speed(uint16_t *values);
void HAL_TIM2_PeriodElapsedCallback(void);

HAL_StatusTypeDef fnd_input_i2c_read_sht_temp_humi(uint8_t idx, float *values);

#endif
