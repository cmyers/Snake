/*entity_manager.hpp*/

#ifndef ENTITYMANAGER_HPP
#define ENTITYMANAGER_HPP
#include "Grid.h"
#include "EntityGroup.h"
#include <random>

namespace SnakeGame {

	class EntityManager
	{
	private:
		Grid * grid; //only ever one grid
		EntityGroup* entityGroup; //TODO: we may want multiple entitygroups in the future for other players, enemies and pickups
		std::random_device rd;  //seed
		std::mt19937 randGen; //mersenne_twister_engine seeded with rd
	public:
		bool loadEntities();
		Grid* getGrid();
		void spawnPickup();

		EntityManager();
		~EntityManager();

		template <class T>
		T* getEntityGroup();
	};
}

#endif
