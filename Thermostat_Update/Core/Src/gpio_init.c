#include "gpio_init.h"

void MX_GPIO_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    // 1. Enable GPIO clocks
    __HAL_RCC_GPIOA_CLK_ENABLE();  // Buttons
    __HAL_RCC_GPIOB_CLK_ENABLE();  // Fan LED
    __HAL_RCC_GPIOB_CLK_ENABLE();  // I2C1 SCL/SDA (PB6, PB7)

    // 2. Configure button pins as input with pull-up
    GPIO_InitStruct.Pin = BUTTON_POWER_PIN | BUTTON_SET_PIN | BUTTON_UP_PIN | BUTTON_DOWN_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_PULLUP;  // Buttons connect to GND when pressed
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(BUTTON_GPIO_PORT, &GPIO_InitStruct);

    // 3. Configure fan LED pin as output
    GPIO_InitStruct.Pin = FAN_LED_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(FAN_LED_PORT, &GPIO_InitStruct);

    // 4. Configure I2C1 pins PB6/SCL and PB7/SDA as alternate function
    GPIO_InitStruct.Pin = GPIO_PIN_6 | GPIO_PIN_7;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_OD;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF4_I2C1;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
}
