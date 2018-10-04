###############################################################################
# Makefile for the project 用DS1302与数码管设计的可调电子钟
###############################################################################

## General Flags
PROJECT = 用DS1302与数码管设计的可调电子钟
MCU = atmega16
TARGET = 用DS1302与数码管设计的可调电子钟.elf
CC = avr-gcc.exe

## Options common to compile, link and assembly rules
COMMON = -mmcu=$(MCU)

## Compile options common for all C compilation units.
CFLAGS = $(COMMON)
CFLAGS += -Wall -gdwarf-2              -DF_CPU=4000000UL  -O1 -fsigned-char
CFLAGS += -MD -MP -MT $(*F).o -MF dep/$(@F).d 

## Assembly specific flags
ASMFLAGS = $(COMMON)
ASMFLAGS += -x assembler-with-cpp -Wa,-gdwarf2

## Linker flags
LDFLAGS = $(COMMON)
LDFLAGS += 


## Intel Hex file production flags
HEX_FLASH_FLAGS = -R .eeprom

HEX_EEPROM_FLAGS = -j .eeprom
HEX_EEPROM_FLAGS += --set-section-flags=.eeprom="alloc,load"
HEX_EEPROM_FLAGS += --change-section-lma .eeprom=0


## Include Directories
INCLUDES = -I"C:\WinAVR-20090313\avr\include" 

## Objects that must be built in order to link
OBJECTS = 用DS1302与数码管设计的可调电子钟.o ds1302.o

## Objects explicitly added by the user
LINKONLYOBJECTS = 

## Build
all: $(TARGET) 用DS1302与数码管设计的可调电子钟.hex 用DS1302与数码管设计的可调电子钟.eep

## Compile
用DS1302与数码管设计的可调电子钟.o: ../用DS1302与数码管设计的可调电子钟.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

ds1302.o: ../ds1302.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

##Link
$(TARGET): $(OBJECTS)
	 $(CC) $(LDFLAGS) $(OBJECTS) $(LINKONLYOBJECTS) $(LIBDIRS) $(LIBS) -o $(TARGET)

%.hex: $(TARGET)
	avr-objcopy -O ihex $(HEX_FLASH_FLAGS)  $< $@

%.eep: $(TARGET)
	avr-objcopy $(HEX_EEPROM_FLAGS) -O ihex $< $@

%.lss: $(TARGET)
	avr-objdump -h -S $< > $@

## Clean target
.PHONY: clean
clean:
	-rm -rf $(OBJECTS) 用DS1302与数码管设计的可调电子钟.elf dep/* 用DS1302与数码管设计的可调电子钟.hex 用DS1302与数码管设计的可调电子钟.eep

## Other dependencies
-include $(shell mkdir dep 2>/dev/null) $(wildcard dep/*)

