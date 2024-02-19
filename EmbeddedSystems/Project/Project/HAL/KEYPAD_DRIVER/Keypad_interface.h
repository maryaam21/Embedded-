//   ___     ___    ____    ____    ____    ____    	   |	     	             |_     ___    ____    ____    ____    ____
// _/   \___/   \__/    \__/    \__/    \__/    \__/AUTHOR | MARIAM RAMADAN EL-Badri | \___/   \__/    \__/    \__/    \__/    \__
//																	Layer: HAL
#ifndef KEYPAD_INTERFACE_H_
#define KEYPAD_INTERFACE_H_

//Functions
#define KEYPAD_notPressed  0xff //== 255 out of the range of the KPD to avoid garbage values
void KEYPAD_Initiate(void); 
u8 KEYPAD_GetKey(void); 


#endif 