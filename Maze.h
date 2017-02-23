//Kyle Spurlock

#ifndef MAZE_H
#define MAZE_H

#include "Tile.h"
#include <vector>

class Maze {
public:
	Maze(int mazeLength, int mazeWidth);
	
	void generate();
	
private:
	std::vector<std::vector<Tile> > maze;
	Tile* start;
	Tile* end;
	
	int mazeLength;
	int mazeWidth;
};

#endif