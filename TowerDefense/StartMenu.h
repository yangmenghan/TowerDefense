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
	
	Button startGameButton = Button(START_GAME_BUTTON_TEXTURE);
	Button openCreditsButton = Button(CREDITS_BUTTON_TEXTURE);
	Button muteButton = Button(MUTE_BUTTON_TEXTURE);
	Button exitGameButton = Button(EXIT_GAME_BUTTON_TEXTURE);

public:
	StartMenu();
	StartMenu(std::string myTextureAddress, sf::Vector2u mySize, sf::Vector2i myPosition);
	~StartMenu();

	void draw(sf::RenderWindow&);

	void resolveEvent(sf::Event); 

	void startGame();
	void openCredits();
	void muteGame();
	void playMusic();
	void exitGame();
};