#pragma once
#include "EntityManager.h"
#include "Pickup.h"
#include "SFML/Graphics.hpp"

class Game
{
	private:
		EntityManager* entityManager;
		sf::RenderWindow* sfWindow;
		sf::Font sfFont;
		sf::Text sfText;
		void renderStart();
		void renderGrid();
		void mainRender();
		bool update(); //TODO: make this virtual so we can inherit and implement in a SnakeGame class
		bool running;
		
	public:
		Game();
		Game(EntityManager* entityManager);
		void gameLoop();
};