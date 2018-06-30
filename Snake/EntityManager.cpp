#include "stdafx.h"
#include "EntityManager.h"
#include "Snake.h"
#include "Pickup.h"

using namespace SnakeGame;

EntityManager::EntityManager() {}

EntityManager::~EntityManager()
{
	delete this->grid;
	delete this->entityGroup;
}

bool EntityManager::loadEntities()
{
	//this can be responsible for creating 1 grid at a time and initialising the player and pickups inside this grid
	//this means we can reload a grid using different parameters if we want different levels etc. For now this is hard coded to a fixed size
	delete this->grid; //delete the original grid
	this->grid = new Grid(60, 30);
	this->entityGroup = new Snake((*this));
	this->spawnPickup();
	return true;
}

Grid* EntityManager::getGrid()
{
	return this->grid;
}

void EntityManager::spawnPickup() // TODO: Create an entity manager class to handle these types of methods?
{
	Pickup* pickup = nullptr;

	while (pickup == nullptr)
	{
		int x = rand() % ((this->grid->getWidth() - 1) + 1);
		int y = rand() % ((this->grid->getHeight() - 1) + 1);

		if (this->grid->getEntityAt(x, y) == nullptr)
		{
			pickup = new Pickup(0, x, y, true, "Egg", 10);
			break;
		}
	}

	this->grid->addEntity(pickup);
}

template<typename T>
T* EntityManager::getEntityGroup()
{
	return dynamic_cast<T*>(this->entityGroup);
}

template Snake* EntityManager::getEntityGroup<Snake>();