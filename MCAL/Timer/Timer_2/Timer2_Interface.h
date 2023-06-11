/*
 * Timer2_Interface.h
 *
 *  Created on: Apr 1, 2023
 *      Author: MIX
 */

#ifndef MCAL_TIMER_TIMER_2_TIMER2_INTERFACE_H_
#define MCAL_TIMER_TIMER_2_TIMER2_INTERFACE_H_
#include "defintion.h"
#include "std_types.h"
#include "Bit_Math.h"
#include "Timer2_Private.h"
#include "Timer2_Configuration.h"


void TIMER2_voidInit(void);

void TIMER2_voidSetCallBachFn(void(*ptr)(void));




#endif /* MCAL_TIMER_TIMER_2_TIMER2_INTERFACE_H_ */
