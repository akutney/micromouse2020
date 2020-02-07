/*
 * sensor_driver.c
 */

#include <error.h>

#include "sensor_driver.h"
#include "distance_sensor_driver.h"
#include "encoder_driver.h"
#include "time_driver.h"
#include "imu_driver.h"

int init_sensor_driver(void)
{
  // Initialize each sensors driver
  if (DISTANCE_SENSOR_DRIVER_ENABLED) {
    CHECK_ERR(init_distance_sensor_driver());
  }

  if (ENCODER_DRIVER_ENABLED) {
    CHECK_ERR(init_encoder_driver());
  }

  if (TIME_DRIVER_ENABLED) {
    CHECK_ERR(init_time_driver());
  }

  if (IMU_DRIVER_ENABLED) {
    CHECK_ERR(init_imu_driver());
  }

  return RETURN_SUCCESS;
}

int get_sensor_data(sensor_data_t *data)
{
  THROW_ERR("get_sensor_data", ENOSYS);
}