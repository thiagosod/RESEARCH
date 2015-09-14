/*
 * beaglegpio.c
 *
 *  Created on: 11/05/2015
 *      Author: rtems
 */

#include "beaglegpio.h"

int					g_active;
unsigned long *		g_controlModule;
unsigned long * 	g_gpio[4];


#define beagleboneioassert( condition ) \
		if (!(condition))	\
		{			\
			printf( "Assert Failed in file '%s on line %d", __FILE__,__LINE__ );	\
			return 0;	\
		}

const int BeagleBone_GPIO_Pin_Bank[] = {
	-1, -1,  1,  1,  1,	// P8_1  -> P8_5
	 1,  2,  2,  2,  2,	// P8_6  -> P8_10
	 1,  1,  0,  0,  1, 	// P8_11 -> P8_15
	 1,  0,  2,  0,  1, 	// P8_16 -> P8_20
	 1,  1,  1,  1,  1, 	// P8_21 -> P8_25
	 1,  2,  2,  2,  2, 	// P8_26 -> P8_30
	 0,  0,  0,  2,  0, 	// P8_31 -> P9_35
	 2,  2,  2,  2,  2, 	// P8_36 -> P8_40
	 2,  2,  2,  2,  2, 	// P8_41 -> P8_45
	 2,			// P8_46
	-1, -1, -1, -1, -1, 	// P9_1  -> P9_5
	-1, -1, -1, -1, -1, 	// P9_6  -> P9_10
	 0,  1,  0,  1,  1, 	// P9_11 -> P9_15
	 1,  0,  0,  0,  0,	// P9_16 -> P9_20
	 0,  0,  1,  0,  3, 	// P9_21 -> P9_25
	 0,  3,  3,  3,  3, 	// P9_26 -> P9_30
	 3, -1, -1, -1, -1, 	// P9_31 -> P9_35
	-1, -1, -1, -1, -1, 	// P9_36 -> P9_40
	 0,  0, -1, -1, -1, 	// P9_41 -> P9_45
	-1			// P9_46
};

const int BeagleBone_GPIO_Pin_Id[] = {
	-1, -1,  6,  7,  2,	// P8_1  -> P8_5
	 3,  2,  3,  5,  4,	// P8_6  -> P8_10
	13, 12, 23, 26, 15, 	// P8_11 -> P8_15
	14, 27,  1, 22, 31, 	// P8_16 -> P8_20
	30,  5,  4,  1,  0, 	// P8_21 -> P8_25
	29, 22, 24, 23, 25, 	// P8_26 -> P8_30
	10, 11,  9, 17,  8, 	// P8_31 -> P9_35
	16, 14, 15, 12, 13, 	// P8_36 -> P8_40
	10, 11,  8,  9,  6, 	// P8_41 -> P8_45
	 7,			// P8_46
	-1, -1, -1, -1, -1, 	// P9_1  -> P9_5
	-1, -1, -1, -1, -1,	// P9_6  -> P9_10
	30, 28, 31, 18, 16, 	// P9_11 -> P9_15
	19,  5,  4, 13, 12, 	// P9_16 -> P9_20
	 3,  2, 17, 15, 21, 	// P9_21 -> P9_25
	14, 19, 17, 15, 16, 	// P9_26 -> P9_30
	14, -1, -1, -1, -1, 	// P9_31 -> P9_35
	-1, -1, -1, -1, -1, 	// P9_36 -> P9_40
	20,  7, -1, -1, -1, 	// P9_41 -> P9_45
	-1			// P9_46
};

const unsigned long BeagleBone_GPIO_Pad_Control[] = {
	0x0000, 0x0000, 0x0818, 0x081C, 0x0808,	// P8_1  -> P8_5
	0x080C, 0x0890, 0x0894, 0x089C, 0x0898,	// P8_6  -> P8_10
	0x0834, 0x0830, 0x0824, 0x0828, 0x083C,	// P8_11 -> P8_15
	0x0838, 0x082C, 0x088C, 0x0820, 0x0884,	// P8_16 -> P8_20
	0x0880, 0x0814, 0x0810, 0x0804, 0x0800,	// P8_21 -> P8_25
	0x087C, 0x08E0, 0x08E8, 0x08E4, 0x08EC,	// P8_26 -> P8_30
	0x08D8, 0x08DC, 0x08D4, 0x08CC, 0x08D0,	// P8_31 -> P8_35
	0x08C8, 0x08C0, 0x08C4, 0x08B8, 0x08BC,	// P8_36 -> P8_40
	0x08B0, 0x08B4, 0x08A8, 0x08AC, 0x08A0,	// P8_41 -> P8_45
	0x08A4,					// P8_46
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000,	// P9_1  -> P9_5
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000,	// P9_6  -> P9_10
	0x0870, 0x0878, 0x0874, 0x0848, 0x0840,	// P9_11 -> P9_15
	0x084C, 0x095C, 0x0958, 0x097C, 0x0978,	// P9_16 -> P9_20
	0x0954, 0x0950, 0x0844, 0x0984, 0x09AC,	// P9_21 -> P9_25
	0x0980, 0x09A4, 0x099C, 0x0994, 0x0998,	// P9_26 -> P9_30
	0x0990, 0x0000, 0x0000, 0x0000, 0x0000,	// P9_31 -> P9_35
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000,	// P9_36 -> P9_40
	0x09B4, 0x0964, 0x0000, 0x0000, 0x0000,	// P9_41 -> P9_45
	0x0000					// P9_46
};


