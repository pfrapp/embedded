# List of all the STM Standard Periphera Lib source files.
PLATFORMSRC = ${STD_PERIPH_LIB_SRC}/adc.c \
              ${STD_PERIPH_LIB_SRC}/aes.c \
              ${STD_PERIPH_LIB_SRC}/can.c \
              ${STD_PERIPH_LIB_SRC}/comp.c \
              ${STD_PERIPH_LIB_SRC}/cpu.c \
              ${STD_PERIPH_LIB_SRC}/crc.c \
              ${STD_PERIPH_LIB_SRC}/des.c \
              ${STD_PERIPH_LIB_SRC}/eeprom.c \
              ${STD_PERIPH_LIB_SRC}/emac.c \
              ${STD_PERIPH_LIB_SRC}/epi.c \
              ${STD_PERIPH_LIB_SRC}/flash.c \
              ${STD_PERIPH_LIB_SRC}/fpu.c \
              ${STD_PERIPH_LIB_SRC}/gpio.c \
              ${STD_PERIPH_LIB_SRC}/hibernate.c \
              ${STD_PERIPH_LIB_SRC}/i2c.c \
              ${STD_PERIPH_LIB_SRC}/interrupt.c \
              ${STD_PERIPH_LIB_SRC}/lcd.c \
              ${STD_PERIPH_LIB_SRC}/mpu.c \
              ${STD_PERIPH_LIB_SRC}/pwm.c \
              ${STD_PERIPH_LIB_SRC}/qei.c \
              ${STD_PERIPH_LIB_SRC}/shamd5.c \
              ${STD_PERIPH_LIB_SRC}/ssi.c \
              ${STD_PERIPH_LIB_SRC}/sw_crc.c \
              ${STD_PERIPH_LIB_SRC}/sysctl.c \
              ${STD_PERIPH_LIB_SRC}/sysexc.c \
              ${STD_PERIPH_LIB_SRC}/systick.c \
              ${STD_PERIPH_LIB_SRC}/timer.c \
              ${STD_PERIPH_LIB_SRC}/uart.c \
              ${STD_PERIPH_LIB_SRC}/udma.c \
              ${STD_PERIPH_LIB_SRC}/usb.c \
              ${STD_PERIPH_LIB_SRC}/watchdog.c

# Required include directories
PLATFORMINC = ${STD_PERIPH_LIB_INC}