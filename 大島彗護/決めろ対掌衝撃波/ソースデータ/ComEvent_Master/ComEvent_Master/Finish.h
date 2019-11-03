#pragma once
#include "GraphMusic.h"
#include "Angle.h"
#include "Keyboard.h"
#include <vector>

class Finish {
public:
	Finish( );
	~Finish( );

public:
	void update( const int score );
	bool check( );
private:
	void initialize( );
	void finalize( );
	void enemyPop( const int score );

private:
	bool init;
	bool last_five;
	int start_count;
	int result_count;
	int enemy_num;
	int back_y;
	int stop_y;
	int last_flag;

	std::vector< int >enemy;				//�G�̎��
	std::vector< int >enemy_flag;			//�G����ʂɔ�Ԃ��̃t���O 1�Ȃ��ʂɔ�ԁA0�Ȃ�K���ɔ��
	std::vector< int >enemy_control;		//�G���ǂ����ɔ�Ԃ��̔��� 1�Ȃ�E�ɁA0�Ȃ獶�ɔ��
	std::vector< int >enemy_distance;		//��ʂ̒��S����G�ւ̋���
	std::vector< double >enemy_mag;			//�G����ʂɔ�ԍۂ̊g��l
	std::vector< int >efects_flag;			//�r�[�����G�ɓ����������̃G�t�F�N�g�̏���
	std::vector< bool >rotate_flag;
	std::vector< int >enemy_count;
	std::vector< int >enemy_pos_y;

	GraphMusic _graph_music;
	Angle angle = Angle( );
	Keyboard _keyboard = Keyboard( );
};

