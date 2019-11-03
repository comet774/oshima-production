#pragma once
#include "Keyboard.h"

class Turret {
public:
	Turret( );
	~Turret( );

public:
	void update( const int GAME_TIMER, const bool PLAYER1_OVERHEAT, const bool PLAYER2_OVERHEAT );
	bool getTurretMove( ) const;
	bool getTurret1Fire( ) const;
	bool getTurret2Fire( ) const;
	int getPlayer1Angle( ) const;
	int getPlayer1AngleDown( ) const;
	int getPlayer2Angle( ) const;
	int getPlayer2AngleDown( ) const;

private:
	void initialize( );
	void finalize( );


private:
	bool init;
	bool turret_move;		//�^���b�g�������Ă邩�ǂ���
	bool turret1_fire;		//�^���b�g1���e�����������ǂ���
	bool turret2_fire;		//�^���b�g2���e�����������ǂ���
	bool player1_down;		//�v���C���[1���_�E����Ԃ̎��ɐU�����,true�ŉE,false�ō�
	bool player2_down;		//�v���C���[2���_�E����Ԃ̎��ɐU�����,true�ŉE,false�ō�
	int player1_angle;		//�v���C���[1�̃^���b�g�������Ă����
	int player2_angle;		//�v���C���[2�̃^���b�g�������Ă����
	int player1_angle_down;	//�v���C���[1�̃_�E����Ԃ̃^���b�g�������Ă����
	int player2_angle_down;	//�v���C���[2�̃_�E����Ԃ̃^���b�g�������Ă����

	Keyboard *_keyboard;
};

