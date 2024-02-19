//   ___     ___    ____    ____    ____    ____    	   |	     	             |_     ___    ____    ____    ____    ____
// _/   \___/   \__/    \__/    \__/    \__/    \__/AUTHOR | MARIAM RAMADAN EL-Badri | \___/   \__/    \__/    \__/    \__/    \__
//																	Layer: MCAL
#ifndef _TIMERS_INTERFACE_H_
#define _TIMERS_INTERFACE_H_

#define TIMER_OVF_INT 0
#define TIMER_CTC_INT 1

/*  TIMER 0 Functions*/
/*
 * Description : This Function specify the OC0 PINS
 * Parameters  : Nothing
 * return      : Nothing
*/
/*****************************************************************************
* Function Name: InitializeOC0PIN
* Purpose      : Set OC0 pin direction as OUTPUT(PORTB, PIN3, OUTPUT)
* Parameters   : void
* Return value : void
*****************************************************************************/
void InitializeOC0PIN(void);
/*
 * Description : Selecting TIMER0 modes 
 * Parameters  : Nothing
 * return      : Nothing
*/
/*****************************************************************************
* Function Name: TIMER0_initiate
* Purpose      : Select Timer mode: fast PWM and make it non-inverting
* Parameters   : void
* Return value : void
*****************************************************************************/
void TIMER0_initiate(void);
void TIMER0_start(void);
void TIMER0_setCompareMatchValue(u8 compareValue);
void TIMER0_setDutyCycle(u8 dutyCycle);
u8 TIMER0_OCR0Ton(u8 dutyCycle);
u8 TIMER0_OCR0Toff(u8 dutyCycle);
u8 TIMER0_Frequency(u8 dutyCycle);
void TIMER0_stop(void);
u8   TIMER0_setCallBack(u8 copy_u8IntID,void (*ptrToFunc)(void));
///

void TIMER0_start(void);
void TIMER0_stop(void);

void TIMER0_setCompareMatchValue(u8 compareValue);//sets the OCR0
void TIMER0_setDutyCycle(u8 dutyCycle);

/////
/*  TIMER 1 Functions*/
void TIMER1_initiate(void);
void Timer1_start(void);
void Timer1_stop (void);
void TIMER1_setCompareValueChannelA(u16 CompareValue);
void TIMER1_setTimerValue(u16 TimerValue);
u16  TIMER1_getTimerValue(void);
u16 TIMER_OCR1A_u16(void);


#endif