/*
 * Stepper_Program.c
 *
 *  Created on: Mar 28, 2023
 *      Author: hisha
 */

#include "../../Common/std_types.h"
#include "../../Common/defintion.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include <util/delay.h>

#include "../Stepper_Motor/Stepper_Interface.h"
#define delay  2





StErrState  Stepper_StErrStateInit(Stper_info * Motor1)
{
	u8 flag = 0 ;
	ErrState  Res ;
	Res = DIO_ErrStateSetPinDirection(Motor1->Stper_Group ,Motor1->Stper_Blue ,DIO_Output );
	if(Res!=NoError){flag =1;}
	Res =DIO_ErrStateSetPinDirection(Motor1->Stper_Group ,Motor1->Stper_Pink ,DIO_Output );
	if(Res!=NoError){flag =1;}
	Res =DIO_ErrStateSetPinDirection(Motor1->Stper_Group ,Motor1->Stper_Yellow ,DIO_Output );
	if(Res!=NoError){flag =1;}
	Res =DIO_ErrStateSetPinDirection(Motor1->Stper_Group ,Motor1->Stper_Orange ,DIO_Output );
	if(Res!=NoError){flag =1;}
	if (flag == 1 )
	{
		return SteperDirectionpinError ;
	}
	else
	{
		return SteperNoError ;
	}

}

StErrState   Stepper_StErrStateControlMotorRotate(Stper_info * Motor1 , u16 Copy_Degree)
{
	u16 Local_NumberofSteps ;
	u16 Local_NumberofIterations ;
	u16 Local_counter ;
	if(Motor1->Direction_type == CW)
	{
		if (Motor1->TypesOfStpe == FullStep)
		{
			Local_NumberofSteps = (Copy_Degree / DegreeforfullStep)+1 ;
			Local_NumberofIterations = Local_NumberofSteps / FullStep ;
			for (Local_counter =  0 ; Local_counter < Local_NumberofIterations ; Local_counter++)
			{
				Stepper_voidCWFullSteps(Motor1);
			}

		}
		else if (Motor1->TypesOfStpe == HalfStep)
		{
			Local_NumberofSteps = (Copy_Degree / DegreeforHalfStep)+1 ;
			Local_NumberofIterations = Local_NumberofSteps / HalfStep ;
			for (Local_counter =  0 ; Local_counter < Local_NumberofIterations ; Local_counter++)
			{

				Stepper_voidCWHalfSteps(Motor1);
			}
		}
		else
		{
			return SteperTypeStepError ;
		}

	}
	else if (Motor1->Direction_type == CCW)
	{
		if (Motor1->TypesOfStpe == FullStep)
		{
			Local_NumberofSteps = (Copy_Degree / DegreeforfullStep)+1 ;
			Local_NumberofIterations = Local_NumberofSteps / FullStep ;
			for (Local_counter =  0 ; Local_counter < Local_NumberofIterations ; Local_counter++)
			{

				Stepper_voidCCWFullSteps(Motor1);
			}

		}
		else if (Motor1->TypesOfStpe == HalfStep)
		{
			Local_NumberofSteps = (Copy_Degree / DegreeforHalfStep)+1 ;
			Local_NumberofIterations = Local_NumberofSteps / HalfStep ;
			for (Local_counter =  0 ; Local_counter < Local_NumberofIterations ; Local_counter++)
			{

				Stepper_voidCCWHalfSteps(Motor1);
			}
		}
		else
		{
			return SteperTypeStepError ;
		}

	}
	else
	{
		return SteperDirectionTypeError ;
	}
	return SteperNoError ;

}


