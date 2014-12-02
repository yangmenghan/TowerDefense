#include "StartMenu.h"
#include "MenuManager.h"
#include <string>

StartMenu::StartMenu()
{
}

StartMenu::~StartMenu()
{
}

StartMenu::StartMenu(std::string myTextureAddress, sf::Vector2u mySize, sf::Vector2i myPosition) :Menu(myTextureAddress, mySize, myPosition)
{
	
}

//functions

void StartMenu::draw(sf::RenderWindow& w)
{
	w.draw(sprite);
	startGameButton.draw(w);
	openCreditsButton.draw(w);
	muteButton.draw(w);
	exitGameButton.draw(w);
}

void StartMenu::resolveEvent(sf::Event event)
{
	if (startGameButton.resolveEvent(event))
	{
		startGame();
	}
	if (openCreditsButton.resolveEvent(event))
	{
		openCredits();
	}
	if (muteButton.resolveEvent(event))
	{
		AudioManager audio = AudioManager::getAudioManager();
		if (audio.isMute() == false)
		{
			muteGame();
		}
		else
		{
			playMusic();
		}
	}
	if (exitGameButton.resolveEvent(event))
	{
		exitGame();
	}
}

void StartMenu::startGame()
{
	MenuManager* m = MenuManager::getMenuManager();

	m->popMenu();
	m->addMenu(make_shared<GameMenu>(GAME_MENU_DEFAULT_TEXTURE, sf::Vector2u(WINDOW_WIDTH, WINDOW_HEIGHT), sf::Vector2i(0, 0)));

	this -> ~StartMenu();
}

void StartMenu::openCredits()
{
	MenuManager* m = MenuManager::getMenuManager();

	m->addMenu(make_shared<CreditsMenu>());
}

void StartMenu::muteGame()
{
	AudioManager audio = AudioManager::getAudioManager();
	audio.mute();
}

void StartMenu::playMusic()
{
	AudioManager audio = AudioManager::getAudioManager();
	audio.play();
}

void StartMenu::exitGame()
{
	MenuManager* m = MenuManager::getMenuManager();
	m-> ~MenuManager();
}

