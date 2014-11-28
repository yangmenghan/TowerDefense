#include "Config.h"
#include <SFML\Graphics.hpp>

/* Global game configuration constants
For using those constants :
include Config.h in your class
call simply the name of the global constant ! :D
*/

/*
Main Window constants
*/

extern const int		WINDOW_WIDTH			= 2200;
extern const int		WINDOW_HEIGHT			= 1200;
extern const int		BORDER_SIZE				= 30;


/*
Tile constants
*/

extern const int		TILE_WIDTH				= 100;
extern const int		TILE_HEIGHT				= 100;
extern const int		TILE_COOLDOWN			= 50;
extern const int		TILE_NUM_HOR			= 20;
extern const int		TILE_NUM_VER			= 10;
//extern const int		TILE_NUM				= TILE_NUM_HOR * TILE_NUM_VER;
extern const int		NUM_START_TILE			= 0;
extern const int		NUM_END_TILE			= TILE_NUM_HOR * TILE_NUM_VER - 1;

/*
BuildMenu Constants
*/

extern const int		BUTTON_WIDTH			= 70;
extern const int		BUTTON_HEIGHT			= 70;

/*
Wave constants
*/

extern const int		WAVE_TOTAL				= 21;
extern const string		WAVE_FILE_ADDRESS		= "\Waves.txt";
extern const int		WAVE_SPAWN_COOLDOWN		= 300;
extern const int		WAVE_COOLDOWN			= 600;

/*
Enemy constants
*/

extern const float		NORMAL_ENEMY_SPEED		= 1;
extern const int		NORMAL_ENEMY_HP			= 100;
extern const int		NORMAL_ENEMY_BOUNTY		= 100;
extern const int		NORMAL_ENEMY_SCOREVALUE = 100;
extern const float		NORMAL_ENEMY_DEFENCE	= 10;
extern const string		NORMAL_ENEMY_SPRITE_ADD = "";

extern const float		FAST_ENEMY_SPEED		= 3;
extern const int		FAST_ENEMY_HP			= 50;
extern const int		FAST_ENEMY_BOUNTY		= 150;
extern const int		FAST_ENEMY_SCOREVALUE	= 150;
extern const float		FAST_ENEMY_DEFENCE		= 7;
extern const string		FAST_ENEMY_SPRITE_ADD	= "";

extern const float		BOMB_ENEMY_SPEED		= 1;
extern const int		BOMB_ENEMY_HP			= 200;
extern const int		BOMB_ENEMY_BOUNTY		= 100;
extern const int		BOMB_ENEMY_SCOREVALUE	= 200;
extern const float		BOMB_ENEMY_DEFENCE		= 15;
extern const string		BOMB_ENEMY_SPRITE_ADD	= "";
extern const int		BOMB_ENEMY_TRIGGER		= 25;
extern const int		BOMB_ENEMY_COUNTDOWN	= 5;

extern const float		TOUGH_ENEMY_SPEED		= 0.5;
extern const int		TOUGH_ENEMY_HP			= 500;
extern const int		TOUGH_ENEMY_BOUNTY		= 300;
extern const int		TOUGH_ENEMY_SCOREVALUE	= 350;
extern const float		TOUGH_ENEMY_DEFENCE		= 10;
extern const string		TOUGH_ENEMY_SPRITE_ADD	= "";


/*
Tower constants
*/

extern const float		INCOME_RATE				= 0.8;
extern const int		UPGRADE_INCREMENT		= 5;
extern const float		UPGRADE_RATE			= 1.5;
extern const sf::Color	RANGE_CIRCLE_FILL_COLOR = sf::Color(0, 0, 255, 100);
extern const int		TOWER_SPEED				= 15;


extern const float		NORMAL_TOWER_DAMAGE[3] = { 10, 20, 30 };
//extern const int		NORMAL_TOWER_SPEED[3] = { 15, 10, 5 };
extern const float		NORMAL_TOWER_RANGE[3] = { 10, 15, 20 };
extern const int		NORMAL_TOWER_PRICE = 200;
extern const int		NORMAL_TOWER_INCOME[3] = {150,300, 450 };
extern const string		NORMAL_TOWER_SPRITE_ADD = "";

extern const float		SUN_TOWER_DAMAGE[3] = { 10, 15, 20 };
//extern const int		SUN_TOWER_SPEED[3] = { 30, 20, 10 };
extern const float		SUN_TOWER_RANGE[3] = { 10, 15, 20 };
extern const int		SUN_TOWER_PRICE = 500;
extern const int		SUN_TOWER_INCOME[3] = {400, 800, 1200};
extern const string		SUN_TOWER_SPRITE_ADD	= "";

extern const float		MONEY_TOWER_DAMAGE[3] = { 0, 0, 0 };
//extern const int		MONEY_TOWER_SPEED[3] = { 15, 10, 5 };
extern const float		MONEY_TOWER_RANGE[3] = { 0, 0, 0 };
extern const int		MONEY_TOWER_PRICE = 400;
extern const int		MONEY_TOWER_INCOME[3] = {300, 600, 900};
extern const string		MONEY_TOWER_SPRITE_ADD	= "";

extern const float		SLOW_TOWER_DAMAGE[3] = { 10, 20, 30 };
extern const int		SLOW_TOWER_SPEED[3] = { 15, 10, 5 };
extern const float		SLOW_TOWER_RANGE[3] = { 10, 15, 20 };
extern const int		SLOW_TOWER_PRICE = 300;
extern const int		SLOW_TOWER_INCOME[3] = {250, 500, 750};
extern const string		SLOW_TOWER_SPRITE_ADD	= "";

/*
Attack constants
*/

extern const int		SLOW_EFFECT				= 100;

/*
Menu constants
*/
extern const string		GAME_MENU_DEFAULT_TEXTURE = "TowerDefense/sprite/background.jpg";
extern const string		START_MENU_TEXTURE		  = "TowerDefense/sprite/background.jpg";
extern const string		CREDITS_SPRITE_ADD		  = "TowerDefense/sprite/credits.png";
extern const string		GAMEOVER_MENU_TEXTURE	  = "";
		
/*
Button constants
*/
extern const string		PAUSE_BUTTON_TEXTURE	  = "";
extern const string		SPEED_BUTTON_TEXTURE	  = "";
extern const string		MUTE_BUTTON_TEXTURE		  = "TowerDefense/sprites/mute_button.png";
extern const string		RESTART_BUTTON_TEXTURE	  = "";
extern const string		GIVE_UP_BUTTON_TEXTURE	  = "";
extern const string		START_GAME_BUTTON_TEXTURE = "TowerDefense/sprites/start_game_button";
extern const string		SCOREBOARD_BUTTON_TEXTURE = "";
extern const string		CREDITS_BUTTON_TEXTURE    = "TowerDefense/sprites/credits_button.png";
extern const string		EXIT_GAME_BUTTON_TEXTURE  = "TowerDefense/sprites/exit_game.png";
extern const string		BACK_BUTTON_TEXTURE		  = "TowerDefense/sprite/back_button.png";

extern const sf::Vector2i	BUTTON_SIZE			  = sf::Vector2i(407, 230);
extern const sf::Vector2i	MUTE_BUTTON_SIZE	  = sf::Vector2i(100, 33);
extern const sf::Vector2i	SMALL_BUTTON_SIZE	  = sf::Vector2i(BUTTON_WIDTH, BUTTON_HEIGHT);


/*
Other constants
*/
extern const int		INIT_MONEY				= 0;
extern const int		INIT_HP					= 10;