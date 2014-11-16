#pragma once

#include <SFML\Graphics.hpp>
#include "Menu.h"
#include <vector>

class MenuManager
{
private:
	std::vector<Menu*> menuStack;

public:
	static MenuManager* menuManager;

	MenuManager();
	~MenuManager();

	void display(sf::RenderWindow& w);
	void addMenu(Menu menu);
	void popMenu();

	std::vector<Menu*>* getMenus();

	void openMenu(Menu menu);
	void closeMenu();
	

	static MenuManager* getMenuManager();

	void resolveEvent(sf::Event);
};