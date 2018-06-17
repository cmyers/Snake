#include "stdafx.h"
#include "Game.h"
#include "Grid.h"

Game::Game(Grid grid)
{
	this->grid = grid;
}

void Game::input()
{

}

void Game::logic()
{

}

void Game::render()
{

}

bool Game::gameLoop()
{
	this->input();
	this->logic();
	this->render();
	return true;
}