#pragma once
#include "Grid.h"

class Game
{
private:
	Grid grid;
	void render();
	void input();
	void logic();
public:
	Game(Grid grid);
	bool gameLoop();
};