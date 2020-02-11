/*
 * distance_sensor_driver.c
 */

#include <asf.h>
#include <error.h>

#include "distance_sensor_driver.h"
#include "../types/types.h"

bool DISTANCE_SENSOR_DRIVER_ENABLED = true;

int init_distance_sensor_driver(void)
{
  THROW_ERR("init_distance_sensor_driver", ENOSYS);
}

int start_get_distance_sensor_data(void)
{
  THROW_ERR("start_get_distance_sensor_data", ENOSYS);
}

int get_distance_sensor_data(distance_sensor_data_t *distances)
{
  THROW_ERR("get_distance_sensor_data", ENOSYS);
}
