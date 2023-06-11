/*
 * DIO_Program.c
 *
 *  Created on: Mar 22, 2023
 *      Author: Muham
 */


#include "DIO_Interface.h"
#include "../../Common/Bit_Math.h"
#include "../../Common/defintion.h"


ErrState  DIO_ErrStateSetPinDirection(DIO_GroupNumber Copy_GroupNumber ,DIO_PinNumber Copy_PinNumber,DIO_DirectionState Copy_DirectionState)
{
	if(Copy_PinNumber<=Pin7 && Copy_PinNumber>=Pin0)
	{
		/*Input-> write Zero DDR (CLR) */
		if (Copy_DirectionState == DIO_Input )
		{
			switch(Copy_GroupNumber){
			/*Group A*/
			case DIO_GroupA : Clr_Bit(DDRA, Copy_PinNumber ) ;break ;
			/*Group B*/
			case DIO_GroupB: Clr_Bit(DDRB, Copy_PinNumber ) ;break ;
			/*Group C*/
			case DIO_GroupC : Clr_Bit(DDRC, Copy_PinNumber ) ;break ;
			/*Group D*/
			case DIO_GroupD : Clr_Bit(DDRD, Copy_PinNumber ) ;break ;
			/*Wrong*/
			default:
				return GroupError ;
			}
		}

		/*Output -> write DDR = one */
		else if (Copy_DirectionState == DIO_Output )
		{
			switch(Copy_GroupNumber){
			/*Group A*/
			case DIO_GroupA : Set_Bit(DDRA,Copy_PinNumber);break;
			/*Group B*/
			case DIO_GroupB : Set_Bit(DDRB,Copy_PinNumber);break;
			/*Group C*/
			case DIO_GroupC : Set_Bit(DDRC,Copy_PinNumber);break;
			/*Group D*/
			case DIO_GroupD : Set_Bit(DDRD,Copy_PinNumber);break;
			/*Wrong*/
			default:
				return GroupError ;
			}
		}

		else
		{
			return DirectionError ;
		}

		return NoError ;
	}
	else
	{
		return PinNumberError ;
	}
}

ErrState  DIO_ErrStateSetPinValue(DIO_GroupNumber Copy_GroupNumber ,DIO_PinNumber Copy_PinNumber,DIO_ValueState Copy_ValueState)
{
	if(Copy_PinNumber<=Pin7 && Copy_PinNumber>=Pin0)
	{
		/*Low-> write Zero Port (CLR) */
		if (Copy_ValueState == DIO_Low )
		{
			switch(Copy_GroupNumber){
			/*Group A*/
			case DIO_GroupA : Clr_Bit(PORTA, Copy_PinNumber ) ;break ;
			/*Group B*/
			case DIO_GroupB: Clr_Bit(PORTB, Copy_PinNumber ) ;break ;
			/*Group C*/
			case DIO_GroupC : Clr_Bit(PORTC, Copy_PinNumber ) ;break ;
			/*Group D*/
			case DIO_GroupD : Clr_Bit(PORTD, Copy_PinNumber ) ;break ;
			/*Wrong*/
			default:
				return GroupError ;
			}
		}

		/*High -> write port = one */
		else if (Copy_ValueState == DIO_High )
		{
			switch(Copy_GroupNumber){
			/*Group A*/
			case DIO_GroupA : Set_Bit(PORTA,Copy_PinNumber);break;
			/*Group B*/
			case DIO_GroupB : Set_Bit(PORTB,Copy_PinNumber);break;
			/*Group C*/
			case DIO_GroupC : Set_Bit(PORTC,Copy_PinNumber);break;
			/*Group D*/
			case DIO_GroupD : Set_Bit(PORTD,Copy_PinNumber);break;
			/*Wrong*/
			default:
				return GroupError ;
			}
		}

		else
		{
			return ValueError ;
		}

		return NoError ;
	}
	else
	{
		return PinNumberError ;
	}

}

ErrState  DIO_ErrStateReadPinValue(DIO_GroupNumber Copy_GroupNumber ,DIO_PinNumber Copy_PinNumber ,u8 *Result)
{
	/*check on pin range from 0 to 7 */
	if (Copy_PinNumber>= Pin0 && Copy_PinNumber <=Pin7)
	{
		switch(Copy_GroupNumber)
		{
		case DIO_GroupA: *Result=Get_Bit(PINA,Copy_PinNumber); break ;
		case DIO_GroupB: *Result=Get_Bit(PINB,Copy_PinNumber); break ;
		case DIO_GroupC: *Result=Get_Bit(PINC,Copy_PinNumber); break ;
		case DIO_GroupD: *Result=Get_Bit(PIND,Copy_PinNumber); break ;
		default:
		return GroupError ;
		}
		return NoError ;
	}
	else
	{
		return PinNumberError ;
	}

}

//
ErrState  DIO_ErrStateSetGroupDirection(DIO_GroupNumber Copy_GroupNumber ,u8 Copy_DirectionState)
{
	if (Copy_DirectionState <= 0xff && Copy_DirectionState>=0x00)
	{
		switch(Copy_GroupNumber)
		{
		case DIO_GroupA: DDRA =  Copy_DirectionState ;break ;
		case DIO_GroupB: DDRB =  Copy_DirectionState ;break ;
		case DIO_GroupC: DDRC =  Copy_DirectionState ;break ;
		case DIO_GroupD: DDRD =  Copy_DirectionState ;break ;
		default :
			return GroupError ;
		}
		return NoError ;
	}
	else
	{
		return DirectionRangError;
	}
}
ErrState  DIO_ErrStateSetGroupValue(DIO_GroupNumber Copy_GroupNumber ,u8 Copy_ValueState)
{
	if (Copy_ValueState <= 0xff && Copy_ValueState>=0x00)
	{
		switch(Copy_GroupNumber)
		{
		case DIO_GroupA: PORTA =  Copy_ValueState ;break ;
		case DIO_GroupB: PORTB =  Copy_ValueState ;break ;
		case DIO_GroupC: PORTC =  Copy_ValueState ;break ;
		case DIO_GroupD: PORTD =  Copy_ValueState ;break ;
		default :
			return GroupError ;
		}
		return NoError ;
	}
	else
	{
		return ValueRangError;
	}

}
ErrState  DIO_ErrStateReadGroupValue(DIO_GroupNumber Copy_GroupNumber ,u8 *Result)
{
	if(Result!=Null)
	{
		switch(Copy_GroupNumber)
		{
		case DIO_GroupA: PORTA=0Xff;
		*Result = PINA ;
		break ;
		case DIO_GroupB: PORTB=0Xff;
		*Result = PINB ;
		break ;
		case DIO_GroupC: PORTC=0Xff;
		*Result = PINC ;
		break ;
		case DIO_GroupD: PORTD=0Xff;
		*Result = PIND ;
		break ;
		default :
			return GroupError ;
		}
		return NoError ;
	}
	else
	{
		return AddressError;
	}

}

