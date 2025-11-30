#ifndef BSP_TEMP_SENSOR_H
#define BSP_TEMP_SENSOR_H

#include "stm32f4xx_hal.h"

void BSP_TempSensor_Init(void);
float BSP_TempSensor_ReadCelsius(void);

#endif
