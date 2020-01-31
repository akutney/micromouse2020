/**
 * \file
 *
 * \brief Empty user application template
 *
 */

/**
 * \mainpage User Application template doxygen documentation
 *
 * \par Empty user application template
 *
 * Bare minimum empty user application template
 *
 * \par Content
 *
 * -# Include the ASF header files (through asf.h)
 * -# Minimal main function that starts with a call to system_init()
 * -# "Insert application code here" comment
 *
 */

/*
 * Include header files for all drivers that have been imported from
 * Atmel Software Framework (ASF).
 */
/*
 * Support and FAQ: visit <a href="https://www.microchip.com/support/">Microchip Support</a>
 */

#include "samd21.h"
#include <asf.h>

#include "types/types.h"

#include "algorithms/navigation.h"
#include "algorithms/guidance.h"
#include "algorithms/controller.h"

#define LED_PORT	PORTA
#define LED_PIN		17


// Function Declarations
void SysTick_Init(void);

int main (void)
{
    // ASF system and board initialization
    system_init();

    /* Insert application code here, after the board has been initialized. */
    printf("Hello World!\r\n");
    
    // Configure LED pin
    LED_PORT.DIR.reg |= 0x1 << LED_PIN;
    LED_PORT.PINCFG[LED_PIN].reg = 0x0;

    SysTick_Init();
}

void SysTick_Handler(void)
{
    static uint32_t tickCount = 0;

    tickCount++ ;
    // Toggle LEDs every second (i.e. 1000ms)
    if(tickCount % 1000 == 0){
        // Toggle LED pin output level.
        LED_PORT.OUTTGL.reg |= 0x1 << LED_PIN;
    }

}


void SysTick_Init(void)
{
    // Configure SysTick to trigger an ISR every millisecond using a 48MHz CPU Clock
    SysTick->CTRL = 0;					// Disable SysTick
    SysTick->LOAD = 47999UL;			// Set reload register for 1mS interrupts
    NVIC_SetPriority(SysTick_IRQn, 3);	// Set interrupt priority to least urgency
    SysTick->VAL = 0;					// Reset the SysTick counter value
    SysTick->CTRL = 0x00000007;			// Enable SysTick, Enable SysTick Exceptions, Use CPU Clock
    NVIC_EnableIRQ(SysTick_IRQn);		// Enable SysTick Interrupt
}