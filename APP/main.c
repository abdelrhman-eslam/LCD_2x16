/*
 * main.c
 *
 *  Created on: Aug 13, 2023
 *      Author: ENG.AbdelrhmanEslam
 */


#include "../MCAL/DIO/DIO.h"
#include "../HAL/LCD/LCD_int.h"




void main() {

	/*MDIO_voidSetPortDirection(PORTA,0xff);
	MDIO_voidSetPortDirection(PORTB,0xff);
	HLCD_voidInit();
	u8 raa[]={
			0x00, 0x02, 0x01, 0x01, 0x02, 0x04, 0x18
	};
	u8 yaa[]={
			0x00, 0x00, 0x01, 0x1F, 0x00, 0x0A, 0x00
		};
	u8 mem[]={
			0x00, 0x04, 0x0A, 0x1B, 0x14, 0x10, 0x10, 0x00
		};
	HLCD_voidSaveCustomChar(0,raa);
	HLCD_voidSaveCustomChar(1,yaa);
	HLCD_voidSaveCustomChar(2,mem);
	HLCD_voidCursor(5,LCD_LINE1);
	HLCD_voidDisplayCustomChar(0);
	HLCD_voidCursor(4,LCD_LINE1);
	HLCD_voidDisplayCustomChar(1);
	HLCD_voidCursor(3,LCD_LINE1);
	HLCD_voidDisplayCustomChar(2);



	HLCD_voidCursor(3,LCD_LINE0);
	HLCD_voidDisplayNumber(-120);*/
	HLCD_voidInit();
	HLCD_voidSendData('A');

while(1){

}

}
