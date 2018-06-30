#include "stdafx.h"
#include "Pickup.h"
#include "Snake.h"

//Snake snake;
//Grid grid;

EntityManager::EntityManager() {} //: grid(grid), entityGroup(snake) {}

EntityManager::~EntityManager()
{
	delete this->entityGroup;
}

EntityManager::EntityManager(Grid grid) : grid(grid)
{
	this->entityGroup = new Snake((*this));
}

void EntityManager::spawnPickup() // TODO: Create an entity manager class to handle these types of methods?
{
	Pickup* pickup = nullptr;

	while (pickup == nullptr)
	{
		int x = rand() % ((this->grid.getWidth() - 1) + 1);
		int y = rand() % ((this->grid.getHeight() - 1) + 1);

		if (this->grid.getEntityAt(x, y) == nullptr)
		{
			pickup = new Pickup(0, x, y, true, "Egg", 10);
			break;
		}
	}

	this->grid.addEntity(pickup);
}

Grid EntityManager::getGrid()
{
	return this->grid;
}

template<typename T>
T* EntityManager::getEntityGroup()
{
	return dynamic_cast<T*>(this->entityGroup);
}

template Snake* EntityManager::getEntityGroup<Snake>();

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