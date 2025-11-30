#ifndef __GPIO_INIT_H__
#define __GPIO_INIT_H__

#include "stm32f4xx_hal.h"

// Buttons connected to these pins
#define BUTTON_POWER_PIN   GPIO_PIN_0
#define BUTTON_SET_PIN     GPIO_PIN_1
#define BUTTON_UP_PIN      GPIO_PIN_2
#define BUTTON_DOWN_PIN    GPIO_PIN_3
#define BUTTON_GPIO_PORT   GPIOA

// Optional fan/LED indicator
#define FAN_LED_PIN        GPIO_PIN_5
#define FAN_LED_PORT       GPIOB

void MX_GPIO_Init(void);

#endif
