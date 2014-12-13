#include "Config.h"
#include <SFML\Graphics.hpp>

/* 
Global game configuration constants
*/

/*
Main Window constants
*/

extern const int		WINDOW_WIDTH			= 1100;
extern const int		WINDOW_HEIGHT			= 600;
extern const int		BORDER_SIZE				= 30;
extern const int		FRAME_RATE				= 60;

/* 
Audio constants
*/

extern const string		MAIN_BGM				= "music/test.ogg";

/*
Tile constants
*/

extern const int		TILE_WIDTH				= 50; //changed from 100
extern const int		TILE_HEIGHT				= 50;
extern const int		TILE_COOLDOWN			= 240;
extern const int		TILE_NUM_HOR			= 10;
extern const int		TILE_NUM_VER			= 20;
extern const int		NUM_START_TILE			= 4 * TILE_NUM_VER;
extern const int		NUM_END_TILE			= 5 * TILE_NUM_VER  - 1;
extern const string		TILE_SPRITE				= "sprites/tile_texture.png";

/*
BuildMenu Constants
*/

extern const int		BUTTON_WIDTH			= 50;
extern const int		BUTTON_HEIGHT			= 50;

/*
Wave constants
*/

extern const int		WAVE_TOTAL				= 24;
extern const string		WAVE_FILE_ADDRESS		= "Waves.txt";
extern const int		WAVE_SPAWN_COOLDOWN		= 30;
extern const int		WAVE_SPAWN_PAUSE_COOLDOWN = 100;
extern const int		WAVE_COOLDOWN			= 300;

/*
Enemy constants
*/

extern const float		NORMAL_ENEMY_SPEED		= 5;
extern const int		NORMAL_ENEMY_HP			= 100;
extern const int		NORMAL_ENEMY_BOUNTY		= 100;
extern const int		NORMAL_ENEMY_SCOREVALUE = 100;
extern const float		NORMAL_ENEMY_DEFENCE	= 10;
extern const string		NORMAL_ENEMY_SPRITE_ADD = "sprites/Enemy4.png";

extern const float		FAST_ENEMY_SPEED		= 5;
extern const int		FAST_ENEMY_HP			= 50;
extern const int		FAST_ENEMY_BOUNTY		= 150;
extern const int		FAST_ENEMY_SCOREVALUE	= 150;
extern const float		FAST_ENEMY_DEFENCE		= 7;
extern const string		FAST_ENEMY_SPRITE_ADD	= "sprites/Enemy2.png";

extern const float		BOMB_ENEMY_SPEED		= 5;
extern const int		BOMB_ENEMY_HP			= 5000;
extern const int		BOMB_ENEMY_BOUNTY		= 100;
extern const int		BOMB_ENEMY_SCOREVALUE	= 200;
extern const float		BOMB_ENEMY_DEFENCE		= 15;
extern const string		BOMB_ENEMY_SPRITE_ADD	= "sprites/Enemy1.png";
extern const int		BOMB_ENEMY_TRIGGER		= 4800;
extern const int		BOMB_ENEMY_COUNTDOWN	= 120;

extern const float		TOUGH_ENEMY_SPEED		= 5;
extern const int		TOUGH_ENEMY_HP			= 500;
extern const int		TOUGH_ENEMY_BOUNTY		= 300;
extern const int		TOUGH_ENEMY_SCOREVALUE	= 350;
extern const float		TOUGH_ENEMY_DEFENCE		= 10;
extern const string		TOUGH_ENEMY_SPRITE_ADD	= "sprites/Enemy5.png";


/*
Tower constants
*/

extern const sf::Color	RANGE_CIRCLE_FILL_COLOR = sf::Color(0, 0, 255, 100);
extern const int		TOWER_SPEED				= 15;


extern const float		NORMAL_TOWER_DAMAGE[3]	= { 10, 20, 25 };
extern const int		NORMAL_TOWER_SLOW_AMOUNT[3]	= { 0, 0, 0 };
extern const int		NORMAL_TOWER_SPEED[3]	= {20, 15, 10};
extern const float		NORMAL_TOWER_RANGE[3]	= { 125, 175, 225 };
extern const int		NORMAL_TOWER_PRICE		= 200;
extern const int		NORMAL_TOWER_INCOME[3]	= {150,300, 450 };
extern const string		NORMAL_TOWER_SPRITE_ADD = "sprites/normal_tower.png";

extern const float		SUN_TOWER_DAMAGE[3]		= { 25, 45, 60};
extern const int		SUN_TOWER_SLOW_AMOUNT[3]= { 0, 0, 0 };
extern const int		SUN_TOWER_SPEED[3]		= {30, 25, 20};
extern const float		SUN_TOWER_RANGE[3]		= { 125, 175, 225 };
extern const int		SUN_TOWER_PRICE			= 500;
extern const int		SUN_TOWER_INCOME[3]		= {400, 800, 1200};
extern const string		SUN_TOWER_SPRITE_ADD	= "sprites/sun_tower.png";

extern const float		MONEY_TOWER_DAMAGE[3]	= { 0, 0, 0 };
extern const int		MONEY_TOWER_GENERATION_UNIT[3] = { 300, 600, 900 }; 
extern const int		MONEY_TOWER_SPEED[3]	= {180, 150, 120};
extern const float		MONEY_TOWER_RANGE[3]	= { 0, 0, 0 };
extern const int		MONEY_TOWER_PRICE		= 400;
extern const int		MONEY_TOWER_INCOME[3]	= {300, 600, 900};
extern const string		MONEY_TOWER_SPRITE_ADD	= "sprites/money_tower.png";

