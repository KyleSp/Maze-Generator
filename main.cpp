//Kyle Spurlock

#include "main.h"

int main() {
	
	Maze maze;
	
	maze.inputMaze();
	
	//maze.inputMaze(LENGTH, WIDTH, START_ROW, START_COL, END_ROW, END_COL);
	
	Solver solver(maze.getMaze());
	
	solver.solve();
	
	return 0;
}