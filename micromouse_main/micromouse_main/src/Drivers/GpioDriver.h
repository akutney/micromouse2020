/* 
 * GpioDriver.h
 *
 * Author: Dylan Staatz
 */


#ifndef __GPIODRIVER_H__
#define __GPIODRIVER_H__

#include "../Types/Ints.h"


/* GpioDriver
 * 
 * Provides simple functions to create and use Gpio pins
 * Note: The current implementation does no error checking for the caller
 * 
 * Probably should be implemented as static functions
 * in a class but I couldn't get that to work
 */
namespace GpioDriver
{

    enum PIN_DIR {INPUT = 0, OUTPUT = 1, INPUT_PULLUP = 2};

    enum PORT_NUM {PORT_A = 0, PORT_B = 1};

    enum VALUE {LOW = 0, HIGH = 1};

    typedef struct {
        PORT_NUM port;
        uint8_t pinNum;
    } pin_t;

    
    void ConfigurePin(pin_t pin, PIN_DIR direction);

    VALUE ReadPin(pin_t pin);

    void SetPin(pin_t pin, VALUE val);


}; //GpioDriver

#endif //__GPIODRIVER_H__

