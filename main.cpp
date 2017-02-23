//Kyle Spurlock

#include "main.h"

int main() {
	
	const int length = 10;
	const int width = 10;
	
	Maze maze(length, width);
	
	maze.generate();
	
	return 0;
}