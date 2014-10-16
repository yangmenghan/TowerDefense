#include <SFML\Graphics.hpp>
#include "CreditsMenu.h"


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

void CreditsMenu::rollCredits()
{

}