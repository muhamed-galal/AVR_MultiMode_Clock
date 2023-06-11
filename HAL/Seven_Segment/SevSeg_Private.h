/*
 * SevSeg_Private.h
 *
 *  Created on: Mar 23, 2023
 *      Author: hisha
 */

#ifndef HAL_SEVEN_SEGMENT_SEVSEG_PRIVATE_H_
#define HAL_SEVEN_SEGMENT_SEVSEG_PRIVATE_H_

#define SevSeg_ArrSize  10
/*Cathode -> Led On if write One*/

#define SevSegCA_0      0x3F
#define SevSegCA_1      0x06
#define SevSegCA_2      0x5B
#define SevSegCA_3      0x4F
#define SevSegCA_4      0x66
#define SevSegCA_5      0x6D
#define SevSegCA_6      0x7D
#define SevSegCA_7      0x07
#define SevSegCA_8      0x7F
#define SevSegCA_9      0x6F

/*Anode -> Led On if write Zero*/

#define SevSegAN_0      ~(0x3F)
#define SevSegAN_1      ~(0x06)
#define SevSegAN_2      ~(0x5B)
#define SevSegAN_3      ~(0x4F)
#define SevSegAN_4      ~(0x66)
#define SevSegAN_5      ~(0x6D)
#define SevSegAN_6      ~(0x7D)
#define SevSegAN_7      ~(0x07)
#define SevSegAN_8      ~(0x7F)
#define SevSegAN_9      ~(0x6F)

typedef enum
{
SevSeg_NoError,
SevSegTypeError,
SevSeg_ValueError,
SevSeg_RangeValueError,
SevSeg_MaxValueError,
SevSegDirectionError
}SevErrState;


typedef enum
{
	Cathode,
	Anode
}SevSeg_Type;





#endif /* HAL_SEVEN_SEGMENT_SEVSEG_PRIVATE_H_ */
