//Kyle Spurlock

#include "main.h"

int main() {
	
	Maze maze(LENGTH, WIDTH);
	
	maze.generateMaze(START_ROW, START_COL, END_ROW, END_COL);
	
	return 0;
}