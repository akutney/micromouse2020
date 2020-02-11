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
  if (DISTANCE_SENSOR_DRIVER_ENABLED)
  {
    CHECK_ERR(init_distance_sensor_driver());
  }

  if (ENCODER_DRIVER_ENABLED)
  {
    CHECK_ERR(init_encoder_driver());
  }

  if (TIME_DRIVER_ENABLED)
  {
    CHECK_ERR(init_time_driver());
  }

  if (IMU_DRIVER_ENABLED)
  {
    CHECK_ERR(init_imu_driver());
  }

  return RETURN_SUCCESS;
}

int get_sensor_data(sensor_data_t *data)
{
  /* ----- Call start functions ----- */
  CHECK_ERR(start_get_distance_sensor_data());
  CHECK_ERR(start_get_encoder_data());
  CHECK_ERR(start_get_imu_data());

  // Maybe wait for a bit?

  /* ----- Call get functions ----- */
  CHECK_ERR(get_distance_sensor_data(&(data->distance_sensor_data)));
  CHECK_ERR(get_encoder_data(&(data->encoder_data)));
  CHECK_ERR(get_imu_data(&(data->imu_data)));

  // Finally, get time last so it is most up to date
  CHECK_ERR(get_time(&(data->time_data)));

  return RETURN_SUCCESS;
}