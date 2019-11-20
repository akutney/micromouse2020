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

// Types
#include "src/Types/ButtonData.h"
#include "src/Types/SensorData.h"
#include "src/Types/RobotState.h"
#include "src/Types/MazeState.h"
#include "src/Types/MotorOutputs.h"


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
    ButtonData bd;
    SensorData sd;
    MazeState ms;
    RobotState rs;
    MotorOutputs mo;
    
}