/*
 * battery.c
 *
 *  Created on: Feb 22, 2024
 *      Author: mateu
 */
#include "adc.h"
#include "Battery.h"

void Battery_Get_ADC_Value(ADC_HandleTypeDef* hadc , uint32_t* bat_adc_val)
{
	HAL_ADC_Start(hadc);
    HAL_ADC_PollForConversion(hadc, HAL_MAX_DELAY);
    *bat_adc_val = HAL_ADC_GetValue(hadc);
}


void Battery_Get_Voltage(ADC_HandleTypeDef* hadc , float* batteryVoltage)
{
	uint32_t bat_adc_val;
	Battery_Get_ADC_Value(hadc, &bat_adc_val);
    float VoltageADC = (((float)bat_adc_val / ADC_RESOLUTION) * VREF);
    *batteryVoltage = ((VoltageADC - V_RMIN) / (V_RMAX - V_RMIN)) * (VMAX - VMIN)+ VMIN;
    HAL_ADC_Stop(hadc);
}
