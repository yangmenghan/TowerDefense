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
Main Window constants
*/

extern const int		WINDOW_WIDTH;
extern const int		WINDOW_HEIGHT;
extern const int		BORDER_SIZE;
extern const int		FRAME_RATE;

/*
Audio constants
*/

extern const string		MAIN_BGM;


/*
Tile constants
*/
extern const int		TILE_WIDTH;
extern const int		TILE_HEIGHT;
extern const int		TILE_COOLDOWN;
extern const int		TILE_NUM_HOR;
extern const int		TILE_NUM_VER;
#define					TILE_NUM			200
extern const int		NUM_START_TILE;
extern const int		NUM_END_TILE;
extern const string		TILE_SPRITE;

/*
BuildMenu Constants
*/
extern const int		BUTTON_WIDTH;
extern const int		BUTTON_HEIGHT;

/*
Wave Constants 
*/
extern const int		WAVE_TOTAL;
extern const string		WAVE_FILE_ADDRESS;
extern const int		WAVE_SPAWN_COOLDOWN;
extern const int		WAVE_COOLDOWN;


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
extern const int		UPGRADE_INCREMENT;
extern const float		UPGRADE_RATE;
extern const int		TOWER_SPEED;

extern const sf::Color	RANGE_CIRCLE_FILL_COLOR;

extern const float		NORMAL_TOWER_DAMAGE[3];
//extern const int		NORMAL_TOWER_SPEED[3];
extern const float		NORMAL_TOWER_RANGE[3];
extern const int		NORMAL_TOWER_PRICE;
extern const int		NORMAL_TOWER_INCOME[3];
extern const string		NORMAL_TOWER_SPRITE_ADD;

extern const float		SUN_TOWER_DAMAGE[3];
//extern const int		SUN_TOWER_SPEED[3];
extern const float		SUN_TOWER_RANGE[3];
extern const int		SUN_TOWER_PRICE;
extern const int		SUN_TOWER_INCOME[3];
extern const string		SUN_TOWER_SPRITE_ADD;

extern const float		MONEY_TOWER_DAMAGE[3];
extern const int		MONEY_TOWER_GENERATION_UNIT[3];
//extern const int		MONEY_TOWER_SPEED[3];
extern const float		MONEY_TOWER_RANGE[3];
extern const int		MONEY_TOWER_PRICE;
extern const int		MONEY_TOWER_INCOME[3];
extern const string		MONEY_TOWER_SPRITE_ADD;

extern const float		SLOW_TOWER_DAMAGE[3];
//extern const int		SLOW_TOWER_SPEED[3];
extern const float		SLOW_TOWER_RANGE[3];
extern const int		SLOW_TOWER_PRICE;
extern const int		SLOW_TOWER_INCOME[3];
extern const string		SLOW_TOWER_SPRITE_ADD;


/*
Attack constants
*/
extern const int		SLOW_EFFECT;


/*
Menu constants
*/
extern const string		GAME_MENU_DEFAULT_TEXTURE;
extern const string		START_MENU_TEXTURE;
extern const string		CREDITS_SPRITE_ADD;
extern const string		GAMEOVER_MENU_TEXTURE;

/*
Display constants
*/

extern const string			FONT;
extern const sf::Vector2f	LIFE_COUNT_DISPLAY_POSITION;
extern const sf::Vector2f	POINTS_COUNT_DISPLAY_POSITION;
extern const sf::Vector2f	WAVE_COUNT_DISPLAY_POSITION;
extern const sf::Vector2f	MONEY_COUNT_DISPLAY_POSITION;

/*
Button constants
*/
extern const string		PAUSE_BUTTON_TEXTURE;
extern const string		SPEED_BUTTON_TEXTURE;
extern const string		MUTE_BUTTON_TEXTURE;
extern const string		RESTART_BUTTON_TEXTURE;
extern const string		GIVE_UP_BUTTON_TEXTURE;
extern const string		START_GAME_BUTTON_TEXTURE;
extern const string		SCOREBOARD_BUTTON_TEXTURE;
extern const string		CREDITS_BUTTON_TEXTURE;
extern const string		EXIT_GAME_BUTTON_TEXTURE;
extern const string		BACK_BUTTON_TEXTURE;
extern const string		BASIC_TOWER_BUTTON_TEXTURE;
extern const string		SUN_TOWER_BUTTON_TEXTURE;
extern const string		SLOW_TOWER_BUTTON_TEXTURE;
extern const string		MONEY_TOWER_BUTTON_TEXTURE;
extern const string		SELL_BUTTON_TEXTURE;
extern const string		UPGRADE_BUTTON_TEXTURE;

extern const sf::Vector2i	BUTTON_SIZE;
extern const sf::Vector2i	MUTE_BUTTON_SIZE;
extern const sf::Vector2i	SMALL_BUTTON_SIZE;

extern const sf::Vector2i	START_BUTTON_POSITION;
extern const sf::Vector2i	CREDITS_BUTTON_POSITION;
extern const sf::Vector2i	EXIT_BUTTON_POSITION;
extern const sf::Vector2i	MUTE_BUTTON_POSITION;
extern const sf::Vector2i	BACK_BUTTON_POSITION;

/*
Other constants
*/
extern const int		 INIT_MONEY;
extern const int		 INIT_HP;
