#pragma once
#ifndef GAME_HPP
#define GAME_HPP

#include "EntityManager.h"
#include "SFML/Graphics.hpp"

namespace SnakeGame {

	class Game
	{
	private:
		EntityManager entityManager;
		sf::RenderWindow& sfWindow;
		sf::Font sfFont;
		sf::Text sfText;
		void renderStart();
		void renderGrid();
		std::string renderScore();
		void mainRender();
		sf::Keyboard::Key getInput();
		bool update(); //TODO: make this virtual so we can inherit and implement in a SnakeGame class
		bool running;

	public:
		Game();
		~Game();
		Game(sf::RenderWindow &sfWindow);
		void gameLoop();
	};
}

#endif