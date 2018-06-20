#include "stdafx.h"
#include "Grid.h"
#include <vector>
#include "Entity.h"

Grid::Grid() {}

Grid::Grid(int xSize, int ySize) 
{
	this->entities = std::vector<std::vector<Entity*>>(ySize, std::vector<Entity*>(xSize));

	/*for (int y = 0; y < ySize; y++)
	{
		this->entities.push_back(std::vector<Entity*>());
		for (int x = 0; x < xSize; x++)
		{
			this->entities.at(y).push_back(nullptr);
		}
	}*/
};

Grid::Grid(std::vector<std::vector<Entity*>> entities)
{
	this->entities = entities;
}

Entity* Grid::getEntity(int x, int y)
{
	return this->entities.at(y).at(x);
}

bool Grid::removeEntity(Entity* entity)
{
	for (int y = 0; y < this->entities.size() -1; y++)
	{
		for (int x = 0; x < this->entities.at(y).size() -1; x++)
		{
			if (entity == this->entities.at(y).at(x))
			{
				Entity* e = this->entities.at(y).at(x);
				delete e;
				this->entities.at(y).at(x) = nullptr;
				return true;
			}
		}
	}
	return false;
}


void Grid::moveEntity(int xFrom, int yFrom, int xTo, int yTo)
{
	Entity* entity = this->entities.at(yFrom).at(xFrom);
	this->entities.at(yTo).at(xTo) = entity;
	this->entities.at(yFrom).at(xFrom) = nullptr;
}

void Grid::addEntity(Entity* entity, int x, int y)
{
	this->entities.at(y).at(x) = entity;
	return;
}