/*
 * ADC_Register.h
 *
 *  Created on: Apr 4, 2023
 *      Author: Muham
 */

#ifndef MCAL_ADC_ADC_REGISTER_H_
#define MCAL_ADC_ADC_REGISTER_H_

 #define ADMUX				*((volatile u8*)0x27)  		   // ADC_mlutiplexer Selection Register
 #define ADMUX_REFS1		    7				 		   // Reference Selection bit 1
 #define ADMUX_REFS0		    6				 		   // Reference Selection bit 0
 #define ADMUX_ADLAR		    5				           // ADC left adjust result

 #define  ADCSRA			*((volatile u8*)0x26)		   // ADC control and status register
 #define  ADCSRA_ADEN			7                          // ADC enable
 #define  ADCSRA_ADSC			6                          // Start conversion
 #define  ADCSRA_ADATE			5                          // Auto trigger enable
 #define  ADCSRA_ADIF			4                          // Interrupt flag
 #define  ADCSRA_ADIE			3                          // Interrupt enable
 #define  ADCSRA_ADPS2			2                          // Prescaler bit 2
 #define  ADCSRA_ADPS1			1	                       // Prescaler bit 1
 #define  ADCSRA_ADPS0			0                          // Prescaler bit 0

 #define ADCH				*((volatile u8*)0x25)		   // ADC high register
 #define ADCL				*((volatile u8*)0x24)		   // ADC low register

 #define ADC 				*((volatile u16*)0x24)

#define SREG_REG     		(*(volatile u8*)0x5F)

#endif /* MCAL_ADC_ADC_REGISTER_H_ */
