#pragma once
#include "Entity.h"

class Entity
{
	private:
		int id;
		int x;
		int y;
		bool collidable;
	public:
		Entity();
		~Entity();
		Entity(int id, int x, int y, bool collidable);
		int getX();
		int getY();
		bool virtual isConsumable();
};