#pragma once

#include <SFML\Graphics.hpp>
#include "Menu.h"
#include <vector>
#include <memory>

using namespace std;

class MenuManager
{
private:
	vector<shared_ptr<Menu> > menuStack;

public:
	static MenuManager* menuManager;

	MenuManager();
	~MenuManager();

	void display(sf::RenderWindow& w);
	void addMenu(shared_ptr<Menu> menu);
	void popMenu();

	std::vector<shared_ptr<Menu>>* getMenus();

	void openMenu(shared_ptr<Menu> menu);
	void closeMenu();
	

	static MenuManager* getMenuManager();

	void resolveEvent(sf::Event);
};