/*
 * beaglegpio.h
 *
 *  Created on: 11/05/2015
 *      Author: rtems
 */

#ifndef BEAGLEGPIO_H
#define BEAGLEGPIO_H

#include <stdio.h>

enum	{
	kREVISION		= 0x0,
	kSYSCONFIG		= 0x10,
	kIRQSTATUS_RAW_0	= 0x24,
	kIRQSTATUS_RAW_1	= 0x28,
	kIRQSTATUS_0		= 0x2C,
	kIRQSTATUS_1		= 0x30,
	kIRQSTATUS_SET_0	= 0x34,
	kIRQSTATUS_SET_1	= 0x38,
	kIRQSTATUS_CLR_0	= 0x3C,
	kIRQSTATUS_CLR_1	= 0x40,
	kIRQWAKEN_0		= 0x44,
	kIRQWAKEN_1		= 0x48,
	kSYSSTATUS		= 0x114,
	kCTRL			= 0x130,
	kOE			= 0x134,
	kDATAIN			= 0x138,
	kDATAOUT		= 0x13C,
	kLEVELDETECT0		= 0x140,
	kLEVELDETECT1		= 0x144,
	kRISINGDETECT		= 0x148,
	kFALLINGDETECT		= 0x14C,
	kDEBOUNCEENABLE		= 0x150,
	kDEBOUNCINGTIME		= 0x154,
	kCLEARDATAOUT		= 0x190,
	kSETDATAOUT		= 0x194
}Beagle_GPIO_Registers;

typedef enum	{
	kINPUT	= 0,
	kOUTPUT = 1
} Beagle_GPIO_Direction;

	// GPIO Pins
enum	{
	P8_1,  P8_2,  P8_3,  P8_4,  P8_5,
	P8_6,  P8_7,  P8_8,  P8_9,  P8_10,
	P8_11, P8_12, P8_13, P8_14, P8_15,
	P8_16, P8_17, P8_18, P8_19, P8_20,
	P8_21, P8_22, P8_23, P8_24, P8_25,
	P8_26, P8_27, P8_28, P8_29, P8_30,
	P8_31, P8_32, P8_33, P8_34, P8_35,
	P8_36, P8_37, P8_38, P8_39, P8_40,
	P8_41, P8_42, P8_43, P8_44, P8_45,
	P8_46,
	P9_1,  P9_2,  P9_3,  P9_4,  P9_5,
	P9_6,  P9_7,  P9_8,  P9_9,  P9_10,
	P9_11, P9_12, P9_13, P9_14, P9_15,
	P9_16, P9_17, P9_18, P9_19, P9_20,
	P9_21, P9_22, P9_23, P9_24, P9_25,
	P9_26, P9_27, P9_28, P9_29, P9_30,
	P9_31, P9_32, P9_33, P9_34, P9_35,
	P9_36, P9_37, P9_38, P9_39, P9_40,
	P9_41, P9_42, P9_43, P9_44, P9_45,
	P9_46
} GPIO_Pins;

void initBeagle_GPIO();
int configurePin( unsigned short _pin, Beagle_GPIO_Direction _direction );
int enablePinInterrupts( unsigned short _pin, int _enable );

#endif /* 01_BEAGLEBONEBLACK_BEAGLEGPIO_H_ */
