//   ___     ___    ____    ____    ____    ____    	   |	     	             |_     ___    ____    ____    ____    ____
// _/   \___/   \__/    \__/    \__/    \__/    \__/AUTHOR | MARIAM RAMADAN EL-Badri | \___/   \__/    \__/    \__/    \__/    \__
//																	Layer: MCAL

//LIB
#include "..\..\LIB\BIT_MATH.h"
#include "..\..\LIB\STD_TYPE.h"
#include "..\..\LIB\Error_State.h"

//MCAL
#include "..\DIO_DRIVER\DIO_interface.h"
#include "TIMERS_config.h"
#include "TIMERS_private.h"
#include "TIMERS_interface.h"


static void (*ptrToFunc_ovf)(void)=NULL;
static void (*ptrToFunc_ctc)(void)=NULL;


/*  TIMER 0 Functions*/

void InitializeOC0PIN(void)
{
	DIO_Vid_Set_Pin_Dir(PORTB, PIN3, OUTPUT); // OC0 --> OUTPUT
}

void TIMER0_initiate(void)
{
	/*Set fast PWM mode | Table 38 */
	/*Timer/Counter Control Register – TCCR0*/
	SET_BIT(TCCR0,WGM00); //BIT No. 6
	SET_BIT(TCCR0,WGM01); //BIT No. 3
	
	/*NON INVERTING*/
	CLR_BIT(TCCR0,COM00);
	SET_BIT(TCCR0,COM01);
	

}

void TIMER0_start(void)
{
		
		/*Prescaler*/
		//The three Clock Select bits select the clock source to be used by the Timer/Counter. | Table 42  /8= 010
		// (CS02, CS01, CS00) 010
		//TCCR0 &=0b11111000;
		//TCCR0 |=2;
		CLR_BIT(TCCR0,CS02);//BIT No. 2
		SET_BIT(TCCR0,CS01);//BIT No. 1
		SET_BIT(TCCR0,CS00);//BIT No. 0
		
		
		//OCR0=value;
				
}

void TIMER0_setCompareMatchValue(u8 compareValue)
{   /*Compare match value to 32us on time if u8 value = 64*/
	//OCR0=value
	//Output Compare Register OCR
	//sets the OCR0
	OCR0 = compareValue;
}

void TIMER0_setDutyCycle(u8 dutyCycle)
{
	//Under condition non-inverting fast PWM
	if (dutyCycle<=100)
	{
		OCR0 =  ((dutyCycle*256)/100)-1; // the desired duty cycle as a percentage (0 to 100)
	}
}
/* Calculations */

u8 TIMER0_OCR0Ton(u8 dutyCycle)
{
	
	//Ton is determined by the value written to the output compare register (OCR0)
	u8 OCR0Value = ((dutyCycle * 256) / 100) - 1; //OCR0 value
	return OCR0Value;
}
u8 TIMER0_OCR0Toff(u8 dutyCycle)
{
	//Toff = Total PWM period - Ton
	//OCR0 value is 8-bit, the maximum value is 255. So, for a duty cycle of 100%, OCR0 would be 255.
	//255-ton
	u8 Toff = 255 - ((dutyCycle * 256) / 100);
	return Toff;
	
}

u8 TIMER0_Frequency(u8 dutyCycle)
{
	//Frequency = 1 / (Ton + Toff)
	u8 freq = 1/(TIMER0_OCR0Ton(dutyCycle)+TIMER0_OCR0Toff(dutyCycle));
	return freq;
}

/* End of calculations*/
void TIMER0_stop(void)
{
	//Set the prescaler value = 0
	CLR_BIT(TCCR0,CS00);
	CLR_BIT(TCCR0,CS01);
	CLR_BIT(TCCR0,CS02);
}


u8 TIMER0_setCallBack(u8 copy_u8IntID,void (*ptrToFunc)(void))
{

	u8 Error_state=OK;

	if(ptrToFunc != NULL)
	{
		if(copy_u8IntID == TIMER_OVF_INT)
		{
			ptrToFunc_ovf=ptrToFunc;
		}
		else if(copy_u8IntID==TIMER_CTC_INT)
		{
			ptrToFunc_ctc=ptrToFunc;
		}
		else
		{
			Error_state=NOK;
		}
		
		
	}
	else
	{
		Error_state=NULL_POINTER;
	}


	return Error_state;
}

/********************END OF TIMER0 ********************/

/********************TIMER 1 starts********************/
/*  TIMER 1 Functions*/

void TIMER1_initiate(void)
{
	/*Set normal mode*/
	CLR_BIT(TCCR1A,COM1A0);
	CLR_BIT(TCCR1A,COM1A1);
	
	/*Set waveform generation mode normal */
	CLR_BIT(TCCR1A,WGM10);
	CLR_BIT(TCCR1A,WGM11);
	CLR_BIT(TCCR1B,WGM12);
	CLR_BIT(TCCR1B,WGM13);

	
}
void Timer1_start(void)
{
	/*The Timer/Counter is inactive when no clock source	is selected.
	The output from the clock select logic is referred to as the timer clock (clkT1).
	/*Prescaler :Division by 8*/
	CLR_BIT(TCCR1B,CS10);
	SET_BIT(TCCR1B,CS11);
	CLR_BIT(TCCR1B,CS12);
}

void TIMER1_setTimerValue(u16 TimerValue)
{
	TCNT1_u16=TimerValue;
}

u16 TIMER1_getTimerValue(void)
{
	return TCNT1_u16;
}

void TIMER1_setCompareValueChannelA(u16 CompareValue)
{
	/*Set compare value*/
	//Initiate Timer with compare value 
	OCR1A_u16=CompareValue;
}

u16 TIMER_OCR1A_u16(void)
{
	return OCR1A_u16;
}


void Timer1_stop (void)
{
	//Select Prescalar value = 0 by clearing
	CLR_BIT(TCCR1B,CS10);
	CLR_BIT(TCCR1B,CS11);
	CLR_BIT(TCCR1B,CS12);
}


/*Interrupt */

/*ISR CTC MODE*/
void __vector_10(void) __attribute__((signal));
void __vector_10(void)
{
ptrToFunc_ctc();
}


/*ISR OVF MODE*/
void __vector_11(void) __attribute__((signal));
void __vector_11(void)
{
	ptrToFunc_ovf();
}