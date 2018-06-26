#include "stdafx.h"
#include "Snake.h"

Snake::Snake(Grid* grid)
{
	this->grid = grid;
	this->dir = Direction::LEFT;
	for (int i = 0; i < 4; i++)
	{
		this->body.push_back(new Entity(i, i+5, 5, true));
		this->grid->addEntity(this->body.at(i));
	}
}

bool Snake::checkCollision(int x, int y)
{
	Entity* entity = this->grid->getEntityAt(x, y);

	for (int i = 0; i < this->body.size(); i++)
	{
		if(entity == this->body[i])
		{ 
			return true;
		}
	}

	if (entity != nullptr)
	{
		//TODO: check Entity type and decide how to proceed?
		return true;
	}

	return false;
}

void Snake::eat()
{

}

void Snake::setSpeed(int speed)
{
	this->speed = speed;
}

int Snake::getSpeed()
{
	return this->speed;
}

void Snake::updateScore()
{

}

void Snake::deleteTail()
{
	Entity* eTail = this->body.at(this->body.size() - 1);
	this->grid->removeEntity(eTail);
	this->body.pop_back();
}

bool Snake::addHead()
{
	int x = this->body.at(0)->getX();
	int y = this->body.at(0)->getY();

	switch (this->dir)
	{
		case Direction::UP:
			y--;

			if (y == 0)
			{
				y = this->grid->getHeight() - 2;
			}
			break;
		case Direction::DOWN:
			y++;

			if (y == this->grid->getHeight() - 1)
			{
				y = 1;
			}
			break;
		case Direction::LEFT:
			x--;

			if (x == 0)
			{
				x = this->grid->getWidth() - 2;
			}
			break;
		case Direction::RIGHT:
			x++;

			if (x == this->grid->getWidth() - 1)
			{
				x = 1;
			}
			break;
		case Direction::STOP:
		default:
			break;
	}

	if (!this->checkCollision(x, y))
	{
		Entity* newHead = new Entity(0, x, y, true);
		this->body.push_front(newHead);
		this->grid->addEntity(newHead);
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
		case Direction::STOP:
		default:
			break;	
	}
	this->dir = dir;
}

Direction Snake::getDirection()
{
	return this->dir;
}