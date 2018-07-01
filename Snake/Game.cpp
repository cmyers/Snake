#include "stdafx.h"
#include "Game.h"
#include <sstream>
#include "SFML/Graphics.hpp"
#include "Snake.h"

using namespace SnakeGame;

sf::RenderWindow renderWindow;

Game::Game() : sfWindow(renderWindow) {}

Game::~Game() {}

Game::Game(sf::RenderWindow& sfWindow) : sfWindow(sfWindow)
{
	this->entityManager.loadEntities();

	this->sfText = sf::Text();
	this->sfFont = sf::Font();

	//this->entityManager.spawnPickup();

	if (!sfFont.loadFromFile("resources/Consolas.ttf"))
	{
		// handle error
	}

	this->sfText.setFont(this->sfFont);
	this->sfText.setFillColor(sf::Color::Red);
	this->sfText.setCharacterSize(15);
};

sf::Keyboard::Key Game::getInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		return sf::Keyboard::Down;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		return sf::Keyboard::Up;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		return sf::Keyboard::Left;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		return sf::Keyboard::Right;
	}
	return sf::Keyboard::Key::Unknown;
}

bool Game::update()
{
	sf::Keyboard::Key key = this->getInput();

	switch (key)
	{
		case sf::Keyboard::Down:
			this->entityManager.getEntityGroup<Snake>()->changeDirection(Direction::DOWN);
			break;
		case sf::Keyboard::Up:
			this->entityManager.getEntityGroup<Snake>()->changeDirection(Direction::UP);
			break;
		case sf::Keyboard::Left:
			this->entityManager.getEntityGroup<Snake>()->changeDirection(Direction::LEFT);
			break;
		case sf::Keyboard::Right:
			this->entityManager.getEntityGroup<Snake>()->changeDirection(Direction::RIGHT);
			break;
		default:
			break;
	}

	return this->entityManager.getEntityGroup<Snake>()->moveSnake();
}

void Game::renderStart()
{
	this->running = true;
}

void Game::renderGrid()
{
	int xSize = this->entityManager.getGrid()->getWidth();
	int ySize = this->entityManager.getGrid()->getHeight();
	std::stringstream sStream;
	sf::String sfString;

	for (int y = 0; y < ySize; y++)
	{
		for (int x = 0; x < xSize; x++)
		{
			if (y == 0 || x == 0 || y == ySize - 1)
			{
				sStream << "#";
				if (x == xSize - 1)
				{
					sStream << std::endl;
				}
			}
			else if (x == xSize - 1)
			{
				sStream << "#" << std::endl;
			}
			else
			{
				Entity* entity = this->entityManager.getGrid()->getEntityAt(x, y);

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
	sStream << std::endl << this->renderScore();
	sfString = sf::String(sStream.str());
	sfText.setString(sfString);

}

std::string Game::renderScore()
{
	std::stringstream ss;
	ss << "Score: " << this->entityManager.getEntityGroup<Snake>()->getScore();
	return ss.str();
}

void Game::mainRender()
{
	// TODO: Add score render

	this->renderGrid();
}

void Game::gameLoop()
{
	this->renderStart();

	sf::Clock clock;
	sf::Time elapsedTime;

	while (this->sfWindow.isOpen() && this->running)
	{
		elapsedTime += clock.getElapsedTime();
		sf::Event event;

		while (this->sfWindow.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				this->sfWindow.close();
				break;
			}
		}

		if (elapsedTime.asMilliseconds() > (16.6 * 1000))
		{
			this->running = this->update();
			this->mainRender();
			elapsedTime = clock.restart();
		}

		this->sfWindow.clear();
		this->sfWindow.draw(this->sfText);
		this->sfWindow.display();
	}
}