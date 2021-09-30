#include "fnd_output.h"

#define EXCITE_TICKS 5

void fnd_output_stepper_init(stepper_motor *stepper)
{
}

void fnd_output_stepper_set_position(stepper_motor *stepper, uint16_t position)
{
}

void fnd_output_stepper_10ms_tick(stepper_motor *motor)
{
    if (motor->current_pos == motor->target_pos)
    {
        motor->mode = STOP;
        motor->up_excite_cnt = 0;
        motor->down_excite_cnt = 0;
    }
    else if (motor->current_pos < motor->target_pos)
    {
        motor->down_excite_cnt = 0;
        if (motor->up_excite_cnt < EXCITE_TICKS)
        {
            motor->mode = UP_EXCITE;
            motor->up_excite_cnt = motor->up_excite_cnt + 1;
        }
        else
        {
            motor->mode = UP;
        }
    }
    else if (motor->current_pos > motor->target_pos)
    {
        motor->up_excite_cnt = 0;
        if (motor->down_excite_cnt < EXCITE_TICKS)
        {
            motor->mode = DOWN_EXCITE;
            motor->down_excite_cnt = motor->down_excite_cnt + 1;
        }
        else
        {
            motor->mode = DOWN;
        }
    }

    if (motor->mode == STOP)
    {
        for (uint8_t i = 0; i < 4; i++)
        {
            HAL_GPIO_WritePin(motor->gpio_port[i], motor->gpio_pin[i], GPIO_PIN_RESET);
        }
    }
    else if (motor->mode == UP_EXCITE || motor->mode == DOWN_EXCITE)
    {
        HAL_GPIO_WritePin(motor->gpio_port[0], motor->gpio_pin[0], (motor->phase == 0 || motor->phase == 1 || motor->phase == 7) ? GPIO_PIN_SET : GPIO_PIN_RESET);
        HAL_GPIO_WritePin(motor->gpio_port[1], motor->gpio_pin[1], (motor->phase == 1 || motor->phase == 2 || motor->phase == 3) ? GPIO_PIN_SET : GPIO_PIN_RESET);
        HAL_GPIO_WritePin(motor->gpio_port[2], motor->gpio_pin[2], (motor->phase == 3 || motor->phase == 4 || motor->phase == 5) ? GPIO_PIN_SET : GPIO_PIN_RESET);
        HAL_GPIO_WritePin(motor->gpio_port[3], motor->gpio_pin[3], (motor->phase == 5 || motor->phase == 6 || motor->phase == 7) ? GPIO_PIN_SET : GPIO_PIN_RESET);
    }
    else if (motor->mode == UP)
    {
        for (uint8_t i = 0; i < 4; i++)
        {
            HAL_GPIO_WritePin(motor->gpio_port[i], motor->gpio_pin[i], GPIO_PIN_RESET);
        }
        motor->phase = (motor->phase + 1) % 8;
        HAL_GPIO_WritePin(motor->gpio_port[0], motor->gpio_pin[0], (motor->phase == 0 || motor->phase == 1 || motor->phase == 7) ? GPIO_PIN_SET : GPIO_PIN_RESET);
        HAL_GPIO_WritePin(motor->gpio_port[1], motor->gpio_pin[1], (motor->phase == 1 || motor->phase == 2 || motor->phase == 3) ? GPIO_PIN_SET : GPIO_PIN_RESET);
        HAL_GPIO_WritePin(motor->gpio_port[2], motor->gpio_pin[2], (motor->phase == 3 || motor->phase == 4 || motor->phase == 5) ? GPIO_PIN_SET : GPIO_PIN_RESET);
        HAL_GPIO_WritePin(motor->gpio_port[3], motor->gpio_pin[3], (motor->phase == 5 || motor->phase == 6 || motor->phase == 7) ? GPIO_PIN_SET : GPIO_PIN_RESET);
    }
    else if (motor->mode == DOWN)
    {
        for (uint8_t i = 0; i < 4; i++)
        {
            HAL_GPIO_WritePin(motor->gpio_port[i], motor->gpio_pin[i], GPIO_PIN_RESET);
        }
        motor->phase = (motor->phase + 7) % 8;
        HAL_GPIO_WritePin(motor->gpio_port[0], motor->gpio_pin[0], (motor->phase == 0 || motor->phase == 1 || motor->phase == 7) ? GPIO_PIN_SET : GPIO_PIN_RESET);
        HAL_GPIO_WritePin(motor->gpio_port[1], motor->gpio_pin[1], (motor->phase == 1 || motor->phase == 2 || motor->phase == 3) ? GPIO_PIN_SET : GPIO_PIN_RESET);
        HAL_GPIO_WritePin(motor->gpio_port[2], motor->gpio_pin[2], (motor->phase == 3 || motor->phase == 4 || motor->phase == 5) ? GPIO_PIN_SET : GPIO_PIN_RESET);
        HAL_GPIO_WritePin(motor->gpio_port[3], motor->gpio_pin[3], (motor->phase == 5 || motor->phase == 6 || motor->phase == 7) ? GPIO_PIN_SET : GPIO_PIN_RESET);
    }
}
