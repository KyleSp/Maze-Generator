//Kyle Spurlock

/*
Uses std priority queue to iterate through maze from start to end.
Each step away from start increases value by 1.
*/

#ifndef SOLVER_H
#define SOLVER_H

#include "Tile.h"
#include "Maze.h"
#include <queue>

class Solver {
public:
	Solver(Maze maze);
	
	void solve();
	
private:
	struct tileComp {
		bool operator()(Tile &t1, Tile &t2) {
			return t1.getVal() < t2.getVal();		//TODO: how to break ties
		}
	};
	
	Maze maze;
	
	std::priority_queue<Tile, std::vector<Tile>, tileComp> pq;
	
	int stepsTaken;
};

#endif