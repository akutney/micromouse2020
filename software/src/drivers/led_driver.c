/*
 * led_driver.c
 */ 

#include <asf.h>
#include <error.h>
#include "i2c_driver.h"
#include "../types/types.h"

bool LED_DRIVER_ENABLED = true;

int init_led_driver(void)
{
  init_i2c_driver();
  THROW_ERR("init_led_driver", ENOSYS);
}

int set_led_outputs(led_outputs_t * outputs)
{
  THROW_ERR("set_led_outputs", ENOSYS);
}
