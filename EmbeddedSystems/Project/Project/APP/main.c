//   ___     ___    ____    ____    ____    ____    	   |	     	             |_     ___    ____    ____    ____    ____
// _/   \___/   \__/    \__/    \__/    \__/    \__/AUTHOR | MARIAM RAMADAN EL-Badri | \___/   \__/    \__/    \__/    \__/    \__
//															PULSE WIDTH MODULATION
//Delay
#define F_CPU 16000000UL
#include <util/delay.h>

//Utilities libraries
#include "..\LIB\BIT_MATH.h"
#include "..\LIB\STD_TYPE.h"

//MCAL
#include "..\MCAL\DIO_DRIVER\DIO_interface.h"
#include "..\MCAL\TIMERS_DRIVER\TIMERS_interface.h"
#include "..\MCAL\TIMERS_DRIVER\TIMERS_config.h"
//HAL
#include "..\HAL\LCD_DRIVER\LCD_interface.h"
#include "..\HAL\LCD_DRIVER\LCD_config.h"
#include "..\HAL\KEYPAD_DRIVER\Keypad_config.h"
#include "..\HAL\KEYPAD_DRIVER\Keypad_interface.h"
#include "..\MCAL\EXTI_DRIVER\EXTI_interface.h"
//Global
volatile static u16 SWICU_u16PeriodTicks=0;
volatile static u16 SWICU_u16OnTicks=0;

void SW_ICU(void)
{

	static u16 Counter=0;// Tracking number of times the SW_ICU function
	Counter++;
	if(Counter == 1)
	{
		TIMER1_setTimerValue(0);
	}
	if(Counter == 2)
	{
		SWICU_u16PeriodTicks=TIMER1_getTimerValue();
		EXTI_voidPeripheralINTEnable(EXTI_INT0,EXTI_SENSE_FALLING_EDGE);
		
	}
	if(Counter == 3)
	{
		SWICU_u16OnTicks=TIMER1_getTimerValue()-SWICU_u16PeriodTicks;//3-2
		EXTI_voidPeripheralINTDisbale(EXTI_INT0);
	}

}

void startingTheProgram(void)
{
	LCD_startProgram();
	// Initialize PWM variables
	//u8 PWM_increase =0;
	//u8 Initial_PWM  =75;
	// Initialize PWM Signal
	LCD_writeString("Initializing PWM Signal");
	_delay_ms(1000);
	LCD_clear();
	
	//InitializeOC0PIN();// OC0 --> OUTPUT
	
	//InitializeICUPIN();// ICU PIN --> INPUT
	
	// Initialize TIMER 0
	
	// Start TIMER 0
	//TIMER0_start();
	//LCD_writeString("TIMER 0 is starting ..");
	//_delay_ms(1000);
//	LCD_clear();
	
	// Initial PWM signal
	//TIMER0_setDutyCycle(Initial_PWM);
	//LCD_writeString("PWM: ");
	//LCD_sendChar(Initial_PWM);
	//LCD_writeString("%");
	//_delay_ms(500);
	//LCD_clear();
	//TIMER1_connectTimer0(Initial_PWM);
	//LCD_DrawNormalPWM();
	LCD_DrawNormalPWM();
	_delay_ms(500);
	LCD_clear();
	/* Pin OC0 output for HW PWM*/
	 InitializeOC0PIN();
	//DIO_Vid_Set_Pin_Dir(PORTB, PIN3, OUTPUT); // OC0 --> OUTPUT
	 
	 /* INT0 PIN INPUT*/
	 DIO_Vid_Set_Pin_Dir(PORTD,PIN2,INPUT);
	 EXTI_voidPeripheralINTEnable(EXTI_INT0,EXTI_SENSE_RISING_EGDE);
	 EXTI_callBackFunc_INT0(&SW_ICU);
	 
	 /* LCD initialization*/
	 //LCD_init();
	 
	 /*TIMERS Initialization*/
	 
	 TIMER0_initiate();
	 LCD_writeString("Initializing TIMER 0");
	 _delay_ms(500);
	 LCD_clear();
	 
	 
	 TIMER0_start();
	 LCD_writeString("Starting TIMER 0");
	 _delay_ms(500);
	 LCD_clear();
	 
	 TIMER1_initiate();
	 LCD_writeString("Initializing TIMER 1");
	 _delay_ms(500);
	 LCD_clear();
	 
	 Timer1_start();
	 LCD_writeString("Starting TIMER 1");
	 _delay_ms(500);
	 LCD_clear();
	 
	 u8 value=64;
	 TIMER0_setCompareMatchValue(value);


	 /* GIE Enable */
	 GIE_voidEnable();
	 
	 KEYPAD_Initiate();
	 
	  LCD_writeString("Insert compare match number using Keypad ");
	  _delay_ms(500);
	  LCD_clear();
	  
}
int main(void)
{
	startingTheProgram();
	
	 u8 input;
	/* 
	 u8 button1State;
	 u8 button2State;
	 u8 button3State;
	 
	 DIO_Vid_Set_Pin_Dir(PORTB,PIN0,INPUT); // Button 0
	 DIO_Vid_Set_Pin_Dir(PORTD,PIN7,INPUT); // Button 1 -- Entry
	 DIO_Vid_Set_Pin_Dir(PORTD,PIN2,INPUT); // Button 2
	 
	 button1State = DIO_u8_Get_Pin_Val(PORTB,PIN0); //Button 0
	 button2State = DIO_u8_Get_Pin_Val(PORTD,PIN7); //Button 1
	 button3State = DIO_u8_Get_Pin_Val(PORTD,PIN2); //Button 2
	 */
	 //   ___     ___    ____    ____
	 // _/   \___/   \__/    \__/    \
	 // __    __    __
	 //|  |__|  |__|  |
	 // Display PWM signal on LCD
	 // LCD_DrawNormalPWM();
  
    while (1) 
    {
		input=KEYPAD_GetKey() ;
		if(input != 0xff)
		{
			LCD_writeString("Insert compare match value using Keypad... ");
			_delay_ms(500);
			LCD_clear();
			LCD_writeString("Your inserted compare match value is: ");
			LCD_sendChar(input) ;
			//Change the PWM wave according the input number from Keypad
			TIMER0_setCompareMatchValue(input);

	    }

		SW_ICU();		
		while((SWICU_u16PeriodTicks ==0 ) && (SWICU_u16OnTicks==0));
		LCD_DrawNormalPWM();
		LCD_setCursor(0,22);
		LCD_writeString("Period Ticks= ");
		LCD_writeNumber(SWICU_u16PeriodTicks*0.5);
		LCD_setCursor(1,24);
		LCD_writeString("On Ticks= ");
		LCD_writeNumber(SWICU_u16OnTicks*0.5);
}
}
