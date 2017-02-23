//Kyle Spurlock

#include "Tile.h"

Tile::Tile(int row, int col, int type) : row(row), col(col), type(type) {
	val = 0;
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

int Tile::getType() {
	return type;
}

void Tile::setVal(int val) {
	this->val = val;
}
