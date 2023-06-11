/*
 * Stepper_Private.h
 *
 *  Created on: Mar 28, 2023
 *      Author: hisha
 */

#ifndef HAL_STEPPER_MOTOR_STEPPER_PRIVATE_H_
#define HAL_STEPPER_MOTOR_STEPPER_PRIVATE_H_



typedef enum
{
	FullStep=4,
	HalfStep=8
}Steper_StepType ;

typedef enum
{
	CW,
	CCW
}Stper_Direction ;


typedef enum
{
	SteperNoError,
	SteperDirectionpinError,
	SteperDirectionTypeError,
	SteperTypeStepError,
}StErrState;
typedef struct
{
	DIO_GroupNumber Stper_Group;
	DIO_PinNumber   Stper_Blue;
	DIO_PinNumber   Stper_Pink;
	DIO_PinNumber   Stper_Yellow;
	DIO_PinNumber   Stper_Orange;
	Steper_StepType  TypesOfStpe ;
	Stper_Direction  Direction_type ;

}Stper_info ;


#endif /* HAL_STEPPER_MOTOR_STEPPER_PRIVATE_H_ */
