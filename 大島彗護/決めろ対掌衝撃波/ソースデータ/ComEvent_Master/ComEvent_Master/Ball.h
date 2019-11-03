#pragma once
#include <vector>
#include "Angle.h"
#include "GraphMusic.h"

class Ball {
public:
	Ball( );
	~Ball( );

public:
	void update( const int GAME_COUNT, const int SHIFT, const bool HARD_MODE );
	void Player1Fire( int turret_angle );
	void Player2Fire( int turret_angle );
	int getMagnification( ) const;
	bool getHoleIn( ) const;
	bool getMix( ) const;
	int getAllScore ( ) const;

private:
	void initialize( ) ;
	void finalize( );

private:
	bool init;			//������������
	bool hole_in;		//���ɓ�������
	bool mix;			//����������
	int magnification;	//�����e�����ɓ�������
	int distance;		//1�v���C���[,2�v���C���[�̃{�[���Ԃ̋���
	int all_score;		//�X�R�A

	struct Player {
		std::vector< int > ball_angle{ 0 };			//�����猩���{�[���̊p�x
		std::vector< int > ball_start_angle{ 0 };	//�{�[�������˂��ꂽ���̔��ˑ�̊p�x
		std::vector< int > score{ 0 };				//�{�[���̃X�R�A
		std::vector< int > score_count{ 0 };		//�{�[�������ɓ��������̃X�R�A�̕\������
		std::vector< double > ball_radius{ 0 };		//���ƃ{�[���̋���
		std::vector< double > ball_pos_x{ 0 };		//�{�[����x���W
		std::vector< double > ball_pos_y{ 0 };		//�{�[����y���W
		std::vector< double > ball_speed{ 0 };		//�{�[���̃X�s�[�h
		std::vector< double > ball_acc{ 0 };		//�{�[�������˂��ꂽ���̒��i�X�s�[�h
		std::vector< int > ball_efects{ 0 };		//�{�[���̃G�t�F�N�g

		int ball_min = 1;			//���ɓ������{�[���̐�
		int ball_max = 1;			//���˂��ꂽ�{�[���̑���
		int color_num = 0;			//�{�[���̐F
		int pos_num = 0;			//�{�[�������ɓ��������̃X�R�A�̕\���ʒu
	};

	struct Player player1;
	struct Player player2;
	struct Player ball_mix;

	Angle *_angle;
	GraphMusic _graph_music;
};

