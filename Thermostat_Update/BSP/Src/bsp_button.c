#include "bsp_button.h"

// ------------------------------
// Button GPIO Assignments
// ------------------------------
#define POWER_BUTTON_PORT   GPIOA
#define POWER_BUTTON_PIN    GPIO_PIN_0

#define SET_BUTTON_PORT     GPIOA
#define SET_BUTTON_PIN      GPIO_PIN_1

#define UP_BUTTON_PORT      GPIOA
#define UP_BUTTON_PIN       GPIO_PIN_2

#define DOWN_BUTTON_PORT    GPIOA
#define DOWN_BUTTON_PIN     GPIO_PIN_3


// ------------------------------
// Initialize GPIO for all buttons
// ------------------------------
void BSP_Buttons_Init(void)
{
    __HAL_RCC_GPIOA_CLK_ENABLE();   // Enable GPIO port clock

    GPIO_InitTypeDef GPIO_InitStruct = {0};

    GPIO_InitStruct.Mode  = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull  = GPIO_PULLUP;   // Buttons active low
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;

    // POWER button
    GPIO_InitStruct.Pin = POWER_BUTTON_PIN;
    HAL_GPIO_Init(POWER_BUTTON_PORT, &GPIO_InitStruct);

    // SET button
    GPIO_InitStruct.Pin = SET_BUTTON_PIN;
    HAL_GPIO_Init(SET_BUTTON_PORT, &GPIO_InitStruct);

    // UP button
    GPIO_InitStruct.Pin = UP_BUTTON_PIN;
    HAL_GPIO_Init(UP_BUTTON_PORT, &GPIO_InitStruct);

    // DOWN button
    GPIO_InitStruct.Pin = DOWN_BUTTON_PIN;
    HAL_GPIO_Init(DOWN_BUTTON_PORT, &GPIO_InitStruct);
}


// ------------------------------
// Read button state
// Returns 1 = pressed, 0 = not pressed
// (Assumes active-low buttons)
// ------------------------------
uint8_t BSP_Button_Read(uint8_t button_id)
{
    switch(button_id)
    {
        case BUTTON_POWER:
            return HAL_GPIO_ReadPin(POWER_BUTTON_PORT, POWER_BUTTON_PIN) == GPIO_PIN_RESET;

        case BUTTON_SET:
            return HAL_GPIO_ReadPin(SET_BUTTON_PORT, SET_BUTTON_PIN) == GPIO_PIN_RESET;

        case BUTTON_UP:
            return HAL_GPIO_ReadPin(UP_BUTTON_PORT, UP_BUTTON_PIN) == GPIO_PIN_RESET;

        case BUTTON_DOWN:
            return HAL_GPIO_ReadPin(DOWN_BUTTON_PORT, DOWN_BUTTON_PIN) == GPIO_PIN_RESET;

        default:
            return 0;
    }
}
