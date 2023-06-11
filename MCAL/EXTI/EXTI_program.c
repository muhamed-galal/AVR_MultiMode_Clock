/*
 * EXTI_program.c
 *
 *  Created on: Apr 16, 2023
 *      Author: Muham
 */

#include "std_types.h"
#include "Bit_Math.h"
#include "defintion.h"

#include "EXTI_config.h"
#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_register.h"

/* global pointer to functionsn to hold INT0 ISR adress */

void (*EXTI_pvInt0Func)(void) = Null;
void (*EXTI_pvInt1Func)(void) = Null;
void (*EXTI_pvInt2Func)(void) = Null;


void EXTI_voidInt0Init(void)
{
	/*1- check sense control*/
#if 	INT0_SENSE == LOW_LEVEL

	Clr_Bit(MCUCR,MCUCR_ISC01);
	Clr_Bit(MCUCR,MCUCR_ISC00);

#elif 	INT0_SENSE == ON_CHANGE

	Set_Bit(MCUCR,MCUCR_ISC00);
	Clr_Bit(MCUCR,MCUCR_ISC01);

#elif	INT0_SENSE == FALLING_EDGE

	Set_Bit(MCUCR,MCUCR_ISC01);
	Clr_Bit(MCUCR,MCUCR_ISC00);

#elif	INT0_SENSE == RISING_EDGE

	Set_Bit(MCUCR,MCUCR_ISC01);
	Set_Bit(MCUCR,MCUCR_ISC00);

#else

#error "Wrong INTO_SENSE configuration optin"

#endif

	/* check PIE initial state */
#if INT0_INITIAL_STATE == ENABLED

	Set_Bit(GICR,GICR_INT0);

#elif INT0_INITIAL_STATE == DISABLED

	Clr_Bit(GICR,GICR_INT0);

#else

#error "Wrong INT0_INITIAL_STATE configuration optin"

#endif
}

void EXTI_voidInt1Init(void)
{
	/*1- check sense control*/
#if 	INT1_SENSE == LOW_LEVEL

	Clr_Bit(MCUCR,MCUCR_ISC11);
	Clr_Bit(MCUCR,MCUCR_ISC10);

#elif 	INT1_SENSE == ON_CHANGE

	Set_Bit(MCUCR,MCUCR_ISC10);
	Clr_Bit(MCUCR,MCUCR_ISC11);

#elif	INT1_SENSE == FALLING_EDGE

	Set_Bit(MCUCR,MCUCR_ISC11);
	Clr_Bit(MCUCR,MCUCR_ISC10);

#elif	INT1_SENSE == RISING_EDGE

	Set_Bit(MCUCR,MCUCR_ISC11);
	Set_Bit(MCUCR,MCUCR_ISC10);

#else

#error "Wrong INT1_SENSE configuration optin"

#endif

	/* check PIE initial state */
#if INT1_INITIAL_STATE == ENABLED

	Set_Bit(GICR,GICR_INT1);

#elif INT1_INITIAL_STATE == DISABLED

	Clr_Bit(GICR,GICR_INT1);

#else

#error "Wrong INT0_INITIAL_STATE configuration optin"

#endif
}

void EXTI_voidInt2Init(void)
{
	/*1- check sense control*/
#if 	INT2_SENSE == FALLING_EDGE

	Clr_Bit(MCUCSR,MCUCSR_INT2);

#elif	INT2_SENSE == RISING_EDGE

	Set_Bit(MCUCSR,MCUCSR_INT2);

#else

#error "Wrong INT2_SENSE configuration optin"

#endif

	/* check PIE initial state */
#if INT2_INITIAL_STATE == ENABLED

	Set_Bit(GICR,GICR_INT2);

#elif INT2_INITIAL_STATE == DISABLED

	Clr_Bit(GICR,GICR_INT2);

#else

#error "Wrong INT0_INITIAL_STATE configuration optin"

#endif

}

/* EXTI Postbuild Configuratuin implementation*/

