#include "stdafx.h"
#include "Game.h"
#include "Grid.h"
#include <iostream>

Game::Game() {}

Game::Game(Grid* grid)
{
	this->grid = grid;
};

void Game::input()
{

}

void Game::logic()
{

}

void Game::renderStart()
{

}

void Game::renderGrid(int xSize, int ySize)
{
	for (int y = 0; y < ySize; y++)
	{
		for (int x = 0; x < xSize; x++)
		{
			if (y == 0 || x == 0 || y == ySize-1)
			{
				std::cout << "#";
				if (x == xSize - 1) 
				{
					std::cout << std::endl;
				}
			} 
			else if (x == xSize-1)
			{
				std::cout << "#" << std::endl;
			}
			else
			{
				//TODO: check if entity exists at this location through 2d vector coords?
				//look at grid which will contain entities passed to it such as the body of a snake
				Entity* entity = this->grid->getEntity(x, y);

				if (entity != nullptr)
				{
					std::cout << "X";
				}
				else
				{
					std::cout << " ";
				}
				//std::cout << " ";
			}
		}
	}
}

void Game::mainRender()
{
	this->renderGrid(50, 25);
}

bool Game::gameLoop()
{
	this->input();
	this->logic();
	this->mainRender();
	return true;
}