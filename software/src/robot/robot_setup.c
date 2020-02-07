/*
 * robot_setup.c
 */

#include <asf.h>
#include <error.h>

#include "robot_setup.h"
#include "robot.h"
#include "../drivers/sensor_driver.h"
#include "../drivers/motor_driver.h"

int init_robot(robot_t *robot)
{
  // Initialize drivers and set up robot struct
  printf("Initializing Robot...\n");

  if (robot == NULL) { THROW_ERR("init_robot", EINVAL); }

  CHECK_ERR(init_sensor_driver());
  CHECK_ERR(init_motor_driver());
  
  robot->get_sensor_data_callback = get_sensor_data;
  robot->set_motor_outputs_callback = set_motor_outputs;
  
  return RETURN_SUCCESS;
}
