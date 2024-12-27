# Code for my embedded projects

In this repository, you find the code that I use for my
embedded projects, that is, programming microcontrollers.

You will mainly find source code, linker scripts, and
build files.

I would like to thank Freddie Chopin who used
to feature a bunch of embedded projects on his
website http://www.freddiechopin.info/.
It was very helpful to get started with topics
such as linker scripts.

## Tools

Here is an overview about the tools that I am currently using.

### JTAG adapter

Regarding the actual hardware needed for embedded programming,
I am using the Olimex ARM-USB-OCD-HL adapter wogether with the
20 to 10 pin converter.

### OpenOCD

I'm running a self-compiled OpenOCD on an Apple Silicon MacBook.
In order to get it compiled and running, I had to do some small adjustments.

* Issue: `glibtoolize` had not been found.<br />
  Solution: Rename to `libtoolize` and install `libtool`.
* Issue: Naming conflicts of `LIST_HEAD` with some XCode libraries.<br />
  Solution: Rename `LIST_HEAD` in the OpenOCD source code to for instance `MY_LIST_HEAD`.
* Issue: `libusb` was too old and not compiled for Apple Silicon.<br />
  Solution: Recompile and install from source.
* Issue: I got some linker errors related to "bitbang".<br />
  Solution: Configure via<br />
  ```
     ./configure --enable-remote-bitbang --enable-bitbang
  ```

### ARM Toolchain

I downloaded and installed `arm-gnu-toolchain-14.2.rel1-darwin-arm64-arm-none-eabi.pkg`
from
https://developer.arm.com/downloads/-/arm-gnu-toolchain-downloads

