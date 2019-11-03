#pragma once
#include "DxLib.h"

enum ENEMYSTATES {
	ENEMYSTATES_HIERARCHY,
	ENEMYSTATES_NUMBER,
	ENEMYSTATES_SHAPE,
	ENEMYSTATES_COLOR,
	ENEMYSTATES_HP,
	ENEMYSTATES_ATTACK,
	ENEMYSTATES_DEFENCE
};

enum GAMEFLOW {
	GAMEFLOW_TITLE,
	GAMEFLOW_CHARACTORCHOICE,
	GAMEFLOW_DUNGEONCHOICE,
	GAMEFLOW_BATTLE,
	GAMEFLOW_GAMECLEAR,
	GAMEFLOW_GAMEOVER
};

enum BATTLEFLOW {
	BATTLEFLOW_PLAYERCHOICE,
	BATTLEFLOW_INTERVAL,
	BATTLEFLOW_PLAYERATTACK,
	BATTLEFLOW_ENEMYATTACK,
	BATTLEFLOW_NEXT
};

enum COMMAND {
	 COMMAND_ATTACK,
	 COMMAND_DEFENCE
//	 , COMMAND_ABILITY
};

enum SHAPE {
	SHAPE_BOX,
	SHAPE_TRIANGLE,
	SHAPE_SIXSTAR,
	SHAPE_X
};

enum COLOR {
	COLOR_RED,
	COLOR_BLUE, 
	COLOR_GREEN,
	COLOR_WHITE

};

struct drawcolor{
	int red;
	int green;
	int blue;
};

struct enemydata{
	int hierarchy;
	int number;
	int shape;
	int color;
	int hp;
	int attack;
	int defence;

};

struct playerdata{
	int hp;
	int attack;
	int defence;
};

const struct enemydata INITENEMY{ 0, 0, 0, 0, 0, 0, 0 };
const struct playerdata INITPLAYER{ 10, 2, 0 };

const int RED = GetColor( 255, 0, 0 );
const int BLUE = GetColor( 0, 0, 255 );
const int GREEN = GetColor( 0, 255, 0 );
const int WHITE = GetColor( 255, 255, 255 );

const int STATE_NUM = ENEMYSTATES_DEFENCE + 1;

const int SCREEN_SIZE_X = 800;
const int SCREEN_SIZE_Y = 600;
const int HALF_SCREEN_SIZE_X = SCREEN_SIZE_X / 2;
const int HALF_SCREEN_SIZE_Y = SCREEN_SIZE_Y / 2;
const int DRAW_ENEMY_Y_POS = HALF_SCREEN_SIZE_Y - 100;
const int STRING_ROW_INTERVAL = 20;
const int DRAW_SHAPE_SIZE = 100;
const int DRAW_SHAPE_INTERVAL = 10;
