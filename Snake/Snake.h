#pragma once
#ifndef SNAKE_HPP
#define SNAKE_HPP

#include "Enums.h"
#include "EntityManager.h"
#include "EntityGroup.h"

namespace SnakeGame {

	class Snake : public EntityGroup
	{
	private:
		Direction dir;
		bool checkCollision(int x, int y);
		void updateScore(int add);
		void deleteTail();
		bool addHead();
		int speed;
		int score;
	public:
		Snake();
		~Snake();
		Snake(EntityManager &entityManager);
		bool moveSnake();
		void eat(Entity *entity);
		void changeDirection(Direction dir);
		Direction getDirection();
		int getSpeed();
		void setSpeed(int speed);
		int getScore();
	};
}

#endif