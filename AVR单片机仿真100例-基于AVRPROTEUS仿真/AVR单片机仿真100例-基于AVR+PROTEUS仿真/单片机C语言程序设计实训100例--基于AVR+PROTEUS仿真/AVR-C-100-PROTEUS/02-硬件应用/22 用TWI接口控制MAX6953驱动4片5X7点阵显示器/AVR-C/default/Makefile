###############################################################################
# Makefile for the project 用TWI接口控制MAX6953驱动4片5X7点阵显示器
###############################################################################

## General Flags
PROJECT = 用TWI接口控制MAX6953驱动4片5X7点阵显示器
MCU = atmega16
TARGET = 用TWI接口控制MAX6953驱动4片5X7点阵显示器.elf
CC = avr-gcc.exe

## Options common to compile, link and assembly rules
COMMON = -mmcu=$(MCU)

## Compile options common for all C compilation units.
CFLAGS = $(COMMON)
CFLAGS += -Wall -gdwarf-2          -DF_CPU=4000000UL -O1 -fsigned-char
CFLAGS += -MD -MP -MT $(*F).o -MF dep/$(@F).d 

## Assembly specific flags
ASMFLAGS = $(COMMON)
ASMFLAGS += $(CFLAGS)
ASMFLAGS += -x assembler-with-cpp -Wa,-gdwarf2

## Linker flags
LDFLAGS = $(COMMON)
LDFLAGS += 


## Intel Hex file production flags
HEX_FLASH_FLAGS = -R .eeprom

HEX_EEPROM_FLAGS = -j .eeprom
HEX_EEPROM_FLAGS += --set-section-flags=.eeprom="alloc,load"
HEX_EEPROM_FLAGS += --change-section-lma .eeprom=0 --no-change-warnings


## Objects that must be built in order to link
OBJECTS = 用TWI接口控制MAX6953驱动4片5X7点阵显示器.o 

## Objects explicitly added by the user
LINKONLYOBJECTS = 

## Build
all: $(TARGET) 用TWI接口控制MAX6953驱动4片5X7点阵显示器.hex 用TWI接口控制MAX6953驱动4片5X7点阵显示器.eep size

## Compile
用TWI接口控制MAX6953驱动4片5X7点阵显示器.o: ../用TWI接口控制MAX6953驱动4片5X7点阵显示器.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

##Link
$(TARGET): $(OBJECTS)
	 $(CC) $(LDFLAGS) $(OBJECTS) $(LINKONLYOBJECTS) $(LIBDIRS) $(LIBS) -o $(TARGET)

%.hex: $(TARGET)
	avr-objcopy -O ihex $(HEX_FLASH_FLAGS)  $< $@

%.eep: $(TARGET)
	-avr-objcopy $(HEX_EEPROM_FLAGS) -O ihex $< $@ || exit 0

%.lss: $(TARGET)
	avr-objdump -h -S $< > $@

size: ${TARGET}
	@echo
	@avr-size -C --mcu=${MCU} ${TARGET}

## Clean target
.PHONY: clean
clean:
	-rm -rf $(OBJECTS) 用TWI接口控制MAX6953驱动4片5X7点阵显示器.elf dep/* 用TWI接口控制MAX6953驱动4片5X7点阵显示器.hex 用TWI接口控制MAX6953驱动4片5X7点阵显示器.eep

## Other dependencies
-include $(shell mkdir dep 2>/dev/null) $(wildcard dep/*)

