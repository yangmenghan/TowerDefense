#include "Config.h"

/* Global game configuration constants
For using those constants :
include Config.h in your class
call simply the name of the global constant ! :D
*/

/*
Tile constants
*/
extern const int		TILE_WIDTH				= 100;
extern const int		TILE_HEIGHT				= 100;
extern const int		TILE_COOLDOWN_TIME		= 5;
extern const int		TILE_NUM_HOR			= 20;
extern const int		TILE_NUM_VER			= 10;

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
extern const sf::Color	RANGE_CIRCLE_FILL_COLOR = sf::Color(0, 0, 255, 100);


extern const float		NORMAL_TOWER_DAMAGE		= 18;
extern const float		NORMAL_TOWER_SPEED		= 1;
extern const float		NORMAL_TOWER_RANGE		= 10;
extern const int		NORMAL_TOWER_PRICE		= 200;
extern const string		NORMAL_TOWER_SPRITE_ADD = "";

extern const float		SUN_TOWER_DAMAGE		= 17;
extern const float		SUN_TOWER_SPEED			= 0.8;
extern const float		SUN_TOWER_RANGE			= 10;
extern const int		SUN_TOWER_PRICE			= 500;
extern const string		SUN_TOWER_SPRITE_ADD	= "";

extern const float		MONEY_TOWER_DAMAGE		= 0;
extern const float		MONEY_TOWER_SPEED		= 0.1;
extern const float		MONEY_TOWER_RANGE		= 0;
extern const int		MONEY_TOWER_PRICE		= 400;
extern const string		MONEY_TOWER_SPRITE_ADD	= "";

extern const float		SLOW_TOWER_DAMAGE		= 0;
extern const float		SLOW_TOWER_SPEED		= 1.5;
extern const float		SLOW_TOWER_RANGE		= 10;
extern const int		SLOW_TOWER_PRICE		= 300;
extern const string		SLOW_TOWER_SPRITE_ADD	= "";

/*
Attack constants
*/

/*
Wave constants
*/

/*
Other constants
*/
extern const int		INIT_MONEY				= 0;
extern const int		INIT_HP					= 10;