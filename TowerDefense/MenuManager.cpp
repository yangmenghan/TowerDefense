#include <SFML\Graphics.hpp>
#include "Menu.h"
#include <vector>
#include "MenuManager.h"

MenuManager* MenuManager::menuManager = NULL;

MenuManager::MenuManager()
{
}

MenuManager::~MenuManager()
{
	menuStack.clear();
}

void MenuManager::addMenu(Menu menu)
{
	Menu* pmenu = &menu;
	menuStack.push_back(pmenu);
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
	for ( std::vector<Menu*>::iterator menu = menuStack.begin(); menu != menuStack.end(); menu++)
	{
		(*menu)->draw(w);
	}
}

std::vector<Menu*>* MenuManager::getMenus()
{
	return &menuStack;
}

void MenuManager::openMenu(Menu menu)
{
	addMenu(menu);
}

void MenuManager::closeMenu()
{
	popMenu();
}

MenuManager* MenuManager::getMenuManager()
{
	return menuManager;
}

void MenuManager::resolveEvent(sf::Event event)
{
	menuStack.back()->resolveEvent(event);
}