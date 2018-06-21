#pragma once
#include "Entity.h"
#include "Enums.h"
#include "Grid.h"
#include <deque>

class Snake
{
	private:
		std::deque<Entity*> body;
		Grid* grid; //snake controls and knows where it is in the world, so has access to grid and can move around it
		Direction dir;
		bool checkCollision();
		void updateScore();
		void deleteTail();
		bool addHead(Direction dir);
	public:
		Snake(Grid* grid);
		void moveSnake(Direction dir);
		void eat();
};