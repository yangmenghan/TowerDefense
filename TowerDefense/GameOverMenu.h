#include <SFML\Graphics.hpp>
#include "Menu.h"
#include "GameMenu.h"
#include "CreditsMenu.h"
#include "Button.h"
#include "Config.h"
#include <SFML\Graphics.hpp>
#include "Menu.h"
#include "GameMenu.h"
#include "Button.h"
#include "Config.h"
#include "AudioManager.h"
#include <vector>

class GameOverMenu 
	: public Menu
{
private:

	Button reStartGameButton = Button(RESTART_BUTTON_TEXTURE);//The button to restart the game.
	Button exitGameButton = Button(EXIT_GAME_BUTTON_TEXTURE);//The button te exit.
	

public:
	GameOverMenu(); //Constructor.
	GameOverMenu(std::string, sf::Vector2u, sf::Vector2i);
	~GameOverMenu();//Destructor.

	void draw(sf::RenderWindow&);//Draw.

	void resolveEvent(sf::Event);

	void reStartGame();
	void exitGame();
};