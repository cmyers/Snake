#include "stdafx.h"
#include "Game.h"
#include "Grid.h"
#include <iostream>
#include <conio.h>
#include "Enums.h"
#include "Snake.h"

#define KEY_UP 119
#define KEY_DOWN 115
#define KEY_LEFT 97
#define KEY_RIGHT 100
#define ESC 27

Game::Game() {}

Game::Game(Grid* grid, Snake* snake) 
{
	this->grid = grid;
	this->snake = snake;
};

int Game::input()
{
	if (_kbhit())
	{
		return _getch();
	}
}

bool Game::update(int key) 
{
	if (key == 0)
	{
		return true;
	}
	switch (key) {
		case KEY_UP:
		{
			this->snake->moveSnake(Direction::UP);
			break;
		}
		case KEY_DOWN:
		{
			this->snake->moveSnake(Direction::DOWN);
			break;
		}
		case KEY_LEFT:
		{
			this->snake->moveSnake(Direction::LEFT);
			break;
		}
		case KEY_RIGHT:
		{
			this->snake->moveSnake(Direction::RIGHT);
			break;
		}
		default:
			return false;
			break;
	}
	return true;
}

void Game::renderStart()
{
	this->running = true;
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
				Entity* entity = this->grid->getEntityAt(x, y);

				if (entity != nullptr)
				{
					std::cout << "X";
				}
				else
				{
					std::cout << " ";
				}
			}
		}
	}
}

void Game::mainRender()
{
	this->renderGrid(50, 25);
}

void Game::gameLoop()
{
	this->renderStart();
	while (this->running)
	{
		char key = this->input();
		this->running = this->update(key);
		this->mainRender();
		if (system("CLS")) system("clear");
	}
	
}