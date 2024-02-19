//   ___     ___    ____    ____    ____    ____    	   |	     	             |_     ___    ____    ____    ____    ____
// _/   \___/   \__/    \__/    \__/    \__/    \__/AUTHOR | MARIAM RAMADAN EL-Badri | \___/   \__/    \__/    \__/    \__/    \__
//																	Layer: LIB
#ifndef BIT_MATH_h
#define BIT_MATH_h

//Set bit change bit //REG = REG
#define SET_BIT(REG,BIT)         (REG |=1<<BIT)
#define CLR_BIT(REG,BIT)         (REG &=~(1<<BIT))
#define TOGGLE_BIT(REG,BIT)      (REG^=1<<BIT)
#define GET_BIT(REG,BIT)         ((REG>>BIT)&0x01)


#endif