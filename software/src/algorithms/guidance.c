/*
 * guidance.c
 */ 

#include <error.h>

#include "guidance.h"


#include <stdio.h>
#include <stdlib.h>
#include"queue.h"
#include "../types/types.h"


//unfinished conversion of strategy.cpp 


//#define IS_CELL_OUT_OF_BOUNDS(cell) ((cell).x < 0 || (cell).x >= (MAZE_WIDTH) || (cell).y < 0 || (cell).y >= (MAZE_HEIGHT))

/* Simple representation of a cell
 *  - For use with probabilistic_maze_t */
typedef struct cell_t {
	int x;
	int y;
} cell_location_t;

/* The number of steps away from the goal based on the floodfill algorithm */
int values[MAZE_WIDTH][MAZE_HEIGHT];

/* Keeps track of which cells have been discovered already */
int discovered[MAZE_WIDTH][MAZE_HEIGHT]; //0 is false, 1 is true

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
	
	//set up the two queues: q and q_next
	queue q;
	q.size = MAZE_WIDTH * MAZE_HEIGHT;
	init(&q);
	q.count = 0;
	
	queue q_next;
	q_next.count = MAZE_WIDTH * MAZE_HEIGHT;
	init(&q_next)
	q_next.count = 0;
	
	discovered[cell.x][cell.y] = 1; //true
	
	enqueue(&cell);
	
	while (!q.count == 0 || !q_next.count == 0){
		if (empty(&q)){
			
			//swap(&q, &q_next);	Need to figure this line out, the code likes it but I don't currently
			
			value++;
		}
		
		cell = dequeue(&q);
		
		if (IS_CELL_OUT_OF_BOUNDS(cell)){
			continue;
		}
		values[cell.x][cell.y] = value;
		
		cell_location_t next;
		
		next.x = cell.x;
		next.y = cell.y-1;
		if (!CELL_OUT_OF_BOUNDS(next)) {
			if (!discovered[next.x][next.y] && maze_state->cells[cell.x][cell.y].north->exists < WALL_THRESHOLD){
				discovered[next.x][next.y] = 1; //true
				//enqueue(next)
			}
		}
		
		next.x = cell.x+1;
		next.y = cell.y;
		if (!IS_CELL_OUT_OF_BOUNDS(next)) {
			if (!discovered[next.x][next.y] && maze_state->cells[cell.x][cell.y].east->exists < WALL_THRESHOLD){
				discovered[next.x][next.y] = 1; //true
				//enqueue(next)
			}
		}
		
		if (!iS_CELL_OUT_OF_BOUNDS(next)) {
			
		}
	}
}

/* These methods are taken from the 2019 work, they need the constants defined, 
so commented out for now
void convertLocationToCell(robot_state_location* location, cell_location_t* to_return) {
	to_return->x_mu = (((cell->x) * (WALL_THICKNESS + CELL_LENGTH)) + (CELL_LENGTH / 2));
	to_return->y_mu = (((cell->y) * (WALL_THICKNESS + CELL_LENGTH)) + (CELL_LENGTH / 2));
}

void convertCellToLocation(cell_location_t* cell, robot_state_location* to_return) {
	to_return->x_mu = (((cell->x) * (WALL_THICKNESS + CELL_LENGTH)) + (CELL_LENGTH / 2));
	to_return->y_mu = (((cell->y) * (WALL_THICKNESS + CELL_LENGTH)) + (CELL_LENGTH / 2));
}*/

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
