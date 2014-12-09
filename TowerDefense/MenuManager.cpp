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
	for (shared_ptr<Menu> menu : menuStack)
	{
		menu->draw(w);
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

std::vector<shared_ptr<Menu>>* MenuManager::getMenus()
{
	return &menuStack;
}

void MenuManager::openMenu(shared_ptr<Menu> menu)
{
	addMenu(menu);
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