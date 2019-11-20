/* 
 * MazeState.h
 *
 * Author: Dylan Staatz
 * 
 * Notes:
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
 *  [0,H-1][1,H-1] ... [W-1,H-1]
 *   ...     ...   ...    ...
 *  [0,1]   [1,1]  ...  [W-1,1]
 *  [0,0]   [1,0]  ...  [W-1,0]
 * 
 * Note: H = MAZE_HEIGHT
 *       W = MAZE_WIDTH
 */

#ifndef __MAZE_STATE_H__
#define __MAZE_STATE_H__

#define MAX_MAZE_WIDTH  16
#define MAX_MAZE_HEIGHT 16


typedef struct {
    double exists;
} Wall;


typedef struct {
    Wall* north;
    Wall* east;
    Wall* south;
    Wall* west;
} Cell;


typedef struct {
    Cell cells[MAX_MAZE_WIDTH][MAX_MAZE_HEIGHT];
    Wall wall_buffer[MAX_MAZE_HEIGHT * (MAX_MAZE_WIDTH + 1) + (MAX_MAZE_HEIGHT + 1) * MAX_MAZE_WIDTH];
} MazeState;


/* Initialize the state of the maze
 *   - Responsible for setting up the pointers to the
 * wall in such a way that there are no duplicates.
 */
void initializeMaze(MazeState* maze);


#endif //__MAZE_STATE_H__
