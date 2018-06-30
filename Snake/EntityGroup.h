#pragma once
#ifndef ENTITYGROUP_HPP
#define ENTITYGROUP_HPP

#include "Entity.h"
#include <deque>

namespace SnakeGame {

	class EntityManager;

	class EntityGroup
	{
	protected:
		std::deque<Entity*> entities;
		virtual bool isInGroup(Entity *entity);
		EntityManager &entityManager;
	public:
		EntityGroup();
		~EntityGroup();
		EntityGroup(EntityManager &entityManager);
	};

}

#endif