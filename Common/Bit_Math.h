/*
 * Bit_Math.h
 *
 *  Created on: Mar 22, 2023
 *      Author: Muham
 */

#ifndef COMMON_BIT_MATH_H_
#define COMMON_BIT_MATH_H_

#define Set_Bit(Reg,Bit) 	Reg|=(1<<Bit)
#define Clr_Bit(Reg,Bit)	Reg&=~(1<<Bit)
#define Tog_Bit(Reg,Bit)	Reg^=(1<<Bit)
#define Get_Bit(Reg,Bit)	(Reg>>Bit)&1


#endif /* COMMON_BIT_MATH_H_ */
