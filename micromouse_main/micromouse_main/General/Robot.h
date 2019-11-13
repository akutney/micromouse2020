/* 
* Robot.h
*
* Created: 11/12/2019 6:58:11 PM
* Author: Dylan Staatz
*/


#ifndef __ROBOT_H__
#define __ROBOT_H__


#include "../Drivers/TimingDriver.h"


class Robot
{
    
public:

    Robot();
    
    ~Robot();
    
    virtual void Setup();
    
    virtual void Loop();

protected:
    // Timing Driver
    // - need some class or function to set up timings
    TimingDriver timingDriver;

    // IMU Driver (I2C implementation)
    
    // IR Driver (ADC implementation)
    
    // Motor Driver (Either PWM implementation or attach another physical module to output PWM)
    
    // LED Driver (GPIO outputs)
    
    // Serial Driver (Need the ability to print to either blue tooth serial or USB for debugging)
    
    // EEPROM driver (store maze information through power cycles)

};

#endif //__ROBOT_H__
