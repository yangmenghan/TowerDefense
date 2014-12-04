#pragma once

#include <SFML\Graphics.hpp>
#include "Menu.h"
#include "Button.h"
#include "Config.h"
#include <string>

class CreditsMenu : public Menu
{
private:
	Button backButton = Button(BACK_BUTTON_TEXTURE, MUTE_BUTTON_SIZE, sf::Vector2i(2000, 200), 3);

public:
	CreditsMenu();
	CreditsMenu(std::string myTextureAddress, sf::Vector2u mySize, sf::Vector2i myPosition);
	virtual ~CreditsMenu();

	string getCreditsAddress();
	sf::Sprite getSprite();
	void setSprite(sf::Sprite);
	void draw(sf::RenderWindow& w);
	void closeMenu();
	void resolveEvent(sf::Event event);
};