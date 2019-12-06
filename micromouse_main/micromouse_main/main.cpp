/*
 * micromouse_main.cpp
 *
 * Created: 11/12/2019 5:12:01 PM
 * Author : Dylan Staatz
 */ 

// System
#include "sam.h"

// General
#include "src/General/RobotConfig.h"
#include "src/General/NGCRobot.h"

// Drivers
#include "src/Drivers/GpioDriver.h"

// Types
#include "src/Types/Ints.h"

// Embedded Tests
#include "Tests.h"
#define RUN_TESTS


int main(void)
{
    // Initialize the SAM system
    SystemInit();
    
    // Uncomment to run a test
    //test_GpioDriver();
    
    // Actual Start of code
    // TODO:
}

