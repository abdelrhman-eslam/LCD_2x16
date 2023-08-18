/*
 * LCD_int.h
 *
 *  Created on: Aug 15, 2023
 *      Author: ENG.AbdelrhmanEslam
 */

#ifndef HAL_LCD_LCD_INT_H_
#define HAL_LCD_LCD_INT_H_

#define F_CPU	8000000UL

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO.h"
#include <util/delay.h>

#define Data_Port	PORTA
#define Control_Port PORTB

#define LCD_ROW_1   127
#define LCD_ROW_2   191


#define LCD_LINE1	1
#define LCD_LINE0	0

#define	LCD_functionSet	 0b00111100
#define	LCD_DispalyOnOff 0b00001100
#define LCD_Dispalyclear 0b00000001
#define LCD_EntryMode	 0b00000110

void HLCD_voidInit();
void HLCD_voidSendCommand(u8 A_u8cmd);
void HLCD_voidSendData(u8 A_u8Data);
void HLCD_voidClear();
void HLCD_voidCursor(u8 A_u8RowNum,u8 A_u8ColNum);
void HLCD_voidSendString(u8 *A_u8PtrString);
void HLCD_voidDisplayNumber(s32 A_s32Number  );
void HLCD_voidSaveCustomChar(u8 A_u8CGRAMIndex, u8 A_u8CustomArray[]);
void HLCD_voidDisplayCustomChar(u8 A_u8CGRAMIndex);

#endif /* HAL_LCD_LCD_INT_H_ */
