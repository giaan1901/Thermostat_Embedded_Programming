#ifndef __BSP_LCD_H
#define __BSP_LCD_H

#include "stm32f4xx_hal.h"
#include "D:\HCMUT\Semester 5\Embedded\Assignment_1\New folder\Thermostat\Drivers\I2C_LCD\lcd_i2c.h"

void BSP_LCD_Init(void);
void BSP_LCD_Clear(void);
void BSP_LCD_SetCursor(uint8_t row, uint8_t col);
void BSP_LCD_Print(const char *str);

#endif
