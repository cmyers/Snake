#pragma once
#include "Entity.h"
#include <vector>

class Grid
{
	private:
		std::vector<std::vector<Entity*>> entities;
	public:
		Grid();
		Grid(int xSize, int ySize);
		Grid(std::vector<std::vector<Entity*>> entities);
		Entity* getEntity(int x, int y);
		void moveEntity(int xFrom, int yFrom, int xTo, int yTo);
		void addEntity(Entity* entity, int x, int y);
		bool removeEntity(Entity* entity);
		void removeEntity(int x, int y);
};