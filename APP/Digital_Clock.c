/*
 * main.c
 *
 *  Created on: Mar 22, 2023
 *      Author: Galal
 *
 */
#include "Bit_Math.h"
#include "defintion.h"
#include "../MCAL/DIO/DIO_Interface.h"
#include "../HAL/LCD/Lcd_Interface.h"
#include "../HAL/KEYPAD/KPD_Interface.h"
#include "../MCAL/Timer/Timer_2/Timer2_Interface.h"
#include "util/delay.h"


void DigitalWatch(void);
void StopWatch(void);

Lcd_Info LCD1={DIO_GroupB,DIO_GroupB,DIO_GroupB,Pin2,Pin1,Pin0,DIO_GroupA};
KPD_INFO KP={DIO_GroupC,Pin0,DIO_GroupC,Pin1,DIO_GroupC,Pin2,DIO_GroupC,Pin3,DIO_GroupC,Pin4,DIO_GroupC,Pin5,DIO_GroupC,Pin6,DIO_GroupC,Pin7};
u8 array[10]={'0','0',':','0','0',':','0','0','\0'};
u8 pressed;
u32 Count_Seconds;


void main ()
{

	DIO_ErrStateSetPinDirection(DIO_GroupD,Pin7,DIO_Output); // check Output compare Pin Output
	Lcd_VoidInit(&LCD1);
	Lcd_VoidSendString("Enter The Mode",&LCD1);
	_delay_ms(500);
	Lcd_VoidInit(&LCD1);
	Lcd_VoidGoXY(&LCD1,0,0);
	Lcd_VoidSendString("For Clock :1",&LCD1);
	Lcd_VoidGoXY(&LCD1,1,0);
	Lcd_VoidSendString("For Stopwatch :2",&LCD1);

	TIMER2_voidInit();
	OCR2_REG=250;

	while(1)
	{
		pressed= KeyPad(&KP);

		if (pressed == '1')
		{
			Set_Bit(SREG_REG,7);
			Lcd_VoidInit(&LCD1);
			Lcd_VoidSendString("Clock Mode",&LCD1);
			_delay_ms(300);
			Lcd_VoidInit(&LCD1);
			Lcd_VoidGoXY(&LCD1,0,0);
			//Lcd_VoidSendString(array,&LCD1);
			TIMER2_voidSetCallBachFn(&DigitalWatch);
		}
		else if (pressed == '2')
		{
			Set_Bit(SREG_REG,7);
			Lcd_VoidInit(&LCD1);
			Lcd_VoidSendString("StopWatch Mode",&LCD1);
			_delay_ms(500);
			Lcd_VoidInit(&LCD1);
			Lcd_VoidGoXY(&LCD1,0,0);
			Lcd_VoidSendString(array,&LCD1);
			for(int count=0;count<8;count++)
			{
				Clr_Bit(SREG_REG,7);
				if(count ==2 || count==5) continue;
				pressed= KeyPad(&KP);
				if(pressed == '=') break;
				array[count]=pressed;
				Lcd_VoidInit(&LCD1);
				Lcd_VoidGoXY(&LCD1,0,0);
				Lcd_VoidSendString(array,&LCD1);
			}
			Count_Seconds = ((array[7] -48) + (10 * (array[6] -48))) + (((array[4] -48) + (10 * (array[3] -48))) * 60) + (((array[1] -48)* 3600 + (36000 * (array[0] -48))));
			Set_Bit(SREG_REG,7);
			Lcd_VoidInit(&LCD1);
			Lcd_VoidGoXY(&LCD1,0,0);
			Lcd_VoidSendString(array,&LCD1);
			TIMER2_voidSetCallBachFn(&StopWatch);
		}
		else if(pressed == '%')
		{
			Clr_Bit(SREG_REG,7);
			Lcd_VoidInit(&LCD1);
			Lcd_VoidGoXY(&LCD1,0,0);
			Lcd_VoidSendString("Enter The Mode",&LCD1);
			_delay_ms(500);

		}
		else
		{
			Clr_Bit(SREG_REG,7);
			Lcd_VoidInit(&LCD1);
			Lcd_VoidSendString("Try again",&LCD1);
			_delay_ms(1000);
			Lcd_VoidInit(&LCD1);
			Lcd_VoidGoXY(&LCD1,0,0);
			Lcd_VoidSendString("Enter The Mode",&LCD1);
			_delay_ms(500);
		}

	}


}

void StopWatch(void)
{
	static u32 Count_OC;
	Count_OC++;
	if(Count_OC == 125)
	{
		Count_OC=0;
		Lcd_VoidGoXY(&LCD1,0,0);
		Count_Seconds--;
		if(Count_Seconds==86400)
		{
			Count_Seconds=0;
		}

		u32 seconds,minutes,hours;

		seconds= Count_Seconds % 60 ;
		array[7]= (seconds %10) + '0';
		array[6]= (seconds /10) + '0';

		minutes = (Count_Seconds/60) % 60 ;
		array[4]= (minutes %10) + '0';
		array[3]= (minutes /10) + '0';

		hours= (Count_Seconds/3600) ;
		array[1]= (hours %10) + '0';
		array[0]= (hours /10) + '0';

		Lcd_VoidSendString(array,&LCD1);
	}

}
void DigitalWatch(void)
{
	static u32 Counter_OC,Counter_Seconds;
	Counter_OC++;

	if(Counter_OC == 125)
	{
		Counter_OC=0;
		Lcd_VoidGoXY(&LCD1,0,0);
		Counter_Seconds++;
		if(Counter_Seconds==86400)
		{
			Counter_Seconds=0;
		}
		u32 Seconds,Minutes,Hours;

		Seconds= Counter_Seconds % 60 ;
		array[7]= (Seconds %10) + '0';
		array[6]= (Seconds /10) + '0';

		Minutes = (Counter_Seconds/60) % 60 ;
		array[4]= (Minutes %10) + '0';
		array[3]= (Minutes /10) + '0';

		Hours= (Counter_Seconds/3600) ;
		array[1]= (Hours %10) + '0';
		array[0]= (Hours /10) + '0';

		Lcd_VoidSendString(array,&LCD1);

	}

}
