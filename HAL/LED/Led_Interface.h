/*
 * Led_Interface.h
 *
 *  Created on: Mar 24, 2023
 *      Author: hisha
 */

#ifndef HAL_LED_LED_INTERFACE_H_
#define HAL_LED_LED_INTERFACE_H_
#include "Led_Configuration.h"
#include "Led_Private.h"

LedErrState	Led_LedErrStateTurnOn(Led_info *Led) ;
LedErrState	Led_LedErrStateTurnOff(Led_info *Led) ;

#endif /* HAL_LED_LED_INTERFACE_H_ */
