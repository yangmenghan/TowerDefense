#pragma once
#include <SFML\Graphics.hpp>

class Player {
public:
	Player();

	void manageMoney(int);
	void manageScore(int);
	void manageHP(int);

	int getHP();
	int getScore();
	int getMoney();

private:
	int money;
	int score;
	int hp;

};