//   ___     ___    ____    ____    ____    ____    	   |	     	             |_     ___    ____    ____    ____    ____
// _/   \___/   \__/    \__/    \__/    \__/    \__/AUTHOR | MARIAM RAMADAN EL-Badri | \___/   \__/    \__/    \__/    \__/    \__
//																	Layer: HAL
#ifndef LCD_PRIVATE_H_
#define LCD_PRIVATE_H_
//Send command - 8 bits command/ 4 bits mode so: 8/2
// Most significant bits first (first 4 MSB)
// then enable
// the least significant bits
// then enable

static void private_writeHalfPort(u8 value);

#endif