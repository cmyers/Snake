#ifndef PICKUP_HPP
#define PICKUP_HPP

#include "Entity.h"
#include "Grid.h"

class Pickup : public Entity
{
	private:
		int points;
		std::string name;
	public:
		Pickup(int id, int x, int y, bool collidable, std::string name, int points);
		std::string getName();
		int getPoints();
		bool isConsumable();
};

#endif
