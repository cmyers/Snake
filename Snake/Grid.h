#pragma once
#include "Entity.h"
#include <vector>

class Grid
{
	private:
		std::vector<std::vector<Entity*>> entities;
	public:
		Grid();
		~Grid();
		Grid(std::vector<std::vector<Entity*>> entities);
		Entity* getEntity(int x, int y);
		void addEntity(Entity* entity, int x, int y);
		Entity* removeEntity(int x, int y);
};