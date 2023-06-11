
/***********************************************************************************
 * Author 	  : Hesham Ahmed													   *
 * Date   	  : 30/4/2022														   *
 * File name  : LCD_REGISTER.h											 		   *
 * Description: This File Contain The Address for LCD Address	                   *
 * Version    :  01																   *
 ***********************************************************************************/

#ifndef HAL_LCD_HEADER_LCD_REGISTER_H_
#define HAL_LCD_HEADER_LCD_REGISTER_H_

#define LCD_FirstLine        0x00
#define LCD_SecondLine       0x40


/*Command Line */
/*Set CG RAM Address*/
#define  LCD_SetAddressCGRAM      0x40
/*Set DDRAM Address*/
#define  LCD_SetAddressDDRAM      0x80


#endif /* HAL_LCD_HEADER_LCD_REGISTER_H_ */
