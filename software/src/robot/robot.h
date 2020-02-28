/* 
 * robot.h
 */

#ifndef __ROBOT_H__
#define __ROBOT_H__

#include <types.h>

/* If continuous mode is enabled, then run_robot_loop will be called
 * immediately. Otherwise, it will be called every Systick, however
 * fast that is configured */
#define CONTINUOUS_MODE

typedef int (*get_sensor_data_callback_t)(sensor_data_t *);
typedef int (*set_motor_outputs_callback_t)(motor_outputs_t *);
typedef int (*set_led_outputs_callback_t)(led_outputs_t *);

typedef struct
{
  robot_state_t robot_state;
  maze_state_t maze_state;
  robot_state_t next_state;
  get_sensor_data_callback_t get_sensor_data_callback;
  set_motor_outputs_callback_t set_motor_outputs_callback;
  set_led_outputs_callback_t set_led_outputs_callback;
} robot_t;

int run_robot_loop(robot_t * r);

#endif //__ROBOT_H__
