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
		bool checkCollision(int x, int y);
		void updateScore();
		void deleteTail();
		bool addHead();
		int speed;
	public:
		Snake(Grid* grid);
		bool moveSnake();
		void eat();
		void changeDirection(Direction dir);
		Direction getDirection();
		int getSpeed();
		void setSpeed(int speed);
};