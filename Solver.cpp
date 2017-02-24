//Kyle Spurlock

#include "Solver.h"

Solver::Solver(Maze* maze) : maze(maze) {
	stepsTaken = 0;
}

void Solver::solve() {
	bool reachedEnd = false;
	Tile* current = maze->getStart();
	
	Tile* left;
	Tile* top;
	Tile* bottom;
	Tile* right;
	
	while (!reachedEnd) {
		//get adjacent tiles
		left = maze->getTile(current->getRow(), current->getCol() - 1);
		top = maze->getTile(current->getRow() - 1, current->getCol());
		bottom = maze->getTile(current->getRow() + 1, current->getCol());
		right = maze->getTile(current->getRow(), current->getCol() + 1);
		
		//update adjacent tile values (distances from start tile)
		left->setVal(current->getVal() + 1);
		top->setVal(current->getVal() + 1);
		bottom->setVal(current->getVal() + 1);
		right->setVal(current->getVal() + 1);
		
		//add adjacent tiles to priority queue, if possible
		if (left && current->getLeft()) {
			//pq.push(*left);
			pq.push(left);
		}
		if (top && current->getTop()) {
			//pq.push(*top);
			pq.push(top);
		}
		if (bottom && current->getBottom()) {
			//pq.push(*bottom);
			pq.push(bottom);
		}
		if (right && current->getRight()) {
			//pq.push(*right);
			pq.push(right);
		}
		
		current = pq.top();
		
		//TEMP
		reachedEnd = true;
		//TEMP
	}
}
