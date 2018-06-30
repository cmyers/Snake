#ifndef ENTITYMANAGER_HPP
#define ENTITYMANAGER_HPP

#include "Grid.h"
#include "EntityGroup.h"

class EntityManager
{
	private:
		Grid grid;
		EntityGroup *entityGroup; //TODO: vector of entity groups to represent other players?
	public:
		EntityManager();
		~EntityManager();
		EntityManager(Grid grid);
		void spawnPickup();
		//void consumePickup(Entity* entity);
		Grid getGrid();

		template <class T>
		T* getEntityGroup();
};

#endif