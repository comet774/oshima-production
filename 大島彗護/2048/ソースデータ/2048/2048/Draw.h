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
	int num_pos_col;	//ブロックの横の位置
	int num_pos_row;	//ブロックの縦の位置
	int block_num;		//ブロックの数字
	int box_color;		//ブロックの色
	int str_color;		//ブロックの数字の色
	int type;			//ブロックの色分け
	int sub;			//色の調整
	int score;			//スコア
	int highscore;		//ハイスコア
	int str_size;		//文字のサイズ
	Game *_game;
};

