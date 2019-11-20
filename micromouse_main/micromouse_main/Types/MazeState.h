/* probabilistic_maze.h
 *  
 *  This file defines a probabilistic maze where each
 *  wall holds the probability of that wall exists.
 * 
 * Structure of overall maze:
 * 
 *              maze
 *           /   |    \
 *       cell cell... cell
 *       / \   / \    / \                   
 *    wall  wall  wall   wall
 * 
 * Note: two cells will point to the same wall if the
 * two cells are adjacent.
 * 
 * --------------------------------------------------
 * 
 * Structure of cells [x, y]:
 * 
 *  [0,0]   [1,0]  ...  [W-1,0]
 *  [0,1]   [1,1]  ...  [W-1,1]
 *   ...     ...   ...    ...
 *  [0,H-1][1,H-1] ... [W-1,H-1]
 * 
 * Note: H = MAZE_HEIGHT
 *       W = MAZE_WIDTH
 */

#ifndef _MAZE_STATE_H_
#define _MAZE_STATE_H_

#include "../settings.h"


typedef struct {
    double exists;
} wall_t;


typedef struct {
    wall_t* north;
    wall_t* east;
    wall_t* south;
    wall_t* west;
} cell_t;


typedef struct {
    cell_t cells[MAZE_WIDTH][MAZE_HEIGHT];
    wall_t wall_buffer[MAZE_HEIGHT * (MAZE_WIDTH + 1) + (MAZE_HEIGHT + 1) * MAZE_WIDTH];
} MazeState;


/* Initialize the state of the maze
 *   - Responsible for setting up the pointers to the
 * wall in such a way that there are no duplicates.
 */
void initializeMaze(MazeState* maze);


#endif //_MAZE_STATE_H_
