#include "lcd_i2c.h"
#include "string.h"

// -------------------- Low-level functions ------------------------
HAL_StatusTypeDef LCD_Send_Data(uint8_t data)
{
	uint8_t data_u, data_l;
    uint8_t data_t[4];

    data_u = (data & 0xF0); // Upper nibble
    data_l = ((data << 4) & 0xF0); // Lower nibble

    data_t[0] = data_u | 0x0D; // Enable high, RS high
    data_t[1] = data_u | 0x09; // Enable low, RS high
    data_t[2] = data_l | 0x0D; // Enable high, RS high
    data_t[3] = data_l | 0x09; // Enable low, RS high

    if (HAL_I2C_Master_Transmit(&hi2c1, LCD_I2C_ADDR << 1, (uint8_t *)data_t, 4, HAL_MAX_DELAY) != HAL_OK)
    {
        // Handle error
        return HAL_ERROR;
    }
    return HAL_OK;
}

HAL_StatusTypeDef LCD_Send_Cmd(uint8_t cmd)
{
	uint8_t data_u, data_l;
    uint8_t data_t[4];

    data_u = (cmd & 0xF0); // Upper nibble
    data_l = ((cmd << 4) & 0xF0); // Lower nibble

    data_t[0] = data_u | 0x0C; // Enable high, RS low
    data_t[1] = data_u | 0x08; // Enable low, RS low
    data_t[2] = data_l | 0x0C; // Enable high, RS low
    data_t[3] = data_l | 0x08; // Enable low, RS low

    if (HAL_I2C_Master_Transmit(&hi2c1, LCD_I2C_ADDR << 1, (uint8_t *)data_t, 4, HAL_MAX_DELAY) != HAL_OK)
    {
        // Handle error
        return HAL_ERROR;
    }
    return HAL_OK;
}
// -------------------- High-level API ------------------------

void LCD_Init(void)
{
    // 4-bit initialization
    HAL_Delay(50);  // Wait for >40ms
    LCD_Send_Cmd(0x30);
    HAL_Delay(5);   // Wait for >4.1ms
    LCD_Send_Cmd(0x30);
    HAL_Delay(1);   // Wait for >100us
    LCD_Send_Cmd(0x30);
    HAL_Delay(10);
    LCD_Send_Cmd(0x20);  // 4-bit mode
    HAL_Delay(10);

    // Display initialization
    LCD_Send_Cmd(LCD_CMD_FUNCTION_SET);  // Function set: DL=0 (4-bit mode), N=1 (2-line display), F=0 (5x8 characters)
    HAL_Delay(1);
    LCD_Send_Cmd(LCD_CMD_DISPLAY_OFF);   // Display off
    HAL_Delay(1);
    LCD_Send_Cmd(LCD_CMD_CLEAR_DISPLAY); // Clear display
    HAL_Delay(2);
    LCD_Send_Cmd(LCD_CMD_ENTRY_MODE_SET); // Entry mode set: I/D=1 (increment cursor), S=0 (no shift)
    HAL_Delay(1);
    LCD_Send_Cmd(LCD_CMD_DISPLAY_ON);    // Display on: D=1, C=0, B=0 (Cursor and blink)
    HAL_Delay(1);
}

void LCD_Clear(void)
{
	if (LCD_Send_Cmd(LCD_CMD_CLEAR_DISPLAY) != HAL_OK)
	{
	        // Handle error
	}
	HAL_Delay(50); // Wait for the command to complete
}

void LCD_SetCursor(uint8_t row, uint8_t col)
{
    if (row == 0) col |= LCD_CMD_SET_CURSOR; // Set position for row 0
    if (row == 1) col |= (LCD_CMD_SET_CURSOR | 0x40); // Set position for row 1
    LCD_Send_Cmd(col); // Send command to set cursor position
}

void LCD_Print(char *str)
{
    while (*str)
    {
    	LCD_Send_Data(*str++);
    }
}
