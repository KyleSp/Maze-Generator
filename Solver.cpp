//Kyle Spurlock

#include "Solver.h"

Solver::Solver(Maze* maze) : maze(maze) {
	stepsTaken = 0;
}

void Solver::solve() {
	bool reachedEnd = false;
	Tile* current = maze->getStart();
	Tile* end = maze->getEnd();
	
	Tile* left;
	Tile* top;
	Tile* bottom;
	Tile* right;
	
	current->setVisited();
	
	while (!reachedEnd) {
		//get adjacent tiles
		left = maze->getTile(current->getRow(), current->getCol() - 1);
		top = maze->getTile(current->getRow() - 1, current->getCol());
		bottom = maze->getTile(current->getRow() + 1, current->getCol());
		right = maze->getTile(current->getRow(), current->getCol() + 1);
		
		//add adjacent tiles to priority queue, if possible
		addAdjToPQ(current, left, 0);
		addAdjToPQ(current, top, 1);
		addAdjToPQ(current, bottom, 2);
		addAdjToPQ(current, right, 3);
		
		//get next tile and pop from priority queue
		current = pq.top();
		//current->setVisited();
		pq.pop();
		
		if (current == end) {
			reachedEnd = true;
		}
		
		//std::cerr << "current: " << current->getRow() << ", " << current->getCol() << "\n";
		
		//showMaze();
		
		//TEMP
		//reachedEnd = true;
		//TEMP
	}
	
	stepsTaken = end->getVal();
	
	std::cout << "steps taken: " << stepsTaken << "\n";
}

//TODO: recalculate shortest path based on adjacent tiles: Dijkstra's Algorithm
void Solver::addAdjToPQ(Tile* current, Tile* t, int dir) {
	//if (t) std::cerr << "add: " << t->getRow() << ", " << t->getCol() << ", ";
	if (t && current->getDir(dir) && !t->getVisited()) {
		t->setVal(current->getVal() + 1);
		//std::cerr << "true\n";
		t->setVisited();
		pq.push(t);
	} else {
		//std::cerr << "false\n";
	}
}

//TEMP
void Solver::showMaze() {
	for (int r = 0; r < 10; ++r) {
		for (int c = 0; c < 10; ++c) {
			std::cerr << maze->getTile(r, c)->getVal() << "\t";
		}
		std::cerr << "\n";
	}
}
//TEMP