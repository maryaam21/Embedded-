//   ___     ___    ____    ____    ____    ____    	   |	     	             |_     ___    ____    ____    ____    ____
// _/   \___/   \__/    \__/    \__/    \__/    \__/AUTHOR | MARIAM RAMADAN EL-Badri | \___/   \__/    \__/    \__/    \__/    \__
//																	Layer: HAL

//General
#define F_CPU 16000000UL
#include <util/delay.h>

//LIB
#include "../../LIB\BIT_MATH.h"
#include "../../LIB\STD_TYPE.h"

//MCAL
#include "../../MCAL/DIO_DRIVER/DIO_interface.h"
#include "../../MCAL/TIMERS_DRIVER/TIMERS_interface.h"
#include "../../MCAL/TIMERS_DRIVER/TIMERS_config.h"

//HAL
#include "LCD_interface.h"
#include "LCD_config.h"
#include "LCD_private.h"

//APIs
void LCD_init(void)
{
	/*Initialize the LCD 7 pins as output pins */
DIO_Vid_Set_Pin_Dir(LCD_RS_PORT,LCD_RS_PIN,OUTPUT);
DIO_Vid_Set_Pin_Dir(LCD_RW_PORT,LCD_RW_PIN,OUTPUT);
DIO_Vid_Set_Pin_Dir(LCD_EN_PORT,LCD_EN_PIN,OUTPUT);
DIO_Vid_Set_Pin_Dir(LCD_D4_PORT,LCD_D4_PIN,OUTPUT);
DIO_Vid_Set_Pin_Dir(LCD_D5_PORT,LCD_D5_PIN,OUTPUT);
DIO_Vid_Set_Pin_Dir(LCD_D6_PORT,LCD_D6_PIN,OUTPUT);
DIO_Vid_Set_Pin_Dir(LCD_D7_PORT,LCD_D7_PIN,OUTPUT);

	/*To start the 4 bit mode wait for more than 30 ms */
_delay_ms(40);
	/*Function set:
	DL = 1:8 bit interface operation
	N  = 0:1 - line display | 0 one line display | 1 two line display
	F  = 0:5 x 7 dot character font
	*/
	/*From datasheet*/
	/*Set Rs pin =0 (Write command)
	Rs to select command (0) or data (1)*/
DIO_Vid_Set_Pin_Val(LCD_RS_PORT,LCD_RS_PIN,LOW);

	//Set Rw pin =0 (Write)
DIO_Vid_Set_Pin_Val(LCD_RW_PORT,LCD_RW_PIN,LOW);
private_writeHalfPort(0b0010);//without shifting
	// the 4 bits are given ready to use 

	//Enable pulse H --> L
DIO_Vid_Set_Pin_Val(LCD_EN_PORT,LCD_EN_PIN,HIGH);
_delay_ms(1);
DIO_Vid_Set_Pin_Val(LCD_EN_PORT, LCD_EN_PIN, LOW);


	/*Function set command 2*16 LCD, 4 bit mode */
LCD_sendCommand(0b00101000);
_delay_us(45);

	/* 3) Display ON/OFF control:
	D = 0 : Display OFF
	C = 0 : Cursor OFF
	B = 0 :Blink OFF
	*/
	/* Display on off control (Display on, Cursor off, Blink off)*/
LCD_sendCommand(0b00001100);
_delay_us(45);//to respond for the command

	/*Clear display*/
LCD_sendCommand(0b00000001);
_delay_ms(2);

	/* 4) Entry mode set:
		l/D = 1 : +1 (Increment mode)
		S   = 0 : No display shift operation*/
	/*Auto Increment*/
LCD_sendCommand(0b00000110);

 }
 
 
 
