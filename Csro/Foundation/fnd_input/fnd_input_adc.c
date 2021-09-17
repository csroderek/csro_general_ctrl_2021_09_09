#include "fnd_input.h"
#include "adc.h"
#include "math.h"

#define ADC_TOTAL_CH 13
#define DATA_PER_CH 10

#define NTC_TOTAL_CH 6
#define NTC_START_CH 4

#define DELTA_P_TOTAL_CH 3
#define DELTA_P_START_CH 0

#define VALVE_FB_TOTAL_CH 1
#define VALVE_FB_START_CH 3

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
    for (uint8_t i = 0; i < NTC_TOTAL_CH; i++)
    {
        float ntc_adc_value = get_channel_average(i + NTC_START_CH);
        float ntc_resister_value = (float)1.0 * ntc_adc_value / (4096.0 - ntc_adc_value);
        values[i] = calculate_ntc_temperature(ntc_resister_value, 10.0, 3950);
    }
}

void fnd_input_adc_read_pressure_difference(float *values)
{
    for (uint8_t i = 0; i < DELTA_P_TOTAL_CH; i++)
    {
        float delta_p_adc_value = get_channel_average(i + DELTA_P_START_CH);
        values[i] = delta_p_adc_value;
    }
}

void fnd_input_adc_read_valve_feedback(float *values)
{
    for (uint8_t i = 0; i < VALVE_FB_TOTAL_CH; i++)
    {
        double valve_pos_adc_value = get_channel_average(i + VALVE_FB_START_CH) / 100.0;
        values[i] = (float)valve_pos_adc_value;
    }
}
