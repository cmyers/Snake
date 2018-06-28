#include "stdafx.h"
#include "Entity.h"

Entity::Entity()
{
	this->id = 0;
	this->collidable = false;
}
Entity::~Entity() {}

Entity::Entity(int id, int x, int y, bool collidable)
{
	this->id = id;
	this->x = x;
	this->y = y;
	this->collidable = collidable;
}

int Entity::getX()
{
	return this->x;
}

int Entity::getY()
{
	return this->y;
}

bool Entity::isConsumable()
{
	return false;
}