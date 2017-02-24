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
#include <iostream>

class Solver {
public:
	Solver(Maze* maze);
	
	void solve();	//assume a maze solution exists
	
private:
	struct tileComp {
		bool operator()(Tile* t1, Tile* t2) {
			//std::cerr << "t1: " << t1->getRow() << ", " << t1->getCol() << ": " << t1->getVal() << "\n";
			//std::cerr << "t2: " << t2->getRow() << ", " << t2->getCol() << ": " << t2->getVal() << "\n";
			if (t1->getVal() == t2->getVal()) {
				if (t1->getCol() > t2->getCol()) {
					//std::cerr << "return false\n";
					return true;
				}
				//std::cerr << "return t1 row > t2 row\n";
				return t1->getRow() > t2->getRow();
			}
			//std::cerr << "return t1 val < t2 val\n";
			return t1->getVal() > t2->getVal();
		}
	};
	
	Maze* maze;
	
	std::priority_queue<Tile*, std::vector<Tile*>, tileComp> pq;
	
	int stepsTaken;
	
	void addAdjToPQ(Tile* current, Tile* t, int dir);
	
	void showMaze();
};

#endif