const unsigned long GPIO_Control_Module_Registers = 0x44E10000;

const unsigned long GPIO_Base[] = {
	0x44E07000,	// GPIO0
	0x4804C000,	// GPIO1
	0x481AC000,	// GPIO2
	0x481AE000	// GPIO3
};

void initBeagle_GPIO() {
	int i;
	printf( "initBeagle_GPIO()" );

	// Not initialized by default
	g_active = 0;

	// Map Control Module
	g_controlModule = GPIO_Control_Module_Registers;

	// Now mapping the GPIO registers
	for ( i=0; i<4; ++i){
		// Map a GPIO bank
		g_gpio[i] = GPIO_Base[i];
	}

	// Init complete and successfull
	g_active = 1;

	printf( "Beagle GPIO Initialized" );
}

int configurePin( unsigned short _pin, Beagle_GPIO_Direction _direction ){
	if ( !g_active )
		return 0;

	beagleboneioassert(BeagleBone_GPIO_Pin_Bank[_pin]>=0);
	beagleboneioassert(BeagleBone_GPIO_Pin_Id[_pin]>=0);

	// Set Pin as GPIO on the pad control
	g_controlModule[BeagleBone_GPIO_Pad_Control[_pin]/4] |= 0x07;

	unsigned long v = 0x1 << BeagleBone_GPIO_Pin_Id[_pin];

	if ( _direction == kINPUT)	{
		g_gpio[BeagleBone_GPIO_Pin_Bank[_pin]][kOE/4] |= v;
	}
	else	{
		g_gpio[BeagleBone_GPIO_Pin_Bank[_pin]][kOE/4] &= ~v;
	}

	// Disable Interrupts by default
	g_gpio[BeagleBone_GPIO_Pin_Bank[_pin]][kIRQSTATUS_CLR_0/4] |= v;
	g_gpio[BeagleBone_GPIO_Pin_Bank[_pin]][kIRQSTATUS_CLR_1/4] |= v;

	return 1;
}

int enablePinInterrupts( unsigned short _pin, int _enable )	{
	if ( !g_active )
		return 0;

	beagleboneioassert(BeagleBone_GPIO_Pin_Bank[_pin]>=0);
	beagleboneioassert(BeagleBone_GPIO_Pin_Id[_pin]>=0);

	// Set Pin as GPIO on the pad control
	g_controlModule[BeagleBone_GPIO_Pad_Control[_pin]/4] |= 0x07;

	unsigned long v = 0x1 << BeagleBone_GPIO_Pin_Id[_pin];

	if ( _enable )	{
		g_gpio[BeagleBone_GPIO_Pin_Bank[_pin]][kIRQSTATUS_SET_0/4] |= v;
		g_gpio[BeagleBone_GPIO_Pin_Bank[_pin]][kIRQSTATUS_SET_1/4] |= v;
	}
	else {
		g_gpio[BeagleBone_GPIO_Pin_Bank[_pin]][kIRQSTATUS_CLR_0/4] |= v;
		g_gpio[BeagleBone_GPIO_Pin_Bank[_pin]][kIRQSTATUS_CLR_1/4] |= v;
	}

	return 1;
}

int writePin( unsigned short _pin, unsigned char _value )	{
	beagleboneioassert(BeagleBone_GPIO_Pin_Bank[_pin]>=0);
	beagleboneioassert(BeagleBone_GPIO_Pin_Id[_pin]>=0);

	unsigned long v = (_value & 0x01) << BeagleBone_GPIO_Pin_Id[_pin];
	unsigned long mask = 0x1 << BeagleBone_GPIO_Pin_Id[_pin];

	// Remove bit
	g_gpio[BeagleBone_GPIO_Pin_Bank[_pin]][kDATAOUT/4] &= ~mask;
	// Assign new bit value
	g_gpio[BeagleBone_GPIO_Pin_Bank[_pin]][kDATAOUT/4] |= v;

	return 1;
}

int readPin( unsigned short _pin )	{
	beagleboneioassert(BeagleBone_GPIO_Pin_Bank[_pin]>=0);
	beagleboneioassert(BeagleBone_GPIO_Pin_Id[_pin]>=0);

	unsigned long bit = BeagleBone_GPIO_Pin_Id[_pin];
	return (g_gpio[BeagleBone_GPIO_Pin_Bank[_pin]][kDATAIN/4] & (0x1 << bit)) >> bit;
}

