#include <SFML\Graphics.hpp>
#include "Menu.h"
#include "GameMenu.h"
#include "Button.h"
#include "Config.h"

class StartMenu : public Menu
{
private:
	Button startGameButton = Button(START_GAME_TEXTURE);
	Button openCreditsButton = Button(CREDITS_BUTTON_TEXTURE);
	Button muteButton = Button(MUTE_BUTTON_TEXTURE);
	Button exitGameButton = Button(EXIT_BUTTON_TEXTURE);

private:
	void startGame();
	void openCredits();
};