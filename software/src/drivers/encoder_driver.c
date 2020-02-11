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

int start_get_encoder_data(void)
{
  THROW_ERR("start_get_encoder_data", ENOSYS);
}

int get_encoder_data(encoder_data_t *values)
{
  THROW_ERR("get_encoder_data", ENOSYS);
}
