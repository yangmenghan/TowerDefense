#pragma once
#include "Enemy.h"
#include "Tower.h"
#include "Player.h"
#include "Field.h"
#include "Wave.h"
#include <vector>
#include <SFML\Graphics.hpp>

using namespace std;

class LevelManager{
public:

	//! get a pointer of the LevelManager's singleton
	static LevelManager* getLevelManager();

	//! kill the instance of the LevelManger
	void kill();

	//! the main loop of the game
	/*!
		the main loop of the game, draws field and path, display enemies and towers and resolve actions when called
	*/
	void gameLoop(sf::RenderWindow& w);

	//! add a new enemy in the field
	/*!
		\param e shared pointer of the enemy to add
	*/
	void addEnemy(shared_ptr<Enemy> e);

	//! remove a enemy from the field
	/*!
		\param e shared pointer of the enemy to remove
	*/
	void removeEnemy(shared_ptr<Enemy> e);

	//! remove a enemy from the field
	/*!
		\param index int value of the position of the enemy to remove in the vector
	*/
	void removeEnemy(int index);


	//! add a new tower in the field
	/*!
		\param e shared pointer of the tower to add
	*/
	void addTower(shared_ptr<Tower>);

	//! remove a tower from the field
	/*!
		\param e shared pointer of the tower to remove
	*/
	void removeTower(shared_ptr<Tower>);

	//! remove a tower from the field
	/*!
		\param index int value of the position of the tower to remove in the vector
	*/
	void removeTower(int index);


	//! return a vector of shared pointer of enemies on the field
	vector<shared_ptr<Enemy>> getEnemies();

	//! return a vector of shared pointer of towers on the field
	vector<shared_ptr<Tower>> getTowers();

	//! return a vector of waves on the field
	vector<Wave> getWaves();
	
	//! set a new player for the levelmanager
	/*!
		\param shared pointer of the player to set
	*/
	void setPlayer(shared_ptr<Player> player);

	//! return a shared pointer of the current player
	shared_ptr<Player> getPlayer();

	//! return if the player wins the game (ie, their is no wave and no enemy left)
	bool ifWin();

	//! set a new field to the levelmanager
	void setField(Field &field);

	//! get the field of the game
	Field getField();

	//! get the int value of the game speed
	int getSpeed();

	//! set a new gamespeed
	void setSpeed(int speed);

	//! proceed to the spawn of the next wave
	void nextWave();

	//! load waves 
	/*!
		load waves from the wave txt file, and add them to the game. read the file from top to bottom and from left to right. a line of the txt file represents one wave
		\sa Wave
	*/
	void loadWaves(); 

	//! update path associate to the field
	void updatePath();

	//! stop the game and pop a gameover menu 
	void gameOver(); 

	//! stop tht game and pop a win menu
	void victory(); 

	//! stop the game and clear the vectors
	int stopGame();

	//! start the game and initialize variables
	void startGame();

	//! restart the game
	void restartGame();

	//! get the number of current wave
	int getCurrentWaveNumber();

	//! triggers the wave display
	/*!
		enable/disable the display of the next wave number in big
		\param trigger true : enable the display; false: disable the display
	*/
	void triggerWaveDisplay(bool trigger);

	//! get the wave display enable state
	bool getTrigger();

	//! display enemies, towers path and field
	void display(sf::RenderWindow& w);

private:

	//! private constructor
	LevelManager();
	//! private destructor
	~LevelManager();

	//! pointer to the unique instance of levelmanager
	static LevelManager* levelManager;

	//! current path of enemies on the field from start point to goal
	Path currentPath;

	//! remaining number of frames before the next spawn of wave
	int waveCooldown;

	//! wave display enable state
	bool trigger;

	//! the global game speed
	float gameSpeed = 1;

	//! vector of shared pointers of current displaying enemies 
	vector<shared_ptr<Enemy>> enemies;

	// !vector of shared pointers of current displaying towers
	vector<shared_ptr<Tower>> towers;

	//! vector of remaining waves
	vector<Wave> waves;

	//!  the current player of the game
	shared_ptr<Player> player;

	//! the current field of the game
	Field field;

};