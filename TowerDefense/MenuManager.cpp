#include <SFML\Graphics.hpp>
#include "Menu.h"
#include <vector>
#include <memory>
#include "MenuManager.h"

using namespace std;

MenuManager* MenuManager::menuManager = NULL;

MenuManager::MenuManager()
{
}

MenuManager::~MenuManager()
{
	menuStack.clear();
}

void MenuManager::addMenu(shared_ptr<Menu> menu)
{
	shared_ptr<Menu> pmenu = menu;
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
	for (shared_ptr<Menu> menu : menuStack)
	{
		menu->draw(w);
	}
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
	return menuManager;
}

void MenuManager::resolveEvent(sf::Event event)
{
	menuStack.back()->resolveEvent(event);
}