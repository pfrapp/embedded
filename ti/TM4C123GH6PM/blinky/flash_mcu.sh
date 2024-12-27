#!/bin/zsh

# Flash the binary to the MCU.
openocd -s ~/share/openocd/scripts \
        -f interface/ftdi/olimex-arm-usb-ocd-h.cfg \
        -f target/stellaris.cfg \
        -c "adapter speed 1000" \
        -c "init" \
        -c "reset halt" \
        -c "flash write_image erase ./build/blinky.bin 0x00000000" \
        -c "reset run"

