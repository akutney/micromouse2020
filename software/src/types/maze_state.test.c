#include <testing.h>
#include "maze_state.h"

int count_cell_references(maze_state_t *maze, wall_t *check) {
	int count = 0;
	for (int x = 0; x < MAX_MAZE_WIDTH; ++x) {
		for (int y = 0; y < MAX_MAZE_HEIGHT; ++y) {
			count += (maze->cells[x][y].north == check) +
			(maze->cells[x][y].east == check) +
			(maze->cells[x][y].south == check) +
			(maze->cells[x][y].west == check);
		}
	}
	return count;
}

TEST(north border is 1, maze_state.c) {
	maze_state_t maze;
	init_maze_state(&maze);
	for (int x = 0; x < MAX_MAZE_WIDTH; ++x) {
		if (maze.cells[x][MAX_MAZE_HEIGHT - 1].north->exists != 1) {
			return TEST_FAIL;
		}
	}
	return TEST_SUCCESS;
}

TEST(east border is 1, maze_state.c) {
	maze_state_t maze;
	init_maze_state(&maze);
	for (int y = 0; y < MAX_MAZE_HEIGHT; ++y) {
		if (maze.cells[MAX_MAZE_WIDTH - 1][y].east->exists != 1) {
			return TEST_FAIL;
		}
	}
	return TEST_SUCCESS;
}

TEST(south border is 1, maze_state.c) {
	maze_state_t maze;
	init_maze_state(&maze);
	for (int x = 0; x < MAX_MAZE_WIDTH; ++x) {
		if (maze.cells[x][0].south->exists != 1) {
			return TEST_FAIL;
		}
	}
	return TEST_SUCCESS;
}

TEST(west border is 1, maze_state.c) {
	maze_state_t maze;
	init_maze_state(&maze);
	for (int y = 0; y < MAX_MAZE_HEIGHT; ++y) {
		if (maze.cells[0][y].west->exists != 1) {
			return TEST_FAIL;
		}
	}
	return TEST_SUCCESS;
}

TEST(interior borders are 0.5, maze_state.c) {
	maze_state_t maze;
	init_maze_state(&maze);
	for (int x = 1; x < MAX_MAZE_WIDTH - 1; ++x) {
		for (int y = 1; y < MAX_MAZE_HEIGHT - 1; ++y) {
			if (maze.cells[x][y].north->exists != 0.5 || maze.cells[x][y].south->exists != 0.5 || maze.cells[x][y].east->exists != 0.5 || maze.cells[x][y].west->exists != 0.5) {
				return TEST_FAIL;
			}
		}
	}
	for (int x = 1; x < MAX_MAZE_WIDTH - 1; ++x) {
		if (maze.cells[x][0].north->exists != 0.5 || maze.cells[x][0].east->exists != 0.5 || maze.cells[x][0].west->exists != 0.5) {
			return TEST_FAIL;
		}
		if (maze.cells[x][MAX_MAZE_HEIGHT - 1].south->exists != 0.5 || maze.cells[x][MAX_MAZE_HEIGHT - 1].east->exists != 0.5 || maze.cells[x][MAX_MAZE_HEIGHT - 1].west->exists != 0.5) {
			return TEST_FAIL;
		}
	}
	for (int y = 1; y < MAX_MAZE_WIDTH - 1; ++y) {
		if (maze.cells[0][y].east->exists != 0.5 || maze.cells[0][y].north->exists != 0.5 || maze.cells[0][y].south->exists != 0.5) {
			return TEST_FAIL;
		}
		if (maze.cells[MAX_MAZE_WIDTH - 1][y].west->exists != 0.5 || maze.cells[MAX_MAZE_WIDTH - 1][y].north->exists != 0.5 || maze.cells[MAX_MAZE_WIDTH - 1][y].south->exists != 0.5) {
			return TEST_FAIL;
		}
	}
	if (maze.cells[0][0].north->exists != 0.5 || maze.cells[0][0].east->exists != 0.5) {
		return TEST_FAIL;
	}
	if (maze.cells[0][MAX_MAZE_HEIGHT - 1].south->exists != 0.5 || maze.cells[0][MAX_MAZE_HEIGHT - 1].east->exists != 0.5) {
		return TEST_FAIL;
	}
	if (maze.cells[MAX_MAZE_WIDTH - 1][0].north->exists != 0.5 || maze.cells[MAX_MAZE_WIDTH - 1][0].west->exists != 0.5) {
		return TEST_FAIL;
	}
	if (maze.cells[MAX_MAZE_WIDTH - 1][MAX_MAZE_HEIGHT - 1].south->exists != 0.5 || maze.cells[MAX_MAZE_WIDTH - 1][MAX_MAZE_HEIGHT - 1].west->exists != 0.5) {
		return TEST_FAIL;
	}
	return TEST_SUCCESS;
}

TEST(duplicated wall references, maze_state.c) {
	maze_state_t maze;
	init_maze_state(&maze);
	for (int i = 0; i < sizeof(maze.wall_buffer) / sizeof(maze.wall_buffer[0]); ++i) {
		if (count_cell_references(&maze, maze.wall_buffer + i) > 2) {
			return TEST_FAIL;
		}
	}
	return TEST_SUCCESS;
}

TEST(invalid wall references, maze_state.c) {
	maze_state_t maze;
	init_maze_state(&maze);
	for (int x = 1; x < MAX_MAZE_WIDTH - 1; ++x) {
		for (int y = 1; y < MAX_MAZE_HEIGHT - 1; ++y) {
			if (maze.cells[x][y].north != maze.cells[x][y + 1].south ||
			maze.cells[x][y].east != maze.cells[x + 1][y].west ||
			maze.cells[x][y].south != maze.cells[x][y - 1].north ||
			maze.cells[x][y].west != maze.cells[x - 1][y].east) {
				return TEST_FAIL;
			}
		}
	}
	return TEST_SUCCESS;
}

TEST(invalid outer wall references, maze_state.c) {
	maze_state_t maze;
	init_maze_state(&maze);
	for (int x = 0; x < MAX_MAZE_WIDTH; ++x) {
		if (count_cell_references(&maze, maze.cells[x][MAX_MAZE_HEIGHT - 1].north) != 1) {
			puts("---");
			printf("%d, %d\n", x, count_cell_references(&maze, maze.cells[x][MAX_MAZE_HEIGHT - 1].north));
			return TEST_FAIL;
		}
		if (count_cell_references(&maze, maze.cells[x][0].south) != 1) {
			return TEST_FAIL;
		}
	}
	for (int y = 0; y < MAX_MAZE_WIDTH; ++y) {
		if (count_cell_references(&maze, maze.cells[0][y].west) != 1) {
			printf("%d\n", y);
			return TEST_FAIL;
		}
		if (count_cell_references(&maze, maze.cells[MAX_MAZE_WIDTH - 1][y].east) != 1) {
			return TEST_FAIL;
		}
	}
	return TEST_SUCCESS;
}

TEST(memory waste, maze_state.c) {
	maze_state_t maze;
	init_maze_state(&maze);
	for (int i = 0; i < sizeof(maze.wall_buffer) / sizeof(maze.wall_buffer[0]); ++i) {
		if (count_cell_references(&maze, maze.wall_buffer + i) == 0) {
			return TEST_FAIL;
		}
	}
	return TEST_SUCCESS;
}
