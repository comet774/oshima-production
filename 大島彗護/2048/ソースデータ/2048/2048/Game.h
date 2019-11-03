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

	bool ismove;			//�u���b�N�𓮂�������
	bool skip;				//�u���b�N�𓮂������Ƃ��u���b�N�̊Ԃɋ󔒂��ł�����
	bool finish;			//�Q�[���I�[�o�[���ǂ���
	bool num_col;			//�u���b�N�̃����_���������ɉ��ʒu�����肵����
	bool num_row;			//�u���b�N�̃����_���������ɏc�ʒu�����肵����
	int blocks[ 4 ][ 4 ];	//�������ꂽ�u���b�N�Q
	int score;				//�X�R�A
	int rand_col;			//�u���b�N�̃����_���������̉��ʒu�̐���
	int rand_row;			//�u���b�N�̃����_���������̏c�ʒu�̐���
	int rand_num;			//�u���b�N�������̐����w��̃����_���v�f
	int first;				//�ŏ��̃u���b�N�̐�����
	Keyboard *keyboard;

	
};

