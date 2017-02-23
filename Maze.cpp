//Kyle Spurlock

#include "Maze.h"

Maze::Maze(int mazeLength, int mazeWidth) :
	mazeLength(mazeLength), mazeWidth(mazeWidth) {
}

/*
Maze::Maze(int mazeLength, int mazeWidth, int startRow, int startCol, int endRow,
	int endCol) : mazeLength(mazeLength), mazeWidth(mazeWidth) {
	//start = new Tile(startRow, startCol, -1);
	//end = new Tile(endRow, endCol, -1);
}
*/

/*
void Maze::chooseStartEnd() {
	
}
*/

void Maze::generate(int startRow, int startCol, int endRow, int endCol) {
	//create grid
	std::vector<Tile> row;
	for (int r = 0; r < mazeLength; ++r) {
		row.erase(row.begin(), row.end());		//reset row vector
		for (int c = 0; c < mazeWidth; ++c) {
			row.push_back(Tile(r, c, -1));		//add to row vector
		}
		maze.push_back(row);					//add row vector to maze
	}
	
	//set start and end tiles
	start = &maze[startRow][startCol];
	end = &maze[endRow][endCol];
}

Tile* Maze::getStart() {
	return start;
}

Tile* Maze::getEnd() {
	return end;
}