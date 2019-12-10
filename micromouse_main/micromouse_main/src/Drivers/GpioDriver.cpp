/* 
 * GpioDriver.cpp
 *
 * Author: Dylan Staatz
 */


#include "GpioDriver.h"
#include "sam.h"


void
GpioDriver::ConfigurePin(pin_t pin, PIN_DIR direction)
{
    switch (direction) {
        case INPUT:
            PORT->Group[pin.port].DIR.reg |= 0x1 << pin.pinNum;
            PORT->Group[pin.port].PINCFG[pin.pinNum].reg = PORT_PINCFG_INEN;
            break;
        case OUTPUT:
            PORT->Group[pin.port].DIR.reg |= 0x1 << pin.pinNum;
            PORT->Group[pin.port].PINCFG[pin.pinNum].reg = 0x0;
            break;
        case INPUT_PULLUP:
            PORT->Group[pin.port].DIR.reg |= 0x1 << pin.pinNum;
            PORT->Group[pin.port].PINCFG[pin.pinNum].reg = PORT_PINCFG_INEN | PORT_PINCFG_PULLEN;
            break;
        default:
            break;
    }
}

GpioDriver::VALUE
GpioDriver::ReadPin(pin_t pin)
{
    return PORT->Group[pin.port].IN.reg & (0x1 << pin.pinNum) ? HIGH : LOW;
}

void
GpioDriver::SetPin(pin_t pin, VALUE val)
{
    switch (val) {
        case LOW:
            PORT->Group[pin.port].OUTCLR.reg |= 0x1 << pin.pinNum;
            break;
        case HIGH:
            PORT->Group[pin.port].OUTSET.reg |= 0x1 << pin.pinNum;
            break;
    }
}

void
GpioDriver::TogglePin(pin_t pin)
{
    PORT->Group[pin.port].OUTTGL.reg |= 0x1 << pin.pinNum;
}

