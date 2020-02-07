/*
 * gpio_driver.c
 */

#include <asf.h>
#include <stdint.h>

#include "gpio_driver.h"

int configure_pin(pin_t pin, pin_config config)
{
  switch (config)
  {
  case PIN_INPUT:
    PORT->Group[pin.port].DIR.reg |= 0x1 << pin.pinNum;
    PORT->Group[pin.port].PINCFG[pin.pinNum].reg = PORT_PINCFG_INEN;
    break;
  case PIN_OUTPUT:
    PORT->Group[pin.port].DIR.reg |= 0x1 << pin.pinNum;
    PORT->Group[pin.port].PINCFG[pin.pinNum].reg = 0x0;
    break;
  case PIN_INPUT_PULLUP:
    PORT->Group[pin.port].DIR.reg |= 0x1 << pin.pinNum;
    PORT->Group[pin.port].PINCFG[pin.pinNum].reg = PORT_PINCFG_INEN | PORT_PINCFG_PULLEN;
    break;
  default:
    break;
  }
}

inline int read_pin(pin_t pin, pin_value *val)
{
  (*val) = PORT->Group[pin.port].IN.reg & (0x1 << pin.pinNum) ? PIN_HIGH : PIN_LOW;
}

int set_pin(pin_t pin, pin_value val)
{
  switch (val)
  {
  case PIN_LOW:
    PORT->Group[pin.port].OUTCLR.reg |= 0x1 << pin.pinNum;
    break;
  case PIN_HIGH:
    PORT->Group[pin.port].OUTSET.reg |= 0x1 << pin.pinNum;
    break;
  }
}

inline int toggle_pin(pin_t pin)
{
  PORT->Group[pin.port].OUTTGL.reg |= 0x1 << pin.pinNum;
}
