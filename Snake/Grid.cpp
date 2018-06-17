#include "stdafx.h"
#include "Grid.h"
#include <vector>
#include "Entity.h"

Grid::Grid() {};
Grid::~Grid() {};

Grid::Grid(std::vector<std::vector<Entity*>> entities)
{
	this->entities = entities;
}

Entity* Grid::getEntity(int x, int y)
{
	return this->entities.at(x).at(y);
}

void Grid::addEntity(Entity* entity, int x, int y)
{
	this->entities.at(x).at(y) = entity;
}

Entity* Grid::removeEntity(int x, int y)
{
	return this->entities.at(x).at(y) = NULL;
}