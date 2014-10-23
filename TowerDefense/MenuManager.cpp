#include <SFML\Graphics.hpp>
#include "Menu.h"
#include <vector>
#include "MenuManager.h"

MenuManager::MenuManager()
{}

MenuManager::~MenuManager()
{
	menuStack.clear();
}

void MenuManager::addMenu(Menu* menu)
{
	menuStack.push_back(menu);
}

void MenuManager::popMenu()
{
	if (!menuStack.empty())
	{
		menuStack.pop_back();
	}
}

void MenuManager::display()
{

}

std::vector<Menu*>* MenuManager::getMenus()
{
	return &menuStack;
}

MenuManager* MenuManager::getMenuManager()
{
	return menuManager;
}
