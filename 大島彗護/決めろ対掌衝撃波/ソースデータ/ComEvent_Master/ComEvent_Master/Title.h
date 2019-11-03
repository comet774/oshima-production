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
	bool init = false;			//初期化
	int count = 0;				//タイトルが始まってからの時間
	int right_pos = 0;			//右キャラクターの位置
	int left_pos = 0;			//左キャラクターの位置
	int right_direction = 0;	//右キャラクターの位置
	int left_direction = 0;		//左キャラクターの位置
	bool hard_mode = false;		//Hard Modeかどうか
	bool next = false;			//次に遷移するかどうか
	bool option;				//開発スタッフ,操作指南のどちらを選択してるか
	bool staff_roll;			//開発スタッフ画面に遷移するか
	bool discription;			//操作指南画面に遷移するか
	bool game;					//ゲームを選択したか

	GraphMusic _graph_music;
	Keyboard *_keyboard = nullptr;
};

