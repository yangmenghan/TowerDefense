#include <SFML\Graphics.hpp>
#include "Menu.h"
#include "Button.h"
#include "Config.h"


// needs creation of Button class

class GameMenu 
	: public Menu
{
private:
	Button pauseButton;
	Button speedButton;
	Button muteButton;
	Button restartButton;
	Button exitButton;

	float gameSpeed;
	int waveCount;
	int waveTotal;

public:
//Constructors, destructors
	GameMenu();
	GameMenu(sf::Texture, float, float, int);
	~GameMenu();

//Getters
	float getGameSpeed();
	int getWaveCount();
	int getWaveTotal();

//Setters
	void setGameSpeed(float);
	void setWaveCount(int);
	void setWaveTotal(int); // not useful ?

//Fonctions
	void pauseGame();
	void restartGame();
	void startWave();
};