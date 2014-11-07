#include <SFML\Graphics.hpp>
#include "Menu.h"
#include "GameMenu.h"
#include "CreditsMenu.h"
#include "Button.h"
#include "Config.h"
#include "AudioManager.h"
#include <vector>

class StartMenu : public Menu
{
private:
	Button startGameButton = Button(START_GAME_BUTTON_TEXTURE);
	Button openCreditsButton = Button(CREDITS_BUTTON_TEXTURE);
	Button muteButton = Button(MUTE_BUTTON_TEXTURE);
	Button exitGameButton = Button(EXIT_GAME_BUTTON_TEXTURE);

	vector<Button*> buttons;

	 // not sure where the event will be : linked to a menu ? linked to the renderwindow ?

public:
	StartMenu(sf::RenderWindow&); // is it necessary ?
	~StartMenu();

	void draw(sf::RenderWindow&);

	void resolveEvent(sf::Event); 

	void startGame();
	void openCredits();
	void muteGame();
	void playMusic();
	void exitGame();
};