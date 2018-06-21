#include "stdafx.h"
#include "Grid.h"
#include <vector>
#include "Entity.h"

Grid::Grid() {}

Grid::Grid(int xSize, int ySize) 
{
	this->entities = std::vector<std::vector<Entity*>>(ySize, std::vector<Entity*>(xSize));
};

Grid::Grid(std::vector<std::vector<Entity*>> entities)
{
	this->entities = entities;
}

Entity* Grid::getEntityAt(int x, int y)
{
	return this->entities.at(y).at(x);
}

void Grid::removeEntity(Entity* entity)
{
	int x = entity->getX();
	int y = entity->getY();
	delete entity;
	this->entities.at(y).at(x) = nullptr;
}

void Grid::removeEntityAt(int x, int y)
{
	this->removeEntity(this->getEntityAt(x, y));
}

void Grid::addEntity(Entity* entity)
{
	this->entities.at(entity->getY()).at(entity->getX()) = entity;
}