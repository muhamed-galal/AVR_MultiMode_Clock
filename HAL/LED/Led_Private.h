/*
 * Led_Private.h
 *
 *  Created on: Mar 24, 2023
 *      Author: hisha
 */

#ifndef HAL_LED_LED_PRIVATE_H_
#define HAL_LED_LED_PRIVATE_H_

typedef enum
{
Led_TurnOn_Error,
Led_NoError,
Led_TurnOff_Error,
Led_ValueError,
Led_DirectionError,
Led_Connection_Error
}LedErrState;

typedef enum {
	Source_Connection ,
	Sink_Connection

}Led_ConnectionType;

#endif /* HAL_LED_LED_PRIVATE_H_ */
