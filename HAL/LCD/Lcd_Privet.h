/***********************************************************************************
 * Author 	  : Hesham Ahmed													   *
 * Date   	  : 30/4/2022														   *
 * File name  : LCD_Privet.h											 		   *
 * Description: This File contain Some Macro's For Command Line for Lcd		       *
 * Version    :  01																   *
 ***********************************************************************************/


#ifndef LCD_PRIVET_H_
#define LCD_PRIVET_H_
/*------------------------------------------------------------------------------------------*/
/*
Bit	        Settings
I/D	        0 = Decrement cursor position	   1 = Increment cursor position
S	        0 = No display shift			   1 = Display shift
D	        0 = Display off	                   1 = Display on
C	        0 = Cursor off					   1 = Cursor on
B	        0 = Cursor blink off		       1 = Cursor blink on
S/C	        0 = Move cursor                    1 = Shift display
R/L	        0 = Shift left			           1 = Shift right
DL	        0 = 4-bit interface	               1 = 8-bit interface
N	        0 = 1/8 or 1/11 Duty (1 line)	   1 = 1/16 Duty (2 lines)
F	        0 = 5x7 dots		               1 = 5x10 dots
BF	        0 = Can accept instruction	       1 = Internal operation in progress
*/
/*------------------------------------------------------------------------------------------*/
/*Clear Display*/
#define LCD_ClearDisplay     0x01

/*--------------------------------------------------------------------------------------------------------------------------------------------------*/
/*Return Home*/
#define LCD_ReturnHome       0x02
/*--------------------------------------------------------------------------------------------------------------------------------------------------*/
/*Entry Mode Set*/
#define LCD_EntryMode2       0x06 //  S = 0 (no screen shifting) & I/D = 1 (Increment cursor position)   /*Increment cursor (shift cursor to right)*/
/*--------------------------------------------------------------------------------------------------------------------------------------------------*/

/*Display OFF*/
#define LCD_DisplayOFF   0x08  // D = 0    C = 0    B = 0    The Display is Off so Will Cursor is off  And Blinking is OFF
#define LCD_DisplayON    0x0C  // D = 1    C = 0    B = 0    The Display is On But the Cursor is OFF so the Blinking is OFF
#define LCD_CursorON     0x0E
/*--------------------------------------------------------------------------------------------------------------------------------------------------*/
/*Function Set
RS  R/W DB7 DB6 DB5 DB4 DB3 DB2 DB1 DB0
=== === === === === === === === === ===
 0   0   0   0   1   DL  N   F   *   *
*/

#define  LCD_Set4Bit1Line5x8         0x20     // the Data Will Send by 4 bit and the Number of line is 1 and the Font is 5x8
#define  LCD_Set4Bit1Line5x11        0x24     // the Data Will Send by 4 bit and the Number of line is 1 and the Font is 5x11
#define  LCD_Set4Bit2Line5x8	     0x28     // the Data Will Send by 4 bit and the Number of line is 2 and the Font is 5x8
#define  LCD_Set4Bit2Line5x11        0x2C     // the Data Will Send by 4 bit and the Number of line is 2 and the Font is 5x11
#define  LCD_Reset		             0x30     // the Data Will Send by 8 bit and the Number of line is 1 and the Font is 5x8
#define  LCD_Set8Bit1Line5x11    	 0x34     // the Data Will Send by 8 bit and the Number of line is 1 and the Font is 5x11
#define  LCD_Set8Bit2Line5x8     	 0x38     // the Data Will Send by 8 bit and the Number of line is 2 and the Font is 5x8
#define  LCD_Set8Bit2Line5x11    	 0x3C     // the Data Will Send by 8 bit and the Number of line is 2 and the Font is 5x11
/*--------------------------------------------------------------------------------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------------------------------*/



/*************************************************************************************
 *                                Declaring Options                                  *
 *************************************************************************************/

/*
 * Options for the Pin Direction/Value of the LCD
 */

#define LCD_PinLOW          	LOW
#define LCD_PinHIGH         	HIGH
#define LCD_PinINPUT        	INPUT
#define LCD_PinOUTPUT       	OUTPUT
#define LCD_PORTMAXVALUE    	0xFF
#define LCD_CGRAMPatternSize    8



typedef struct
{
DIO_GroupNumber RS_Group ;
DIO_GroupNumber RW_Group ;
DIO_GroupNumber E_Group  ;
DIO_PinNumber   RS_Pin ;
DIO_PinNumber   RW_Pin ;
DIO_PinNumber   E_Pin ;
DIO_GroupNumber Data_Group ;
}Lcd_Info ;

typedef enum
{
	line0,
	line1,
	Coloum0=0,
	Coloum1,
	Coloum2,
	Coloum3,
	Coloum4,
	Coloum5,
	Coloum6,
	Coloum7,
	Coloum8,
	Coloum9,
	Coloum10,
	Coloum11,
	Coloum12,
	Coloum13,
	Coloum14,
	Coloum15,

}Lines;



#endif /* LCD_PRIVET_H_ */
