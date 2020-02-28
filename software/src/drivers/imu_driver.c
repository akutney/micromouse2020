/*
 * imu_driver.c
 */

#include <asf.h>
#include <error.h>

#include <types.h>
#include "imu_driver.h"
#include "devices/BNO055.h"

bool IMU_DRIVER_ENABLED = false;

volatile imu_data_t *imu_data_ptr;

volatile bool started;
volatile bool ready_flag;

int _get_imu_data(bool is_blocking);

int init_imu_driver(void)
{
  CHECK_ERR(init_BNO055_driver());

  system_interrupt_enter_critical_section();
  started = false;
  ready_flag = false;
  system_interrupt_leave_critical_section();

  // TODO: Initialize BNO055 registers

  return RETURN_SUCCESS;
}

int start_get_imu_data(imu_data_t *data)
{
  system_interrupt_enter_critical_section();

  if (started)
  {
    system_interrupt_leave_critical_section();
    return RETURN_SUCCESS;
  }

  started = true;
  ready_flag = true; // TODO: Change to false once implemented
  imu_data_ptr = data;
  imu_data_ptr->data_valid = false;

  system_interrupt_leave_critical_section();

  // TODO: Start reading register over i2c

  return RETURN_SUCCESS;
}

int get_imu_data(void)
{
  CHECK_ERR(_get_imu_data(true));
  return RETURN_SUCCESS;
}

int try_get_imu_data(void)
{
  CHECK_ERR(_get_imu_data(false));
  return RETURN_SUCCESS;
}

int _get_imu_data(bool is_blocking)
{
  // Start read if not already started, then give user the distance_data once ready
  system_interrupt_enter_critical_section();

  if (!started)
  {
    system_interrupt_leave_critical_section();
    THROW_ERR("_get_imu_data", EIO);
  }

  if (is_blocking)
  {
    // Block
    system_interrupt_leave_critical_section();
    while (!ready_flag)
      ;
    system_interrupt_enter_critical_section();
  }
  else
  {
    // Non-Blocking
    if (!ready_flag)
    {
      system_interrupt_leave_critical_section();
      return RETURN_SUCCESS;
    }
  }

  // Reset flag
  ready_flag = false;

  system_interrupt_leave_critical_section();
  return RETURN_SUCCESS;
}
