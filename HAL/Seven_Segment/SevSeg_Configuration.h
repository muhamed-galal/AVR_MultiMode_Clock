/*
 * SevSeg_Configuration.h
 *
 *  Created on: Mar 23, 2023
 *      Author: hisha
 */

#ifndef HAL_SEVEN_SEGMENT_SEVSEG_CONFIGURATION_H_
#define HAL_SEVEN_SEGMENT_SEVSEG_CONFIGURATION_H_
typedef struct
{
	SevSeg_Type SevenSeg_Type ;
	DIO_GroupNumber SevSeg_Group      ;
	DIO_GroupNumber SevSeg_EnablePort ;
	DIO_PinNumber SevSeg_EnablePin  ;
}SevSeg_info;


#endif /* HAL_SEVEN_SEGMENT_SEVSEG_CONFIGURATION_H_ */
