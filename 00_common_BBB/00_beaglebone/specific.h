#ifndef __BEAGLEBONE_SPECIFIC__
#define __BEAGLEBONE_SPECIFIC__

#include <stdint.h>

static inline void beaglebone_write32(uint32_t val, const void *addr){
    *(volatile uint32_t *)addr = val;
}


static inline void beaglebone_clrbits_le32(const void* addr, uint32_t pattern){
    uint32_t register_value = *(volatile uint32_t *) addr;
    register_value = register_value & ~pattern;
    *(volatile uint32_t *)addr = register_value;
}


static inline void beaglebone_setbits_le32(const void* addr, uint32_t pattern){
    uint32_t register_value = *(volatile uint32_t *) addr;
    register_value = register_value | pattern;
    *(volatile uint32_t *)addr = register_value;
}

#define WAIT(count)\
	{\
		volatile uint32_t i;\
		for(i=0;i<count;i++) {};\
	}\


#define CLRALL

#define SETIOTASK_1 
#define SETIOTASK_2 
#define SETIOTASK_3 
#define SETIOTASK_4 

#endif
