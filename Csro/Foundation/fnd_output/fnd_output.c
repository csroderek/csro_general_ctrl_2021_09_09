#include "fnd_output.h"
#include "fnd_com.h"

void fnd_output_peripheral_init(void)
{
    fnd_output_dac_init();
    fnd_output_pwm_init();
}

void fnd_output_update_value(void)
{
    uint8_t dout_value[4];
    uint16_t dac_out_value[2];
    uint16_t pwm_out_value[2];

    for (uint8_t i = 0; i < 4; i++)
    {
        dout_value[i] = (uint8_t)sys_regs.inputs[INPUT_DOUT_CTRL_START + i];
    }
    fnd_output_gpio_write_dout(dout_value);

    for (uint8_t i = 0; i < 2; i++)
    {
        dac_out_value[i] = (uint16_t)sys_regs.inputs[INPUT_VOLT_CTRL_START + i];
    }
    fnd_output_dac_write_value(dac_out_value);

    for (uint8_t i = 0; i < 2; i++)
    {
        pwm_out_value[i] = (uint16_t)sys_regs.inputs[INPUT_PWM_CTRL_START + i];
    }
    fnd_output_pwm_write_value(pwm_out_value);
}