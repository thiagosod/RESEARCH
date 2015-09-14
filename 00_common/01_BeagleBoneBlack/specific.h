#ifndef __BEAGLEBONE_SPECIFIC__
#define __BEAGLEBONE_SPECIFIC__

#include <stdint.h>
#include "beaglegpio.h"

static inline void beagleboneblack_write32(uint32_t val, const void *addr){
    *(volatile uint32_t *)addr = val;
}


static inline void beagleboneblack_clrbits_le32(const void* addr, uint32_t pattern){
    uint32_t register_value = *(volatile uint32_t *) addr;
    register_value = register_value & ~pattern;
    *(volatile uint32_t *)addr = register_value;
}


static inline void beagleboneblack_setbits_le32(const void* addr, uint32_t pattern){
    uint32_t register_value = *(volatile uint32_t *) addr;
    register_value = register_value | pattern;
    *(volatile uint32_t *)addr = register_value;
}

#define WAIT(count)\
	{\
		volatile uint32_t i;\
		for(i=0;i<count;i++) {};\
	}\

#define PINTASK1 P8_7
#define PINTASK2 P8_9
#define PINTASK3 P8_11
#define PINTASK4 P8_13

#define BEAGLEBONEBLACK_LED_PATTERN     0x1
#define CLRALL  writePin(PINTASK1,0);\
				writePin(PINTASK2,0);\
				writePin(PINTASK3,0);\
				writePin(P8_13,0);\


#define SETIOTASK_1		writePin(PINTASK1,1);


#define SETIOTASK_2	writePin(PINTASK2,1);
#define SETIOTASK_3 writePin(PINTASK3,1);
#define SETIOTASK_4	writePin(PINTASK4,1);

#define GPIO0_BASE_ADDRESS      0x44E07000
#define GPIO1_BASE_ADDRESS      0x4804C000
#define GPIO2_BASE_ADDRESS      0x481AC000
#define GPIO3_BASE_ADDRESS      0x481AE000

#define GPIO_CONTROL_MODULE     0x44E10000

#define	GPIO1_BASE_2430			0x4900c000
#define	GPIO2_BASE_2430			0x4900e000
#define	GPIO3_BASE_2430			0x49010000
#define	GPIO4_BASE_2430			0x49012000
#define	GPIO5_BASE_2430			0x480b6000

#define	GPIO1_BASE_2420			0x48018000
#define	GPIO2_BASE_2420			0x4801a000
#define	GPIO3_BASE_2420			0x4801c000
#define	GPIO4_BASE_2420			0x4801e000

#define	GPIO1_BASE_3430			0x48310000
#define	GPIO2_BASE_3430			0x49050000
#define	GPIO3_BASE_3430			0x49052000
#define	GPIO4_BASE_3430			0x49054000
#define	GPIO5_BASE_3430			0x49056000
#define	GPIO6_BASE_3430			0x49058000

#define	GPIO1_BASE_3530			0x48310000
#define	GPIO2_BASE_3530			0x49050000
#define	GPIO3_BASE_3530			0x49052000
#define	GPIO4_BASE_3530			0x49054000
#define	GPIO5_BASE_3530			0x49056000
#define	GPIO6_BASE_3530			0x49058000

#define	GPIO1_BASE_4430			0x4a310000
#define	GPIO2_BASE_4430			0x48055000
#define	GPIO3_BASE_4430			0x48057000
#define	GPIO4_BASE_4430			0x48059000
#define	GPIO5_BASE_4430			0x4805b000
#define	GPIO6_BASE_4430			0x4805d000

#define	GPIO1_BASE_5430			0x4AE10000
#define	GPIO2_BASE_5430			0x48055000
#define	GPIO3_BASE_5430			0x48057000
#define	GPIO4_BASE_5430			0x48059000
#define	GPIO5_BASE_5430			0x4805b000
#define	GPIO6_BASE_5430			0x4805d000
#define	GPIO7_BASE_5430			0x48051000
#define	GPIO8_BASE_5430			0x48053000

#define	GPIO0_BASE_TI_AM335X		0x44E07000
#define	GPIO1_BASE_TI_AM335X		0x4804C000
#define	GPIO2_BASE_TI_AM335X		0x481AC000
#define	GPIO3_BASE_TI_AM335X		0x481AE000

#define	GPIO1_BASE_TI_DM37XX		0x48310000
#define	GPIO2_BASE_TI_DM37XX		0x49050000
#define	GPIO3_BASE_TI_DM37XX		0x49052000
#define	GPIO4_BASE_TI_DM37XX		0x49054000
#define	GPIO5_BASE_TI_DM37XX		0x49056000
#define	GPIO6_BASE_TI_DM37XX		0x49058000

#define	GPIO_IRQSTATUS1			0x018
#define	GPIO_IRQENABLE1			0x01c
#define	GPIO_WAKEUPENABLE		0x020
#define	GPIO_IRQSTATUS2			0x028
#define	GPIO_IRQENABLE2			0x02c
#define	GPIO_CTRL			0x030
#define	GPIO_OE				0x034
#define	GPIO_DATAIN			0x038
#define	GPIO_DATAOUT			0x03c
#define	GPIO_LEVELDETECT0		0x040
#define	GPIO_LEVELDETECT1		0x044
#define	GPIO_RISINGDETECT		0x048
#define	GPIO_FALLINGDETECT		0x04c
#define	GPIO_DEBOUNCENABLE		0x050
#define	GPIO_DEBOUNINGTIME		0x054
#define	GPIO_CLEARIRQENABLE1		0x060
#define	GPIO_SETIRQENABLE1		0x064
#define	GPIO_CLEARIRQENABLE2		0x070
#define	GPIO_SETIRQENABLE2		0x074
#define	GPIO_CLEANWKUENA		0x080
#define	GPIO_SETWKUENA			0x084
#define	GPIO_CLEARDATAOUT		0x090
#define	GPIO_SETDATAOUT			0x094



#endif