void LCD_sendCommand(u8 command)
{
	
	/*Set Rs pin =0 (Write command)
	Rs to select command (0) or data (1)*/
	DIO_Vid_Set_Pin_Val(LCD_RS_PORT,LCD_RS_PIN,LOW);

	//Set Rw pin =0 (Write)
	DIO_Vid_Set_Pin_Val(LCD_RW_PORT,LCD_RW_PIN,LOW);

	//Send command - 8 bits command/ 4 bits mode so: 8/2
	// Most significant bits first (first 4 MSB)
	// then enable
	// the least significant bits
	// then enable
	
	private_writeHalfPort(command>>4);
	//Enable pulse H --> L
	DIO_Vid_Set_Pin_Val(LCD_EN_PORT,LCD_EN_PIN,HIGH);
	_delay_ms(1);
	DIO_Vid_Set_Pin_Val(LCD_EN_PORT, LCD_EN_PIN, LOW);
	//Write the least 4 bits of command on data pins
	private_writeHalfPort(command);
	//Enable
	//to enable the LCD send high for a while then send low
	//so: high --> delay --> low
	DIO_Vid_Set_Pin_Val(LCD_EN_PORT,LCD_EN_PIN,HIGH);
	_delay_ms(1);
	DIO_Vid_Set_Pin_Val(LCD_EN_PORT, LCD_EN_PIN, LOW);	

}
void LCD_sendChar(u8 charac)
{
	
	//Set Rs pin =1 (Write/send data)| Set RS -> HIGH to send data
	DIO_Vid_Set_Pin_Val(LCD_RS_PORT,LCD_RS_PIN,HIGH);

	//Set Rw pin =0 (Write)
	DIO_Vid_Set_Pin_Val(LCD_RW_PORT,LCD_RW_PIN,LOW);

	//Send command - 8 bits command/ 4 bits mode so: 8/2
	// Most significant bits first (first 4 MSB)
	// then enable
	// the least significant bits
	// then enable
	//Write the most 4 bits of data on data pins
	private_writeHalfPort(charac>>4);
	//Enable pulse H --> L
	DIO_Vid_Set_Pin_Val(LCD_EN_PORT,LCD_EN_PIN,HIGH);
	_delay_ms(1);
	DIO_Vid_Set_Pin_Val(LCD_EN_PORT, LCD_EN_PIN, LOW);
	//Write the least 4 bits of data on data pins
	private_writeHalfPort(charac);
	//Enable
	//to enable the LCD send high for a while then send low
	//so: high --> delay --> low //Enable pulse
	 SEND_ENABLE_PULSE();
	
}
static void private_writeHalfPort(u8 value)
{
	//D4
	if(GET_BIT(value,0)==1)
	{
		DIO_Vid_Set_Pin_Val(LCD_D4_PORT,LCD_D4_PIN,HIGH);
	}
	else
	{
		DIO_Vid_Set_Pin_Val(LCD_D4_PORT,LCD_D4_PIN,LOW);
	}
	
	//D5
	
	if(GET_BIT(value,1)==1)
	{
		DIO_Vid_Set_Pin_Val(LCD_D5_PORT,LCD_D5_PIN,HIGH);
	}
	else
	{
		DIO_Vid_Set_Pin_Val(LCD_D5_PORT,LCD_D5_PIN,LOW);
	}
	
	//D6
	if(GET_BIT(value,2)==1)
	{
		DIO_Vid_Set_Pin_Val(LCD_D6_PORT,LCD_D6_PIN,HIGH);
	}
	else
	{
		DIO_Vid_Set_Pin_Val(LCD_D6_PORT,LCD_D6_PIN,LOW);
	}
	
	
	//D7
	
	if(GET_BIT(value,3)==1)
	{
		DIO_Vid_Set_Pin_Val(LCD_D7_PORT,LCD_D7_PIN,HIGH);
	}
	else
	{
		DIO_Vid_Set_Pin_Val(LCD_D7_PORT,LCD_D7_PIN,LOW);
	}
}
void LCD_writeString(u8* String)
{
	u8 counter=0;
	while(String[counter]!='\0')
	{
		LCD_sendChar(String[counter]);
		++ counter;
	}
}

