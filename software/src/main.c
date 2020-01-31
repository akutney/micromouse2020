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


#include <asf.h>

#include "robot/robot.h"


#define CONTINUOUS_MODE


// Function Declarations
void systick_init(void);


int main (void)
{
    // ASF system and board initialization
    system_init();

    /* Insert application code here, after the board has been initialized. */
    printf("System Initialized\r\n\n");

    printf("Starting Robot...\r\n\n");
    
    init_robot();

#ifdef CONTINUOUS_MODE
    while(1)
    {
        run_robot_loop();
    }
#else
    systick_init();
#endif
}


void systick_init(void)
{
    // Configure SysTick to trigger an ISR every millisecond using a 48MHz CPU Clock
    SysTick->CTRL = 0;                  // Disable SysTick
    SysTick->LOAD = 47999UL;            // Set reload register for 1mS interrupts
    NVIC_SetPriority(SysTick_IRQn, 3);  // Set interrupt priority to least urgency
    SysTick->VAL = 0;                   // Reset the SysTick counter value
    SysTick->CTRL = 0x00000007;         // Enable SysTick, Enable SysTick Exceptions, Use CPU Clock
    NVIC_EnableIRQ(SysTick_IRQn);       // Enable SysTick Interrupt
}


void SysTick_Handler(void)
{
    run_robot_loop();
}
