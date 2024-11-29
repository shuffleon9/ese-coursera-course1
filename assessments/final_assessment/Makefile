#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# <Put a Description Here>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <Put a description of the supported targets here>
#
# Platform Overrides:
#      <Put a description of the supported Overrides here
#
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides: HOST or MSP432
PLATFORM = HOST


#General Flags (Both Platforms)
CFLAGS = -Wall -g -O0 -std=c99 -Wno-attributes
CFLAGS += -D$(PLATFORM) 
CFLAGS += -DCOURSE1 -DVERBOSE
TARGET = c1final
LDFLAGS = -Wl,-Map=$(TARGET).map


ifeq ($(PLATFORM),MSP432)
	CC = arm-none-eabi-gcc
	
	SOURCES += $(SOURCES2)
	INCLUDES += $(INCLUDES2)

	# Architectures Specific Flags
	LINKER_FILE = msp432p401r.lds
	CPU = cortex-m4
	ARCH = armv7e-m
	SPECS = nosys.specs
	CFLAGS += -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16
	CFLAGS += -mcpu=$(CPU) -march=$(ARCH) --specs=$(SPECS)
	LDFLAGS += -T $(LINKER_FILE)
else
	CC = gcc
endif


%.o : %.c
	$(CC) $(CFLAGS) $(DEPFLAGS) $(INCLUDES) -c $< -o $@

OBJS = $(SOURCES:.c=.o)

.PHONY: build
build: $(TARGET).out
	
$(TARGET).out: $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^


.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET).out $(TARGET).map