/*
 * motor_driver.c
 */ 

#include <error.h>

#include "motor_driver.h"
#include "i2c_driver.h"
#include <types.h>

int init_motor_driver(void)
{
  init_i2c_driver();

  THROW_ERR("init_motor_driver", ENOSYS);
}

int set_motor_outputs(motor_outputs_t *outputs)
{
  THROW_ERR("set_motor_outputs", ENOSYS);
}
