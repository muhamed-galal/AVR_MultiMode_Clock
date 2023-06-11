/*
 * KPD_Config.h
 *
 *  Created on: Mar 27, 2023
 *      Author: Adel
 */

#ifndef HAL_KEYPAD_KPD_CONFIG_H_
#define HAL_KEYPAD_KPD_CONFIG_H_

typedef struct
{	/*Rows*/
	DIO_GroupNumber	R0_groub_num;
	DIO_PinNumber 	R0_pin_num;
	DIO_GroupNumber	R1_groub_num;
	DIO_PinNumber 	R1_pin_num;
	DIO_GroupNumber	R2_groub_num;
	DIO_PinNumber 	R2_pin_num;
	DIO_GroupNumber	R3_groub_num;
	DIO_PinNumber 	R3_pin_num;
	/*Coloums*/
	DIO_GroupNumber	C0_groub_num;
	DIO_PinNumber 	C0_pin_num;
	DIO_GroupNumber	C1_groub_num;
	DIO_PinNumber 	C1_pin_num;
	DIO_GroupNumber	C2_groub_num;
	DIO_PinNumber 	C2_pin_num;
	DIO_GroupNumber	C3_groub_num;
	DIO_PinNumber 	C3_pin_num;
}KPD_INFO;


#endif /* HAL_KEYPAD_KPD_CONFIG_H_ */
