#pragma once
#include "Keyboard.h"

class GameOver {
public:
	GameOver( );
	~GameOver( );

public:
	void update( );
	int nextFlow( );

private:
	void nextChoice( );

private:
	int flow;
	Keyboard *_key;

};

