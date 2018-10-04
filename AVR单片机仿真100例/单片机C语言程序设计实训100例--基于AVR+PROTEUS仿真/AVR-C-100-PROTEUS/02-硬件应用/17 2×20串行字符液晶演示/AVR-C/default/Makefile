###############################################################################
# Makefile for the project 2¡Á20´®ÐÐ×Ö·ûÒº¾§ÑÝÊ¾
###############################################################################

## General Flags
PROJECT = 2¡Á20´®ÐÐ×Ö·ûÒº¾§ÑÝÊ¾
MCU = atmega16
TARGET = 2¡Á20´®ÐÐ×Ö·ûÒº¾§ÑÝÊ¾.elf
CC = avr-gcc.exe

## Options common to compile, link and assembly rules
COMMON = -mmcu=$(MCU)

## Compile options common for all C compilation units.
CFLAGS = $(COMMON)
CFLAGS += -Wall -gdwarf-2                    -DF_CPU=4000000UL  -O1 -fsigned-char
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
OBJECTS = 2¡Á20´®ÐÐ×Ö·ûÒº¾§ÑÝÊ¾.o 

## Objects explicitly added by the user
LINKONLYOBJECTS = 

## Build
all: $(TARGET) 2¡Á20´®ÐÐ×Ö·ûÒº¾§ÑÝÊ¾.hex 2¡Á20´®ÐÐ×Ö·ûÒº¾§ÑÝÊ¾.eep

## Compile
2¡Á20´®ÐÐ×Ö·ûÒº¾§ÑÝÊ¾.o: ../2¡Á20´®ÐÐ×Ö·ûÒº¾§ÑÝÊ¾.c
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
	-rm -rf $(OBJECTS) 2¡Á20´®ÐÐ×Ö·ûÒº¾§ÑÝÊ¾.elf dep/* 2¡Á20´®ÐÐ×Ö·ûÒº¾§ÑÝÊ¾.hex 2¡Á20´®ÐÐ×Ö·ûÒº¾§ÑÝÊ¾.eep

## Other dependencies
-include $(shell mkdir dep 2>/dev/null) $(wildcard dep/*)

