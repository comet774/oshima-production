#pragma once
#include "Title.h"
#include "Outset.h"
#include "Game.h"
#include "Finish.h"
#include "Result.h"
#include "StaffRoll.h"
#include "Discription.h"

class ChangeScene
{
public:
	ChangeScene( );
	~ChangeScene( );

public:
	void update( );

private:
	void initialize( );
	void finalize( );
private:
	bool init;			//������
	int scene_num;		//���݂̃X�N���[��
	bool hard_mode;		//�n�[�h���[�h
	int total_score;	//�g�[�^���X�R�A
	int now_score;		//���擾�����X�R�A
	int before_score;	//�O��̃X�R�A

	Title *_title;
	Outset *_outset;
	Game *_game;
	Finish *_finish;
	Result *_result;
	StaffRoll *_staff_roll;
	Discription *_discription;

};

