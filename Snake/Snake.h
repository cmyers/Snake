#pragma once
#include "Entity.h"
#include "Enums.h"
#include <vector>

class Snake
{
	private:
		std::vector<Entity> body;
		bool checkCollision();
		void eat();
		void updateScore();
	public:
		Snake();
		~Snake();
		void moveSnake(Direction dir);
};