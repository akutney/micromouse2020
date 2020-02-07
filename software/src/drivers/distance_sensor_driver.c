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

int get_distances(distance_sensor_data_t *distances)
{
  THROW_ERR("get_distances", ENOSYS);
}
