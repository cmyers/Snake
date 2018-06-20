#include "stdafx.h"
#include "Snake.h"



Snake::Snake(Grid* grid)
{
	this->grid = grid;
	for (int i = 0; i < 4; i++)
	{
		this->body.push_back(new Entity(i, true));
	}
	
	for (int i = 0; i < this->body.size(); i++)
	{
		//set initial position in grid
		this->grid->addEntity(this->body.at(i), i + 5, 5);
	}

	headPos.x = 5;
	headPos.y = 5;
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
{	//add new snake head to relevant position and remove tail
	switch (dir)
	{
		case Direction::UP:
			break;
		case Direction::DOWN:
		{
			//delete tail
			Entity * entity = this->body.at(this->body.size() - 1);
			if (this->grid->removeEntity(entity))
			{
				this->body.pop_back();
			}

			//add new head in direction of movement
			Entity * newHead = new Entity(0, true);
			this->body.push_front(newHead);
			headPos.y++;
			this->grid->addEntity(newHead, headPos.x, headPos.y);
			break;
		}
		case Direction::LEFT:
		{
			//TODO: move this to a new function

			//delete tail
			Entity* entity = this->body.at(this->body.size() - 1);
			if (this->grid->removeEntity(entity))
			{
				this->body.pop_back();
			}
			
			//add new head in direction of movement
			Entity * newHead = new Entity(0, true);
			this->body.push_front(newHead);
			headPos.x--;
			this->grid->addEntity(newHead, headPos.x, headPos.y);
			break;
		}
		case Direction::RIGHT:
			break;
		case Direction::STOP:
		default:
			break;
			
	}
}