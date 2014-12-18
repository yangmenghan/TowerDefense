#pragma once
#include "Entity.h"
#include "Path.h"
#include <SFML\Graphics.hpp>
 

//! Base class of enemies
class Enemy : public Entity{
public :
	//!normal constructor
	Enemy();

	//! constructor with specific caracteristics
	/*!
	\param hp Enemy's maximum hp, integer
	\param defence Enemy's defence, float value, not used yet
	\param bounty integer money that the player get when the enemy is killed
	\param scoreValue integer number of point that the player get when the enemy is killed
	\param sprite sf::Sprite, sprite of the enemy
	\param speed speed of the enemy, float value
	*/
	Enemy(int hP, float defence, int bounty, int scoreValue, sf::Sprite sprite, float speed);

	//!normal desctructor
	virtual ~Enemy();


	//! enemy move method
	/*!
		called when gameLoop executes, do a move of speed*gamespeed pixels
		/sa LevelManager::gameLoop()
	*/
	virtual void move();

	//! enemy succeed method
	/*!
		called in gameLoop(),  when enemy reach the goal tile on the field. This kills the enemy with no bonus and decrease the player's HP. 
		\sa LevelManager::gameLoop()
		\sa Field
	*/
	void succed();

	//! enemy die method
	/*
		called in gameLoop, increase player's money and score
	*/
	void die();

	//! enemy die method
	/*!
		called in succed and BombEnemy::explode() when the enemy is not killed buy the player ( succed / explosion)
		\sa BombEnemy::explode()
		\sa succeed();
	*/
	void dieWithoutBonus();

	//! slow down the enemy
	/*!
		called in SlowAttack when an enemy is touched by the attack. decrese the speed of the enemy for a moment (it is called several times by a slowTower which attacks continuously
		\param time the duration of the effect (in number of frames)
		\sa SlowAttack
	*/
	void slow(int time);

	//! reset the normal speed of the enemy
	/*!
		reset the normal speed of the enemy, called buy the enemy when the slow cooldown reaches zero
	*/
	void unSlow();

	//! update the path of the enemy
	/*!
		called when a new tower appears on the field, update the current path that the enemy follows 
		\sa Field::computePath()
	*/
	void updatePath();

	//! get the hp of the enemy
	int getHP();

	//! update the bounty of the enemy- money bonus given to player when the enemy dies
	int getBounty();

	//! update the score value of the enemy - score bunus given to the player when the enemy dies
	int getScoreValue();

	//!get the defence value of the enemy (not used in v1.0)
	float getDefence();

	//!get the remain slow cooldown timer of the enemy
	int getSlowTime();

	//!get the distance in number of tiles from the enemy position to the goal position
	float getDistanceToTarget();

	//! link a tile to the enemy. 
	/*!
		when the enemy appears, it appears at the position of its tile. modified when the enemy moves on another tile's position
		\param tile the shared pointer of the enemy's tile
	*/
	void setTile(shared_ptr<Tile> tile);

	//! decrease the hp of the enemy of value of damage
	/*!
		\param damage int value of taken damage
	*/
	void takeDamage(int damage);

	//! draw the enemy
	/*!
		\param w sf::RenderWindow the main window of the game
	*/
	void draw(sf::RenderWindow& w);

protected:
	//! int hp value of the enemy. enemy dies when hp = 0
	int hp;

	//! int value of maximal hp value of the enemy, used to show the hp bar
	int maxHp;

	//! float value of the enemy's defence, not used in v1.0
	float defence;

	//! int value of money bonus money bonus given to player when the enemy dies
	int bounty;

	//! score bonus given to player when the enemy dies
	int scoreValue;

	//! cooldown of slow effect in number of frames
	int slowTime;

	//! float value of the original speed of the enemy
	float origin_speed;

	//! true if the enemy is slowed down
	bool slowed;

	//! the path that the enemy follows
	Path path;
};

