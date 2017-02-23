//Kyle Spurlock

#include "Maze.h"

Maze::Maze(int mazeLength, int mazeWidth) :
	mazeLength(mazeLength), mazeWidth(mazeWidth) {
	chooseStartEnd();
}

Maze::Maze(int mazeLength, int mazeWidth, int startRow, int startCol, int endRow,
	int endCol) : mazeLength(mazeLength), mazeWidth(mazeWidth) {
	start = new Tile(startRow, startCol, -1);
	end = new Tile(endRow, endCol, -1);
}

void Maze::chooseStartEnd() {
	
}

void Maze::generate() {
	
}

/*

Tile Maze::getStart() {
	return start;
}

Tile Maze::getEnd() {
	return end;
}
*/