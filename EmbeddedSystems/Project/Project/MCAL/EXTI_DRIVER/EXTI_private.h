//   ___     ___    ____    ____    ____    ____    	   |	     	             |_     ___    ____    ____    ____    ____
// _/   \___/   \__/    \__/    \__/    \__/    \__/AUTHOR | MARIAM RAMADAN EL-Badri | \___/   \__/    \__/    \__/    \__/    \__
//																	Layer: MCAL
#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_

/* External Interrupt Registers*/
#define EXTI_MCUCR    (*((volatile u8*)0X55))
#define EXTI_GICR     (*((volatile u8*)0X5B))
#define EXTI_MCUCSR   (*((volatile u8*)0X54))

#define ISC00   0
#define ISC01   1
#define ISC10   2
#define ISC11   3
#define ISC2    6
/*																								*/
#define NULL                 0

#endif