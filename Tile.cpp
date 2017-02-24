//Kyle Spurlock

#include "Tile.h"

Tile::Tile(int row, int col) : row(row), col(col), val(0),
	left(false), top(false), bottom(false), right(false), visited(false) {
	
}

Tile::Tile(int row, int col, int val) : row(row), col(col), val(val),
	left(false), top(false), bottom(false), right(false), visited(false) {
	
}

int Tile::getRow() {
	return row;
}

int Tile::getCol() {
	return col;
}

int Tile::getVal() {
	return val;
}

bool Tile::getVisited() {
	return visited;
}

bool Tile::getDir(int dir) {
	if (dir == 0) {
		//left
		return left;
	} else if (dir == 1) {
		//top
		return top;
	} else if (dir == 2) {
		//bottom
		return bottom;
	} else if (dir == 3) {
		//right
		return right;
	}
	
	return false;
}

void Tile::setDir(int dir, bool val) {
	if (dir == 0) {
		//left
		left = val;
	} else if (dir == 1) {
		//top
		top = val;
	} else if (dir == 2) {
		//bottom
		bottom = val;
	} else if (dir == 3) {
		//right
		right = val;
	}
}

void Tile::setVal(int val) {
	this->val = val;
}

void Tile::setVisited() {
	visited = true;
}