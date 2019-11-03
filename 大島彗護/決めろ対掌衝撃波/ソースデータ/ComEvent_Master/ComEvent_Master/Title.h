#pragma once
#include "GraphMusic.h"
#include "Keyboard.h"

class Title {
public:
	Title( );
	~Title( );
public:
	void update( );
	bool check( );
	bool getHardMode( ) const;
	bool getStaffRoll( ) const;
	bool getDiscription( ) const;

private:
	void initialize( );
	void finalize( );

private:
	bool init = false;			//������
	int count = 0;				//�^�C�g�����n�܂��Ă���̎���
	int right_pos = 0;			//�E�L�����N�^�[�̈ʒu
	int left_pos = 0;			//���L�����N�^�[�̈ʒu
	int right_direction = 0;	//�E�L�����N�^�[�̈ʒu
	int left_direction = 0;		//���L�����N�^�[�̈ʒu
	bool hard_mode = false;		//Hard Mode���ǂ���
	bool next = false;			//���ɑJ�ڂ��邩�ǂ���
	bool option;
	bool staff_roll;
	bool discription;
	bool game;

	GraphMusic _graph_music;
	Keyboard *_keyboard = nullptr;
};

