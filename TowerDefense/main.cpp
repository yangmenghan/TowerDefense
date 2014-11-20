#pragma once

#include <SFML/Graphics.hpp>
#include "Config.h"
//#include "LevelManager.h"
#include "MenuManager.h"
#include "Menu.h"
#include "StartMenu.h"
#include "GameMenu.h"
#include "CreditsMenu.h"
#include <string>


int main()
{
	sf::VideoMode videoMode(WINDOW_WIDTH, WINDOW_HEIGHT);
	sf::RenderWindow window(videoMode, "~~~Tower Defense!~~~");
	MenuManager menuManager = MenuManager();
	//LevelManager levelManager;////////////////////////PB

	while (window.isOpen())
	{
		window.clear();

		sf::Event event;
		while (window.pollEvent(event))
		{
			if ((event.type == sf::Event::Closed))
				window.close();

			menuManager.resolveEvent(event);
		}

		menuManager.display(window);
	
	}
	return EXIT_SUCCESS;
}