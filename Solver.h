//Kyle Spurlock

/*
Uses std priority queue to iterate through maze from start to end.
Each step away from start increases value by 1
*/

#ifndef SOLVER_H
#define SOLVER_H

#include <queue>

class Solver {
public:
	Solver();
	
private:
	struct tileComp {
		bool operator()(const Tile &t1, const Tile &t2) {
			return false;	//TODO
		}
	};
	
	std::priority_queue<Tile, std::vector<Tile>, tileComp> pq;
};

#endif