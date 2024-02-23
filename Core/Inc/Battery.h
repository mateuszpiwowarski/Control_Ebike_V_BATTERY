/*
 * Battery.h
 *
 *  Created on: Feb 22, 2024
 *      Author: mateu
 */

#ifndef INC_BATTERY_H_
#define INC_BATTERY_H_

#include "adc.h"

#define ADC_RESOLUTION 4095
#define VMIN 20
#define VMAX 30
#define VREF 3.3
#define V_RMAX 3.27
#define V_RMIN 2.17


void Battery_Get_ADC_Value(ADC_HandleTypeDef* hadc , uint32_t* bat_adc_val);
void Battery_Get_Voltage(ADC_HandleTypeDef* hadc , float* batteryVoltage);

#endif /* INC_BATTERY_H_ */
