//Kyle Spurlock

#ifndef MAZE_H
#define MAZE_H

#include "Tile.h"
#include <vector>

class Maze {
public:
	Maze(int mazeLength, int mazeWidth);
	
	Maze(int mazeLength, int mazeWidth, int startRow, int startCol, int endRow, int endCol);
	
	void chooseStartEnd();
	
	void generate();
	
	Tile& getStart();
	Tile& getEnd();
	
private:
	std::vector<std::vector<Tile> > maze;
	Tile* start;
	Tile* end;
	
	int mazeLength;
	int mazeWidth;
};

#endif