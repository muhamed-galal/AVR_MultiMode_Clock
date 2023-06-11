/*
 * EXTI_interface.h
 *
 *  Created on: Apr 16, 2023
 *      Author: Muham
 */

#ifndef MCAL_EXTI_EXTI_INTERFACE_H_
#define MCAL_EXTI_EXTI_INTERFACE_H_

#define  	LOW_LEVEL		1
#define 	ON_CHANGE		2
#define  	FALLING_EDGE	3
#define		RISING_EDGE		4

#define INT0	1
#define INT1	2
#define INT2	3

void EXTI_voidInt0Init(void);

void EXTI_voidInt1Init(void);

void EXTI_voidInt2Init(void);


/* Description: A function to set the required sense control of INT0 using postbuild connfiguration
 * Input: Copy_u8Sense , Options are 1- LOW_LEVEL
  									 2- ON_CHANGE
  									 3- FALLING_EDGE
  									 4- RISING_EDGE
   Output: Error status with type u8
 */
u8 EXTI_u8Int0SetSenseControl(u8 Copy_u8Sense);

u8 EXTI_u8Int1SetSenseControl(u8 Copy_u8Sense);

u8 EXTI_u8Int2SetSenseControl(u8 Copy_u8Sense);

u8 EXTI_u8IntEnable(u8 Copy_u8Int);

u8 EXTI_u8IntDisable(u8 Copy_u8Int);

u8 EXTI_u8Int0SetCallBack(void(*Copy_pvInt0Func)(void));

u8 EXTI_u8Int1SetCallBack(void(*Copy_pvInt1Func)(void));

u8 EXTI_u8Int2SetCallBack(void(*Copy_pvInt2Func)(void));


#endif /* MCAL_EXTI_EXTI_INTERFACE_H_ */
