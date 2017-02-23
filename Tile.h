//Kyle Spurlock

#ifndef TILE_H
#define TILE_H

class Tile {
public:
	Tile(int row, int col, int type);
	
	int getRow();
	int getCol();
	int getVal();
	int getType();
	
	void setVal(int val);
private:
	int row;			//row number on map
	int col;			//column number on map
	int type;			//corresponds to tile type (TODO: maybe make 4 booleans for edges?)
	int val;			//value assigned for traversing maze
};

#endif