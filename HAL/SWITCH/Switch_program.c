/*
 * Switch_program.c
 *
 *  Created on: Mar 24, 2023
 *      Author: hisha
 */

#include "../../Common/defintion.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "Switch_Interface.h"


SwitchErrState  SW_SwitchErrStateGetState(Switch_Info * Switch ,SwitchState * Result)
{
	ErrState Check_Direction;
	ErrState Check_Value;
	ErrState Check_Read;

	Check_Direction=DIO_ErrStateSetPinDirection(Switch->SW_Group , Switch->SW_Pin , DIO_Input );
	if(Switch->ConnectionType == InternalPullUp )
	{
		Check_Value=DIO_ErrStateSetPinValue(Switch->SW_Group , Switch->SW_Pin , DIO_High);
		Check_Read=DIO_ErrStateReadPinValue(Switch->SW_Group,Switch->SW_Pin,&Result);

		if(*Result == PressedPullUp)
		{
			return Switch_NoError;
		}
		else if(*Result == NotPressedPullUp)
		{
			return Switch_NoError;

		}
	}
	else if(Switch->ConnectionType == ExternalPullUp )
	{
		Check_Read=DIO_ErrStateReadPinValue(Switch->SW_Group,Switch->SW_Pin,&Result);
		if(*Result == PressedPullUp)
		{
			return Switch_NoError;
		}
		else if(*Result == NotPressedPullUp)
		{
			return Switch_NoError;
		}


	}
	else if(Switch->ConnectionType == ExternalPullDown )
	{
		Check_Read = DIO_ErrStateReadPinValue(Switch->SW_Group,Switch->SW_Pin,&Result);

		if(*Result == PressedPullDown)
		{
			return Switch_NoError;

		}
		else if(Result == NotPressedPullDown)
		{
			return Switch_NoError;

		}
		else
		{
			return Switch_ReadError;
		}

	}
	else
	{
		return ConnectionType_Error;
	}


}

