#include <SFML\Graphics.hpp>
#include "Menu.h"
#include <vector>
#include "MenuManager.h"

MenuManager::MenuManager()
{
	activeMenu = menuStack.back;
}

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

void MenuManager::display(sf::RenderWindow& w)
{
	activeMenu->draw(w);
}

std::vector<Menu*>* MenuManager::getMenus()
{
	return &menuStack;
}

Menu* MenuManager::getActiveMenu()
{
	return activeMenu;
}

MenuManager* MenuManager::getMenuManager()
{
	return menuManager;
}

void MenuManager::resolveEvent()
{
	activeMenu->resolveEvent();
}