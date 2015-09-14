#include "hardwareconfiguration.h"




void initHWConfiguration(){

	CP15ICacheDisable();
	CP15ICacheFlush();

	printf("<<Disabled Cache>>\n");
/*
    //enable the GPIO module
    //CM_PER Registers -> CM_PER_GPIO1_CLKCTRL
    beagleboneblack_write32((0x2 << 0) | (1 << 18), (uint32_t *)(0x44e00000 + 0xac));

    //GPIO1 -> GPIO_IRQSTATUS_CLR_0 (3Ch)
    beagleboneblack_setbits_le32((uint32_t *)(0x4804c000 + 0x3c), 0xf << 21);

    //enable output
    //GPIO1 -> GPIO_OE (134h)
    beagleboneblack_clrbits_le32((uint32_t *)(0x4804c000 + 0x134), 0xf << 21);
*/
    initBeagle_GPIO();

    configurePin(PINTASK1,kOUTPUT);
    configurePin(PINTASK2,kOUTPUT);
    configurePin(PINTASK3,kOUTPUT);
    configurePin(PINTASK4,kOUTPUT);

    printf("[Hardware Configured]\n");

}

