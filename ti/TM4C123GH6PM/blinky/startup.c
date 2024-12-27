/* Startup-Datei und Linker-Skript kommen von
   http://www.firefly-power.de/ARM/STM32_Plattform_Beschreibung.html
*/

/** \file startup.c
 * \brief STM32 (STM32F101 - STM32F103) vector table and startupcode
 * \details STM32 (STM32F101 - STM32F103) vector table and startupcode
 * \author Marten Petschke
 * \date 21.Aug.2012
 */

/******************************************************************************
* chip: STM32F101VB
* compiler: yagarto-gcc 7.1
******************************************************************************/

extern unsigned long __data_init_start;      // init value location in the flash
extern unsigned long __data_start;           // RAM
extern unsigned long __data_end;             // RAM
extern unsigned long __bss_start;            // RAM
extern unsigned long __bss_end;              // RAM
extern unsigned long __process_stack_end;	   // new stack for normal mode (from linker script)
extern unsigned long __main_stack_end;			// main and intr stack end (from linker script)

/*
+=============================================================================+
| local declarations
+=============================================================================+
*/

void Reset_Handler(void);
void main(void);

/*
+=============================================================================+
| Reset_Handler() - first code after reset
+=============================================================================+
*/
void Reset_Handler(void)
{

#if defined USE_SEPARATE_NORMALMODE_STACK
 asm volatile(
	"ldr		r0, =__process_stack_end" "\n\t"  /*  */
	"msr		PSP, r0"    "\n\t"  /*  */

	"movs		r0, 2"         "\n\t"  /* #define CONTROL_ALTERNATE_STACK	(1 << 1) */
	"msr		CONTROL, r0" "\n\t"
	"isb"                "\n\t"  /*  */
   );

   /*
   PSP register:
     bit:  0..31  aux. process stack pointer end

   CONTROL register:
     bit:      0  Execution privilege in Thread mode
     bit:      1  aux. stack to be used for Thread mode
     bit:      2  FP extension active flag
     bit:  3..31  Reserved
   */
#endif

 unsigned long *source;
 unsigned long *destination;

 // Copying data from Flash to RAM  //Initialize .data section
 source = &__data_init_start;
 for (destination = &__data_start; destination < &__data_end;){
	*(destination++) = *(source++);
 }
 // default zero to undefined variables //Zero-init .bss section
 for (destination = &__bss_start; destination < &__bss_end;){
	*(destination++) = 0;
 }
 // starting main program
 main();
}


/*------------------------------------------------------------------------*//**
* \brief Default interrupt handler.
* \details Default interrupt handler, used for interrupts that don't have their
* own handler defined.
*//*-------------------------------------------------------------------------*/

static void IntDefaultHandler(void) __attribute__ ((interrupt));
static void IntDefaultHandler(void){
	while (1);
}




/*
+=============================================================================+
| Vector table,  ".vectors" must be defined in linker script
| This table covers the very first 8 bytes in the Flash. They contain a
| stack address and a jump address to the first code - Reset_handler()
+=============================================================================+
*/

