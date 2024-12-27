##############################################################################
# Build global options
# NOTE: Can be overridden externally.
#

# Compiler options here.
# You might want to switch from O2 to O0 in order to disable optimization at all.
# That way, when debugging, the instruction pointer matches up with the source and
# does not seem to be jumping, see for instance:
# http://stackoverflow.com/questions/4692592/using-g-and-o2-options-in-gcc
# https://gcc.gnu.org/onlinedocs/gcc/Optimize-Options.html
ifeq ($(USE_OPT),)
  USE_OPT = -O0 -ggdb -fomit-frame-pointer -falign-functions=16
endif

# C specific options here (added to USE_OPT).
ifeq ($(USE_COPT),)
  USE_COPT = 
endif

# C++ specific options here (added to USE_OPT).
ifeq ($(USE_CPPOPT),)
  USE_CPPOPT = -fno-rtti
endif

# Enable this if you want the linker to remove unused code and data
ifeq ($(USE_LINK_GC),)
  USE_LINK_GC = yes
endif

# Linker extra options here.
ifeq ($(USE_LDOPT),)
  USE_LDOPT = 
endif

# Enable this if you want link time optimizations (LTO)
ifeq ($(USE_LTO),)
  USE_LTO = no
endif

# If enabled, this option allows to compile the application in THUMB mode.
ifeq ($(USE_THUMB),)
  USE_THUMB = yes
endif

# Enable this if you want to see the full log while compiling.
ifeq ($(USE_VERBOSE_COMPILE),)
  USE_VERBOSE_COMPILE = no
endif

#
# Build global options
##############################################################################

##############################################################################
# Architecture or project specific options
#

#
# Architecture or project specific options
##############################################################################

##############################################################################
# Project, sources and paths
#

# Define project name here
PROJECT = blinky

# Path to Standard Peripheral Driver Lib
STD_PERIPH_LIB_BASE = $(HOME)/ti/tivaware_c_series_2_1_4_178
STD_PERIPH_LIB_SRC = $(STD_PERIPH_LIB_BASE)/driverlib
STD_PERIPH_LIB_INC = $(STD_PERIPH_LIB_BASE)/driverlib

TIVA_INC = $(STD_PERIPH_LIB_BASE)/inc


# Imported source files and paths

include ./driver_lib.mk


# Define linker script file here
LDSCRIPT = ./tm4c123gh6pm_rom

# C sources that can be compiled in ARM or THUMB mode depending on the global
# setting.
CSRC = $(PLATFORMSRC) blink_led.c startup.c
	

# C++ sources that can be compiled in ARM or THUMB mode depending on the global
# setting.
CPPSRC =

# C sources to be compiled in ARM mode regardless of the global setting.
# NOTE: Mixing ARM and THUMB mode enables the -mthumb-interwork compiler
#       option that results in lower performance and larger code size.
ACSRC =

# C++ sources to be compiled in ARM mode regardless of the global setting.
# NOTE: Mixing ARM and THUMB mode enables the -mthumb-interwork compiler
#       option that results in lower performance and larger code size.
ACPPSRC =

# C sources to be compiled in THUMB mode regardless of the global setting.
# NOTE: Mixing ARM and THUMB mode enables the -mthumb-interwork compiler
#       option that results in lower performance and larger code size.
TCSRC =

# C sources to be compiled in THUMB mode regardless of the global setting.
# NOTE: Mixing ARM and THUMB mode enables the -mthumb-interwork compiler
#       option that results in lower performance and larger code size.
TCPPSRC =

# List ASM source files here
ASMSRC = 

INCDIR = 	$(PLATFORMINC) \
			$(TIVA_INC) \
			$(STD_PERIPH_LIB_BASE)

#
# Project, sources and paths
##############################################################################

##############################################################################
# Compiler settings
#

MCU  = cortex-m3

#TRGT = arm-elf-
TRGT = arm-none-eabi-
CC   = $(TRGT)gcc
CPPC = $(TRGT)g++
# Enable loading with g++ only if you need C++ runtime support.
# NOTE: You can use C++ even without C++ support if you are careful. C++
#       runtime support makes code size explode.
LD   = $(TRGT)gcc
#LD   = $(TRGT)g++
CP   = $(TRGT)objcopy
#AS   = $(TRGT)gcc -x assembler-with-cpp
# Assembler binary mal aendern, um zu testen, ob es dann tut
AS = $(TRGT)as
OD   = $(TRGT)objdump
SZ   = $(TRGT)size
HEX  = $(CP) -O ihex
BIN  = $(CP) -O binary

# ARM-specific options here
AOPT =

# THUMB-specific options here
TOPT = -mthumb -DTHUMB

# Define C warning options here
# CWARN = -Wall -Wextra -Wstrict-prototypes
# -Wstrict-prototypes abschalten
CWARN = -Wall -Wextra

# Define C++ warning options here
CPPWARN = -Wall -Wextra

#
# Compiler settings
##############################################################################

##############################################################################
# Start of default section
#

# List all default C defines here, like -D_DEBUG=1
DDEFS = -Dgcc -DPART_TM4C123GH6PM

# List all default ASM defines here, like -D_DEBUG=1
DADEFS =

# List all default directories to look for include files here
DINCDIR =

# List the default directory to look for the libraries here
DLIBDIR =

# List all default libraries here
DLIBS =

#
# End of default section
##############################################################################

##############################################################################
# Start of user section
#

# List all user C define here, like -D_DEBUG=1
UDEFS =
#UDEFS += -DUSE_CAN
#UDEFS += -DUSE_SERVO

# Define ASM defines here
UADEFS =

# List all user directories here
UINCDIR =

# List the user directory to look for the libraries here
ULIBDIR =

# List all user libraries here
# siehe hier:
# https://stackoverflow.com/questions/13235748/linker-error-on-a-c-project-using-eclipse
# fuer eine Erklaerung, warum die Libs nach -lm auch noch benoetigt werden
ULIBS = -lm -lc -lgcc -lg -lnosys -lrdimon

#
# End of user defines
##############################################################################

#RULESPATH = $(CHIBIOS)/os/ports/GCC/ARMCMx
#include $(RULESPATH)/rules.mk

include ./rules.mk

