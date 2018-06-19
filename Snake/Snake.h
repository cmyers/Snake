#pragma once
#include "Entity.h"
#include "Enums.h"
#include <vector>

class Snake
{
	private:
		std::vector<Entity*> body;
		Direction dir;
		bool checkCollision();
		void eat();
		void updateScore();
	public:
		Snake();
		void moveSnake(Direction dir);
		std::vector<Entity*> getBody();
};