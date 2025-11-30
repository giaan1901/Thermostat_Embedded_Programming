#include "app_display.h"

void APP_Display_Init(void)
{
    BSP_LCD_Init();
    APP_Display_ShowWelcome();
}

void APP_Display_ShowWelcome(void)
{
    BSP_LCD_Clear();
    BSP_LCD_SetCursor(0, 0);
    BSP_LCD_Print("ABCD");
    BSP_LCD_SetCursor(1, 0);
    BSP_LCD_Print("1234");
}

void APP_Display_ShowTemperature(int temp)
{
    char buffer[16];
    BSP_LCD_SetCursor(0, 0);

    snprintf(buffer, sizeof(buffer), "Temp: %2dC", temp);
    BSP_LCD_Print(buffer);
}

void APP_Display_ShowFanState(uint8_t isOn)
{
    BSP_LCD_SetCursor(1, 0);
    BSP_LCD_Print("Fan: ");
    BSP_LCD_Print(isOn ? "ON " : "OFF");
}

void APP_Display_ShowSetTemp(int setTemp)
{
    char buffer[16];
    BSP_LCD_Clear();

    BSP_LCD_SetCursor(0, 0);
    snprintf(buffer, sizeof(buffer), "Set Temp: %2dC", setTemp);
    BSP_LCD_Print(buffer);

    BSP_LCD_SetCursor(1, 0);
    BSP_LCD_Print("UP/DOWN adjust");
}
