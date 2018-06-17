#pragma once
#include "Entity.h"
#include <iostream>

class Pickup : Entity
{
	private:
		int points;
		std::string name;
	public:
		Pickup(std::string name);
		~Pickup();
		std::string getName();
		int getPoints();
};
