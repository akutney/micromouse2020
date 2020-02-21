/*
 * led_driver.h
 */ 


#ifndef __LED_DRIVER_H__
#define __LED_DRIVER_H__

#include <asf.h>
#include <error.h>
#include "../types/types.h"

extern bool LED_DRIVER_ENABLED;

int init_led_driver(void);

int set_led_outputs(led_outputs_t * outputs);

#endif /* __LED_DRIVER_H__ */