extern const float		SLOW_TOWER_DAMAGE[3]	= { 0, 0, 0 };
extern const int		SLOW_TOWER_SLOW_AMOUNT[3]= { 120, 180, 240 };
extern const int		SLOW_TOWER_SPEED[3]		= {20, 15, 10};
extern const float		SLOW_TOWER_RANGE[3]		= { 125, 175, 225 };
extern const int		SLOW_TOWER_PRICE		= 300;
extern const int		SLOW_TOWER_INCOME[3]	= {250, 500, 750};
extern const string		SLOW_TOWER_SPRITE_ADD	= "sprites/slow_tower.png";

/*
Attack constants
*/

extern const int		SLOW_EFFECT				= 1;

/*
Menu constants
*/

extern const string		GAME_MENU_DEFAULT_TEXTURE = "sprites/backgrounds/gamebg.png";
extern const string		START_MENU_TEXTURE		  = "sprites/backgrounds/background.png";
extern const string		CREDITS_SPRITE_ADD		  = "sprites/backgrounds/credits.png";
extern const string		GAMEOVER_MENU_TEXTURE			= "sprites/backgrounds/gameover.png";
extern const string		WIN_MENU_TEXTURE				="sprites/youwin.png";

/*
Display constants
*/

extern const string			FONT								= "ressources/SourceCodePro.ttf";
extern const sf::Vector2f	LIFE_COUNT_DISPLAY_POSITION			= sf::Vector2f(500, 13);
extern const sf::Vector2f	POINTS_COUNT_DISPLAY_POSITION		= sf::Vector2f(700, 13);
extern const sf::Vector2f	WAVE_COUNT_DISPLAY_POSITION			= sf::Vector2f(1000, 13);
extern const sf::Vector2f	MONEY_COUNT_DISPLAY_POSITION		= sf::Vector2f(850, 13);

/*
Button constants
*/
extern const string		PAUSE_BUTTON_TEXTURE		= "sprites/buttons/pause_button.png";
extern const string		SPEED_BUTTON_TEXTURE		= "sprites/buttons/speed_button.png";
extern const string		MUTE_BUTTON_TEXTURE			= "sprites/buttons/mute_button.png";
extern const string		RESTART_BUTTON_TEXTURE		= "sprites/buttons/restart_button.png";
extern const string		GIVE_UP_BUTTON_TEXTURE		= "sprites/buttons/give_up_button.png";
extern const string		START_GAME_BUTTON_TEXTURE	= "sprites/buttons/start_game_button.png";
extern const string		SCOREBOARD_BUTTON_TEXTURE	= "";
extern const string		CREDITS_BUTTON_TEXTURE      = "sprites/buttons/credits_button.png";
extern const string		EXIT_GAME_BUTTON_TEXTURE 	= "sprites/buttons/exit_game.png";
extern const string		BACK_BUTTON_TEXTURE			= "sprites/buttons/back_button.png";
extern const string		BASIC_TOWER_BUTTON_TEXTURE	= "sprites/normal_tower_button.png";
extern const string		SUN_TOWER_BUTTON_TEXTURE	= "sprites/sun_tower_button.png";
extern const string		SLOW_TOWER_BUTTON_TEXTURE	= "sprites/slow_tower_button.png";
extern const string		MONEY_TOWER_BUTTON_TEXTURE	= "sprites/money_tower_button.png";
extern const string		SELL_BUTTON_TEXTURE			= "sprites/sell_tower_button.png";
extern const string		UPGRADE_BUTTON_TEXTURE		= "sprites/upgrade_tower_button.png";


extern const sf::Vector2i	BUTTON_SIZE			  = sf::Vector2i(408, 76);
extern const sf::Vector2i	MUTE_BUTTON_SIZE	  = sf::Vector2i(100, 32);
extern const sf::Vector2i	BACK_BUTTON_SIZE	  = sf::Vector2i(100, 34);
extern const sf::Vector2i	SMALL_BUTTON_SIZE	  = sf::Vector2i(BUTTON_WIDTH, BUTTON_HEIGHT);

extern const sf::Vector2i	START_BUTTON_POSITION	= sf::Vector2i(346, 150);
extern const sf::Vector2i	CREDITS_BUTTON_POSITION = sf::Vector2i(346, 250);
extern const sf::Vector2i	EXIT_BUTTON_POSITION	= sf::Vector2i(346, 350);
extern const sf::Vector2i	MUTE_BUTTON_POSITION	= sf::Vector2i(10, 10);
extern const sf::Vector2i	RESTART_BUTTON_POSITION	= sf::Vector2i(10, 560);

extern const sf::Vector2i	BACK_BUTTON_POSITION	= sf::Vector2i((WINDOW_WIDTH - MUTE_BUTTON_SIZE.x)/2,500);
extern const sf::Vector2i	GO_RESTART_BUTTON_POSITION = sf::Vector2i(((WINDOW_WIDTH - MUTE_BUTTON_SIZE.x) / 2)+100, 500);
extern const sf::Vector2i	GO_BACK_BUTTON_POSITION = sf::Vector2i(((WINDOW_WIDTH - MUTE_BUTTON_SIZE.x) / 2) - 100, 500);




/*
Other constants
*/
extern const int		INIT_MONEY				= 400;
extern const int		INIT_HP					= 10;