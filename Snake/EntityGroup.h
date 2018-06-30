#ifndef ENTITYGROUP_HPP
#define ENTITYGROUP_HPP

#include "Entity.h"
#include <deque>

class EntityManager;

class EntityGroup
{
protected: 
	std::deque<Entity*> entities;
	bool virtual isInGroup(Entity *entity);
	EntityManager &entityManager;
public:
	EntityGroup();
	~EntityGroup();
	EntityGroup(EntityManager &entityManager);
};

#endif