#include "stdafx.h"
#include "Pickup.h"
#include "Entity.h"

using namespace SnakeGame;

Pickup::Pickup(int id, int x, int y, bool collidable, std::string name, int points) : Entity(id, x, y, collidable)
{
	this->name = name;
	this->points = points;
}

std::string Pickup::getName()
{
	return this->name;
}

int Pickup::getPoints()
{
	return this->points;
}

bool Pickup::isConsumable()
{
	return true;
}