#include "fnd_input.h"
#include "fnd_com.h"

void fnd_input_peripheral_init(void)
{
    fnd_input_adc_init();
    fnd_input_tim_input_capture_init();
}

void fnd_input_update_value(void)
{
    float adc_values[6];
    uint8_t gpio_values[8];
    uint16_t speed_values[2];

    fnd_input_adc_read_pressure_difference(adc_values);
    for (uint8_t i = 0; i < 3; i++)
    {
        sys_regs.inputs[INPUT_PRE_START + i] = (int16_t)(adc_values[i]);
    }

    fnd_input_adc_read_valve_feedback(adc_values);
    sys_regs.inputs[INPUT_VAL_START] = (int16_t)(adc_values[0]);

    fnd_input_adc_read_ntc_temp(adc_values);
    for (uint8_t i = 0; i < 6; i++)
    {
        sys_regs.inputs[INPUT_NTC_START + i] = (int16_t)(adc_values[i] * 10);
    }

    fnd_input_gpio_read_di(gpio_values);
    for (uint8_t i = 0; i < 4; i++)
    {
        sys_regs.inputs[INPUT_DIN_START + i] = gpio_values[i];
    }

    fnd_input_gpio_read_id(gpio_values);
    for (uint8_t i = 0; i < 8; i++)
    {
        uint8_t bit_value = (gpio_values[i] == 1) ? 0x01 : 0x00;
        sys_regs.inputs[INPUT_ID_START] = (sys_regs.inputs[INPUT_ID_START] << 1) | bit_value;
    }

    static uint8_t count = 0;
    count = (count + 1) % 20;
    if (count == 0)
    {
        fnd_input_tim_input_read_speed(speed_values);
        for (uint8_t i = 0; i < 2; i++)
        {
            sys_regs.inputs[INPUT_FANSPD_START + i] = (int16_t)speed_values[i];
        }
    }
}

void fnd_input_update_sht_value(void)
{
    float sht1_values[2] = {0};
    float sht2_values[2] = {0};
    HAL_StatusTypeDef status = fnd_input_i2c_read_sht_temp_humi(0, sht1_values);
    for (uint8_t i = 0; i < 2; i++)
    {
        sys_regs.inputs[INPUT_SHT_START + i] = (status == HAL_OK) ? (int16_t)(sht1_values[i] * 10) : (-1);
    }

    status = fnd_input_i2c_read_sht_temp_humi(1, sht2_values);
    for (uint8_t i = 0; i < 2; i++)
    {
        sys_regs.inputs[INPUT_SHT_START + 2 + i] = (status == HAL_OK) ? (int16_t)(sht2_values[i] * 10) : (-1);
    }
}
