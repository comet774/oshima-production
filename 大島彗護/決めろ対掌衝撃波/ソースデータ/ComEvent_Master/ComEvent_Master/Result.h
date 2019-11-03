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
	bool init;			//初期化
	bool select;		//true:OUTSET false:TITLE
	int now_score;		//スコア
	int score_num;		//スコアの桁数
	bool once;			//リザルト表示時の音楽

	GraphMusic _graph_music;
	Keyboard _keyboard;

};

