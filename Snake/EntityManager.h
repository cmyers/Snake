#pragma once
#include "Snake.h"
#include "Pickup.h"
#include "Grid.h"

class EntityManager
{
	private:
		Grid* grid;
		Snake* snake;
	public:
		EntityManager();
		~EntityManager();
		EntityManager(Grid* grid);
		void spawnPickup();
		void consumePickup(Entity* entity);
		Grid* getGrid();
		Snake* getSnake(); //TODO: change this to Player class that snake inherits
};