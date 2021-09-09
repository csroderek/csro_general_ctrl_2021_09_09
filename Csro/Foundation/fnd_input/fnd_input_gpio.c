#include "fnd_input.h"
#include "gpio.h"

GPIO_TypeDef *gpio_input_port[4] = {DI1_GPIO_Port, DI2_GPIO_Port, DI3_GPIO_Port, DI4_GPIO_Port};

uint16_t gpio_input_pin[4] = {DI1_Pin, DI2_Pin, DI3_Pin, DI4_Pin};

void fnd_input_gpio_read_di(uint8_t *values)
{
    for (uint8_t i = 0; i < 4; i++)
    {
        values[i] = (HAL_GPIO_ReadPin(gpio_input_port[i], gpio_input_pin[i]) == GPIO_PIN_SET) ? 1 : 0;
    }
}
