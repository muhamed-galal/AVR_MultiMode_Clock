/*
 * Stepper_Interface.h
 *
 *  Created on: Mar 28, 2023
 *      Author: hisha
 */

#ifndef HAL_STEPPER_MOTOR_STEPPER_INTERFACE_H_
#define HAL_STEPPER_MOTOR_STEPPER_INTERFACE_H_

#include "../Stepper_Motor/Stepper_Config.h"
#include "../Stepper_Motor/Stepper_Private.h"
/*Select the Direction for Pin*/
StErrState  Stepper_StErrStateInit(Stper_info * Motor1);

StErrState  Stepper_StErrStateControlMotorRotate(Stper_info * Motor1 , u16 Copy_Degree);

static void  Stepper_voidCWFullSteps(Stper_info * Motor1);
static void  Stepper_voidCCWFullSteps(Stper_info * Motor1);
static void  Stepper_voidCWHalfSteps(Stper_info * Motor1);
static void  Stepper_voidCCWHalfSteps(Stper_info * Motor1);

#endif /* HAL_STEPPER_MOTOR_STEPPER_INTERFACE_H_ */
