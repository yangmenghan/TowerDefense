#include <SFML\Graphics.hpp>
#include "Menu.h"
#include "GameMenu.h"
#include "Button.h"
#include "Config.h"

GameMenu::GameMenu()
{
	size.x = GAME_MENU_WIDTH;
	size.y = GAME_MENU_HEIGHT;
	texture = GAME_MENU_DEFAULT_TEXTURE;
	gameSpeed = 1;
	waveTotal = WAVE_TOTAL;
	waveCount = 0;
}

GameMenu::GameMenu(sf::Texture t, float w, float h, int n)
{
	size.x = w;
	size.y = h;
	texture = t;
	gameSpeed = 1;
	waveTotal = n;
	waveCount = 0;
}

GameMenu::~GameMenu(){}

void GameMenu::setGameSpeed(float s)
{

}





