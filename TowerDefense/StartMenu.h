#include <SFML\Graphics.hpp>
#include "Menu.h"
#include "Button.h"
#include "Config.h"

class StartMenu : public Menu
{
private :
	Button startButton = Button(START_GAME_TEXTURE);
	Button openScoreBoard = Button(SCOREBOARD_BUTTON_TEXTURE);
	Button creditsButton = Button(CREDITS_BUTTON_TEXTURE);
	Button closeButton = Button(EXIT_BUTTON_TEXTURE);
	Button muteButton = Button(MUTE_BUTTON_TEXTURE);

public:
	void startGame();
	void exitGame();
	void openScoreBoard();
	void openCredits();
};