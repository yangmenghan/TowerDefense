#include <SFML\Graphics.hpp>
#include "Menu.h"
#include "GameMenu.h"
#include "Button.h"
#include "Config.h"

class StartMenu : public Menu
{
private:
	Button startGameButton = Button(START_GAME_BUTTON_TEXTURE);
	Button openCreditsButton = Button(CREDITS_BUTTON_TEXTURE);
	Button muteButton = Button(MUTE_BUTTON_TEXTURE);
	Button exitGameButton = Button(EXIT_GAME_BUTTON_TEXTURE);

public:
	StartMenu();
	StartMenu(sf::RenderWindow&);
	~StartMenu();

	void draw(sf::RenderWindow&);

	void resolveEvent();

	void startGame();
	void openCredits();
	void exitGame();
};