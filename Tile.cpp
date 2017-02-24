//Kyle Spurlock

#include "Tile.h"

Tile::Tile(int row, int col) : row(row), col(col), val(0),
	left(true), top(true), bottom(true), right(true), visited(false) {
	
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

bool Tile::getLeft() {
	return left;
}

bool Tile::getTop() {
	return top;
}

bool Tile::getBottom() {
	return bottom;
}

bool Tile::getRight() {
	return right;
}

bool Tile::getVisited() {
	return visited;
}

void Tile::setLeft(bool left) {
	this->left = left;
}

void Tile::setTop(bool top) {
	this->top = top;
}

void Tile::setBottom(bool bottom) {
	this->bottom = bottom;
}

void Tile::setRight(bool right) {
	this->right = right;
}

void Tile::setVal(int val) {
	this->val = val;
}

void Tile::setVisited() {
	visited = true;
}