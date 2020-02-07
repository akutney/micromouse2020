/*
 * gpio_driver.h
 */

#ifndef __GPIO_DRIVER_H__
#define __GPIO_DRIVER_H__

#include <asf.h>
#include <stdint.h>

typedef enum
{
  PIN_INPUT,
  PIN_OUTPUT,
  PIN_INPUT_PULLUP,
} pin_config;

typedef enum
{
  PIN_PORT_A = PORT_A,
  PIN_PORT_B = PORT_B,
} pin_port;

typedef enum
{
  PIN_LOW,
  PIN_HIGH,
} pin_value;

typedef struct
{
  pin_port port;
  uint8_t pinNum;
} pin_t;

int configure_pin(pin_t pin, pin_config type);

int read_pin(pin_t pin, pin_value *val);

int set_pin(pin_t pin, pin_value val);

int toggle_pin(pin_t pin);

#endif /* __GPIO_DRIVER_H__ */
