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

bool Snake::checkCollision()
{
	return false;
}

void Snake::eat()
{

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

bool Snake::addHead(Direction dir)
{
	int x = this->body.at(0)->getX();
	int y = this->body.at(0)->getY();

	switch (dir)
	{
		case Direction::UP:
			if (this->dir == Direction::DOWN)
			{
				return false;
			}
			y--;
			break;
		case Direction::DOWN:
			if (this->dir == Direction::UP)
			{
				return false;
			}
			y++;
			break;
		case Direction::LEFT:
			if (this->dir == Direction::RIGHT)
			{
				return false;
			}
			x--;
			break;
		case Direction::RIGHT:
			if (this->dir == Direction::LEFT)
			{
				return false;
			}
			x++;
			break;
		case Direction::STOP:
		default:
			break;
	}

	this->dir = dir;
	Entity* newHead = new Entity(0, x, y, true);
	this->body.push_front(newHead);
	this->grid->addEntity(newHead);
	return true;
}
		
void Snake::moveSnake(Direction dir)
{
	if (this->addHead(dir))
	{
		this->deleteTail();
	}
}