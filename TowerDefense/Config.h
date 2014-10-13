#pragma once
#include <string>
#include <SFML\Graphics.hpp>

using namespace std;

/* Global game configuration constants 
	For using those constants : 
		include Config.h in your class
		call simply the name of the global constant ! :D
*/

/*
Enemy constants
*/

extern const float		NORMAL_ENEMY_SPEED;
extern const int		NORMAL_ENEMY_HP;
extern const int		NORMAL_ENEMY_BOUNTY;
extern const int		NORMAL_ENEMY_SCOREVALUE;
extern const float		NORMAL_ENEMY_DEFENCE;
extern const string		NORMAL_ENEMY_SPRITE_ADD;

extern const float		FAST_ENEMY_SPEED;
extern const int		FAST_ENEMY_HP;
extern const int		FAST_ENEMY_BOUNTY;
extern const int		FAST_ENEMY_SCOREVALUE;
extern const float		FAST_ENEMY_DEFENCE;
extern const string		FAST_ENEMY_SPRITE_ADD;

extern const float		BOMB_ENEMY_SPEED;
extern const int		BOMB_ENEMY_HP;
extern const int		BOMB_ENEMY_BOUNTY;
extern const int		BOMB_ENEMY_SCOREVALUE;
extern const float		BOMB_ENEMY_DEFENCE;
extern const string		BOMB_ENEMY_SPRITE_ADD;
extern const int		BOMB_ENEMY_TRIGGER;
extern const int		BOMB_ENEMY_COUNTDOWN;

extern const float		TOUGH_ENEMY_SPEED;
extern const int		TOUGH_ENEMY_HP;
extern const int		TOUGH_ENEMY_BOUNTY;
extern const int		TOUGH_ENEMY_SCOREVALUE;
extern const float		TOUGH_ENEMY_DEFENCE;
extern const string		TOUGH_ENEMY_SPRITE_ADD;

/*
Tower constants
*/

extern const float		INCOME_RATE;
extern const sf::Color	RANGE_CIRCLE_FILL_COLOR;

extern const float		NORMAL_TOWER_DAMAGE;
extern const float		NORMAL_TOWER_SPEED;
extern const float		NORMAL_TOWER_RANGE;
extern const int		NORMAL_TOWER_PRICE;
extern const string		NORMAL_TOWER_SPRITE_ADD;

extern const float		SUN_TOWER_DAMAGE;
extern const float		SUN_TOWER_SPEED;
extern const float		SUN_TOWER_RANGE;
extern const int		SUN_TOWER_PRICE;
extern const string		SUN_TOWER_SPRITE_ADD;

extern const float		MONEY_TOWER_DAMAGE;
extern const float		MONEY_TOWER_SPEED;
extern const float		MONEY_TOWER_RANGE;
extern const int		MONEY_TOWER_PRICE;
extern const string		MONEY_TOWER_SPRITE_ADD;

extern const float		SLOW_TOWER_DAMAGE;
extern const float		SLOW_TOWER_SPEED;
extern const float		SLOW_TOWER_RANGE;
extern const int		SLOW_TOWER_PRICE;
extern const string		SLOW_TOWER_SPRITE_ADD;

/*
Attack constants
*/

/*
Wave constants
*/
extern const int		WAVE_TOTAL;

/*
Game Menu constants
*/
extern const string		GAME_MENU_DEFAULT_TEXTURE;
extern const float		GAME_MENU_WIDTH;
extern const float		GAME_MENU_HEIGHT;

/*
Button constants
*/
extern const string		PAUSE_BUTTON_TEXTURE;
extern const string		SPEED_BUTTON_TEXTURE;
extern const string		MUTE_BUTTON_TEXTURE;
extern const string		RESTART_BUTTON_TEXTURE;
extern const string		EXIT_BUTTON_TEXTURE;

/*
Other constants
*/
extern const int		 INIT_MONEY;
extern const int		 INIT_HP;
