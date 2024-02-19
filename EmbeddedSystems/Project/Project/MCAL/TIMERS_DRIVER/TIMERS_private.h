//   ___     ___    ____    ____    ____    ____    	   |	     	             |_     ___    ____    ____    ____    ____
// _/   \___/   \__/    \__/    \__/    \__/    \__/AUTHOR | MARIAM RAMADAN EL-Badri | \___/   \__/    \__/    \__/    \__/    \__
//																	Layer: MCAL
#ifndef _TIMRES_PRIVATE_H_
#define _TIMRES_PRIVATE_H_

/* MACROS FOR TIMERS CONFIGURATIONS */
/* Options for TIMER0 Mode: */
#define TIMER0_NORMAL_MODE			1
#define TIMER0_CTC_MODE				2
#define TIMER0_FASTPWM_MODE			3

/* MACROS FOR PWM CONFIGURATIONS */

#define TIMER0_PWM_INVERTING		1
#define TIMER0_PWM_NONINVERTING		2

/* TIMER0 Registers */


/* Timer/Counter Control Register – TCCR0 */
#define TCCR0			*((volatile u8*)0X53)
#define CS00	0//Clock Select
#define CS01	1//Clock Select
#define CS02	2//Clock Select
#define WGM01	3//Waveform Generation Mode
#define COM00	4//Compare Match Output Mode
#define COM01	5//Compare Match Output Mode
#define WGM00	6//Waveform Generation Mode
#define FOC0	7// Force Output Compare


/* Timer/Counter Register – TCNT0 */
#define TCNT0			*((volatile u8*)0X52)//address
/*#define TCNT00	0
#define TCNT01	1
#define TCNT02	2
#define TCNT03	3
#define TCNT04	4
#define TCNT05	5
#define TCNT06	6
#define TCNT07	7
*/

/* Output Compare Register – OCR0 */
#define OCR0			*((volatile u8*)0X5C)
/*
#define OCR00	0
#define OCR01	1
#define OCR02	2
#define OCR03	3
#define OCR04	4
#define OCR05	5
#define OCR06	6
#define OCR07	7
*/

/* Timer/Counter Interrupt Mask Register – TIMSK */
#define TIMSK	(*(volatile u8*)0x52)
#define TOIE0	0//Timer/Counter0 Overflow Interrupt Enable
#define OCIE0	1//Timer/Counter0 Output Compare Match Interrupt Enable
#define TOIE1	2
#define OCIE1B	3
#define OCIE1A	4
#define TICIE1	5
#define TOIE2	6
#define OCIE2	7

/* Timer/Counter Interrupt Flag Register – TIFR */
#define TIFR	(*(volatile u8*)0x58)
#define Tov0	0//Timer/Counter0 Overflow Flag
#define OCF0	1//Output Compare Flag 0
#define TOV1	2
#define OCF1B	3
#define OCF1A	4
#define ICF1	5
#define TOV2	6
#define OCF2	7


/* Special Function IO Register – SFIOR */
#define PSR10	0//Prescaler Reset Timer/Counter1 and Timer/Counter0
#define PSR2	1
#define PUD		2
#define ACME	3

#define ADTS0	5
#define ADTS1	6
#define ADTS2	7

/*TIMER0 END*/

/*Timer 1 registers*/

/*Timer/Counter1 Control Register A*/
#define TCCR1A	(*(volatile u8*)0x4F)
#define WGM10	0
#define WGM11	1
#define FOC1B	2
#define FOC1A	3
#define COM1B0	4
#define COM1B1	5
#define COM1A0	6
#define COM1A1	7


/* Timer/Counter1 Control Register B | TCCR1B*/

#define TCCR1B	(*(volatile u8*)0x4E)
#define CS10	0 // Clock Select
#define CS11	1 // Clock Select
#define CS12	2 // Clock Select
#define WGM12	3 // Waveform Generation Mode
#define	WGM13	4 // Waveform Generation Mode
#define ICES1	6 // Input Capture Edge Select
#define	ICNC1	7 // Input Capture Noise Canceler

/* Timer/Counter 1 */
#define TCNT1_u16	(*(volatile u16*)0x4C)

/* Output Compare Register 1 A */
#define OCR1A_u16	(*(volatile u16*)0x4A)

/* Output compare register 1 B */
#define OCR1B_u16	(*(volatile u16*)0x48)

/* Input Capture Register 1 */
#define ICR1_u16	(*(volatile u16*)0x46)

/* Timer / Counter Interrupt Mask Register */
/*#define TIMSK	(*(volatile u8*)0x59)
#define TOIE1	2
#define OCIE1B	3
#define OCIE1A	4
#define TICIE1	5*/

/* Timer / Counter Interrupt Flag Register */
#define TIFR	(*(volatile u8*)0x58)


/* Input Capture Unit */
#define TIMER_u8_ICP_FALLING_EDGE                   0
#define TIMER_u8_ICP_RAISING_EDGE					1

// PRESCALAR
#define TIMER_PRESCALER_1     1
#define TIMER_PRESCALER_8     2
#define TIMER_PRESCALER_64    3
#define TIMER_PRESCALER_256   4
#define TIMER_PRESCALER_1024  5


/*
#define TMR_WGM00   6
#define TMR_WGM01   3
#define TMR_OCIE0   1
#define TMR_TOIE0   0

#define TMR_COM00   4
#define TMR_COM01   5*/

#endif