#pragma once
#include "GraphMusic.h"
#include "Keyboard.h"

class Outset {
public:
	Outset( );
	~Outset( );

public:
	void update( );
	bool check( );

private:
	void initialize( );
	void finalize( );

private:
	bool init = false;
	bool next = false;

	GraphMusic _graph_music;
	Keyboard *_keyboard = nullptr;
};

