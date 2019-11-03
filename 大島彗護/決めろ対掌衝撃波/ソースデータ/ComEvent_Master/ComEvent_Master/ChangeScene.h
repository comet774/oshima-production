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
	bool init;			//初期化
	int scene_num;		//現在のスクリーン
	bool hard_mode;		//ハードモード
	int total_score;	//トータルスコア
	int now_score;		//今取得したスコア
	int before_score;	//前回のスコア

	Title *_title;
	Outset *_outset;
	Game *_game;
	Finish *_finish;
	Result *_result;
	StaffRoll *_staff_roll;
	Discription *_discription;

};

