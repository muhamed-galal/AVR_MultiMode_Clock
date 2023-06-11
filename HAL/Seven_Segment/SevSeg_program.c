/*
 * SevSeg_program.c
 *
 *  Created on: Mar 23, 2023
 *      Author: hisha
 */
#include "../../Common/defintion.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "util/delay.h"
#include "../Seven_Segment/SevSeg_Interface.h"



u8 SevSeg_Arr_Cath[10]=
{		SevSegCA_0 ,
		SevSegCA_1 ,
		SevSegCA_2 ,
		SevSegCA_3 ,
		SevSegCA_4 ,
		SevSegCA_5 ,
		SevSegCA_6 ,
		SevSegCA_7 ,
		SevSegCA_8 ,
		SevSegCA_9
};
u8 SevSeg_Arr_Anod[10]=
{		SevSegAN_0 ,
		SevSegAN_1 ,
		SevSegAN_2 ,
		SevSegAN_3 ,
		SevSegAN_4 ,
		SevSegAN_5 ,
		SevSegAN_6 ,
		SevSegAN_7 ,
		SevSegAN_8 ,
		SevSegAN_9
};


SevErrState   SevSeg_SevErrStateSetNumber(u8 Copy_Number , SevSeg_info * SevenSegment1)
{
	ErrState check_PortDirection,Check_PinDirection,Check_PortValue,Check_PinValue;

	// Check The Error State of port and Pin Directions
	check_PortDirection=DIO_ErrStateSetGroupDirection(SevenSegment1->SevSeg_Group,0xff);
	Check_PinDirection=DIO_ErrStateSetPinDirection(SevenSegment1->SevSeg_EnablePort,SevenSegment1->SevSeg_EnablePin,DIO_Output);

	if(check_PortDirection== NoError && Check_PinDirection == NoError)
	{
		// Check the type of 7_Segment (Anode/Cathode)
		if(SevenSegment1->SevenSeg_Type == Cathode)
		{
			Check_PinValue=DIO_ErrStateSetPinValue(SevenSegment1->SevSeg_EnablePort,SevenSegment1->SevSeg_EnablePin,DIO_Low);
			Check_PortValue=DIO_ErrStateSetGroupValue(SevenSegment1->SevSeg_Group,SevSeg_Arr_Cath[Copy_Number]);

			if(Check_PortValue != NoError || Check_PinValue != NoError)
			{
				return SevSeg_ValueError;
			}
		}
		else if(SevenSegment1->SevenSeg_Type == Anode)
		{
			Check_PinValue=DIO_ErrStateSetPinValue(SevenSegment1->SevSeg_EnablePort,SevenSegment1->SevSeg_EnablePin,DIO_High);
			Check_PortValue=DIO_ErrStateSetGroupValue(SevenSegment1->SevSeg_Group,SevSeg_Arr_Anod[Copy_Number]);

			if(Check_PortValue != NoError || Check_PinValue != NoError)
			{
				return SevSeg_ValueError;
			}
		}
		else
		{
			return SevSegTypeError;
		}
		return SevSeg_NoError;
	}
	else
	{
		return SevSegDirectionError;
	}
}

