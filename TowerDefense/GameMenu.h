#include <SFML\Graphics.hpp>
#include "Menu.h"

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
	int waveNmb;
	int waveTotal;

public:
	GameMenu(sf::Texture, float, float, int);

	void pause();
	void restart();

	float getSpeed();
	float setSpeed();

	void startWave();
	int getWaveNmb();
	int setWaveNmb();
	int getWaveTotal();
	int setWaveTotal();

	void draw();

};