/*
 * micromouse_main.cpp
 *
 * Created: 11/12/2019 5:12:01 PM
 * Author : Dylan Staatz
 */ 

// System
#include "sam.h"

// General
#include "General/RobotConfig.h"
#include "General/Robot.h"


int main(void)
{
    // Initialize the SAM system
    SystemInit();

    // Dummy code to test that you can debug with
    
#if 0 // change to 1 if you want to run this
    while (1)
    {
        // Calculate the total from 0-99
        int total = 0;
        for (int i = 0; i < 100; i++) {
            total += i;
        }
    }
#endif
    
    // Actual Start of code
    Robot r;
    
    r.Setup();
    
    for (;;) {
        r.Loop();
    }
}