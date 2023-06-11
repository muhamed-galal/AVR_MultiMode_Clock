/*
 * GIE_program.c
 *
 *  Created on: Apr 16, 2023
 *      Author: Muham
 */

#include "std_types.h"
#include "Bit_Math.h"
#include "GIE_interface.h"
#include "GIE_register.h"


void GIEvoidEnable(void)
{
	Set_Bit(SREG,SREG_I);
}
void GIEvoidDisable(void)
{
	Clr_Bit(SREG,SREG_I);
}
