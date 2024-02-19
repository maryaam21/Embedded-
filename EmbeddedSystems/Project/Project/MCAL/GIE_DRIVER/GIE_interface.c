//   ___     ___    ____    ____    ____    ____    	   |	     	             |_     ___    ____    ____    ____    ____
// _/   \___/   \__/    \__/    \__/    \__/    \__/AUTHOR | MARIAM RAMADAN EL-Badri | \___/   \__/    \__/    \__/    \__/    \__
//																	Layer: MCAL
#ifndef GIE_INTERFACE_H_
#define GIE_INTERFACE_H_
/*LIB*/
#include "..\..\LIB\STD_TYPE.h"
#include "..\..\LIB\BIT_MATH.h"
#include "..\..\LIB\Error_State.h"
/*MCAL*/
#include "GIE_private.h"
#include "GIE_interface.h"
/*
 * Description : This Function used to enable General Interrupt Enable (GIE)
 * Parameters  : Nothing
 * return      : Nothing
*/
/*****************************************************************************
* Function Name: GIE_voidEnable
* Purpose      : SET(SREG,SREG_I)
* Parameters   : void
* Return value : void
*****************************************************************************/
void GIE_voidEnable(void)
{
	SET_BIT(SREG,SREG_I);	
}
/*
 * Description : This Function used to disable General Interrupt Enable (GIE)
 * Parameters  : Nothing
 * return      : Nothing
*/
/*****************************************************************************
* Function Name: GIE_voidDisable
* Purpose      : CLR(SREG,SREG_I)
* Parameters   : void
* Return value : void
*****************************************************************************/
void GIE_voidDisable(void)
{
	CLR_BIT(SREG,SREG_I);
}

#endif