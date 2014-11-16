#include "StartMenu.h"

StartMenu::StartMenu(sf::RenderWindow& w)
{
	Menu();

	size = w.getSize();
	textureAddress = START_MENU_TEXTURE;
	if (!texture.loadFromFile(textureAddress))
	{
		//error
	}
	sprite.setTexture(texture);
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
	if (startGameButton.mouseClick(event))
	{
		startGame();
	}
	if (openCreditsButton.mouseClick(event))
	{
		openCredits();
	}
	if (muteButton.mouseClick(event))
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
	if (exitGameButton.mouseClick(event))
	{
		exitGame();
	}
}

void StartMenu::startGame()
{
	GameMenu gameMenu = GameMenu();
	MenuManager* m = MenuManager::getMenuManager();

	m->addMenu(gameMenu);
}

void StartMenu::openCredits()
{
	CreditsMenu credits = CreditsMenu();
	MenuManager* m = MenuManager::getMenuManager();

	m->addMenu(credits);
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

