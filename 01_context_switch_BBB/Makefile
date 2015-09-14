##
## paths for the RTEMS tools and RTEMS BSP
##
RTEMS_TOOL_BASE ?= /home/rtems/development
RTEMS_BSP_BASE ?= /home/rtems/development

SDCARD_GEN_PATH = /
##
## Architecture Definitions
##
PREFIX         = $(RTEMS_TOOL_BASE)
RTEMS_PREFIX   = $(RTEMS_BSP_BASE)
BEAGLEBONE_RTEMS_ARCH_LIB = $(RTEMS_PREFIX)/rtems/b-beagle/arm-rtems4.11/beagleboneblack/lib/
BUILD_DIR ?= objs

##
## Linker flags that are needed
##
LDFLAGS += -qrtems 

##
## Compiler Architecture Switches
##
ARCH_OPTS = -mcpu=cortex-a8 

INCLUDE_PATH := -I. -Iinclude/

WARNINGS	= -Wall -Wmissing-prototypes -Wimplicit-function-declaration -Wstrict-prototypes -Wnested-externs
DEBUG_OPTS	= -O2 -g 

COMMON_BBB            = ../00_common_BBB
COMMON_RTEMS          = ../00_common/00_RTEMS
COMMON_CONTEXT_SWITCH = ../01_common_context_switch
BEAGLEBONE_SPECIFIC   = ../00_common/01_BeagleBoneBlack
##
## define build products
##
EXE_TARGET       = beaglebone.exe

##
## Optional objects in src directory
##
OBJS += $(COMMON_RTEMS)/init.o
OBJS += usrAppInit.o
OBJS += $(BEAGLEBONE_SPECIFIC)/hardwareconfiguration.o
OBJS += $(BEAGLEBONE_SPECIFIC)/beaglegpio.o
OBJS += $(BEAGLEBONE_SPECIFIC)/cp15.o
OBJS += $(COMMON_CONTEXT_SWITCH)/01_task01/task1.o
OBJS += $(COMMON_CONTEXT_SWITCH)/02_task02/task2.o
OBJS += $(COMMON_CONTEXT_SWITCH)/03_task03/task3.o
OBJS += $(COMMON_CONTEXT_SWITCH)/04_task04/task4.o


INCLUDES = -I./ -I$(BEAGLEBONE_SPECIFIC) -I$(COMMON_RTEMS)

##
## General gcc options that apply to compiling and dependency generation.
##
COPTS=$(ARCH_OPTS) $(DEBUG_OPTS) $(WARNINGS)

####################################################
## Host Development System and Toolchain defintions
##
## Host OS utils
##
RM=rm -f
CP=cp
MV=mv
CD=cd
TAR=tar
CAT=cat
MKDIR=mkdir
LS=ls

##
## Compiler tools
##
COMPILER   = arm-rtems4.11-gcc
ASSEMBLER  = arm-rtems4.11-gcc
LINKER	   = $(ARCH)-ld
AR	   = $(ARCH)-ar
NM         = $(ARCH)-nm
OBJCOPY    = $(ARCH)-objcopy
SIZE       = $(ARCH)-size

###############################################################################################
##
## Build Targets
##

##
## The default "make" target is the subsystem object module.
##
default::$(EXE_TARGET)

# Create the output directory
$(BUILD_DIR):
	$(MKDIR) -p $(BUILD_DIR)

#  Install rule is mission/target specific
#  install::$(EXE_TARGET)

OBJS2 := $(addprefix $(BUILD_DIR)/, $(notdir $(OBJS)))

##
## Compiler rule
##
.c.o:
	$(COMPILER)  -B$(BEAGLEBONE_RTEMS_ARCH_LIB) -specs bsp_specs -DHAVE_CONFIG_H $(INCLUDES) $(COPTS) -MT $(notdir $@) -MD -MP  -c -o $(BUILD_DIR)/$(notdir $@) $<

.S.o:
	$(COMPILER)  -B$(BEAGLEBONE_RTEMS_ARCH_LIB) -specs bsp_specs -DHAVE_CONFIG_H $(INCLUDES) $(COPTS) -MT $(notdir $@) -MD -MP  -c -o $(BUILD_DIR)/$(notdir $@) $<

##
## Assembly Code Rule
##
.s.o:
	$(COMPILER) $(ASOPTS) $(COPTS) $(DEBUG_OPTS)  -c -o $(BUILD_DIR)/$@ $<

##
## Link Rule to make the final executable image
## add symtab.o for symbol table
$(EXE_TARGET): $(BUILD_DIR) $(OBJS) 
	$(COMPILER) -B$(BEAGLEBONE_RTEMS_ARCH_LIB) -specs bsp_specs $(DEBUG_FLAGS) $(LDFLAGS) $(COPTS) -o $(BUILD_DIR)/$(EXE_TARGET) $(OBJS2) $(LIBS)
	arm-rtems4.11-nm -g -n $(BUILD_DIR)/$(EXE_TARGET) > $(addsuffix .num, $(basename $(EXE_TARGET)))
	$(SIZE) $(BUILD_DIR)/$(EXE_TARGET)
	$(CP) $(BUILD_DIR)/$(EXE_TARGET) $(BUILD_DIR)/$(addsuffix .ralf, $(basename $(EXE_TARGET)))
	sh $(HOME)/development/rtems/rtems-src/c/src/lib/libbsp/arm/beagle/simscripts/sdcard.sh $(HOME)/development/rtems/4.11 $(BUILD_DIR)/$(EXE_TARGET)
#	cd -

##
## Make clean rule
##
clean::
	-$(RM) -r $(BUILD_DIR)
	-$(RM) *.img
	-$(RM) *.num

