/*
 * gpio_driver.h
 * 
 * Allows users to use pins defined in pins.h
 */

#ifndef __GPIO_DRIVER_H__
#define __GPIO_DRIVER_H__

#include <asf.h>
#include <stdint.h>
#include <types.h>

int configure_pin(pin_t pin, pin_config type);

int read_pin(pin_t pin, pin_value *val);

int set_pin(pin_t pin, pin_value val);

int toggle_pin(pin_t pin);

#endif /* __GPIO_DRIVER_H__ */
