#pragma once
#include "Keyboard.h"
#include "GraphMusic.h"

class StaffRoll
{
public:
	StaffRoll();
	~StaffRoll();

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

