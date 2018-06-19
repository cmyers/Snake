#pragma once
#include "Grid.h"

class Game
{
	private:
		Grid* grid;
		void renderStart();
		void renderGrid(int xSize, int ySize);
		void mainRender();
		void input();
		void logic();
	public:
		Game();
		Game(Grid* grid);
		bool gameLoop();
};