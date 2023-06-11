/*
 * KEY_PAD_Pcfg.h
 *
 *  Created on: Oct 24, 2022
 *      Author: abdullah
 */

#ifndef HAL_KEY_PAD_KEY_PAD_PCFG_H_
#define HAL_KEY_PAD_KEY_PAD_PCFG_H_

#include"../../Common/std_types.h"
#include"../../MCAL/DIO/DIO_Interface.h"

#define KEY_PAD_ROWSIZE  4
#define KEY_PAD_COLSIZE  4

#define TRUE             1
#define FALSE            0



u8 KEY_PAD_values[KEY_PAD_ROWSIZE][KEY_PAD_COLSIZE]=
{		//col0 col1 col2 col3
		{'7','8','9','/'},//row0
		{'4','5','6','*'},//row1
		{'1','2','3','-'},//row2
		{'.','0','=','+'}//row3   //s for select
};

/*typedef struct{
	// Rows
	DIO_GroupNumber Row0_Group;
	DIO_GroupNumber Row1_Group;
	DIO_GroupNumber Row2_Group;
	DIO_GroupNumber Row3_Group;
	DIO_PinNumber Row0_Pin;
	DIO_PinNumber Row1_Pin;
	DIO_PinNumber Row2_Pin;
	DIO_PinNumber Row3_Pin;
	//Columns
	DIO_GroupNumber Column0_Group;
	DIO_GroupNumber Column1_Group;
	DIO_GroupNumber Column2_Group;
	DIO_GroupNumber Column3_Group;
	DIO_PinNumber Column0_Pin;
	DIO_PinNumber Column1_Pin;
	DIO_PinNumber Column2_Pin;
	DIO_PinNumber Column3_Pin;

}KeyPad_Info;*/

//in case I dont have a complete port for the KEYPAD
//WE CREATE A 2D ARRAY TO PLACE THE PORT AND PIN FOR EACH SWITCH

#define KEY_PAD_ROW0  {DIO_GroupC,Pin0}
#define KEY_PAD_ROW1  {DIO_GroupC,Pin1}
#define KEY_PAD_ROW2  {DIO_GroupC,Pin2}
#define KEY_PAD_ROW3  {DIO_GroupC,Pin3}
#define KEY_PAD_COL0  {DIO_GroupC,Pin4}
#define KEY_PAD_COL1  {DIO_GroupC,Pin5}
#define KEY_PAD_COL2  {DIO_GroupC,Pin6}
#define KEY_PAD_COL3  {DIO_GroupC,Pin7}


#define KEY_PAD_ARRAY  {KEY_PAD_ROW0,\
		KEY_PAD_ROW1,\
		KEY_PAD_ROW2,\
		KEY_PAD_ROW3,\
		KEY_PAD_COL0,\
		KEY_PAD_COL1,\
		KEY_PAD_COL2,\
		KEY_PAD_COL3}\



#endif /* HAL_KEY_PAD_KEY_PAD_PCFG_H_ */
