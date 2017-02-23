//Kyle Spurlock

#include "Maze.h"

Maze::Maze() {
	
}

Maze::Maze(int mazeLength, int mazeWidth) :
	mazeLength(mazeLength), mazeWidth(mazeWidth) {
}

//cin input of maze (using tile types)
void Maze::inputMaze() {
	//read in maze size
	std::string rowSize, colSize;
	
	std::cin >> rowSize;
	std::cin >> colSize;
	
	//TODO: error checking
	
	//read in start and end tiles
	std::string startRowS, startColS, endRowS, endColS;
	
	std::cin >> startRowS;
	std::cin >> startColS;
	std::cin >> endRowS;
	std::cin >> endColS;
	
	//read in grid
	std::vector<Tile> row;
	std::string tileType;
	for (int r = 0; r < mazeLength; ++r) {
		row.erase(row.begin(), row.end());		//reset row vector
		for (int c = 0; c < mazeWidth; ++c) {
			std::cin >> tileType;
			//add to row vector
			row.push_back(Tile(r, c, std::atoi(tileType.c_str())));
		}
		maze.push_back(row);					//add row vector to maze
	}
	
	//set start and end tiles
	start = &maze[std::atoi(startRowS.c_str())][std::atoi(startColS.c_str())];
	end = &maze[std::atoi(endRowS.c_str())][std::atoi(endColS.c_str())];
}

void Maze::generateMaze(int startRow, int startCol, int endRow, int endCol) {
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