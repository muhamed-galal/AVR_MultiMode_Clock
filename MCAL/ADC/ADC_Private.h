/*
 * ADC_Private.h
 *
 *  Created on: Apr 4, 2023
 *      Author: Muham
 */

#ifndef MCAL_ADC_ADC_PRIVATE_H_
#define MCAL_ADC_ADC_PRIVATE_H_

#define DIV_By_2		0
#define DIV_By_4  		2
#define DIV_By_8  		3
#define DIV_By_16 		4
#define DIV_By_32 		5
#define DIV_By_64 		6
#define DIV_By_128		7

#define EXT_Vref		0
#define Vcc_Vref		1
#define Internal_Vref	3

#define Left_Adjust		1
#define Right_Adjust 	0

#define Reading_8bit	0
#define Reading_10bit	1

#define ADC_Polling 	0
#define	ADC_Interrupt	1


#define ADC_Prescaler_Mask		0b11111000
#define ADC_MUX_Mask			0b11100000
#define ADC_Ref_Mask			0b00111111





#endif /* MCAL_ADC_ADC_PRIVATE_H_ */
