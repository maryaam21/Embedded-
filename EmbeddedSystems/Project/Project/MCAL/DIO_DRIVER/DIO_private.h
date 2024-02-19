//   ___     ___    ____    ____    ____    ____    	   |	     	             |_     ___    ____    ____    ____    ____
// _/   \___/   \__/    \__/    \__/    \__/    \__/AUTHOR | MARIAM RAMADAN EL-Badri | \___/   \__/    \__/    \__/    \__/    \__
//																	Layer: MCAL
#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_

/* Group A */
#define PORTA_REG   *((volatile u8*)0x3B)
#define DDRA_REG    *((volatile u8*)0x3A)
#define PINA_REG    *((volatile u8*)0x39)

/* Group B */
#define PORTB_REG   *((volatile u8*)0x38)
#define DDRB_REG    *((volatile u8*)0x37)
#define PINB_REG    *((volatile u8*)0x36)

/* Group C */
#define PORTC_REG   *((volatile u8*)0x35)
#define DDRC_REG    *((volatile u8*)0x34)
#define PINC_REG    *((volatile u8*)0x33)

/* Group D */
#define PORTD_REG   *((volatile u8*)0x32)
#define DDRD_REG    *((volatile u8*)0x31)
#define PIND_REG    *((volatile u8*)0x30)


#endif /* DIO_PRIVATE_H_ */