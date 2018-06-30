#ifndef SNAKE_HPP
#define SNAKE_HPP

#include "Enums.h"
#include "EntityManager.h"
#include "EntityGroup.h"

class Snake : public EntityGroup
{
	private:
		Direction dir;
		bool checkCollision(int x, int y);
		void updateScore();
		void deleteTail();
		bool addHead();
		int speed;
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
};

#endif