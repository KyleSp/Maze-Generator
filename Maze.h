//Kyle Spurlock

#ifndef MAZE_H
#define MAZE_H

#include "Tile.h"
#include <vector>
#include <string>
#include <iostream>

class Maze {
public:
	Maze();
	
	Maze(int mazeLength, int mazeWidth);
	
	void inputMaze();
	
	void generateMaze(int startRow, int startCol, int endRow, int endCol);
	
	Tile* getTile(int row, int col);
	
	Tile* getStart();
	Tile* getEnd();
	
	Maze* getMaze();
	
private:
	std::vector<std::vector<Tile> > maze;
	Tile* start;
	Tile* end;
	
	int mazeLength;
	int mazeWidth;
};

#endif