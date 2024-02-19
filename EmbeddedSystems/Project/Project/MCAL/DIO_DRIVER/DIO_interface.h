//   ___     ___    ____    ____    ____    ____    	   |	     	             |_     ___    ____    ____    ____    ____
// _/   \___/   \__/    \__/    \__/    \__/    \__/AUTHOR | MARIAM RAMADAN EL-Badri | \___/   \__/    \__/    \__/    \__/    \__
//																	Layer: MCAL
#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

/* PIN directory  */
#define  OUTPUT		1
#define  INPUT		0

/* PIN value  */
#define  HIGH		1
#define  LOW		0

/* PORTS  */
#define  PORTA      0
#define  PORTB      1
#define  PORTC      2
#define  PORTD      3

/* PINS  */
#define  PIN0		0
#define  PIN1		1
#define  PIN2		2
#define  PIN3		3
#define  PIN4		4
#define  PIN5		5
#define  PIN6		6
#define  PIN7		7

/*****************************************************************************
* Function Name: DIO_Vid_Set_Pin_Dir
* Purpose      : Set pin direction (OUTPUT , INPUT)
* Parameters   : u8 Copy_u8_port,u8 Copy_u8_pin,u8 Copy_u8_dir
* Return value : void
*****************************************************************************/
void DIO_Vid_Set_Pin_Dir(u8 copy_u8_port,u8 copy_u8_pin, u8 copy_u8_dir);
/*****************************************************************************
* Function Name: DIO_Vid_Set_Pin_VAL
* Purpose      : Set pin value (HIGH , LOW)
* Parameters   : u8 Copy_u8_port,u8 Copy_u8_pin,u8 Copy_u8_VAL
* Return value : void
*****************************************************************************/
void DIO_Vid_Set_Pin_Val(u8 copy_u8_port,u8 copy_u8_pin, u8 copy_u8_val);
/*****************************************************************************
* Function Name: DIO_Vid_Toggle_Pin_Val
* Purpose      : Toggle  pin value (HIGH , LOW)
* Parameters   : u8 Copy_u8_port,u8 Copy_u8_pin
* Return value : void
*****************************************************************************/
void DIO_Vid_Toggle_Pin_Val(u8 copy_u8_port,u8 copy_u8_pin);
/*****************************************************************************
* Function Name: DIO_u8_Get_Pin_Val
* Purpose      : GET  pin value (HIGH , LOW)
* Parameters   : u8 Copy_u8_port,u8 Copy_u8_pin
* Return value : U8
*****************************************************************************/
u8	 DIO_u8_Get_Pin_Val(u8 copy_u8_port,u8 copy_u8_pin) ;
/*****************************************************************************
* Function Name: DIO_Vid_Set_Port_Dir
* Purpose      : GET  port value (HIGH , LOW)
* Parameters   : u8 copy_u8_port, u8 copy_u8_dir
* Return value : void
*****************************************************************************/
void DIO_Vid_Set_Port_Dir(u8 copy_u8_port, u8 copy_u8_dir);
/*****************************************************************************
* Function Name: DIO_Vid_Set_Port_Val
* Purpose      : Set  port value (HIGH , LOW)
* Parameters   : u8 copy_u8_port, u8 copy_u8_val
* Return value : void
*****************************************************************************/
void DIO_Vid_Set_Port_Val(u8 copy_u8_port, u8 copy_u8_val);

#endif /* DIO_INTERFACE_H_ */