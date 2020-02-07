/* 
 * navigation.h
 */

#ifndef __NAVIGATION_H__
#define __NAVIGATION_H__

#include "../types/types.h"

/* navigation
 * 
 * Updates robot and maze states based on the
 * current states and the new sensor data */
int navigation(
    const robot_state_t *const current_state,
    const maze_state_t *const current_maze,
    const sensor_data_t *const sensor_data,
    robot_state_t *const updated_state,
    maze_state_t *const updated_maze);

#endif //__NAVIGATION_H__
