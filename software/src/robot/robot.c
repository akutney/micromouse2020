/*
 * robot.c
 */

#include <asf.h>
#include <string.h>
#include <error.h>

#include "robot.h"
#include <types.h>
#include "../algorithms/controller.h"
#include "../algorithms/guidance.h"
#include "../algorithms/navigation.h"


/* This function is called with in a loop in main.c */
int run_robot_loop(robot_t *robot)
{
  // Static so that we don't have to allocate each time the loop is called
  static sensor_data_t sensor_data;
  static motor_outputs_t motor_outputs;
  //static robot_state_t updated_robot_state;
  //static maze_state_t updated_maze_state;

  if (robot == NULL) { THROW_ERR("run_robot_loop", EINVAL); }

  CHECK_ERR(robot->get_sensor_data_callback(&sensor_data));

  /* Uncomment as the functions are implemented */
  // CHECK_ERR(navigation(
  //   &robot->robot_state,
  //   &robot->maze_state,
  //   &sensor_data,
  //   &updated_robot_state,
  //   &updated_maze_state));

  // memcpy(&robot->robot_state, &updated_robot_state, sizeof(robot_state_t));
  // memcpy(&robot->maze_state, &updated_maze_state, sizeof(maze_state_t));

  // CHECK_ERR(guidance(
  //   &robot->robot_state,
  //   &robot->maze_state,
  //   &robot->next_state));

  // CHECK_ERR(controller(
  //   &robot->robot_state, 
  //   &robot->next_state, 
  //   &motor_outputs));

  CHECK_ERR(robot->set_motor_outputs_callback(&motor_outputs));
  //CHECK_ERR(robot->set_led_outputs_callback(&led_outputs)); // TODO

  return RETURN_SUCCESS;
}
