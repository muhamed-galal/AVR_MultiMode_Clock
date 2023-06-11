/*
 * Lcd_Program.c
 *
 *  Created on: Mar 25, 2023
 *      Author: hisha
 */

#include <util/delay.h>
#include "../../MCAL/DIO/DIO_Interface.h"
#include "Lcd_Interface.h"

u8 glob_counter=0;
u8 glob_counter2=0;

void Lcd_VoidSendCommand(u8 Copy_Command, Lcd_Info * Lcd)

{
	/*RS->LOW*/
	DIO_ErrStateSetPinValue(Lcd->RS_Group , Lcd->RS_Pin , DIO_Low);
	/*RW-> LOW*/
	DIO_ErrStateSetPinValue(Lcd->RW_Group , Lcd-> RW_Pin , DIO_Low) ;
	/*Group = Command */
	DIO_ErrStateSetGroupValue(Lcd->Data_Group , Copy_Command) ;
	/*Enable*/
	DIO_ErrStateSetPinValue(Lcd->E_Group , Lcd-> E_Pin , DIO_High) ;
	_delay_ms(1);
	DIO_ErrStateSetPinValue(Lcd->E_Group , Lcd-> E_Pin , DIO_Low) ;
	_delay_ms(1);
}

void Lcd_VoidSendChar(u8 Copy_Char, Lcd_Info * Lcd)
{

	//if(glob_counter<16)
	//{
		/*RS->High*/
		DIO_ErrStateSetPinValue(Lcd->RS_Group , Lcd->RS_Pin , DIO_High);
		/*RW-> LOW*/
		DIO_ErrStateSetPinValue(Lcd->RW_Group , Lcd-> RW_Pin , DIO_Low) ;
		/*Group = Char */
		DIO_ErrStateSetGroupValue(Lcd->Data_Group , Copy_Char) ;
		/*Enable*/
		DIO_ErrStateSetPinValue(Lcd->E_Group , Lcd-> E_Pin , DIO_High) ;
		_delay_ms(1);
		DIO_ErrStateSetPinValue(Lcd->E_Group , Lcd-> E_Pin , DIO_Low) ;
		_delay_ms(1);
	//	glob_counter++ ;
	//}
	/*else if(glob_counter>=16)
	{
		Lcd_VoidSendCommand((LCD_SetAddressDDRAM + LCD_SecondLine + glob_counter2),Lcd);
		glob_counter2++;
		//RS->High
		DIO_ErrStateSetPinValue(Lcd->RS_Group , Lcd->RS_Pin , DIO_High);
		//RW-> LOW
		DIO_ErrStateSetPinValue(Lcd->RW_Group , Lcd-> RW_Pin , DIO_Low) ;
		//Group = COmmand
		DIO_ErrStateSetGroupValue(Lcd->Data_Group , Copy_Char) ;
		//Enable
		DIO_ErrStateSetPinValue(Lcd->E_Group , Lcd-> E_Pin , DIO_High) ;
		_delay_ms(1);
		DIO_ErrStateSetPinValue(Lcd->E_Group , Lcd-> E_Pin , DIO_Low) ;
		_delay_ms(1);
	}*/
}

void Lcd_VoidInit(Lcd_Info * Lcd)
{
	/*Set Directions*/
	DIO_ErrStateSetPinDirection(Lcd->RS_Group,Lcd->RS_Pin,DIO_Output);
	DIO_ErrStateSetPinDirection(Lcd->RW_Group,Lcd->RW_Pin,DIO_Output);
	DIO_ErrStateSetPinDirection(Lcd->E_Group,Lcd->E_Pin,DIO_Output);
	DIO_ErrStateSetGroupDirection(Lcd->Data_Group,0xFF);
	/*Wait More than 30 ms */
	_delay_ms(40);
	/*Sent Function Set*/
	Lcd_VoidSendCommand(LCD_Set8Bit2Line5x8,Lcd) ;
	/*wait more than 39us*/
	_delay_ms(1);
	/*Sent Display on/off*/
	Lcd_VoidSendCommand(LCD_DisplayON,Lcd) ;
	/*wait more than 39us*/
	_delay_ms(1);
	/*Sent Clear*/
	Lcd_VoidSendCommand(LCD_ClearDisplay,Lcd) ;
	/*wait more than 39us*/
	_delay_ms(2);


}

void Lcd_VoidSendString(u8 *Address_String ,Lcd_Info * Lcd)
{
	/*Counter For Loop */
	u8 Local_Counter = 0 ;
	/*Loop*/
	while (Address_String[Local_Counter]!='\0')
	{
		/*Send Char */
		Lcd_VoidSendChar(Address_String[Local_Counter],Lcd) ;
		/*Increment Counter */
		Local_Counter++;
	}
}

void Lcd_VoidGoXY(Lcd_Info * Lcd ,u8 Copy_XLocation ,u8 Copy_YLocation )
{
	u8 Local_Address = 0 ;
	if (Copy_XLocation == 0)
	{
		Local_Address = Copy_YLocation ;
	}
	else if (Copy_XLocation == 1)
	{
		Local_Address = Copy_YLocation + LCD_SecondLine ;
	}

	// Send the Address of DDRAM
	Lcd_VoidSendCommand((LCD_SetAddressDDRAM + Local_Address),Lcd);
}

void Lcd_VoidSendSpecialChar(u8 *Special_CharArr,u8 CGRAM_Location,u8 Copy_XLocation,u8 Copy_YLocation,Lcd_Info * Lcd)
{
	u8 CG_RAM_Address=0;

	// calculate the address of CG RAM every location is 8 bytes
	CG_RAM_Address=CGRAM_Location*8;

	// Send the Address of CG RAM
	Lcd_VoidSendCommand(CG_RAM_Address+LCD_SetAddressCGRAM,Lcd);

	// Write the Pattern of Special Char on CGRAM Looping in 8 bytes
	for(u8 count=0;count<8;count++)
	{
		Lcd_VoidSendChar(Special_CharArr[count],Lcd);
	}
	// Return to DDRAM to Display the stored pattern
	Lcd_VoidGoXY(Lcd,Copy_XLocation,Copy_YLocation);
	// Send the Number of loction in CGRAM to Display the stored
	Lcd_VoidSendChar(CGRAM_Location,Lcd);

}

void Lcd_VoidSendNumber(u32 Number,Lcd_Info * Lcd)
{
	u8 arr[10];
	u8 count1=0;
	while(Number!=0)
	{
		for (u8 count=0; count<10;count++)
		{
			arr[count]=Number%10;

			Number=Number/10;

			count1++;

			if(Number == 0) break;
			else continue;
		}
	}

	for(s8 count=count1-1;count>=0;count--)
	{
		Lcd_VoidSendChar(arr[count]+'0',Lcd);
	}
}
