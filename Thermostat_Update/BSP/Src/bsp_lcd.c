#include "bsp_lcd.h"

void BSP_LCD_Init(void)
{
    LCD_Init();
}

void BSP_LCD_Clear(void)
{
    LCD_Clear();
}

void BSP_LCD_SetCursor(uint8_t row, uint8_t col)
{
    LCD_SetCursor(row, col);
}

void BSP_LCD_Print(const char *str)
{
    LCD_Print((char *)str);
}
