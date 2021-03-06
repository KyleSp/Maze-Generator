//Kyle Spurlock

#include "Maze.h"

Maze::Maze() : mazeLength(0), mazeWidth(0) {
	
}

//cin input of maze (using tile types)
void Maze::inputMaze() {
	//read in maze size
	std::string rowSize, colSize;
	
	std::cin >> rowSize;
	std::cin >> colSize;
	
	mazeLength = atoi(rowSize.c_str());
	mazeWidth = atoi(colSize.c_str());
	
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
			if (atoi(tileType.c_str())) {
				row.push_back(Tile(r, c, 1));
			} else {
				row.push_back(Tile(r, c));
			}
		}
		maze.push_back(row);					//add row vector to maze
	}
	
	//set booleans for adjacents based on input maze
	resolveAdjs();
	
	//reset values for each tile
	for (int r = 0; r < mazeLength; ++r) {
		for (int c = 0; c < mazeWidth; ++c) {
			maze[r][c].setVal(0);
		}
	}
	
	//set start and end tiles
	start = &maze[std::atoi(startRowS.c_str())][std::atoi(startColS.c_str())];
	end = &maze[std::atoi(endRowS.c_str())][std::atoi(endColS.c_str())];
}

void Maze::inputMaze(int rowSize, int colSize, int startRow, int startCol,
	int endRow, int endCol) {
	
	mazeLength = rowSize;
	mazeWidth = colSize;
	
	//create grid
	std::vector<Tile> row;
	for (int r = 0; r < mazeLength; ++r) {
		row.erase(row.begin(), row.end());		//reset row vector
		for (int c = 0; c < mazeWidth; ++c) {
			//row.push_back(Tile(r, c, -1));	//add to row vector
			row.push_back(Tile(r, c));
		}
		maze.push_back(row);					//add row vector to maze
	}
	
	srand((unsigned) time(NULL));
	generateMaze();
	
	std::cerr << "\n";
	for (int r = 0; r < mazeLength; ++r) {
		for (int c = 0; c < mazeWidth; ++c) {
			std::cerr << maze[r][c].getVal() << "\t";
		}
		std::cerr << "\n";
	}
	std::cerr << "\n";
	
	//set booleans for adjacents based on input maze
	resolveAdjs();
	
	//reset values for each tile
	for (int r = 0; r < mazeLength; ++r) {
		for (int c = 0; c < mazeWidth; ++c) {
			maze[r][c].setVal(0);
		}
	}
	
	//set start and end tiles
	start = &maze[startRow][startCol];
	end = &maze[endRow][endCol];
}

void Maze::resolveAdjs() {
	Tile* left;
	Tile* top;
	Tile* bottom;
	Tile* right;
	
	for (int r = 0; r < mazeLength; ++r) {
		for (int c = 0; c < mazeWidth; ++c) {
			left = getTile(r, c - 1);
			top = getTile(r - 1, c);
			bottom = getTile(r + 1, c);
			right = getTile(r, c + 1);
			
			if (left && left->getVal()) {
				//left
				maze[r][c].setDir(0, true);
			}
			if (top && top->getVal()) {
				//top
				maze[r][c].setDir(1, true);
			}
			if (bottom && bottom->getVal()) {
				//bottom
				maze[r][c].setDir(2, true);
			}
			if (right && right->getVal()) {
				//right
				maze[r][c].setDir(3, true);
			}
		}
	}
}

void Maze::generateMaze() {
	for (int r = 0; r < mazeLength; ++r) {
		for (int c = 0; c < mazeWidth; ++c) {
			int r = rand() % 10 + 1;	//1 through 10 inclusive
			if (r <= 7) {
				//70% chance
				maze[r][c].setVal(1);
			}
		}
	}
}

Tile* Maze::getTile(int row, int col) {
	if (row < 0 || row >= mazeLength || col < 0 || col >= mazeWidth) {
		return nullptr;
	}
	
	return &maze[row][col];
}

Tile* Maze::getStart() {
	return start;
}

Tile* Maze::getEnd() {
	return end;
}

Maze* Maze::getMaze() {
	return this;
}

int Maze::getLength() {
	return mazeLength;
}

int Maze::getWidth() {
	return mazeWidth;
}