void (* const vectors[])(void) __attribute__ ((section(".vectors"))) = {
		(void (*)(void))&__main_stack_end,	// Main stack end address
		Reset_Handler,                               // The reset handler
		IntDefaultHandler,                                  // The NMI handler
		IntDefaultHandler,                               // The hard fault handler
	    IntDefaultHandler,                      // The MPU fault handler
	    IntDefaultHandler,                      // The bus fault handler
	    IntDefaultHandler,                      // The usage fault handler
	    0,                                      // Reserved
	    0,                                      // Reserved
	    0,                                      // Reserved
	    0,                                      // Reserved
	    IntDefaultHandler,                      // SVCall handler
	    IntDefaultHandler,                      // Debug monitor handler
	    0,                                      // Reserved
	    IntDefaultHandler,                      // The PendSV handler
	    IntDefaultHandler,                      // The SysTick handler
	    IntDefaultHandler,                      // GPIO Port A
	    IntDefaultHandler,                      // GPIO Port B
		IntDefaultHandler,                      // GPIO Port C
		IntDefaultHandler,                      // GPIO Port D
	    IntDefaultHandler,                      // GPIO Port E
		IntDefaultHandler,                      // UART0 Rx and Tx
	    IntDefaultHandler,                      // UART1 Rx and Tx
	    IntDefaultHandler,                      // SSI0 Rx and Tx
		IntDefaultHandler,                      // I2C0 Master and Slave
	    IntDefaultHandler,                      // PWM Fault
	    IntDefaultHandler,                      // PWM Generator 0
	    IntDefaultHandler,                      // PWM Generator 1
	    IntDefaultHandler,                      // PWM Generator 2
	    IntDefaultHandler,                      // Quadrature Encoder 0
	    IntDefaultHandler,                      // ADC Sequence 0
	    IntDefaultHandler,                      // ADC Sequence 1
	    IntDefaultHandler,                      // ADC Sequence 2
	    IntDefaultHandler,                      // ADC Sequence 3
	    IntDefaultHandler,                      // Watchdog timer
		IntDefaultHandler,                      	// Timer 0 subtimer A
	    IntDefaultHandler,                      // Timer 0 subtimer B
	    IntDefaultHandler,                      // Timer 1 subtimer A
	    IntDefaultHandler,                      // Timer 1 subtimer B
	    IntDefaultHandler,                      // Timer 2 subtimer A
	    IntDefaultHandler,                      // Timer 2 subtimer B
	    IntDefaultHandler,                      // Analog Comparator 0
	    IntDefaultHandler,                      // Analog Comparator 1
	    IntDefaultHandler,                      // Analog Comparator 2
	    IntDefaultHandler,                      // System Control (PLL, OSC, BO)
	    IntDefaultHandler,                      // FLASH Control
		IntDefaultHandler,                      // GPIO Port F
	    IntDefaultHandler,                      // GPIO Port G
	    IntDefaultHandler,                      // GPIO Port H
	    IntDefaultHandler,                      // UART2 Rx and Tx
	    IntDefaultHandler,                      // SSI1 Rx and Tx
	    IntDefaultHandler,                      // Timer 3 subtimer A
	    IntDefaultHandler,                      // Timer 3 subtimer B
	    IntDefaultHandler,                      // I2C1 Master and Slave
	    IntDefaultHandler,                      // Quadrature Encoder 1
		IntDefaultHandler,                      // CAN0
	    IntDefaultHandler,                      // CAN1
	    0,                                      // Reserved
	    0,                                      // Reserved
	    IntDefaultHandler,                      // Hibernate
	    IntDefaultHandler,                      // USB0
	    IntDefaultHandler,                      // PWM Generator 3
	    IntDefaultHandler,                      // uDMA Software Transfer
	    IntDefaultHandler,                      // uDMA Error
	    IntDefaultHandler,                      // ADC1 Sequence 0
	    IntDefaultHandler,                      // ADC1 Sequence 1
	    IntDefaultHandler,                      // ADC1 Sequence 2
	    IntDefaultHandler,                      // ADC1 Sequence 3
	    0,                                      // Reserved
	    0,                                      // Reserved
	    IntDefaultHandler,                      // GPIO Port J
	    IntDefaultHandler,                      // GPIO Port K
	    IntDefaultHandler,                      // GPIO Port L
	    IntDefaultHandler,                      // SSI2 Rx and Tx
	    IntDefaultHandler,                      // SSI3 Rx and Tx
	    IntDefaultHandler,                      // UART3 Rx and Tx
	    IntDefaultHandler,                      // UART4 Rx and Tx
	    IntDefaultHandler,                      // UART5 Rx and Tx
	    IntDefaultHandler,                      // UART6 Rx and Tx
	    IntDefaultHandler,                      // UART7 Rx and Tx
	    0,                                      // Reserved
	    0,                                      // Reserved
	    0,                                      // Reserved
	    0,                                      // Reserved
	    IntDefaultHandler,                      // I2C2 Master and Slave
	    IntDefaultHandler,                      // I2C3 Master and Slave
	    IntDefaultHandler,                      // Timer 4 subtimer A
	    IntDefaultHandler,                      // Timer 4 subtimer B
	    0,                                      // Reserved
	    0,                                      // Reserved
	    0,                                      // Reserved
	    0,                                      // Reserved
	    0,                                      // Reserved
	    0,                                      // Reserved
	    0,                                      // Reserved
	    0,                                      // Reserved
	    0,                                      // Reserved
	    0,                                      // Reserved
	    0,                                      // Reserved
	    0,                                      // Reserved
	    0,                                      // Reserved
	    0,                                      // Reserved
	    0,                                      // Reserved
	    0,                                      // Reserved
	    0,                                      // Reserved
	    0,                                      // Reserved
	    0,                                      // Reserved
	    0,                                      // Reserved
	    IntDefaultHandler,                      // Timer 5 subtimer A
	    IntDefaultHandler,                      // Timer 5 subtimer B
	    IntDefaultHandler,                      // Wide Timer 0 subtimer A
	    IntDefaultHandler,                      // Wide Timer 0 subtimer B
	    IntDefaultHandler,                      // Wide Timer 1 subtimer A
	    IntDefaultHandler,                      // Wide Timer 1 subtimer B
	    IntDefaultHandler,                      // Wide Timer 2 subtimer A
	    IntDefaultHandler,                      // Wide Timer 2 subtimer B
	    IntDefaultHandler,                      // Wide Timer 3 subtimer A
	    IntDefaultHandler,                      // Wide Timer 3 subtimer B
	    IntDefaultHandler,                      // Wide Timer 4 subtimer A
	    IntDefaultHandler,                      // Wide Timer 4 subtimer B
	    IntDefaultHandler,                      // Wide Timer 5 subtimer A
	    IntDefaultHandler,                      // Wide Timer 5 subtimer B
	    IntDefaultHandler,                      // FPU
	    IntDefaultHandler,                      // PECI 0
	    IntDefaultHandler,                      // LPC 0
	    IntDefaultHandler,                      // I2C4 Master and Slave
	    IntDefaultHandler,                      // I2C5 Master and Slave
	    IntDefaultHandler,                      // GPIO Port M
	    IntDefaultHandler,                      // GPIO Port N
	    IntDefaultHandler,                      // Quadrature Encoder 2
	    IntDefaultHandler,                      // Fan 0
	    0,                                      // Reserved
	    IntDefaultHandler,                      // GPIO Port P (Summary or P0)
	    IntDefaultHandler,                      // GPIO Port P1
	    IntDefaultHandler,                      // GPIO Port P2
	    IntDefaultHandler,                      // GPIO Port P3
	    IntDefaultHandler,                      // GPIO Port P4
	    IntDefaultHandler,                      // GPIO Port P5
	    IntDefaultHandler,                      // GPIO Port P6
	    IntDefaultHandler,                      // GPIO Port P7
	    IntDefaultHandler,                      // GPIO Port Q (Summary or Q0)
	    IntDefaultHandler,                      // GPIO Port Q1
	    IntDefaultHandler,                      // GPIO Port Q2
	    IntDefaultHandler,                      // GPIO Port Q3
	    IntDefaultHandler,                      // GPIO Port Q4
	    IntDefaultHandler,                      // GPIO Port Q5
	    IntDefaultHandler,                      // GPIO Port Q6
	    IntDefaultHandler,                      // GPIO Port Q7
	    IntDefaultHandler,                      // GPIO Port R
	    IntDefaultHandler,                      // GPIO Port S
	    IntDefaultHandler,                      // PWM 1 Generator 0
	    IntDefaultHandler,                      // PWM 1 Generator 1
	    IntDefaultHandler,                      // PWM 1 Generator 2
	    IntDefaultHandler,                      // PWM 1 Generator 3
	    IntDefaultHandler                       // PWM 1 Fault
};

/******************************************************************************
* END OF FILE
******************************************************************************/
