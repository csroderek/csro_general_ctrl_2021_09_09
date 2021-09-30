#include "fnd_input.h"
#include "gpio.h"

GPIO_TypeDef *gpio_input_port[4] = {DI1_GPIO_Port, DI2_GPIO_Port, DI3_GPIO_Port, DI4_GPIO_Port};

uint16_t gpio_input_pin[4] = {DI1_Pin, DI2_Pin, DI3_Pin, DI4_Pin};

GPIO_TypeDef *gpio_id_port[8] = {IDA1_GPIO_Port, IDA2_GPIO_Port, IDA3_GPIO_Port, IDA4_GPIO_Port, IDB1_GPIO_Port, IDB2_GPIO_Port, IDB3_GPIO_Port, IDB4_GPIO_Port};

uint16_t gpio_id_pin[8] = {IDA1_Pin, IDA2_Pin, IDA3_Pin, IDA4_Pin, IDB1_Pin, IDB2_Pin, IDB3_Pin, IDB4_Pin};

void fnd_input_gpio_read_di(uint8_t *values)
{
    for (uint8_t i = 0; i < 4; i++)
    {
        values[i] = (HAL_GPIO_ReadPin(gpio_input_port[i], gpio_input_pin[i]) == GPIO_PIN_SET) ? 1 : 0;
    }
}

void fnd_input_gpio_read_id(uint8_t *values)
{
    for (uint8_t i = 0; i < 8; i++)
    {
        values[i] = (HAL_GPIO_ReadPin(gpio_id_port[i], gpio_id_pin[i]) == GPIO_PIN_SET) ? 1 : 0;
    }
}