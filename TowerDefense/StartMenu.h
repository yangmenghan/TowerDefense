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
	
	Button startGameButton = Button(START_GAME_BUTTON_TEXTURE, BUTTON_SIZE, sf::Vector2i((WINDOW_WIDTH / 2)-(BUTTON_SIZE.x/2), ((WINDOW_HEIGHT-300)/3)-(BUTTON_SIZE.y/2)), 3);
	Button openCreditsButton = Button(CREDITS_BUTTON_TEXTURE, BUTTON_SIZE, sf::Vector2i((WINDOW_WIDTH / 2) - (BUTTON_SIZE.x / 2), ((WINDOW_HEIGHT - 300) * 2 / 3) - (BUTTON_SIZE.y / 2)),3);
	Button muteButton = Button(MUTE_BUTTON_TEXTURE, MUTE_BUTTON_SIZE, sf::Vector2i(2000, 200),2);
	Button exitGameButton = Button(EXIT_GAME_BUTTON_TEXTURE, BUTTON_SIZE, sf::Vector2i((WINDOW_WIDTH / 2) - (BUTTON_SIZE.x / 2), (WINDOW_HEIGHT - 300) - (BUTTON_SIZE.y / 2)),3);

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