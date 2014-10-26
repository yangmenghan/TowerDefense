#include <SFML\Graphics.hpp>
#include "Menu.h"
#include "GameMenu.h"
#include "Button.h"
#include "Config.h"
#include <vector>

class StartMenu : public Menu
{
private:
	Button startGameButton = Button(w, START_GAME_BUTTON_TEXTURE);
	Button openCreditsButton = Button(w, CREDITS_BUTTON_TEXTURE);
	Button muteButton = Button(w, MUTE_BUTTON_TEXTURE);
	Button exitGameButton = Button(w, EXIT_GAME_BUTTON_TEXTURE);

	vector<Button*> buttons;

	sf::Event event; // not sure where the event will be : linked to a menu ? linked to the renderwindow ?

public:
	StartMenu(sf::RenderWindow& ); // is it necessary ?
	~StartMenu();

	void draw();

	void resolveEvent(); 

	void startGame();
	void openCredits();
	void exitGame();
};