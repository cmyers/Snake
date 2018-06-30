#include "stdafx.h"
#include "EntityGroup.h"
#include "EntityManager.h"

using namespace SnakeGame;

EntityGroup::EntityGroup() : entityManager(entityManager) {}

EntityGroup::EntityGroup(EntityManager& entityManager) : entityManager(entityManager) {}

EntityGroup::~EntityGroup() {}

bool EntityGroup::isInGroup(Entity* entity)
{
	for (int i = 0; i < this->entities.size(); i++)
	{
		if (entity == this->entities[i])
		{
			return true;
		}
	}
	return false;
}