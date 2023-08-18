/*
 * LCD_prog.c
 *
 *  Created on: Aug 15, 2023
 *      Author: ENG.AbdelrhmanEslam
 */

#include "LCD_int.h"


void HLCD_voidSendCommand(u8 A_u8cmd){
	/*Control RS and R/W Pins*/
	MDIO_voidSetPinValue(Control_Port,PIN0,LOW);
	MDIO_voidSetPinValue(Control_Port,PIN1,LOW);
	/*write Command on the data Pins */
	MDIO_voidSetPortValue(Data_Port,A_u8cmd);
	/* Pulse on the Enable PIN*/
	MDIO_voidSetPinValue(Control_Port,PIN2,HIGH);
	_delay_ms(1);
	MDIO_voidSetPinValue(Control_Port,PIN2,LOW);
	_delay_ms(1);
}

void HLCD_voidSendData(u8 A_u8Data){
	/*Control RS and R/W Pins*/
	MDIO_voidSetPinValue(Control_Port,PIN0,HIGH);
	MDIO_voidSetPinValue(Control_Port,PIN1,LOW);
	/*write Command on the data Pins */
	MDIO_voidSetPortValue(Data_Port,A_u8Data);
	/* Pulse on the Enable PIN*/
	MDIO_voidSetPinValue(Control_Port,PIN2,HIGH);
	_delay_ms(1);
	MDIO_voidSetPinValue(Control_Port,PIN2,LOW);
	_delay_ms(1);
}

void HLCD_voidInit(){
	// wait for 30ms
	_delay_ms(30);
	// function Set 0b00111100
	HLCD_voidSendCommand(LCD_functionSet);
	// wait for 39 us -> 1ms
	_delay_ms(1);
	// Dispaly ON/OFF 0b00001100
	HLCD_voidSendCommand(LCD_DispalyOnOff);
	// wait for 39 us -> 1ms
	_delay_ms(1);
	// Dispaly clear 0b00000001
	HLCD_voidSendCommand(LCD_Dispalyclear);
	//wait for 1.53ms -> 2ms
	_delay_ms(2);
	// Entry Mode 0b00000110
	HLCD_voidSendCommand(LCD_EntryMode);
}

void HLCD_voidClear(){
	HLCD_voidSendCommand(LCD_Dispalyclear);
	//wait for 1.53ms -> 2ms
	_delay_ms(2);
}

void HLCD_voidSendString(u8 *A_u8PtrString){
	u8 L_u8Counter = 0;
	while(A_u8PtrString[L_u8Counter] != "\0"){

		HLCD_voidSendData( A_u8PtrString[L_u8Counter++]);
	}


}

void HLCD_voidCursor(u8 A_u8LinePos , u8 A_u8LineNo){
	switch(A_u8LineNo){

	case LCD_LINE0 : HLCD_voidSendCommand(0x80+ 0 + A_u8LinePos); break;

	case LCD_LINE1 : HLCD_voidSendCommand(0x80+ 64+ A_u8LinePos); break;
	}
}

void HLCD_voidDisplayNumber(s32 A_s32Number  ){
	u32 L_u32Number=1;

	if(A_s32Number == 0){
		HLCD_voidSendData('0');
	}
	if(A_s32Number <0){
		HLCD_voidSendData('-');
		A_s32Number *=-1;
	}
	while(A_s32Number !=0 ){
		L_u32Number= ((L_u32Number*10)+(A_s32Number%10));
		A_s32Number= A_s32Number/10;
	}
	while (L_u32Number !=1){

	HLCD_voidSendData((L_u32Number%10)+48);
		L_u32Number= L_u32Number/10;
	}
}

void HLCD_voidSaveCustomChar(u8 A_u8CGRAMIndex, u8 A_u8CustomArray[]){

	HLCD_voidSendCommand(0b01000000+(A_u8CGRAMIndex*8));

		for(u8 L_u8Index=0 ;L_u8Index <8; L_u8Index++){
			HLCD_voidSendData(A_u8CustomArray[L_u8Index]);

		}
	HLCD_voidSendCommand(0x80);
}

void HLCD_voidDisplayCustomChar(u8 A_u8CGRAMIndex){

	if(A_u8CGRAMIndex<8){
		HLCD_voidSendData(A_u8CGRAMIndex);
	}
}

