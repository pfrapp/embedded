#!/bin/zsh

# Just connect to the Tiva.
# Do not flash or debug anything.
openocd -s ~/share/openocd/scripts \
        -f interface/ftdi/olimex-arm-usb-ocd-h.cfg \
        -f target/stellaris.cfg \
        -c "adapter speed 1000"
