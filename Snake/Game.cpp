#include "stdafx.h"
#include "Game.h"
#include "Grid.h"
#include <iostream>
#include <conio.h>
#include "Enums.h"
#include "Snake.h"
#include "SFML/Graphics.hpp"
#include <sstream>

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
	sfWindow = new sf::RenderWindow(sf::VideoMode(600, 600), "SFML");
	this->sfText = sf::Text();
	this->sfFont = sf::Font();

	if (!sfFont.loadFromFile("resources/Consolas.ttf"))
	{
		// handle error
	}

	this->sfText.setFont(this->sfFont);
	
	this->sfText.setFillColor(sf::Color::Red);
	this->sfText.setCharacterSize(16);
	
};

// TOCHECK: is this still required in some form?
int Game::input()
{
	if (_kbhit())
	{
		return _getch();
	}
}

// TOCHECK: pull keyboard input methods out of here?
bool Game::update(int key) 
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
	{
		
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		this->snake->moveSnake(Direction::DOWN);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		this->snake->moveSnake(Direction::UP);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		this->snake->moveSnake(Direction::LEFT);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		this->snake->moveSnake(Direction::RIGHT);
	}
	return true;
}

void Game::renderStart()
{
	this->running = true;
}

void Game::renderGrid(int xSize, int ySize)
{
	std::stringstream sStream;
	sf::String sfString;
	
	for (int y = 0; y < ySize; y++)
	{
		for (int x = 0; x < xSize; x++)
		{
			if (y == 0 || x == 0 || y == ySize-1)
			{
				sStream <<  "#";
				if (x == xSize - 1) 
				{
					sStream << std::endl;
				}
			} 
			else if (x == xSize-1)
			{
				sStream << "#" << std::endl;
			}
			else
			{
				//TODO: check if entity exists at this location through 2d vector coords?
				//look at grid which will contain entities passed to it such as the body of a snake
				Entity* entity = this->grid->getEntityAt(x, y);

				if (entity != nullptr)
				{
					sStream << "X";
				}
				else
				{
					sStream << " ";
				}
			}
		}
	}
	sfString = sf::String(sStream.str());
	sfText.setString(sfString);
}

void Game::mainRender()
{
	this->renderGrid(this->grid->getWidth(), this->grid->getHeight());
}

void Game::gameLoop()
{
	this->renderStart();

	while (this->sfWindow->isOpen() && this->running)
	{
		sf::Event event;

		while (this->sfWindow->pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				this->sfWindow->close();
				break;
			}
		}

		char key = this->input();
		this->running = this->update(key);
		this->mainRender();

		this->sfWindow->clear();
		this->sfWindow->draw(this->sfText);
		this->sfWindow->display();

		
	}
	
}