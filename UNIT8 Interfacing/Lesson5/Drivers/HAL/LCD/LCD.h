/*
 * LCD.h
 *
 *  Created on: Jul 10, 2021
 *      Author: Osama Mahmoud
 */

#ifndef HAL_LCD_LCD_H_
#define HAL_LCD_LCD_H_

#include "GPIO.h"

/**********************************     LCD Modes   **************************************************/
#define M_4BIT_SAMEPORT  0
#define M_8BIT           1

/*********************************   define LCD Mode       *******************************************/
#define LCD_MODE  M_8BIT

/*******************for 8 bit mode and 4 bit_sameport mode define the LCD port **********************/
#define LCD_DATA             GPIOA
#define LCD_CONTROL          GPIOA

/********************************* define control pins     *******************************************/
#define RS  PIN8
#define RW  PIN9
#define EN  PIN10

/******************************************************************************************************/

#define LCD_FUNCTION_8BIT_2LINES   					(0x38)
#define LCD_FUNCTION_4BIT_2LINES   					(0x28)
#define LCD_MOVE_DISP_RIGHT       					(0x1C)
#define LCD_MOVE_DISP_LEFT   						(0x18)
#define LCD_MOVE_CURSOR_RIGHT   					(0x14)
#define LCD_MOVE_CURSOR_LEFT 	  					(0x10)
#define LCD_DISP_OFF   								(0x08)
#define LCD_DISP_ON_CURSOR   						(0x0E)
#define LCD_DISP_ON_CURSOR_BLINK   					(0x0F)
#define LCD_DISP_ON_BLINK   						(0x0D)
#define LCD_DISP_ON   								(0x0C)
#define LCD_ENTRY_DEC   							(0x04)
#define LCD_ENTRY_DEC_SHIFT   						(0x05)
#define LCD_ENTRY_INC_   							(0x06)
#define LCD_ENTRY_INC_SHIFT   						(0x07)
#define LCD_BEGIN_AT_FIRST_ROW						(0x80)
#define LCD_BEGIN_AT_SECOND_ROW						(0xC0)
#define LCD_CLEAR_SCREEN							(0x01)
#define LCD_ENTRY_MODE								(0x06)

/*******************************************************************************************************/

extern void LCD_Init(void);
extern void LCD_WriteChar(u8 Character);
extern void LCD_WriteSentence(u8 *PtrSentance);
extern void LCD_GoTo(u8 Line, u8 x);
extern void LCD_WriteNumber(u64 Number);
extern void LCD_WriteNumber4(u16 Number);
extern void LCD_WriteNumber3(u16 Number);
extern void LCD_WriteRealNumber(double Number);
extern void LCD_Create_Character(u8 *Pattern,u8 Location);
extern void LCD_Clear(void);
void _delay_ms(unsigned int Time);

#endif /* HAL_LCD_LCD_H_ */
