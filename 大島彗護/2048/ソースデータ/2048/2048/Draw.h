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
	int num_pos_col;	//�u���b�N�̉��̈ʒu
	int num_pos_row;	//�u���b�N�̏c�̈ʒu
	int block_num;		//�u���b�N�̐���
	int box_color;		//�u���b�N�̐F
	int str_color;		//�u���b�N�̐����̐F
	int type;			//�u���b�N�̐F����
	int sub;			//�F�̒���
	int score;			//�X�R�A
	int highscore;		//�n�C�X�R�A
	int str_size;		//�����̃T�C�Y
	Game *_game;
};

