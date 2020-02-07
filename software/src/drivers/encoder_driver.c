/*
 * encoder_driver.c
 */ 


#include <asf.h>
#include <error.h>

#include "encoder_driver.h"

bool ENCODER_DRIVER_ENABLED = false;

int init_encoder_driver(void)
{
  THROW_ERR("init_encoder_driver", ENOSYS);
}

int get_encoder_values(encoder_data_t *values)
{
  THROW_ERR("get_encoder_values", ENOSYS);
}
