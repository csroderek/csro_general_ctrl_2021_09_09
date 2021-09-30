#ifndef FND_OUTPUT_H_
#define FND_OUTPUT_H_

#include "stm32f4xx_hal.h"
#include "fnd_output_stepper.h"

void fnd_output_peripheral_init(void);
void fnd_output_update_value(void);

void fnd_output_dac_init(void);
void fnd_output_dac_write_value(uint16_t *values);

void fnd_output_pwm_init(void);
void fnd_output_pwm_write_value(uint16_t *values);

void fnd_output_gpio_write_dout(uint8_t *values);

#endif
