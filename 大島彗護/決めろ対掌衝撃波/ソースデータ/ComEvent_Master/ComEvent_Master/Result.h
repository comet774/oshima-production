#pragma once
#include "GraphMusic.h"
#include "Keyboard.h"

class Result {
public:
	Result( );
	~Result( );

public:
	void update( const int score );
	bool check( );
	bool getSelect( ) const;

private:
	void initialize( );
	void finalize( );

private:
	bool init;
	bool select;		//true:OUTSET false:TITLE
	int now_score;
	int score_num;
	bool once;

	GraphMusic _graph_music;
	Keyboard _keyboard;

};

