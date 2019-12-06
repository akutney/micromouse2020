/*
 * Tests.h
 *
 * Created: 12/6/2019 12:17:18 AM
 *  Author: Dylan Staatz
 */ 


#ifndef TESTS_H_
#define TESTS_H_

#include "src/Drivers/GpioDriver.h"

using namespace GpioDriver;


// Set and Clear pin d2 on the spark-fun board (pin A14 on the SAMD21)
uint8_t test_GpioDriver(void) {
    pin_t pin = {PORT_A, 14};
    ConfigurePin(pin, OUTPUT);
    SetPin(pin, HIGH);
    SetPin(pin, LOW);
    return 0;
}

#endif /* TESTS_H_ */