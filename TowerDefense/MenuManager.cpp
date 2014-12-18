#include <SFML\Graphics.hpp>
#include "Menu.h"
#include <vector>
#include <memory>
#include <iostream>
#include "MenuManager.h"

using namespace std;

MenuManager* MenuManager::menuManager = NULL;

MenuManager::MenuManager()
{
	existBTMenu = false;
}

MenuManager::~MenuManager()
{
	menuStack.clear();
}


void MenuManager::exit()
{
	exitFlag = true;
}

void MenuManager::addMenu(shared_ptr<Menu> menu)
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
	for (int i = 0; i < menuStack.size(); i++)
	{
		menuStack[i]->draw(w);
	}
}

bool MenuManager::getExitFlag()
{
	return exitFlag;
}

bool MenuManager::getExistBTMenu()
{
	return existBTMenu;
}

void MenuManager::setExistBTMenu(bool _exist)
{
	existBTMenu = _exist;
}

void MenuManager::closeMenu()
{
	popMenu();
}

MenuManager* MenuManager::getMenuManager()
{
	if (menuManager == NULL)
	{
		menuManager = new MenuManager;
	}

	return menuManager;
};

void MenuManager::resolveEvent(sf::Event event)
{
	menuStack.back()->resolveEvent(event);
}

int MenuManager::getCount()
{
	return menuStack.size();
}

shared_ptr<Menu> MenuManager::getActiveMenu()
{
	return menuStack.back();
}

void MenuManager::clearMenuStack()
{
	menuStack.clear();
}