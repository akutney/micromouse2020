/* 
 * maze_state.cpp
 */


#include "maze_state.h"

/* initialize the state of the maze
 *   - Responsible for setting up the pointers to the
 * wall in such a way that there are no duplicates.
 */
void init_maze_state(maze_state_t* maze) {
    for (int i = 0; i < sizeof(maze->wall_buffer) / sizeof(maze->wall_buffer[0]); ++i) {
        maze->wall_buffer[i].exists = 0.5;
    }
    for (int x = 0; x < MAX_MAZE_WIDTH; ++x) {
        for (int y = 0; y < MAX_MAZE_HEIGHT; ++y) {
            
            maze->cells[x][y].north = &maze->wall_buffer[x * (MAX_MAZE_WIDTH + 1) + (y + 1)];
            maze->cells[x][y].east = &maze->wall_buffer[MAX_MAZE_HEIGHT * (MAX_MAZE_WIDTH + 1) + (x + 1) * MAX_MAZE_WIDTH + y];
            maze->cells[x][y].south = &maze->wall_buffer[x * (MAX_MAZE_WIDTH + 1) + y];
            maze->cells[x][y].west = &maze->wall_buffer[MAX_MAZE_HEIGHT * (MAX_MAZE_WIDTH + 1) + x * MAX_MAZE_WIDTH + y];

            if (y == MAX_MAZE_HEIGHT - 1) {
                maze->cells[x][y].north->exists = 1;
            } else if (y == 0) {
                maze->cells[x][y].south->exists = 1;
            }
            if (x == 0) {
                maze->cells[x][y].west->exists = 1;
            } else if (x == MAX_MAZE_WIDTH - 1) {
                maze->cells[x][y].east->exists = 1;
            }
        }
    }
}
