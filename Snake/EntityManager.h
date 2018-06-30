/*entity_manager.hpp*/

#ifndef ENTITYMANAGER_HPP
#define ENTITYMANAGER_HPP
#include "Grid.h"
#include "EntityGroup.h"

class EntityManager
{
private:
	Grid * grid; //only ever one grid
	EntityGroup* entityGroup; //TODO: we may want multiple entitygroups in the future for other players, enemies and pickups
public:
	bool loadEntities();
	Grid* getGrid();
	void spawnPickup();

	EntityManager();
	~EntityManager();

	template <class T>
	T* getEntityGroup();
};

#endif