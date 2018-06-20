#include "stdafx.h"
#include "Entity.h"

Entity::Entity()
{
	this->id = 0;
	this->collidable = false;
}
Entity::~Entity() {}

Entity::Entity(int id, bool collidable)
{
	this->id = id;
	this->collidable = collidable;
}