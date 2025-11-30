#ifndef __APP_DISPLAY_H__
#define __APP_DISPLAY_H__

#include "bsp_lcd.h"
#include <stdint.h>
#include <stdio.h>

void APP_Display_Init(void);
void APP_Display_ShowWelcome(void);
void APP_Display_ShowTemperature(int temp);
void APP_Display_ShowFanState(uint8_t isOn);
void APP_Display_ShowSetTemp(int setTemp);


#endif
