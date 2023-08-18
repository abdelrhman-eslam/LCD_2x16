/*
 * DIO.c
 *
 *  Created on: Aug 10, 2023
 *      Author: ENG.AbdelrhmanEslam
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "DIO.h"

#define DIO_PORTA_REG		*((volatile u8 *) 0X3B)
#define DIO_DDRA_REG		*((volatile u8 *) 0X3A)
#define DIO_PINA_REG		*((volatile u8 *) 0X39)

#define DIO_PORTB_REG		*((volatile u8 *) 0X38)
#define DIO_DDRB_REG		*((volatile u8 *) 0X37)
#define DIO_PINB_REG		*((volatile u8 *) 0X36)

#define DIO_PORTC_REG		*((volatile u8 *) 0X35)
#define DIO_DDRC_REG		*((volatile u8 *) 0X34)
#define DIO_PINC_REG		*((volatile u8 *) 0X33)

#define DIO_PORTD_REG		*((volatile u8 *) 0X32)
#define DIO_DDRD_REG		*((volatile u8 *) 0X31)
#define DIO_PIND_REG		*((volatile u8 *) 0X30)

void MDIO_voidSetPinDirection(u8 A_u8PortNo,u8 A_u8PinNo,u8 A_u8PinDirection){
if((A_u8PortNo <= PORTD) && (A_u8PinNo <=PIN7) && (A_u8PinDirection <= OUTPUT))
{
	switch(A_u8PortNo)
	{
		case PORTA:
				switch(A_u8PinDirection)
				{
				case OUTPUT: SET_BIT(DIO_DDRA_REG ,A_u8PinNo); break;
				case INPUT:  CLR_BIT(DIO_DDRA_REG ,A_u8PinNo); break;
				}
			break;
		case PORTB:
				switch(A_u8PinDirection)
				{
				case OUTPUT: SET_BIT(DIO_DDRB_REG ,A_u8PinNo); break;
				case INPUT:  CLR_BIT(DIO_DDRB_REG ,A_u8PinNo); break;
				}
			break;
		case PORTC:
				switch(A_u8PinDirection)
				{
				case OUTPUT: SET_BIT(DIO_DDRC_REG ,A_u8PinNo); break;
				case INPUT:  CLR_BIT(DIO_DDRC_REG ,A_u8PinNo); break;
				}
			break;
		case PORTD:
				switch(A_u8PinDirection)
				{
				case OUTPUT: SET_BIT(DIO_DDRD_REG ,A_u8PinNo); break;
				case INPUT:  CLR_BIT(DIO_DDRD_REG ,A_u8PinNo); break;
				}
			break;
	}		/*endif*/ }


}

void MDIO_voidSetPinValue(u8 A_u8PortNo,u8 A_u8PinNo,u8 A_u8PinValue){
	if ( (A_u8PortNo<=PORTD) && (A_u8PinNo<=PIN7) && (A_u8PinValue <=HIGH)){
	switch(A_u8PortNo)
		{
			case PORTA:
					switch(A_u8PinValue)
					{
					case OUTPUT: SET_BIT(DIO_PORTA_REG ,A_u8PinNo); break;
					case INPUT:  CLR_BIT(DIO_PORTA_REG ,A_u8PinNo); break;
					}
					break;
			case PORTB:
					switch(A_u8PinValue)
					{
					case OUTPUT: SET_BIT(DIO_PORTB_REG ,A_u8PinNo); break;
					case INPUT:  CLR_BIT(DIO_PORTB_REG ,A_u8PinNo); break;
					}
					break;
			case PORTC:
					switch(A_u8PinValue)
					{
					case OUTPUT: SET_BIT(DIO_PORTC_REG ,A_u8PinNo); break;
					case INPUT:  CLR_BIT(DIO_PORTC_REG ,A_u8PinNo); break;
					}
					break;
			case PORTD:
					switch(A_u8PinValue)
					{
					case OUTPUT: SET_BIT(DIO_PORTD_REG ,A_u8PinNo); break;
					case INPUT:  CLR_BIT(DIO_PORTD_REG ,A_u8PinNo); break;
					}
					break;
		}		/*endif*/}
}

u8 MDIO_U8GetPinValue(u8 A_u8PortNo,u8 A_u8PinNo){

	u8 local_u8PinValue=3;

	if ( (A_u8PortNo<=PORTD) && (A_u8PinNo<=PIN7) ){
	switch(A_u8PortNo)
	{
	case PORTA: local_u8PinValue = GET_BIT(DIO_PINA_REG ,A_u8PinNo); break;
	case PORTB: local_u8PinValue = GET_BIT(DIO_PINB_REG ,A_u8PinNo); break;
	case PORTC: local_u8PinValue = GET_BIT(DIO_PINC_REG ,A_u8PinNo); break;
	case PORTD: local_u8PinValue = GET_BIT(DIO_PIND_REG ,A_u8PinNo); break;
	} /* endif */}
	return local_u8PinValue;
}

void MDIO_voidSetPortDirection(u8 A_u8PortNo,u8 A_u8PortDirection){
	if ( (A_u8PortNo<=PORTD) ){
	switch(A_u8PortNo)
		{
		case PORTA: DIO_DDRA_REG= A_u8PortDirection; break;
		case PORTB: DIO_DDRB_REG= A_u8PortDirection; break;
		case PORTC: DIO_DDRC_REG= A_u8PortDirection; break;
		case PORTD: DIO_DDRD_REG= A_u8PortDirection; break;
		 }   }
}

void MDIO_voidSetPortValue(u8 A_u8PortNo,u8 A_u8PortValue){

	if ( (A_u8PortNo<=PORTD) ){
	switch(A_u8PortNo)
			{
			case PORTA: DIO_PORTA_REG= A_u8PortValue; break;
			case PORTB: DIO_PORTB_REG= A_u8PortValue; break;
			case PORTC: DIO_PORTC_REG= A_u8PortValue; break;
			case PORTD: DIO_PORTD_REG= A_u8PortValue; break;
			}		}
}
