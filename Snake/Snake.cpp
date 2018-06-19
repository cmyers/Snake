#include "stdafx.h"
#include "Snake.h"

Snake::Snake()
{
	for (int i = 0; i < 4; i++)
	{
		this->body.push_back(new Entity(i, true));
	}
	bool debug = true;
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
		
void Snake::moveSnake(Direction dir)
{

}

std::vector<Entity*> Snake::getBody()
{
	return this->body;
}