static void  Stepper_voidCWFullSteps(Stper_info * Motor1)
{
	/*the Blue is Low  and all pin is high */
	DIO_ErrStateSetPinValue(Motor1->Stper_Group,Motor1->Stper_Blue , DIO_Low);
	DIO_ErrStateSetPinValue(Motor1->Stper_Group,Motor1->Stper_Pink, DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_Group,Motor1->Stper_Yellow, DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_Group,Motor1->Stper_Orange, DIO_High);
	_delay_ms(delay);
	/*the Pink is Low  and all pin is high*/
	DIO_ErrStateSetPinValue(Motor1->Stper_Group,Motor1->Stper_Blue , DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_Group,Motor1->Stper_Pink, DIO_Low);
	DIO_ErrStateSetPinValue(Motor1->Stper_Group,Motor1->Stper_Yellow, DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_Group,Motor1->Stper_Orange, DIO_High);
	_delay_ms(delay);
	/*the Yellow is Low  and all pin is high*/
	DIO_ErrStateSetPinValue(Motor1->Stper_Group,Motor1->Stper_Blue , DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_Group,Motor1->Stper_Pink, DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_Group,Motor1->Stper_Yellow, DIO_Low);
	DIO_ErrStateSetPinValue(Motor1->Stper_Group,Motor1->Stper_Orange, DIO_High);
	_delay_ms(delay);
	/*the Orange is Low  and all pin is high*/
	DIO_ErrStateSetPinValue(Motor1->Stper_Group,Motor1->Stper_Blue , DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_Group,Motor1->Stper_Pink, DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_Group,Motor1->Stper_Yellow, DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_Group,Motor1->Stper_Orange, DIO_Low);
	_delay_ms(delay);
}
static void  Stepper_voidCCWFullSteps(Stper_info * Motor1)
{
	/*the Blue is Low  and all pin is high */
	DIO_ErrStateSetPinValue(Motor1->Stper_Group,Motor1->Stper_Blue , DIO_Low);
	DIO_ErrStateSetPinValue(Motor1->Stper_Group,Motor1->Stper_Orange, DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_Group,Motor1->Stper_Yellow, DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_Group,Motor1->Stper_Pink, DIO_High);
	_delay_ms(delay);
	/*the Pink is Low  and all pin is high*/
	DIO_ErrStateSetPinValue(Motor1->Stper_Group,Motor1->Stper_Blue , DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_Group,Motor1->Stper_Orange, DIO_Low);
	DIO_ErrStateSetPinValue(Motor1->Stper_Group,Motor1->Stper_Yellow, DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_Group,Motor1->Stper_Pink, DIO_High);
	_delay_ms(delay);
	/*the Yellow is Low  and all pin is high*/
	DIO_ErrStateSetPinValue(Motor1->Stper_Group,Motor1->Stper_Blue , DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_Group,Motor1->Stper_Orange, DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_Group,Motor1->Stper_Yellow, DIO_Low);
	DIO_ErrStateSetPinValue(Motor1->Stper_Group,Motor1->Stper_Pink, DIO_High);
	_delay_ms(delay);
	/*the Orange is Low  and all pin is high*/
	DIO_ErrStateSetPinValue(Motor1->Stper_Group,Motor1->Stper_Blue , DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_Group,Motor1->Stper_Orange, DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_Group,Motor1->Stper_Yellow, DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_Group,Motor1->Stper_Pink, DIO_Low);
	_delay_ms(delay);
}

