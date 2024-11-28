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
PLATFORM = MSP432


#General Flags (Both Platforms)
CFLAGS = -Wall -Werror -g -O0 -std=c99 -Wno-attributes
CFLAGS += -D$(PLATFORM)
TARGET = c1m2
LDFLAGS = -Wl,-Map=$(TARGET).map
DEPFLAGS = -MMD -MP -MF $(@:.o=.d)


ifeq ($(PLATFORM),MSP432)
	CC = arm-none-eabi-gcc
	
	SOURCES += $(SOURCES2)
	INCLUDES += $(INCLUDES2)

	# Architectures Specific Flags
	LINKER_FILE = ../msp432p401r.lds
	CPU = cortex-m4
	ARCH = armv7e-m
	SPECS = nosys.specs
	CFLAGS += -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16
	CFLAGS += -mcpu=$(CPU) -march=$(ARCH) --specs=$(SPECS)
	LDFLAGS += -T $(LINKER_FILE)
else
	CC = gcc
endif


#Build rule 1
%.i : %.c
	$(CC) $(CFLAGS) $(INCLUDES) -E $< -o $@

#Build rule 2
%.asm : %.c
	$(CC) $(CFLAGS) $(INCLUDES) -S $< -o $@

#Build rule 3
%.o : %.c
	$(CC) $(CFLAGS) $(DEPFLAGS) $(INCLUDES) -c $< -o $@


#Build rule 4: compile-all
OBJS = $(SOURCES:.c=.o)

.PHONY: compile-all
compile-all: $(OBJS)


#Build rule 5: build
.PHONY: build
build: $(TARGET).out
	
$(TARGET).out: $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^


#Build rule 6: clean
.PHONY: clean
clean:
	rm -f *.i *.asm *.o *.d *.map *.out