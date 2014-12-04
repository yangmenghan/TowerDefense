#include <SFML\Graphics.hpp>
#include "CreditsMenu.h"
#include "MenuManager.h"

CreditsMenu::CreditsMenu()
{
}

CreditsMenu::~CreditsMenu()
{
}

CreditsMenu::CreditsMenu(std::string myTextureAddress, sf::Vector2u mySize, sf::Vector2i myPosition) :Menu(myTextureAddress, mySize, myPosition)
{

}

void CreditsMenu::draw(sf::RenderWindow& w)
{
	w.draw(sprite);

	backButton.mouseHover(w);
	backButton.draw(w);
}

void CreditsMenu::closeMenu()
{
	MenuManager* m = MenuManager::getMenuManager();
	m->popMenu();
	//this->~CreditsMenu();
}

void CreditsMenu::resolveEvent(sf::Event event)
{
	if (backButton.checkHover())
	{
		backButton.resolveEvent(event);
		if (backButton.checkClick())
		{
			closeMenu();
		}
	}
}