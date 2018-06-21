#pragma once
#include "Grid.h"
#include "Snake.h"

class Game
{
	private:
		Grid* grid;
		Snake* snake; //TODO: set this to player class which Snake will inherit from
		void renderStart();
		void renderGrid(int xSize, int ySize);
		void mainRender();
		int input();
		bool update(int key); //TODO: make this virtual so we can inherit and implement in a SnakeGame class
		bool running;
		
	public:
		Game();
		Game(Grid* grid, Snake* snake);
		void gameLoop();
};