u8 EXTI_u8Int0SetSenseControl(u8 Copy_u8Sense)
{
	u8 Local_u8ErrorState = OK;
	switch (Copy_u8Sense)
	{

	case LOW_LEVEL:Clr_Bit(MCUCR,MCUCR_ISC01); Clr_Bit(MCUCR,MCUCR_ISC00); break;

	case ON_CHANGE:Set_Bit(MCUCR,MCUCR_ISC00); Clr_Bit(MCUCR,MCUCR_ISC01); break;

	case FALLING_EDGE:Set_Bit(MCUCR,MCUCR_ISC01); Clr_Bit(MCUCR,MCUCR_ISC00); break;

	case RISING_EDGE:Set_Bit(MCUCR,MCUCR_ISC01); Set_Bit(MCUCR,MCUCR_ISC00); break;

	default:Local_u8ErrorState=NOK;

	}
	return Local_u8ErrorState;
}
u8 EXTI_u8Int1SetSenseControl(u8 Copy_u8Sense)
{
	u8 Local_u8ErrorState = OK;
	switch (Copy_u8Sense)
	{

	case LOW_LEVEL:Clr_Bit(MCUCR,MCUCR_ISC11); Clr_Bit(MCUCR,MCUCR_ISC10); break;

	case ON_CHANGE:Set_Bit(MCUCR,MCUCR_ISC10); Clr_Bit(MCUCR,MCUCR_ISC11); break;

	case FALLING_EDGE:Set_Bit(MCUCR,MCUCR_ISC11); Clr_Bit(MCUCR,MCUCR_ISC10); break;

	case RISING_EDGE:Set_Bit(MCUCR,MCUCR_ISC11); Set_Bit(MCUCR,MCUCR_ISC10); break;

	default:Local_u8ErrorState=NOK;

	}
	return Local_u8ErrorState;
}

u8 EXTI_u8Int2SetSenseControl(u8 Copy_u8Sense)
{
	u8 Local_u8ErrorState = OK;
	switch (Copy_u8Sense)
	{

	case FALLING_EDGE:Clr_Bit(MCUCSR,MCUCSR_INT2); break;

	case RISING_EDGE:Set_Bit(MCUCSR,MCUCSR_INT2); break;

	default:Local_u8ErrorState=NOK;

	}
	return Local_u8ErrorState;

}
u8 EXTI_u8IntEnable(u8 Copy_u8Int)
{
	u8 Local_u8ErrorState = OK;
	switch (Copy_u8Int)
	{

	case INT0:	Set_Bit(GICR,GICR_INT0); break;

	case INT1:	Set_Bit(GICR,GICR_INT1); break;

	case INT2:	Set_Bit(GICR,GICR_INT2); break;

	default:Local_u8ErrorState=NOK;

	}

	return Local_u8ErrorState;
}

u8 EXTI_u8IntDisable(u8 Copy_u8Int)
{
	u8 Local_u8ErrorState = OK;
	switch (Copy_u8Int)
	{

	case INT0:	Clr_Bit(GICR,GICR_INT0); break;

	case INT1:	Clr_Bit(GICR,GICR_INT1); break;

	case INT2:	Clr_Bit(GICR,GICR_INT2); break;

	default:Local_u8ErrorState=NOK;

	}

	return Local_u8ErrorState;

}

u8 EXTI_u8Int0SetCallBack(void(*Copy_pvInt0Func)(void))
{
	u8 Local_u8ErrorStatus=OK;

	if(Copy_pvInt0Func != Null)
	{
		EXTI_pvInt0Func = Copy_pvInt0Func;
	}
	else
	{
		// null pointer
	}

	return Local_u8ErrorStatus;
}

void __vector_1 (void)__attribute__((signal));
void __vector_1 (void)
{
	EXTI_pvInt0Func();
}

u8 EXTI_u8Int1SetCallBack(void(*Copy_pvInt1Func)(void))
{
	u8 Local_u8ErrorStatus=OK;

	if(Copy_pvInt1Func != Null)
	{
		EXTI_pvInt1Func = Copy_pvInt1Func;
	}
	else
	{
		// null pointer
	}

	return Local_u8ErrorStatus;
}

void __vector_2 (void)__attribute__((signal));
void __vector_2 (void)
{
	EXTI_pvInt1Func();
}

u8 EXTI_u8Int2SetCallBack(void(*Copy_pvInt2Func)(void))
{
	u8 Local_u8ErrorStatus=OK;

	if(Copy_pvInt2Func != Null)
	{
		EXTI_pvInt0Func = Copy_pvInt2Func;
	}
	else
	{
		// null pointer
	}

	return Local_u8ErrorStatus;
}
void __vector_3 (void)__attribute__((signal));
void __vector_3 (void)
{
	EXTI_pvInt2Func();
}





