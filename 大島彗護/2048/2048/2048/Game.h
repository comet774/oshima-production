#pragma once
#include "Keyboard.h"

class Game {
public:
	Game( );
	~Game( );
public:
	void update( );
	int getScore( );
	bool getFinish( );
	int getBlock( int col, int row );

private:
	void Init( );
	void GameInit( );
	void Action( );
	void Retry( );
private:

	bool ismove;
	bool skip;
	bool finish;
	bool num_col;
	bool num_row;
	int noblock;
	int blocks[ 4 ][ 4 ];
	int score;
	int rand_col;
	int rand_row;
	int rand_num;
	int first;
	Keyboard *keyboard;

	
};

