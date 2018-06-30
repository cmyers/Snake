#ifndef GRID_HPP
#define GRID_HPP

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
		Entity* getEntityAt(int x, int y);
		void removeEntityAt(int x, int y);
		void addEntity(Entity* entity);
		void removeEntity(Entity* entity);
		int getWidth();
		int getHeight();

};

#endif