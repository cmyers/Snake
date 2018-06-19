#include "stdafx.h"
#include "Grid.h"
#include <vector>
#include "Entity.h"

Grid::Grid() {}

Grid::Grid(int xSize, int ySize) 
{
	this->entities = std::vector<std::vector<Entity*>>();
	for (int y = 0; y < ySize; y++)
	{
		this->entities.push_back(std::vector<Entity*>());
		for (int x = 0; x < xSize; x++)
		{
			this->entities.at(y).push_back(NULL);
		}
	}
	bool debug = true;
};

Grid::Grid(std::vector<std::vector<Entity*>> entities)
{
	this->entities = entities;
}

Entity* Grid::getEntity(int x, int y)
{
	return this->entities.at(y).at(x);
}

void Grid::addEntity(Entity* entity, int x, int y)
{
	this->entities.at(y).at(x) = entity;
}

Entity* Grid::removeEntity(int x, int y)
{
	return this->entities.at(y).at(x) = NULL;
}