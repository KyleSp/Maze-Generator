//Kyle Spurlock

#ifndef MAZE_H
#define MAZE_H

#include "Tile.h"

class Maze {
public:
	Maze(int mazeLength, int mazeWidth);
	
private:
	std::vector<std::vector<Tile> > maze;
	
	int mazeLength;
	int mazeWidth;
};

#endif