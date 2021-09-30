#include "fnd_output.h"
#include "fnd_com.h"

#define INPUT_FAN_PWM_CTRL_START 30 //30-31
#define INPUT_VAL_PWM_CTRL_START 32 //32
#define INPUT_RLY_DO_CTRL_START 33  //33-38
#define INPUT_STEPPER_CTRL_START 39 //39-42

void fnd_output_peripheral_init(void)
{
    fnd_output_pwm_init();
}

void fnd_output_update_value(void)
{
    uint16_t pwm_out_value[3];
    uint8_t relay_out_value[6];
    uint16_t stepper_pos_value[4];

    pwm_out_value[0] = (uint16_t)sys_regs.inputs[INPUT_FAN_PWM_CTRL_START + 0];
    pwm_out_value[1] = (uint16_t)sys_regs.inputs[INPUT_FAN_PWM_CTRL_START + 1];
    pwm_out_value[2] = (uint16_t)sys_regs.inputs[INPUT_VAL_PWM_CTRL_START + 0];
    fnd_output_pwm_write_value(pwm_out_value);

    for (uint8_t i = 0; i < 6; i++)
    {
        relay_out_value[i] = (uint8_t)sys_regs.inputs[INPUT_RLY_DO_CTRL_START + i];
    }
    fnd_output_gpio_write_dout(relay_out_value);

    for (uint8_t i = 0; i < 4; i++)
    {
        stepper_pos_value[i] = (uint16_t)sys_regs.inputs[INPUT_STEPPER_CTRL_START + i];
    }
    fnd_output_stepper_set_position(stepper_pos_value);
}