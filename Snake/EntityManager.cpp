#include "stdafx.h"
#include "EntityManager.h"

EntityManager::EntityManager(Grid *grid)
{
	this->grid = grid;
	this->snake = new Snake(grid);
}

EntityManager::EntityManager() {}

EntityManager::~EntityManager() {}

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

//void EntityManager::consumePickup(Entity *entity)
//{
//	for (int i = 0; i < this->pickups.size() - 1; i++)
//	{
//		if (*this->pickups.at(i) == entity)
//		{
//			this->pickups.erase(this->pickups.begin() + i);
//			return;
//		}
//	}
//}

Grid* EntityManager::getGrid()
{
	return this->grid;
}

Snake* EntityManager::getSnake()
{
	return this->snake;
}

//std::vector<Entity**> EntityManager::getPickups()
//{
//	return this->pickups;
//}