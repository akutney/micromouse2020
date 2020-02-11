/*
 * distance_sensor_driver.c
 */

#include <asf.h>
#include <error.h>

#include "../types/types.h"
#include "distance_sensor_driver.h"
#include "adc_driver.h"

bool DISTANCE_SENSOR_DRIVER_ENABLED = true;

int init_distance_sensor_driver(void)
{
  init_adc_driver();
  
  THROW_ERR("init_distance_sensor_driver", ENOSYS);
}

int start_get_distance_sensor_data(void)
{
  // Need to take two measurements, one to record a base amount IR being
  // received on the sensor, and one with the IR emitter on
  
  // Need to set up interrupts and callbacks start these actions in order:
  // - Take adc measurement (baseline)
  // - Set emitter high
  // - Take adc measurement
  // - Set emitter low
  
  THROW_ERR("start_get_distance_sensor_data", ENOSYS);
}

int get_distance_sensor_data(distance_sensor_data_t *distances)
{
  THROW_ERR("get_distance_sensor_data", ENOSYS);
}
