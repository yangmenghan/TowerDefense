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

	shared_ptr<AudioManager> audio = AudioManager::getAudioManager();
	if (audio->isMute() == false)
	{
		muteButton.spriteUpdate(0);
	}
	else
	{
		muteButton.spriteUpdate(1);
	}

	startGameButton.mouseHover(w);
	openCreditsButton.mouseHover(w);
	muteButton.mouseHover(w);
	exitGameButton.mouseHover(w);

	startGameButton.draw(w);
	openCreditsButton.draw(w);
	muteButton.draw(w);
	exitGameButton.draw(w);
}

void StartMenu::resolveEvent(sf::Event event)
{
	if (startGameButton.checkHover())
	{ 
		startGameButton.resolveEvent(event);
		if (startGameButton.checkClick())
		{
			startGame();
		}
	}
	else if (openCreditsButton.checkHover())
	{
		openCreditsButton.resolveEvent(event);
		if (openCreditsButton.checkClick())
		{
			
			openCredits();
		}
	}
	else if (muteButton.checkHover())
	{
		muteButton.resolveEvent(event);
		if (muteButton.checkClick())
		{
			shared_ptr<AudioManager> audio = AudioManager::getAudioManager();
			if (!audio->isMute())
			{
				audio->mute();
			}
			else
			{
				audio->play();
			}
		}
	}
	else if (exitGameButton.checkHover())
	{
		exitGameButton.resolveEvent(event);
		if (exitGameButton.checkClick())
		{
			exitGame();
		}
	}
}

void StartMenu::startGame()
{
	MenuManager* m = MenuManager::getMenuManager();

	m->addMenu(make_shared<GameMenu>(GAME_MENU_DEFAULT_TEXTURE, sf::Vector2u(WINDOW_WIDTH, WINDOW_HEIGHT), sf::Vector2i(0, 0)));
}

void StartMenu::openCredits()
{
	MenuManager* m = MenuManager::getMenuManager();
	openCreditsButton.setClickedState(false);
	m->addMenu(make_shared<CreditsMenu>(CREDITS_SPRITE_ADD, sf::Vector2u(WINDOW_WIDTH, WINDOW_HEIGHT), sf::Vector2i(0, 0)));
}

void StartMenu::exitGame()
{
	MenuManager* m = MenuManager::getMenuManager();
	m->exit();
}

