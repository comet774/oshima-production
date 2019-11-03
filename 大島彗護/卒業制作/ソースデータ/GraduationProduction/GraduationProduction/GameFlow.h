#pragma once
#include "Title.h"
#include "Battle.h"
#include "GameClear.h"
#include "GameOver.h"
#include "Keyboard.h"

class GameFlow {
public:
	GameFlow( );
	~GameFlow( );

public:
	void update( Keyboard *key );

private:
	int flow;

	Title *title;
	Battle *battle;
	GameClear *gameclear;
	GameOver *gameover;
};

