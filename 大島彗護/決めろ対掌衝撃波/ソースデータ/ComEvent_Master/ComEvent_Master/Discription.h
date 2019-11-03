#pragma once
#include "Keyboard.h"
#include "GraphMusic.h"

class Discription {
public:
	Discription( );
	~Discription( );

public:
	void update( );
	bool check( );

private:
	void initialize( );
	void finalize( );

private:
	Keyboard *_keyboard;
	GraphMusic _graph_music;
};

