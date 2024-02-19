//   ___     ___    ____    ____    ____    ____    	   |	     	             |_     ___    ____    ____    ____    ____
// _/   \___/   \__/    \__/    \__/    \__/    \__/AUTHOR | MARIAM RAMADAN EL-Badri | \___/   \__/    \__/    \__/    \__/    \__
//																	Layer: HAL
#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_
//So editing connection will be easier and smart

/*** Control pins ***/
/* 1-
Rs --> Register select*/
#define LCD_RS_PORT PORTB
#define LCD_RS_PIN  PIN1

/* 2-
Rw --> Read/Write
Read -->1 | Write --> 0
*/
#define LCD_RW_PORT PORTB
#define LCD_RW_PIN  PIN2

/* 3-
Enable
*/
#define LCD_EN_PORT PORTB
#define LCD_EN_PIN  PIN4

/* 4-
Data registers
*/
#define LCD_D4_PORT	PORTA
#define LCD_D4_PIN	PIN4

#define LCD_D5_PORT	PORTA
#define LCD_D5_PIN	PIN5

#define LCD_D6_PORT	PORTA
#define LCD_D6_PIN	PIN6

#define LCD_D7_PORT	PORTA
#define LCD_D7_PIN	PIN7

#define LCD_SET_CGRAM_ADDR  0x40
#define LCD_SET_DDRAM_ADDR  0x80

#endif