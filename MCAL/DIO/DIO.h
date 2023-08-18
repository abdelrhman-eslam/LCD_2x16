/*
 * DIO.h
 *
 *  Created on: Aug 10, 2023
 *      Author: ENG.AbdelrhmanEslam
 */

#ifndef DIO_H_
#define DIO_H_
#include "../../LIB/STD_TYPES.h"
/*PORTS*/
#define PORTA  0
#define PORTB  1
#define PORTC  2
#define PORTD  3

/*I/O*/
#define OUTPUT 1
#define INPUT  0

/*Pin*/
#define PIN0   0
#define PIN1   1
#define PIN2   2
#define PIN3   3
#define PIN4   4
#define PIN5   5
#define PIN6   6
#define PIN7   7

/* Values */
#define HIGH 1
#define LOW  0


void MDIO_voidSetPinDirection(u8 A_u8PortNo,u8 A_u8PinNo,u8 A_u8PinDirection);
void MDIO_voidSetPinValue(u8 A_u8PortNo,u8 A_u8PinNo,u8 A_u8PinValue);
u8	 MDIO_U8GetPinValue(u8 A_u8PortNo,u8 A_u8PinNo);

void MDIO_voidSetPortDirection(u8 A_u8PortNo,u8 A_u8PortDirection);
void MDIO_voidSetPortValue(u8 A_u8PortNo,u8 A_u8PortValue);

#endif /* DIO_H_ */
