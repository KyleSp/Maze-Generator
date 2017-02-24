//Kyle Spurlock

#ifndef TILE_H
#define TILE_H

class Tile {
public:
	Tile(int row, int col);
	Tile(int row, int col, int val);
	
	int getRow();
	int getCol();
	int getVal();
	bool getVisited();
	bool getDir(int dir);
	
	void setDir(int dir, bool val);
	void setVal(int val);
	void setVisited();
private:
	int row;			//row number on map
	int col;			//column number on map
	int val;			//value assigned for traversing maze
	
	//whether there is an opening next to the tile (opening == true)
	bool left;
	bool top;
	bool bottom;
	bool right;
	
	bool visited;		//whether the tile was in the priority queue already
};

#endif