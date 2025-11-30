#ifndef __LCD_I2C_H__
#define __LCD_I2C_H__

#include "stm32f4xx_hal.h"

// Change to your I2C handler from CubeMX
extern I2C_HandleTypeDef hi2c1;

// LCD I2C address
#define LCD_I2C_ADDR 0x27 // 0x27 confirmed address

// LCD commands
#define LCD_CMD_CLEAR_DISPLAY 0x01
#define LCD_CMD_RETURN_HOME 0x02
#define LCD_CMD_ENTRY_MODE_SET 0x06
#define LCD_CMD_DISPLAY_ON 0x0C
#define LCD_CMD_DISPLAY_OFF 0x08
#define LCD_CMD_FUNCTION_SET 0x28
#define LCD_CMD_SET_CURSOR 0x80
#define LCD_CMD_INIT_8_BIT_MODE 0x30
#define LCD_CMD_INIT_4_BIT_MODE 0x20

// Public API
void LCD_Init(void);
void LCD_Clear(void);
void LCD_SetCursor(uint8_t row, uint8_t col);
void LCD_Print(char *str);
HAL_StatusTypeDef LCD_Send_Cmd(uint8_t cmd);
HAL_StatusTypeDef LCD_Send_Data(uint8_t data);


#endif
