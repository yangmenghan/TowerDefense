#pragma once

#include <SFML\Graphics.hpp>
#include "Menu.h"
#include <vector>
#include <memory>

using namespace std;

class MenuManager
{
private:
	vector<shared_ptr<Menu>> menuStack;
	bool exitFlag;


	MenuManager();
	~MenuManager();

public:

	static MenuManager* menuManager;

	void exit();

	void display(sf::RenderWindow& w);
	void addMenu(shared_ptr<Menu> menu);
	void popMenu();

	bool getExitFlag();
	std::vector<shared_ptr<Menu>>* getMenus();

	void openMenu(shared_ptr<Menu> menu);
	void closeMenu();
	

	static MenuManager* getMenuManager();

	void resolveEvent(sf::Event);
};