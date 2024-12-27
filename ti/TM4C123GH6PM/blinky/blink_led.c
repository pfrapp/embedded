#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "inc/hw_gpio.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/sysctl.h"

#define LED_PIN_GN     GPIO_PIN_3  // PF3
#define LED_PIN_RD     GPIO_PIN_2  // PF2
#define LED_PIN_S1     GPIO_PIN_1  // PF1

void setup() {
    // Set system clock to 50 MHz (this is often the default)
    SysCtlClockSet(SYSCTL_SYSDIV_4 | SYSCTL_OSC_MAIN | SYSCTL_USE_PLL | SYSCTL_XTAL_8MHZ);

    // Enable the GPIOF module (PF3 is on GPIO Port F)
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);

    // Wait for the GPIO module to be ready
    while (!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF)) {}

    // Set PF3 as an output pin
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, LED_PIN_GN | LED_PIN_RD | LED_PIN_S1);
}

void loop() {
    while (1) {
        // Toggle LED state (PF3)
        GPIOPinWrite(GPIO_PORTF_BASE, LED_PIN_GN, LED_PIN_GN);  // LED ON
        GPIOPinWrite(GPIO_PORTF_BASE, LED_PIN_RD, LED_PIN_RD);  // LED ON
        GPIOPinWrite(GPIO_PORTF_BASE, LED_PIN_S1, LED_PIN_S1);  // LED ON
        SysCtlDelay(2000000);  // Delay
        GPIOPinWrite(GPIO_PORTF_BASE, LED_PIN_GN, 0);  // LED OFF
        GPIOPinWrite(GPIO_PORTF_BASE, LED_PIN_RD, 0);  // LED OFF
        GPIOPinWrite(GPIO_PORTF_BASE, LED_PIN_S1, 0);  // LED OFF
        SysCtlDelay(2000000);  // Delay
    }
}

int main() {
    setup();
    loop();
    return 0;
}
