/*
 * ADC_Program.c
 *
 *  Created on: Apr 4, 2023
 *      Author: Muham
 */

#include "std_types.h"
#include "Bit_Math.h"
#include "defintion.h"

#include "ADC_Config.h"
#include "ADC_Interface.h"
#include "ADC_Register.h"
#include "ADC_Private.h"

void (*Ptr_ADC)(void)=Null;


void ADC_voidInit(void)
{
#if ADC_Type == ADC_Interrupt

	Set_Bit(ADCSRA,ADCSRA_ADIE);	// Enable PIE

	Set_Bit(SREG_REG,7);			//	Enable GIE

#endif
#if 	ADC_Refernce == EXT_Vref

	// External Voltage as reference voltage

	ADMUX &= ADC_Ref_Mask;
	ADMUX |= ADC_Refernce<<6;

#elif	ADC_Refernce == Vcc_Vref

	// AVCC as reference voltage
	ADMUX &= ADC_Ref_Mask;
	ADMUX |= ADC_Refernce<<6;
	/*
	Set_Bit(ADMUX,ADMUX_REFS0);
	Clr_Bit(ADMUX,ADMUX_REFS1);

	 */
#elif	ADC_Refernce == Internal_Vref

	// Internal 2.65v as reference voltage
	ADMUX &= ADC_Ref_Mask;
	ADMUX |= ADC_Refernce<<6;

#endif

#if ADC_LR_Adjust == Left_Adjust

	// activate Left adjust result
	Set_Bit(ADMUX,ADMUX_ADLAR);

#elif ADC_LR_Adjust == Right_Adjust

	// activate Right adjust result
	Clr_Bit(ADMUX,ADMUX_ADLAR);

#endif

#if ADC_Prescaler == DIV_By_2
	// Set Prescaler to divide by 2
	ADCSRA &=ADC_Prescaler_Mask;
	ADCSRA |=ADC_Prescaler;

#elif ADC_Prescaler == DIV_By_4
	// Set Prescaler to divide by 4
	ADCSRA &=ADC_Prescaler_Mask;
	ADCSRA |=ADC_Prescaler;

#elif ADC_Prescaler == DIV_By_8
	// Set Prescaler to divide by 8
	ADCSRA &=ADC_Prescaler_Mask;
	ADCSRA |=ADC_Prescaler;

#elif ADC_Prescaler == DIV_By_16
	// Set Prescaler to divide by 16
	ADCSRA &=ADC_Prescaler_Mask;
	ADCSRA |=ADC_Prescaler;

#elif ADC_Prescaler == DIV_By_32
	// Set Prescaler to divide by 32
	ADCSRA &=ADC_Prescaler_Mask;
	ADCSRA |=ADC_Prescaler;

#elif ADC_Prescaler == DIV_By_64
	// Set Prescaler to divide by 64
	ADCSRA &=ADC_Prescaler_Mask;
	ADCSRA |=ADC_Prescaler;

#elif ADC_Prescaler == DIV_By_128

	// Set Prescaler to divide by 128
	ADCSRA &=ADC_Prescaler_Mask;
	ADCSRA |=ADC_Prescaler;
#endif

	// Enable ADC peripheral
	Set_Bit(ADCSRA,ADCSRA_ADEN);

}

u8 ADC_u8GetChannelReading(u8 Copy_u8Channel)
{
#if ADC_Type == ADC_Polling

#if ADC_Reading == Reading_10bit

	ADMUX &=ADC_MUX_Mask;

	// Set the required channel into MUX bits

	ADMUX |=Copy_u8Channel;

	// Start conversion
	Set_Bit(ADCSRA,ADCSRA_ADSC);

	// polling (busy waiting) until conversion complete flag is set
	while (Get_Bit(ADCSRA,ADCSRA_ADIF)==0);
	// clear the conversion complete flag
	Set_Bit(ADCSRA,ADCSRA_ADIF);

	//  return the reading
	return ADC;

#elif ADC_Reading == Reading_8bit

	// clear the MUX bits in ADMUX
	ADMUX &=ADC_MUX_Mask;
	// Set the required channel into MUX bits
	ADMUX |=Copy_u8Channel;
	// Start conversion
	Set_Bit(ADCSRA,ADCSRA_ADSC);

	// polling busy waiting until conversion complete flag is set
	while ((Get_Bit(ADCSRA,ADCSRA_ADIF))==0);
	// clear the conversion complete flag
	Set_Bit(ADCSRA,ADCSRA_ADIF);

	//  return the reading

	return ADCH;
#endif

#elif ADC_Type== ADC_Interrupt
#if ADC_Reading == Reading_10bit

	ADMUX &=ADC_MUX_Mask;

	// Set the required channel into MUX bits

	ADMUX |=Copy_u8Channel;

	// Start conversion
	Set_Bit(ADCSRA,ADCSRA_ADSC);

	// polling (busy waiting) until conversion complete flag is set
	while (Get_Bit(ADCSRA,ADCSRA_ADIF)==0);
	// clear the conversion complete flag
	Set_Bit(ADCSRA,ADCSRA_ADIF);

	//  return the reading
	return ADC;

#elif ADC_Reading == Reading_8bit

	// clear the MUX bits in ADMUX
	ADMUX &=ADC_MUX_Mask;
	// Set the required channel into MUX bits
	ADMUX |=Copy_u8Channel;
	// Start conversion
	Set_Bit(ADCSRA,ADCSRA_ADSC);



	// polling busy waiting until conversion complete flag is set
	while ((Get_Bit(ADCSRA,ADCSRA_ADIF))==0);
	// clear the conversion complete flag
	Set_Bit(ADCSRA,ADCSRA_ADIF);

	//  return the reading

	return ADCH;
#endif

#endif

}
void ADC_CallbackFn(void (*ptr)(void))
{
	Ptr_ADC=ptr;
}
void __vector_16(void)__attribute__((signal));
void __vector_16(void)
{
	if(Ptr_ADC != Null)
	{
		Ptr_ADC();
	}
}

