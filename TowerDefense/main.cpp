#pragma once

#include <SFML/Graphics.hpp>
#include "Config.h"
#include "LevelManager.h"

int main()
{
	sf::VideoMode videoMode(WINDOW_WIDTH, WINDOW_HEIGHT);
	sf::RenderWindow window(videoMode, "~~~Tower Defense!~~~");

	while (window.isOpen())
	{
		window.clear();

		LevelManager levelManager;////////////////////////PB

		sf::Event event;
		while (window.pollEvent(event))
		{
			if ((event.type == sf::Event::Closed) ||
				((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)))
				window.close();
		}


	
	}
	return EXIT_SUCCESS;
}