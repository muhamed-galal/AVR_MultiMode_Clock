/*
 * Timer2_Programme.c
 *
 *  Created on: Apr 1, 2023
 *      Author: MIX
 */
#include"Timer2_Interface.h"

void (*ptr_fn4)(void)=Null;

void TIMER2_voidInit(void)
{
#if TIMER_PRESCALING==TIMER_PRESCALING_NO_CLOCK
	TCCR2_REG&=~(7<<0);
/*Clr_Bit(TCCR2_REG,0);
Clr_Bit(TCCR2_REG,1);
Clr_Bit(TCCR2_REG,2);*/
#elif TIMER_PRESCALING==TIMER_PRESCALING_NO_SCALE
Set_Bit(TCCR2_REG,0);
Clr_Bit(TCCR2_REG,1);
Clr_Bit(TCCR2_REG,2);
#elif TIMER_PRESCALING==TIMER_PRESCALING_8
//TCCR2_REG &=~(7<<0);
//TCCR2_REG |= (2<<0);
Clr_Bit(TCCR2_REG,0);
Set_Bit(TCCR2_REG,1);
Clr_Bit(TCCR2_REG,2);
#elif TIMER_PRESCALING==TIMER_PRESCALING_32
TCCR2_REG&=~(7<<0);
TCCR2_REG|=(3<<0);
/*Set_Bit(TCCR2_REG,0);
Set_Bit(TCCR2_REG,1);
Clr_Bit(TCCR2_REG,2);*/
#elif TIMER_PRESCALING==TIMER_PRESCALING_64
Clr_Bit(TCCR2_REG,0);
Clr_Bit(TCCR2_REG,1);
Set_Bit(TCCR2_REG,2);
#elif TIMER_PRESCALING==TIMER_PRESCALING_128
Set_Bit(TCCR2_REG,0);
Clr_Bit(TCCR2_REG,1);
Set_Bit(TCCR2_REG,2);
#elif TIMER_PRESCALING==TIMER_PRESCALING_256
Clr_Bit(TCCR2_REG,0);
Set_Bit(TCCR2_REG,1);
Set_Bit(TCCR2_REG,2);
#elif TIMER_PRESCALING==TIMER_PRESCALING_1024
Set_Bit(TCCR2_REG,0);
Set_Bit(TCCR2_REG,1);
Set_Bit(TCCR2_REG,2);
#endif

#if TIMER_MODE==TIMER_NORMAL_MODE
Clr_Bit(TCCR2_REG,3);
Clr_Bit(TCCR2_REG,6);
#elif TIMER_MODE==TIMER_PWM_MODE
Set_Bit(TCCR2_REG,6);
Clr_Bit(TCCR2_REG,3);
#elif TIMER_MODE==TIMER_CTC_MODE
Clr_Bit(TCCR2_REG,6);
Set_Bit(TCCR2_REG,3);
Clr_Bit(TCCR2_REG,5);
Set_Bit(TCCR2_REG,4);
#elif TIMER_MODE==TIMER_FAST_PWM_MODE
Set_Bit(TCCR2_REG,3);
Set_Bit(TCCR2_REG,6);
Clr_Bit(TCCR2_REG,4);	// non inverting pwm
Set_Bit(TCCR2_REG,5);	// non inverting pwm

#endif

#if TIMER_OPERATION==TIMER_INTURRUPT
Set_Bit(TIMSK_REG,7);						//PIE  pin7 for OC flag pin6 for of flag
Set_Bit(SREG_REG,7);    					//GIE
#elif	TIMER_OPERATION==TIMER_INTURRUPT && TIMER_MODE==TIMER_NORMAL_MODE
Set_Bit(TIMSK_REG,6);
Set_Bit(SREG_REG,7);
#endif
}
#if TIMER_OPERATION==TIMER_INTURRUPT && TIMER_MODE==TIMER_NORMAL_MODE
void TIMER2_voidSetCallBachFn(void(*ptr)(void))
{
	ptr_fn4=ptr;
}
void __vector_5(void)__attribute__((signal));
void __vector_5(void)
{
	if(ptr_fn4!=Null)
		{
			ptr_fn4();
		}
}
#elif TIMER_OPERATION==TIMER_INTURRUPT
void TIMER2_voidSetCallBachFn(void(*ptr)(void))
{
	ptr_fn4=ptr;
}
void __vector_4(void)__attribute__((signal));
void __vector_4(void)
{
	if(ptr_fn4!=Null)
		{
			ptr_fn4();
		}
}
#endif
