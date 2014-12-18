#pragma once
#include <SFML\Graphics.hpp>

class Player {
public:
	//! normal contructor
	Player();

	//! modify the player's money by adding a int value 
	void manageMoney(int);

	//! modify the player's score by adding a int value 
	void manageScore(int);

	//! modify the player's hp by adding a int value 
	void manageHP(int);

	//! return the hp of the player
	int getHP();

	//! get the current score of the player
	int getScore();

	//! get the current money of the player
	int getMoney();

	//! reset the player's attributs to their initial value
	void init();

private:
	//! money of the player
	int money;

	//! score of the player
	int score;

	//! hp of the player
	int hp;

};