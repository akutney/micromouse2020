/*
 * guidance.c
 */ 

#include <error.h>

#include "guidance.h"


#include <stdio.h>
#include <stdlib.h>
#include"queue.h"


//unfinished conversion of strategy.cpp 


//#define IS_CELL_OUT_OF_BOUNDS(cell) ((cell).x < 0 || (cell).x >= (MAZE_WIDTH) || (cell).y < 0 || (cell).y >= (MAZE_HEIGHT))

/* Simple representation of a cell
 *  - For use with probabilistic_maze_t */
typedef struct struct_cell_t{
   int x;
   int y;
} cell_t;

/* The number of steps away from the goal based on the floodfill algorithm */
int values[MAZE_WIDTH][MAZE_HEIGHT];

/* Keeps track of which cells have been discovered already */
bool discovered[MAZE_WIDTH][MAZE_HEIGHT];

/* initialize strategy
 * Initializes the maze solving algorithm */
void initializeStrategy(void) {

    resetValues();
    setAllDiscoveredToFalse();
}

//this is strategy from cpp
int guidance(
  const robot_state_t *const current_state,
  const maze_state_t *const current_maze,
  robot_state_t *const next_state)
{
  static cell_t prev_next_cell;

  cell_t robot_cell;
  convertLocationToCell(current_state, & robot_cell);

  floodfill(current_state, goal_cell, 0);

  cell_t next_cell = chooseNextCell(current_maze, robot_cell); //got up to here

  /*
      if (prev_next_cell.x == next_cell.x && prev_next_cell.y == next_cell.y) {
        toggleLED(2);
        if (robot_cell.x == next_cell.x && robot_cell.y == next_cell.y) {
            setHighLED(1);
        }
    }
  */

 prev_next_cell = next_cell;

 convertCellToLocation(&next_cell, next_state);
}

void floodfill(maze_state_t* maze_state, cell_t cell, int value){
  // Reset everything
    resetValues();
    setAllDiscoveredToFalse();

    //add the queue stuff here.
}

void resetValues(void) {
    for (int x = 0; x < MAZE_WIDTH; x++) {
        for (int y = 0; y < MAZE_HEIGHT; y++) {
            values[x][y] = MAX_VALUE;
        }
    }
}

void setAllDiscoveredToFalse(void){
    for (int i=0; i<MAZE_WIDTH; i++){
        for (int j=0; j<MAZE_HEIGHT; j++){
            discovered[i][j] = false;
        }
    }
}
