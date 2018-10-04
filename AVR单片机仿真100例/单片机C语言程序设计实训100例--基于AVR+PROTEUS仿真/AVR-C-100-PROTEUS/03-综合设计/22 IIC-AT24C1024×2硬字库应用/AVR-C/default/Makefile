###############################################################################
# Makefile for the project  IIC-AT24C1024×2硬字库应用
###############################################################################

## General Flags
PROJECT =  IIC-AT24C1024×2硬字库应用
MCU = atmega16
TARGET =  IIC-AT24C1024×2硬字库应用.elf
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
OBJECTS = main.o LCD12864.o AT24C1024.o

## Objects explicitly added by the user
LINKONLYOBJECTS = 

## Build
all: $(TARGET)  IIC-AT24C1024×2硬字库应用.hex  IIC-AT24C1024×2硬字库应用.eep size
build: elf hex eep lss sym extcoff

## Compile
main.o: ../main.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

LCD12864.o: ../LCD12864.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

AT24C1024.o: ../AT24C1024.c
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
	-rm -rf $(OBJECTS)  IIC-AT24C1024×2硬字库应用.elf dep/*  IIC-AT24C1024×2硬字库应用.hex  IIC-AT24C1024×2硬字库应用.eep

## Other dependencies
-include $(shell mkdir dep 2>/dev/null) $(wildcard dep/*)





