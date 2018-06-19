// Snake.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Entity.h"
#include "Game.h"
#include "Grid.h"
#include "Snake.h"
#include <vector>

Game game;

void loadEntities()
{
	Snake snake;
	Grid *grid = new Grid(50, 25);

	game = Game(grid);

	std::vector<Entity*> snakeBody = snake.getBody();
	for (int i = 0; i < snakeBody.size(); i++)
	{
		grid->addEntity(snakeBody.at(i), i + 5, 5);
	}

	bool debug = true;
}

void init()
{
	
	
	loadEntities();


	game.gameLoop();
}

int main()
{
	init();
    return 0;
}