SevErrState   SevSeg_SevErrStateDisplayRange(SevSeg_info * SevenSegment1 , u8 Copy_start , u8 Copy_End )
{
	ErrState check_PortDirection,Check_PinDirection,Check_PortValueStrt,Check_PortValueEnd,Check_PinValue;

	// Check The Error State of port and Pin Directions
	check_PortDirection=DIO_ErrStateSetGroupDirection(SevenSegment1->SevSeg_Group,0xff);
	Check_PinDirection=DIO_ErrStateSetPinDirection(SevenSegment1->SevSeg_EnablePort,SevenSegment1->SevSeg_EnablePin,DIO_Output);

	if(check_PortDirection== NoError && Check_PinDirection == NoError)
	{
		// Check the type of 7_Segment (Anode/Cathode)
		if(SevenSegment1->SevenSeg_Type == Cathode)
		{
			Check_PinValue=DIO_ErrStateSetPinValue(SevenSegment1->SevSeg_EnablePort,SevenSegment1->SevSeg_EnablePin,DIO_Low);
			Check_PortValueStrt=DIO_ErrStateSetGroupValue(SevenSegment1->SevSeg_Group,SevSeg_Arr_Cath[Copy_start]);
			_delay_ms(1000);
			Check_PortValueEnd=DIO_ErrStateSetGroupValue(SevenSegment1->SevSeg_Group,SevSeg_Arr_Cath[Copy_End]);
			_delay_ms(1000);
			if(Check_PortValueEnd != NoError || Check_PinValue != NoError || Check_PortValueStrt == NoError)
			{
				return SevSeg_RangeValueError;
			}
		}
		else if(SevenSegment1->SevenSeg_Type == Anode)
		{
			Check_PinValue=DIO_ErrStateSetPinValue(SevenSegment1->SevSeg_EnablePort,SevenSegment1->SevSeg_EnablePin,DIO_High);
			Check_PortValueStrt=DIO_ErrStateSetGroupValue(SevenSegment1->SevSeg_Group,SevSeg_Arr_Cath[Copy_start]);
			_delay_ms(1000);
			Check_PortValueEnd=DIO_ErrStateSetGroupValue(SevenSegment1->SevSeg_Group,SevSeg_Arr_Cath[Copy_End]);
			_delay_ms(1000);
			if(Check_PortValueStrt != NoError || Check_PinValue != NoError || Check_PortValueEnd != NoError )
			{
				return SevSeg_RangeValueError;
			}
		}
		else
		{
			return SevSegTypeError;
		}
		return SevSeg_NoError;
	}
	else
	{
		return SevSegDirectionError;
	}
}

SevErrState    SevSeg_SevErrStateDisplayMax(SevSeg_info * SevenSegment1)
{

	ErrState check_PortDirection,Check_PinDirection,Check_PortValue,Check_PinValue;

	// Check The Error State of port and Pin Directions
	check_PortDirection=DIO_ErrStateSetGroupDirection(SevenSegment1->SevSeg_Group,0xff);
	Check_PinDirection=DIO_ErrStateSetPinDirection(SevenSegment1->SevSeg_EnablePort,SevenSegment1->SevSeg_EnablePin,DIO_Output);

	if(check_PortDirection== NoError && Check_PinDirection == NoError)
	{
		// Check the type of 7_Segment (Anode/Cathode)
		if(SevenSegment1->SevenSeg_Type == Cathode)
		{
			Check_PinValue=DIO_ErrStateSetPinValue(SevenSegment1->SevSeg_EnablePort,SevenSegment1->SevSeg_EnablePin,DIO_Low);
			for(u8 Count=0;Count<10;Count++)
			{
			Check_PortValue=DIO_ErrStateSetGroupValue(SevenSegment1->SevSeg_Group,SevSeg_Arr_Cath[Count]);

			_delay_ms(1000);
			}

			if(Check_PortValue != NoError || Check_PinValue != NoError)
			{
				return SevSeg_MaxValueError;
			}
		}
		else if(SevenSegment1->SevenSeg_Type == Anode)
		{
			Check_PinValue=DIO_ErrStateSetPinValue(SevenSegment1->SevSeg_EnablePort,SevenSegment1->SevSeg_EnablePin,DIO_High);
			for(u8 Count=0;Count<10;Count++)
			{
			Check_PortValue=DIO_ErrStateSetGroupValue(SevenSegment1->SevSeg_Group,SevSeg_Arr_Anod[Count]);
			_delay_ms(1000);
			}
			if(Check_PortValue != NoError || Check_PinValue != NoError)
			{
				return SevSeg_MaxValueError;
			}
		}
		else
		{
			return SevSegTypeError;
		}
		return SevSeg_NoError;
	}
	else
	{
		return SevSegDirectionError;
	}

}
