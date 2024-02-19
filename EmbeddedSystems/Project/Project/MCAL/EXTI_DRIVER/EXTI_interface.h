//   ___     ___    ____    ____    ____    ____    	   |	     	             |_     ___    ____    ____    ____    ____
// _/   \___/   \__/    \__/    \__/    \__/    \__/AUTHOR | MARIAM RAMADAN EL-Badri | \___/   \__/    \__/    \__/    \__/    \__
//																	Layer: MCAL
#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

/*External Interrupt*/
/* 
	Hint : I assume those values 6,7,5 because the position of each INT bits in the Reg (GICR,GIFR ....)	
	I will use That for SET and CLR BITS

 */
#define EXTI_INT0				  6
#define EXTI_INT1				  7
#define EXTI_INT2				  5

/*SENSE CONTROL*/
#define EXTI_SENSE_LOW_LEVEL      0
#define EXTI_SENSE_FALLING_EDGE   1
#define EXTI_SENSE_RISING_EGDE    2
#define EXTI_SENSE_ON_CHANGE      3

/*Functions*/
void EXTI_voidPeripheralINTEnable(u8 copy_u8IntID,u8 copy_u8SenseMode);
void EXTI_voidPeripheralINTDisbale(u8 copy_u8IntID);
void EXTI_callBackFunc_INT1(void(*ptr_func)(void));
void EXTI_callBackFunc_INT0(void(*ptr_func)(void));
void EXTI_callBackFunc_INT2(void(*ptr_func)(void));




#endif /* EXTI_INTERFACE_H_ */