void LCD_clear (void)
{
	/*Clear display*/
	LCD_sendCommand(0b00000001);
	_delay_ms(2);//must -delay- to be executed
}
//To generate pulse / in case
static void SEND_ENABLE_PULSE(void)
{
DIO_Vid_Set_Pin_Val(LCD_EN_PORT,LCD_EN_PIN,HIGH);
_delay_ms(1);
DIO_Vid_Set_Pin_Val(LCD_EN_PORT, LCD_EN_PIN, LOW);
}

void LCD_customChar(u8 location, u8 *data)
{
	if (location < 8)
	{
		LCD_sendCommand(0x40 + (location * 8)); // Set the CGRAM address
		for (u8 i = 0; i < 8; i++)
		{
			LCD_sendChar(data[i]); // Send character pattern data
		}
	}
}
// Function to set the cursor position
void LCD_setCursor(u8 row, u8 col) {
	u8 address = col;
	
	if (row == 1) {
		address += 0x40;
	}
	
	// Set DDRAM address
	LCD_sendCommand(LCD_SET_DDRAM_ADDR | address);
}

// Function to define custom characters
void LCD_defineCustomCharacter(u8 location, const u8 *pattern) {
	// Set CGRAM address for custom character
	LCD_sendCommand(LCD_SET_CGRAM_ADDR | (location << 3));
	
	// Send character pattern to CGRAM
	for (u8 i = 0; i < 8; i++) {
		LCD_sendChar(pattern[i]);
		_delay_us(40);
	}
}

//---------------------------------------------------CUSTOM---------------------------------------------------

void LCD_writeNumber(u32 number)
{
	u32 local_reversed=1;
	
	if(number==0)
	{
		LCD_sendChar('0');
	}
	else
	{
		//Reverse Number
		while (number != 0)
		{
			local_reversed=local_reversed*10 + (number%10);
			number/=10;
		}
		
		do
		{
			LCD_sendChar((local_reversed % 10) + '0');
			local_reversed/=10;
		}
		while(local_reversed != 1);
	}
}
void LCD_startProgram(void)
{
	//BEFORE PUSHING ANY BUTTON
	// Initialize LCD
	LCD_init();

	// Display loading messages
	LCD_setCursor(0,11);
	LCD_writeString("LOADING ... ");
	_delay_ms(500);
	LCD_clear();
	LCD_setCursor(0,11);
	LCD_writeString("LOADING .... ");
	_delay_ms(400);
	LCD_clear();
	LCD_setCursor(0,11);
	LCD_writeString("LOADING ..... ");
	_delay_ms(300);
	LCD_clear();
	LCD_setCursor(0,17);
	LCD_writeString("HELLO ");
	_delay_ms(500);
	LCD_clear();
	LCD_setCursor(0,5);
	LCD_writeString("Embedded SYSTEMS PROJECT BY : ");
	_delay_ms(1000);
	LCD_clear();
	LCD_setCursor(0,9);
	LCD_writeString("MARIAM RAMADAN EL BADRI  ");
	_delay_ms(1000);
	LCD_clear();
	LCD_setCursor(0,8);
	LCD_writeString("PWM DRAWER IS STARTING");
	_delay_ms(1000);
	LCD_clear();
	LCD_setCursor(0,15);
	LCD_writeString("WELCOME =) ");
	_delay_ms(1000);
	LCD_clear();
	//LCD_setCursor(0,8);
	//LCD_writeString("PRESS BUTTON 0 TO START ...");
	//_delay_ms(1000);
	//LCD_clear();
}

