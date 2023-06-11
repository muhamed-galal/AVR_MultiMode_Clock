/*
 * KPD_Program.c
 *
 *  Created on: Mar 27, 2023
 *      Author: Adel
 */

#include <util/delay.h>
#include "KPD_Interface.h"

u8 KPD_ELEMENTS[4][4]={
		{'7','8','9','/'},
		{'4','5','6','*'},
		{'1','2','3','-'},
		{'%','0','=','+'}
};

u8 KeyPad (KPD_INFO * KP)
{
	/*make Rows output and High*/
	DIO_ErrStateSetPinDirection(KP->R0_groub_num,KP->R0_pin_num,DIO_Output);
	DIO_ErrStateSetPinValue    (KP->R0_groub_num,KP->R0_pin_num,DIO_High  );
	DIO_ErrStateSetPinDirection(KP->R1_groub_num,KP->R1_pin_num,DIO_Output);
	DIO_ErrStateSetPinValue    (KP->R1_groub_num,KP->R1_pin_num,DIO_High  );
	DIO_ErrStateSetPinDirection(KP->R2_groub_num,KP->R2_pin_num,DIO_Output);
	DIO_ErrStateSetPinValue    (KP->R2_groub_num,KP->R2_pin_num,DIO_High  );
	DIO_ErrStateSetPinDirection(KP->R3_groub_num,KP->R3_pin_num,DIO_Output);
	DIO_ErrStateSetPinValue    (KP->R3_groub_num,KP->R3_pin_num,DIO_High  );
	/*make coloums input and pull up*/
	DIO_ErrStateSetPinDirection(KP->C0_groub_num,KP->C0_pin_num,DIO_Input);
	DIO_ErrStateSetPinValue    (KP->C0_groub_num,KP->C0_pin_num,DIO_High );
	DIO_ErrStateSetPinDirection(KP->C1_groub_num,KP->C1_pin_num,DIO_Input);
	DIO_ErrStateSetPinValue    (KP->C1_groub_num,KP->C1_pin_num,DIO_High );
	DIO_ErrStateSetPinDirection(KP->C2_groub_num,KP->C2_pin_num,DIO_Input);
	DIO_ErrStateSetPinValue    (KP->C2_groub_num,KP->C2_pin_num,DIO_High );
	DIO_ErrStateSetPinDirection(KP->C3_groub_num,KP->C3_pin_num,DIO_Input);
	DIO_ErrStateSetPinValue    (KP->C3_groub_num,KP->C3_pin_num,DIO_High );

	/*looping to get the pressed key*/
	u8 Row,coloum;
	u8 res;
	while(1)
	{	_delay_ms(200); //******************************Verrrrrrrrry Important******************************8888
	for(Row=0;Row<4;Row++)
	{
		switch(Row)
		{
		case 0 : DIO_ErrStateSetPinValue(KP->R0_groub_num,KP->R0_pin_num,DIO_Low); break;
		case 1 : DIO_ErrStateSetPinValue(KP->R1_groub_num,KP->R1_pin_num,DIO_Low); break;
		case 2 : DIO_ErrStateSetPinValue(KP->R2_groub_num,KP->R2_pin_num,DIO_Low); break;
		case 3 : DIO_ErrStateSetPinValue(KP->R3_groub_num,KP->R3_pin_num,DIO_Low); break;
		}
		for(coloum=0;coloum<4;coloum++)
		{
			switch(coloum)
			{
			case 0 : DIO_ErrStateReadPinValue(KP->C0_groub_num,KP->C0_pin_num,&res); break;
			case 1 : DIO_ErrStateReadPinValue(KP->C1_groub_num,KP->C1_pin_num,&res); break;
			case 2 : DIO_ErrStateReadPinValue(KP->C2_groub_num,KP->C2_pin_num,&res); break;
			case 3 : DIO_ErrStateReadPinValue(KP->C3_groub_num,KP->C3_pin_num,&res); break;
			}
			if(res==0)						//0->pressed connected to gnd
			{
				return KPD_ELEMENTS[Row][coloum];
			}
		}
		switch(Row)
		{
		case 0 : DIO_ErrStateSetPinValue(KP->R0_groub_num,KP->R0_pin_num,DIO_High); break;
		case 1 : DIO_ErrStateSetPinValue(KP->R1_groub_num,KP->R1_pin_num,DIO_High); break;
		case 2 : DIO_ErrStateSetPinValue(KP->R2_groub_num,KP->R2_pin_num,DIO_High); break;
		case 3 : DIO_ErrStateSetPinValue(KP->R3_groub_num,KP->R3_pin_num,DIO_High); break;
		}
	}
	}
	}



