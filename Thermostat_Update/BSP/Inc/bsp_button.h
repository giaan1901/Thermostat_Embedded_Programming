#ifndef BSP_BUTTON_H
#define BSP_BUTTON_H

#include "stm32f4xx_hal.h"

// Button identifiers
#define BUTTON_POWER  0
#define BUTTON_SET    1
#define BUTTON_UP     2
#define BUTTON_DOWN   3

void BSP_Button_Init_GPIO(void);
uint8_t BSP_Button_Press(uint8_t button);

#endif
