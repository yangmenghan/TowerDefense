#include <SFML\Graphics.hpp>
#include "Menu.h"
#include "GameMenu.h"

GameMenu::GameMenu(sf::Texture t, float w, float h, int n)
{
	width = w;
	height = h;
	texture = t;
	gameSpeed = 1;
	waveTotal = n;
	waveNmb = 0;
}

GameMenu::~GameMenu(){}






