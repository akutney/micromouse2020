/*
 * navigation.c
 */ 

#include <error.h>

#include "navigation.h"

int navigation(
  const robot_state_t *const current_state,
  const maze_state_t *const current_maze,
  const sensor_data_t *const sensor_data,
  robot_state_t *const updated_state,
  maze_state_t *const updated_maze)
{
    THROW_ERR("navigation", ENOSYS);
}
