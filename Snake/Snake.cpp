#include "stdafx.h"
#include "Snake.h"
#include "Pickup.h"

using namespace SnakeGame;

Snake::Snake() : EntityGroup(entityManager) {}
Snake::~Snake() {}

Snake::Snake(EntityManager& entityManager) : EntityGroup(entityManager)
{
	this->dir = Direction::LEFT;
	for (int i = 0; i < 4; i++)
	{
		this->entities.push_back(new Entity(i, i + 5, 5, true));
		this->entityManager.getGrid()->addEntity(this->entities.at(i));
	}
}

bool Snake::checkCollision(int x, int y)
{
	Entity* entity = this->entityManager.getGrid()->getEntityAt(x, y);

	if (this->isInGroup(entity))
	{
		return true;
	}

	if (entity != nullptr)
	{
		if (entity->isConsumable())
		{
			this->eat(entity);
		}
	}
	return false;
}

template<typename T>
T* EntityManager::getEntityGroup()
{
	return dynamic_cast<T*>(this->entityGroup);
}

template Snake* EntityManager::getEntityGroup<Snake>();

void Snake::eat(Entity* entity)
{
	Pickup* p = dynamic_cast<Pickup*>(entity);
	this->updateScore(p->getPoints());
	this->entityManager.getGrid()->removeEntity(entity);
	this->addHead();
	this->entityManager.spawnPickup();
}

void Snake::setSpeed(int speed)
{
	this->speed = speed;
}

int Snake::getSpeed()
{
	return this->speed;
}

void Snake::updateScore(int add)
{
	this->score += add;
}

void Snake::deleteTail()
{
	Entity* eTail = this->entities.at(this->entities.size() - 1);
	this->entityManager.getGrid()->removeEntity(eTail);
	this->entities.pop_back();
}

bool Snake::addHead()
{
	int x = this->entities.at(0)->getX();
	int y = this->entities.at(0)->getY();

	switch (this->dir)
	{
		case Direction::UP:
			y--;

			if (y == 0)
			{
				y = this->entityManager.getGrid()->getHeight() - 2;
			}
			break;
		case Direction::DOWN:
			y++;

			if (y == this->entityManager.getGrid()->getHeight() - 1)
			{
				y = 1;
			}
			break;
		case Direction::LEFT:
			x--;

			if (x == 0)
			{
				x = this->entityManager.getGrid()->getWidth() - 2;
			}
			break;
		case Direction::RIGHT:
			x++;

			if (x == this->entityManager.getGrid()->getWidth() - 1)
			{
				x = 1;
			}
			break;
		default:
			break;
	}

	if (!this->checkCollision(x, y))
	{
		Entity* newHead = new Entity(0, x, y, true);
		this->entities.push_front(newHead);
		this->entityManager.getGrid()->addEntity(newHead);
		return true;
	}
	return false;

}

bool Snake::moveSnake()
{
	if (this->addHead())
	{
		this->deleteTail();
		return true;
	}
	else
	{
		return false;
	}
}

void Snake::changeDirection(Direction dir)
{
	switch (dir)
	{
		case Direction::UP:
			if (this->dir == Direction::DOWN)
			{
				return;
			}
			break;
		case Direction::DOWN:
			if (this->dir == Direction::UP)
			{
				return;
			}
			break;
		case Direction::LEFT:
			if (this->dir == Direction::RIGHT)
			{
				return;
			}
			break;
		case Direction::RIGHT:
			if (this->dir == Direction::LEFT)
			{
				return;
			}
			break;
		default:
			break;
	}
	this->dir = dir;
}

Direction Snake::getDirection()
{
	return this->dir;
}

int Snake::getScore()
{
	return this->score;
}