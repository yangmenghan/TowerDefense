#include <SFML\Graphics.hpp>
#include "CreditsMenu.h"
#include "MenuManager.h"

CreditsMenu::CreditsMenu()
{
}

CreditsMenu::~CreditsMenu()
{
}

string CreditsMenu::getCreditsAddress()
{
	return CREDITS_ADD;
}

sf::Sprite CreditsMenu::getSprite()
{
	return sprite;
}

void CreditsMenu::setSprite(sf::Sprite mySprite)
{
	sprite = mySprite;
}

void CreditsMenu::draw(sf::RenderWindow& w)
{
	w.draw(sprite);
}

void CreditsMenu::closeMenu()
{
	MenuManager* m = MenuManager::getMenuManager();
	m->popMenu();
	this->~CreditsMenu();
}

void CreditsMenu::resolveEvent(sf::Event event)
{
	if (backButton.resolveEvent(event))
	{
		closeMenu();
	}
}