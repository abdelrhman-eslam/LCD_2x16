/*
 * BIT_MATH.h
 *
 *  Created on: Aug 10, 2023
 *      Author: ENG.AbdelrhmanEslam
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(Reg, bitnum)       (Reg |=1<<bitnum)
#define CLR_BIT(Reg, bitnum)       (Reg &=~(1<<bitnum))
#define TOGGLE_BIT(Reg, bitnum)    (Reg ^=(1<<bitnum))
#define GET_BIT(Reg, bitnum)       ((Reg>>bitnum)& 0x01)
#define SET_BYTE(Reg,value)        ( Reg = value )

#endif /* BIT_MATH_H_ */
