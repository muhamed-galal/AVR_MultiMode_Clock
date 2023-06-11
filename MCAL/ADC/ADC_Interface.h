/*
 * ADC_Interface.h
 *
 *  Created on: Apr 4, 2023
 *      Author: Muham
 */

#ifndef MCAL_ADC_ADC_INTERFACE_H_
#define MCAL_ADC_ADC_INTERFACE_H_

void ADC_voidInit(void);

u8 ADC_u8GetChannelReading(u8 Copy_u8Channel);

void ADC_CallbackFn(void (*ptr)(void));


#endif /* MCAL_ADC_ADC_INTERFACE_H_ */
