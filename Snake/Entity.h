#pragma once
#ifndef ENTITY_HPP
#define ENTITY_HPP

namespace SnakeGame {

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
		virtual bool isConsumable();
	};

}

#endif