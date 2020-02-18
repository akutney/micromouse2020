/*
 * distance_sensor_driver.c
 */

#include <asf.h>
#include <error.h>

#include "../types/types.h"
#include "distance_sensor_driver.h"
#include "adc_driver.h"

// Need to take two measurements, one to record a base amount IR being
// received on the sensor, and one with the IR emitter on

// Need to set up interrupts and callbacks start these actions in order:
// - Take adc measurement (baseline)
// - Set emitter high
// - Take adc measurement
// - Set emitter low

bool DISTANCE_SENSOR_DRIVER_ENABLED = true;

typedef enum {
  NOT_STARTED,
  PHOTO_0,
  EMITTER_0,
  PHOTO_1,
  EMITTER_1,
} distance_driver_state;

distance_driver_state state;

int init_distance_sensor_driver(void)
{
  state = NOT_STARTED;
  init_adc_driver();
  // TODO: init_i2c_driver() ??? // Probably will call init_i2c_driver
  // multiple times from different drivers

  THROW_ERR("start_get_distance_sensor_data", ENOSYS);
}

int start_get_distance_sensor_data(void)
{
  THROW_ERR("start_get_distance_sensor_data", ENOSYS);
}

int get_distance_sensor_data(distance_sensor_data_t *distances)
{
  uint16_t * buffer = NULL;
  get_adc_data(buffer);

  // write_reg8(thing)...

  get_adc_data(buffer);

  // write_reg8(thing)...

  THROW_ERR("get_distance_sensor_data", ENOSYS);
}

int try_get_distance_sensor_data(distance_sensor_data_t *distances)
{
  THROW_ERR("get_distance_sensor_data", ENOSYS);
}
