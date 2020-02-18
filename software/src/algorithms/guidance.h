/* 
 * guidance.h
 */

#ifndef __GUIDANCE_H__
#define __GUIDANCE_H__

#include "../types/types.h"

/* guidance
 * 
 * Runs an algorithm on the robot and maze state to determine
 * the next dcdesired state */
int guidance(
    const robot_state_t *const current_state,
    const maze_state_t *const current_maze,
    robot_state_t *const next_state);

cell_t chooseNextCell(maze_state_t* robot_maze_state, cell_t* robot_cell); //not sure if we can return a stuct. if not put it in a pointer :shrugh:
void floodfill(maze_state_t* maze_state, cell_t cell, int value);    

void convertLocationToCell(robot_state_t* location, cell_t* to_return);
void convertCellToLocation(cell_t* cell, robot_state_t* to_return);

void resetValues(void);
void setAllDiscoveredToFalse(void);

#endif //__GUIDANCE_H__
