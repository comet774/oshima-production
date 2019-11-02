#pragma once
#include "Game.h"

class Draw {
public:
	Draw( );
	~Draw( );

public:
	void update( Game *game );

private:
	void color( );

private:
	int num_pos_col;
	int num_pos_row;
	int block_num;
	int box_color;
	int str_color;
	int type;
	int sub;
	int score;
	int highscore;
	int str_size;
	Game *_game;
};

