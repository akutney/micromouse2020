/*
 * micromouse_main.cpp
 *
 * Created: 11/12/2019 5:12:01 PM
 * Author : Dylan Staatz
 */ 


#include "sam.h"

#include "src/Clocks/ClocksInit.h"

#include "src/Types/Ints.h"

#include "src/Drivers/GpioDriver.h"
#include "src/Drivers/SerialDriver.h"

#include "src/Controller/RobotConfig.h"
#include "src/Controller/NGCRobot.h"

// Embedded Tests
#include "Tests.h"


using namespace GpioDriver;


// Globals and Constants

pin_t ledPin = {
    .port = PORT_A,
    .pinNum = 17
};


// Function Declarations
void SysTickInit(void);


int main(void)
{
    // Initialize the SAM system
    SystemInit();

    // Setup 48 MHz system clock based on external 32.768 kHz MHz clock
    ClocksInit();
    
    // Uncomment to run a test
    //test_GpioDriver();
    
    // Initialize Serial Console
    //SerialDriver serial();

    // Configure flashing LED
    ConfigurePin(ledPin, OUTPUT);
    SetPin(ledPin, LOW);

    // Set up SysTick_Handler to be called every 1mS
    SysTickInit();
}


void SysTick_Handler(void)
{
	static uint32_t tickCount = 0;

    tickCount++ ;
	// Toggle LEDs every second (i.e. 1000ms)
	if(tickCount % 1000 == 0){
		// Toggle LED pin output level.
		TogglePin(ledPin);
	}


}


void SysTickInit(void)
{
	// Configure SysTick to trigger an ISR every millisecond using a 48MHz CPU Clock
	SysTick->CTRL = 0;					// Disable SysTick
	SysTick->LOAD = 47999UL;			// Set reload register for 1mS interrupts
	NVIC_SetPriority(SysTick_IRQn, 3);	// Set interrupt priority to least urgency
	SysTick->VAL = 0;					// Reset the SysTick counter value
	SysTick->CTRL = 0x00000007;			// Enable SysTick, Enable SysTick Exceptions, Use CPU Clock
	NVIC_EnableIRQ(SysTick_IRQn);		// Enable SysTick Interrupt
}