static void  Stepper_voidCWHalfSteps(Stper_info * Motor1)
{
	/*the Blue is Low  and all pin is high */
	DIO_ErrStateSetPinValue(Motor1->Stper_Group,Motor1->Stper_Blue , DIO_Low);
	DIO_ErrStateSetPinValue(Motor1->Stper_Group,Motor1->Stper_Pink, DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_Group,Motor1->Stper_Yellow, DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_Group,Motor1->Stper_Orange, DIO_High);
	_delay_ms(delay);
	/*the Blue is Low  and Pink all pin is high */
	DIO_ErrStateSetPinValue(Motor1->Stper_Group,Motor1->Stper_Blue , DIO_Low);
	DIO_ErrStateSetPinValue(Motor1->Stper_Group,Motor1->Stper_Pink, DIO_Low);
	DIO_ErrStateSetPinValue(Motor1->Stper_Group,Motor1->Stper_Yellow, DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_Group,Motor1->Stper_Orange, DIO_High);
	_delay_ms(delay);
	/*the Pink is Low  and all pin is high*/
	DIO_ErrStateSetPinValue(Motor1->Stper_Group,Motor1->Stper_Blue , DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_Group,Motor1->Stper_Pink, DIO_Low);
	DIO_ErrStateSetPinValue(Motor1->Stper_Group,Motor1->Stper_Yellow, DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_Group,Motor1->Stper_Orange, DIO_High);
	_delay_ms(delay);
	/*the Pink is Low  and all pin is high*/
	DIO_ErrStateSetPinValue(Motor1->Stper_Group,Motor1->Stper_Blue , DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_Group,Motor1->Stper_Pink, DIO_Low);
	DIO_ErrStateSetPinValue(Motor1->Stper_Group,Motor1->Stper_Yellow, DIO_Low);
	DIO_ErrStateSetPinValue(Motor1->Stper_Group,Motor1->Stper_Orange, DIO_High);
	_delay_ms(delay);
	/*the Yellow is Low  and all pin is high*/
	DIO_ErrStateSetPinValue(Motor1->Stper_Group,Motor1->Stper_Blue , DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_Group,Motor1->Stper_Pink, DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_Group,Motor1->Stper_Yellow, DIO_Low);
	DIO_ErrStateSetPinValue(Motor1->Stper_Group,Motor1->Stper_Orange, DIO_High);
	_delay_ms(delay);

	/*the Yellow is Low  and all pin is high*/
	DIO_ErrStateSetPinValue(Motor1->Stper_Group,Motor1->Stper_Blue , DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_Group,Motor1->Stper_Pink, DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_Group,Motor1->Stper_Yellow, DIO_Low);
	DIO_ErrStateSetPinValue(Motor1->Stper_Group,Motor1->Stper_Orange, DIO_Low);
	_delay_ms(delay);
	/*the Orange is Low  and all pin is high*/
	DIO_ErrStateSetPinValue(Motor1->Stper_Group,Motor1->Stper_Blue , DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_Group,Motor1->Stper_Pink, DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_Group,Motor1->Stper_Yellow, DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_Group,Motor1->Stper_Orange, DIO_Low);
	_delay_ms(delay);
	/*the Orange is Low  and all pin is high*/
	DIO_ErrStateSetPinValue(Motor1->Stper_Group,Motor1->Stper_Blue , DIO_Low);
	DIO_ErrStateSetPinValue(Motor1->Stper_Group,Motor1->Stper_Pink, DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_Group,Motor1->Stper_Yellow, DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_Group,Motor1->Stper_Orange, DIO_Low);
	_delay_ms(delay);
}
static void  Stepper_voidCCWHalfSteps(Stper_info * Motor1)
{
	/*the Blue is Low  and all pin is high */
	DIO_ErrStateSetPinValue(Motor1->Stper_Group,Motor1->Stper_Blue , DIO_Low);
	DIO_ErrStateSetPinValue(Motor1->Stper_Group,Motor1->Stper_Orange, DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_Group,Motor1->Stper_Yellow, DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_Group,Motor1->Stper_Pink, DIO_High);
	_delay_ms(delay);
	/*the Blue is Low  and Pink all pin is high */
	DIO_ErrStateSetPinValue(Motor1->Stper_Group,Motor1->Stper_Blue , DIO_Low);
	DIO_ErrStateSetPinValue(Motor1->Stper_Group,Motor1->Stper_Orange, DIO_Low);
	DIO_ErrStateSetPinValue(Motor1->Stper_Group,Motor1->Stper_Yellow, DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_Group,Motor1->Stper_Pink, DIO_High);
	_delay_ms(delay);
	/*the Pink is Low  and all pin is high*/
	DIO_ErrStateSetPinValue(Motor1->Stper_Group,Motor1->Stper_Blue , DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_Group,Motor1->Stper_Orange, DIO_Low);
	DIO_ErrStateSetPinValue(Motor1->Stper_Group,Motor1->Stper_Yellow, DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_Group,Motor1->Stper_Pink, DIO_High);
	_delay_ms(delay);
	/*the Pink is Low  and all pin is high*/
	DIO_ErrStateSetPinValue(Motor1->Stper_Group,Motor1->Stper_Blue , DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_Group,Motor1->Stper_Orange, DIO_Low);
	DIO_ErrStateSetPinValue(Motor1->Stper_Group,Motor1->Stper_Yellow, DIO_Low);
	DIO_ErrStateSetPinValue(Motor1->Stper_Group,Motor1->Stper_Pink, DIO_High);
	_delay_ms(delay);
	/*the Yellow is Low  and all pin is high*/
	DIO_ErrStateSetPinValue(Motor1->Stper_Group,Motor1->Stper_Blue , DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_Group,Motor1->Stper_Orange, DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_Group,Motor1->Stper_Yellow, DIO_Low);
	DIO_ErrStateSetPinValue(Motor1->Stper_Group,Motor1->Stper_Pink, DIO_High);
	_delay_ms(delay);

	/*the Yellow is Low  and all pin is high*/
	DIO_ErrStateSetPinValue(Motor1->Stper_Group,Motor1->Stper_Blue , DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_Group,Motor1->Stper_Orange, DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_Group,Motor1->Stper_Yellow, DIO_Low);
	DIO_ErrStateSetPinValue(Motor1->Stper_Group,Motor1->Stper_Pink, DIO_Low);
	_delay_ms(delay);
	/*the Orange is Low  and all pin is high*/
	DIO_ErrStateSetPinValue(Motor1->Stper_Group,Motor1->Stper_Blue , DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_Group,Motor1->Stper_Pink, DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_Group,Motor1->Stper_Yellow, DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_Group,Motor1->Stper_Orange, DIO_Low);
	_delay_ms(delay);
	/*the Orange is Low  and all pin is high*/
	DIO_ErrStateSetPinValue(Motor1->Stper_Group,Motor1->Stper_Blue , DIO_Low);
	DIO_ErrStateSetPinValue(Motor1->Stper_Group,Motor1->Stper_Pink, DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_Group,Motor1->Stper_Yellow, DIO_High);
	DIO_ErrStateSetPinValue(Motor1->Stper_Group,Motor1->Stper_Orange, DIO_Low);
	_delay_ms(delay);
}
