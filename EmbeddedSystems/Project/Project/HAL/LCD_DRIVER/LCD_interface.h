//   ___     ___    ____    ____    ____    ____    	   |	     	             |_     ___    ____    ____    ____    ____
// _/   \___/   \__/    \__/    \__/    \__/    \__/AUTHOR | MARIAM RAMADAN EL-Badri | \___/   \__/    \__/    \__/    \__/    \__
//																	Layer: HAL

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_
//General - Main
void LCD_init(void);
void LCD_sendCommand(u8 command);
void LCD_sendChar(u8 charac);
void LCD_writeString(u8* String);
void LCD_clear (void);
static void SEND_ENABLE_PULSE(void);
//Customs
void LCD_writeNumber(u32 number);
void LCD_customChar(u8 location, u8 *data);
void LCD_DisplayICRValue(void);
void LCD_defineCustomCharacter(u8 location, const u8 *pattern);
void LCD_setCursor(u8 row, u8 col);
//Starting the PWM program intro
void LCD_startProgram(void);
//For buttons control
void LCD_checkState( u8 button1,u8 button2,u8 button3);
//Draw
void LCD_DrawNormalPWM(void);
void LCD_DrawIncreasedPWM(void);
void LCD_DrawDecreasedPWM(void);

#endif