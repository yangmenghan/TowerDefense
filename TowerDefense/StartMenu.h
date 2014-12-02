#pragma once

#include <SFML\Graphics.hpp>
#include "Menu.h"
#include "GameMenu.h"
#include "CreditsMenu.h"
#include "Button.h"
#include "Config.h"
#include "AudioManager.h"
#include <vector>
#include <string>

class StartMenu : public Menu
{
private:
	
	Button startGameButton = Button(START_GAME_BUTTON_TEXTURE, BUTTON_SIZE, START_BUTTON_POSITION, 3);
	Button openCreditsButton = Button(CREDITS_BUTTON_TEXTURE, BUTTON_SIZE, CREDITS_BUTTON_POSITION,3);
	Button muteButton = Button(MUTE_BUTTON_TEXTURE, MUTE_BUTTON_SIZE, MUTE_BUTTON_POSITION,2);
	Button exitGameButton = Button(EXIT_GAME_BUTTON_TEXTURE, BUTTON_SIZE, EXIT_BUTTON_POSITION,3);

public:
	StartMenu();
	StartMenu(std::string myTextureAddress, sf::Vector2u mySize, sf::Vector2i myPosition);
	virtual ~StartMenu();

	void draw(sf::RenderWindow&);

	void resolveEvent(sf::Event); 

	void startGame();
	void openCredits();
	void muteGame();
	void playMusic();
	void exitGame();
};