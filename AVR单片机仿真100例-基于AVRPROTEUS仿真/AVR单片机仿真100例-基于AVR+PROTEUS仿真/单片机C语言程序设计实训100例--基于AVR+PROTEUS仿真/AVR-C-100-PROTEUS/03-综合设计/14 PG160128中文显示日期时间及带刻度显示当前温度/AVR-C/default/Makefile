###############################################################################
# Makefile for the project   PG160128中文显示日期时间及带刻度显示当前温度
###############################################################################

## General Flags
PROJECT =   PG160128中文显示日期时间及带刻度显示当前温度
MCU = atmega64
TARGET =   PG160128中文显示日期时间及带刻度显示当前温度.elf
CC = avr-gcc.exe

## Options common to compile, link and assembly rules
COMMON = -mmcu=$(MCU)

## Compile options common for all C compilation units.
CFLAGS = $(COMMON)
CFLAGS += -Wall -gdwarf-2              -DF_CPU=1000000UL  -O1 -fsigned-char
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
OBJECTS = main.o LCD_160128.o ds18b20.o ds1302.o

## Objects explicitly added by the user
LINKONLYOBJECTS = 

## Build
all: $(TARGET)   PG160128中文显示日期时间及带刻度显示当前温度.hex   PG160128中文显示日期时间及带刻度显示当前温度.eep size

## Compile
main.o: ../main.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

LCD_160128.o: ../LCD_160128.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

ds18b20.o: ../ds18b20.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

ds1302.o: ../ds1302.c
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
	-rm -rf $(OBJECTS)   PG160128中文显示日期时间及带刻度显示当前温度.elf dep/*   PG160128中文显示日期时间及带刻度显示当前温度.hex   PG160128中文显示日期时间及带刻度显示当前温度.eep

## Other dependencies
-include $(shell mkdir dep 2>/dev/null) $(wildcard dep/*)

