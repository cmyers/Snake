#include "stdafx.h"
#include "Game.h"
#include <sstream>
#include "SFML/Graphics.hpp"

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
	return 0;
}

// TOCHECK: pull keyboard input methods out of here?
bool Game::update() 
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
	{
		
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		this->snake->changeDirection(Direction::DOWN);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		this->snake->changeDirection(Direction::UP);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		this->snake->changeDirection(Direction::LEFT);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		this->snake->changeDirection(Direction::RIGHT);
	}

	this->snake->moveSnake();

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
				sStream << "#";
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

	sf::Clock clock;
	sf::Time elapsedTime;

	while (this->sfWindow->isOpen() && this->running)
	{
		elapsedTime += clock.getElapsedTime();
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

 		if (elapsedTime.asMilliseconds() > (16.6*1000) )
		{
			this->running = this->update();
			this->mainRender();
			elapsedTime = clock.restart();
		}
		
		this->sfWindow->clear();
		this->sfWindow->draw(this->sfText);
		this->sfWindow->display();
		
	}
	
}