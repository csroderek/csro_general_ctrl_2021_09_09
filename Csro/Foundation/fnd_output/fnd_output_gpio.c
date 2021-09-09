#include "fnd_output.h"
#include "gpio.h"

GPIO_TypeDef *relay_port[6] = {RLY1_GPIO_Port, RLY2_GPIO_Port, RLY3_GPIO_Port, RLY4_GPIO_Port, RLY5_GPIO_Port, RLY6_GPIO_Port};
uint16_t relay_pin[6] = {RLY1_Pin, RLY2_Pin, RLY3_Pin, RLY4_Pin, RLY5_Pin, RLY6_Pin};

void fnd_output_gpio_write_dout(uint8_t *values)
{
    for (uint8_t i = 0; i < 4; i++)
    {
        HAL_GPIO_WritePin(relay_port[i], relay_pin[i], (values[i] == 0) ? GPIO_PIN_RESET : GPIO_PIN_SET);
    }
}