void LCD_checkState( u8 button1,u8 button2,u8 button3)
{
	 // Read button states
	 u8 button1State = button1;
	 u8 button2State = button2;
	 u8 button3State = button3;

	 // Initialize PWM variables
/*	 u8 PWM_increase =0;
	 u8 Initial_PWM  =75;*/
//---------------------------------------------------------STATES---------------------------------------------------------------------------	 
	 // Check which button is pressed
	 // If Button 0 is pressed -- PWM will start for the first time
	 if (button1State == INPUT) 
	 {
		//Wait for button release
		while (button1State == INPUT)
		{
		//	 button1State = button1;
			 _delay_ms(1000);
			 
		}
		
	  }
                         
	/*  // Increase PWM signal if button 2 is pressed
	  if (button2State == INPUT)
	  {
		  // Wait for button release
		  while (button2State == INPUT) {
			 // button2State = button2;
			  _delay_ms(1000);
		  }
		  ++PWM_increase;
		  // Increase PWM signal by 25%
		  Initial_PWM += 25;
		  if (Initial_PWM > 100)
		  {
			  Initial_PWM = 100;  
		  }
		  TIMER0_setDutyCycle(Initial_PWM);
		  LCD_clear();
		  LCD_writeString("PWM: ");
		  LCD_sendChar(Initial_PWM);
		  LCD_writeString("%");
		  _delay_ms(500);
	  }
	  
	  // Decrease PWM signal if button 2 is pressed
	  if (button3State == INPUT)
	  {
		  // Wait for button release
		  while (button3State == INPUT) {
		//	  button3State = button3;
			  _delay_ms(1000);
		  }
		  --PWM_increase;
		  // Decrease PWM signal by 25%
		  Initial_PWM -= 25;
		  if (Initial_PWM < 0) {
			  Initial_PWM = 0;
		  }
		  TIMER0_setDutyCycle(Initial_PWM);
		  LCD_clear();
		  LCD_writeString("PWM: ");
		  LCD_sendChar(Initial_PWM);
		  LCD_writeString("%");
		  _delay_ms(500);
	   }*/	
}
void LCD_DisplayICRValue(void)
{
	// Get the ICR value
	//u16 ICRValue = TIMER_u16GetICR();
	
	// Print the ICR value on the LCD
	LCD_writeString("ICR Value:");
	
	// Convert the ICR value to a string
//	LCD_sendChar(ICRValue);

}
void LCD_DrawNormalPWM(void)
{
	// Set cursor to the desired position
	LCD_setCursor(1, 0);
	LCD_writeString("_");
	_delay_ms(100);
	
	LCD_setCursor(1, 1);
	LCD_writeString("_");
	_delay_ms(100);
	
	LCD_setCursor(1, 2);
	LCD_writeString("_");
	_delay_ms(100);
	
	LCD_setCursor(1, 3);
	LCD_writeString("|");
	_delay_ms(100);
	
	LCD_setCursor(0, 4);
	LCD_writeString("_");
	_delay_ms(100);
	
	LCD_setCursor(0, 5);
	LCD_writeString("_");
	_delay_ms(100);
	
	LCD_setCursor(0, 6);
	LCD_writeString("_");
	_delay_ms(100);
	
	LCD_setCursor(1, 7);
	LCD_writeString("|");
	_delay_ms(100);
	
	LCD_setCursor(1, 8);
	LCD_writeString("_");
	_delay_ms(100);
	
	LCD_setCursor(1, 9);
	LCD_writeString("_");
	_delay_ms(100);
	
	LCD_setCursor(1, 10);
	LCD_writeString("_");
	_delay_ms(100);
	
	LCD_setCursor(1, 11);
	LCD_writeString("|");
	_delay_ms(100);
	
	LCD_setCursor(0, 12);
	LCD_writeString("_");
	_delay_ms(100);
	
	LCD_setCursor(0, 13);
	LCD_writeString("_");
	_delay_ms(100);
	
	LCD_setCursor(0, 14);
	LCD_writeString("_");
	_delay_ms(100);
	
	LCD_setCursor(1, 15);
	LCD_writeString("|");
	_delay_ms(100);
	
	LCD_setCursor(1, 16);
	LCD_writeString("_");
	_delay_ms(100);
	
	LCD_setCursor(1, 17);
	LCD_writeString("_");
	_delay_ms(100);
	
	LCD_setCursor(1, 18);
	LCD_writeString("_");
	_delay_ms(100);
	
	
}
void LCD_DrawIncreasedPWM(void)
{
	// Set cursor to the desired position
	LCD_setCursor(1, 0);
	LCD_writeString("_");
	_delay_ms(100);
	
	LCD_setCursor(1, 1);
	LCD_writeString("_");
	_delay_ms(100);
	
	LCD_setCursor(1, 2);
	LCD_writeString("_");
	_delay_ms(100);
	
	LCD_setCursor(1, 3);
	LCD_writeString("|");
	_delay_ms(100);
	
	LCD_setCursor(0, 4);
	LCD_writeString("_");
	_delay_ms(100);
	
	LCD_setCursor(0, 5);
	LCD_writeString("_");
	_delay_ms(100);
	
	LCD_setCursor(0, 6);
	LCD_writeString("_");
	_delay_ms(100);
	
	LCD_setCursor(1, 7);
	LCD_writeString("|");
	_delay_ms(100);
	
	LCD_setCursor(1, 8);
	LCD_writeString("_");
	_delay_ms(100);
	
	LCD_setCursor(1, 9);
	LCD_writeString("_");
	_delay_ms(100);
	
	LCD_setCursor(1, 10);
	LCD_writeString("_");
	_delay_ms(100);
	
	LCD_setCursor(1, 11);
	LCD_writeString("|");
	_delay_ms(100);
	
	LCD_setCursor(0, 12);
	LCD_writeString("_");
	_delay_ms(100);
	
	LCD_setCursor(0, 13);
	LCD_writeString("_");
	_delay_ms(100);
	
	LCD_setCursor(0, 14);
	LCD_writeString("_");
	_delay_ms(100);
	
	LCD_setCursor(1, 15);
	LCD_writeString("|");
	_delay_ms(100);
	
	LCD_setCursor(1, 16);
	LCD_writeString("_");
	_delay_ms(100);
	
	LCD_setCursor(1, 17);
	LCD_writeString("_");
	_delay_ms(100);
	
	LCD_setCursor(1, 18);
	LCD_writeString("_");
	_delay_ms(100);
}
void LCD_DrawDecreasedPWM(void)
{
	// Set cursor to the desired position
	LCD_setCursor(1, 0);
	LCD_writeString("_");
	_delay_ms(100);
	
	LCD_setCursor(1, 1);
	LCD_writeString("_");
	_delay_ms(100);
	
	LCD_setCursor(1, 2);
	LCD_writeString("_");
	_delay_ms(100);
	
	LCD_setCursor(1, 3);
	LCD_writeString("|");
	_delay_ms(100);
	
	LCD_setCursor(0, 4);
	LCD_writeString("_");
	_delay_ms(100);
	
	LCD_setCursor(0, 5);
	LCD_writeString("_");
	_delay_ms(100);
	
	LCD_setCursor(0, 6);
	LCD_writeString("_");
	_delay_ms(100);
	
	LCD_setCursor(1, 7);
	LCD_writeString("|");
	_delay_ms(100);
	
	LCD_setCursor(1, 8);
	LCD_writeString("_");
	_delay_ms(100);
	
	LCD_setCursor(1, 9);
	LCD_writeString("_");
	_delay_ms(100);
	
	LCD_setCursor(1, 10);
	LCD_writeString("_");
	_delay_ms(100);
	
	LCD_setCursor(1, 11);
	LCD_writeString("|");
	_delay_ms(100);
	
	LCD_setCursor(0, 12);
	LCD_writeString("_");
	_delay_ms(100);
	
	LCD_setCursor(0, 13);
	LCD_writeString("_");
	_delay_ms(100);
	
	LCD_setCursor(0, 14);
	LCD_writeString("_");
	_delay_ms(100);
	
	LCD_setCursor(1, 15);
	LCD_writeString("|");
	_delay_ms(100);
	
	LCD_setCursor(1, 16);
	LCD_writeString("_");
	_delay_ms(100);
	
	LCD_setCursor(1, 17);
	LCD_writeString("_");
	_delay_ms(100);
	
	LCD_setCursor(1, 18);
	LCD_writeString("_");
	_delay_ms(100);
}
void DisplayFrequency(void)
{
	
}