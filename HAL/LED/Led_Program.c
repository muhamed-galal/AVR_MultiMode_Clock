/*
 * Led_Program.c
 *
 *  Created on: Mar 24, 2023
 *      Author: hisha
 */
#include "../../Common/defintion.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "Led_Interface.h"


LedErrState	Led_LedErrStateTurnOn(Led_info *Led)
{
	if(Led != Null)
	{
		ErrState Check_Direction;
		ErrState Check_Value;

		Check_Direction=DIO_ErrStateSetPinDirection(Led->Led_Group , Led->Led_Pin , DIO_Output );

		if(Check_Direction == NoError)
		{
			if(Led->ConnectionType == Source_Connection)
			{
				Check_Value=DIO_ErrStateSetPinValue(Led->Led_Group  , Led->Led_Pin , DIO_High);
				if(Check_Value != NoError)
				{
					return Led_ValueError;
				}
			}
			else if(Led->ConnectionType == Sink_Connection)
			{
				Check_Value=DIO_ErrStateSetPinValue(Led->Led_Group  , Led->Led_Pin , DIO_Low);
				if(Check_Value != NoError)
				{
					return Led_ValueError;
				}
			}
			else
			{
				return Led_Connection_Error;
			}
			return Led_NoError;
		}
		else
		{
			return Led_DirectionError;
		}
	}
	else
	{
		return Led_TurnOn_Error;
	}

}

LedErrState	Led_LedErrStateTurnOff(Led_info *Led)
{
	if(Led != Null)
	{
		ErrState Check_Direction;
		ErrState Check_Value;

		Check_Direction=DIO_ErrStateSetPinDirection(Led->Led_Group , Led->Led_Pin , DIO_Output );

		if(Check_Direction == NoError)
		{
			if(Led->ConnectionType == Source_Connection)
			{
				Check_Value=DIO_ErrStateSetPinValue(Led->Led_Group  , Led->Led_Pin , DIO_Low);
				if(Check_Value != NoError)
				{
					return Led_ValueError;
				}
			}
			else if(Led->ConnectionType == Sink_Connection)
			{
				Check_Value=DIO_ErrStateSetPinValue(Led->Led_Group  , Led->Led_Pin , DIO_High);
				if(Check_Value != NoError)
				{
					return Led_ValueError;
				}
			}
			else
			{
				return Led_Connection_Error;
			}
			return Led_NoError;
		}
		else
		{
			return Led_DirectionError;
		}
	}
	else
	{
		return Led_TurnOff_Error;
	}

}


