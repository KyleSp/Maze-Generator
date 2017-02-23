//Kyle Spurlock

#include "main.h"

int main() {
	
	Maze maze(LENGTH, WIDTH);
	
	maze.generate(START_ROW, START_COL, END_ROW, END_COL);
	
	return 0;
}