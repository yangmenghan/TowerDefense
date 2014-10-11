#pragma once
#include <SFML\Graphics.hpp>

class Player {
public:
	Player();

	void manageMoney(int);
	void manageScore(int);
	void manageHP(int);

private:
	int money;
	int score;
	int hp;

};