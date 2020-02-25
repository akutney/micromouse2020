/*
 * imu_driver.c
 */ 

#include <asf.h>
#include <error.h>

#include "imu_driver.h"

bool IMU_DRIVER_ENABLED;

int init_imu_driver(void)
{
  THROW_ERR("init_imu_driver", ENOSYS);
}

int start_get_imu_data(void)
{
  THROW_ERR("start_get_imu_data", ENOSYS);
}

int get_imu_data(imu_data_t *data)
{
  THROW_ERR("get_imu_data", ENOSYS);
}

int try_get_imu_data(imu_data_t *data)
{
  THROW_ERR("try_get_imu_data", ENOSYS);
}
