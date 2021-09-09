#include "fnd_input.h"
#include "adc.h"
#include "math.h"

#define ADC_TOTAL_CH 12
#define DATA_PER_CH 10

uint32_t fnd_adc_data[ADC_TOTAL_CH * DATA_PER_CH];

static float get_channel_average(uint8_t ch_idx)
{
    float sum = 0;
    for (uint8_t i = 0; i < DATA_PER_CH; i++)
    {
        sum = sum + fnd_adc_data[ch_idx + i * ADC_TOTAL_CH];
    }
    return sum / DATA_PER_CH;
}

static float calculate_ntc_temperature(double res_value, double res_ref, double b_value)
{
    return (float)(1 / (((log(res_value / res_ref)) / b_value) + (1 / (273.15 + 25))) - 273.15);
}

void fnd_input_adc_init(void)
{
    HAL_ADC_Start_DMA(&hadc1, fnd_adc_data, ADC_TOTAL_CH * DATA_PER_CH);
}

void fnd_input_adc_read_ntc_temp(float *values)
{
    for (uint8_t i = 0; i < 4; i++)
    {
        float ntc_adc_value = get_channel_average(i);
        float ntc_resister_value = (float)10 * ntc_adc_value / (4096 - ntc_adc_value);
        values[i] = calculate_ntc_temperature(ntc_resister_value, 10.0, 3950);
    }
}

void fnd_input_adc_read_rhi_temp_humi(float *values)
{
    for (uint8_t i = 0; i < 2; i++)
    {
        float rhi_temp_adc_value = get_channel_average(4 + 2 * i);
        float rhi_temp_res_value = 10 * rhi_temp_adc_value / (4096 - rhi_temp_adc_value);
        values[2 * i] = calculate_ntc_temperature(rhi_temp_res_value, 10.0, 3380);

        float rhi_humi_adc_value = get_channel_average(5 + 2 * i);
        float ave_adc_vrefint = get_channel_average(11);
        float rhi_humi_voltage = rhi_humi_adc_value / ave_adc_vrefint * 1.20;
        values[1 + 2 * i] = rhi_humi_voltage / 3.3 * 100;
    }
}

void fnd_input_adc_read_valve_feedback(float *values)
{
    for (uint8_t i = 0; i < 2; i++)
    {
        double valve_pos_adc_value = get_channel_average(8 + i) / 100.0;
        values[i] = (0.0004 * pow(valve_pos_adc_value, 4) - 0.0157 * pow(valve_pos_adc_value, 3) + 0.2021 * pow(valve_pos_adc_value, 2) + 1.6306 * valve_pos_adc_value + 2.3352);
    }
}
