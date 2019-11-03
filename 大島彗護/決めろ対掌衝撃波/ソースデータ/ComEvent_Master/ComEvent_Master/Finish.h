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

	std::vector< int >enemy;				//敵の種類
	std::vector< int >enemy_flag;			//敵が画面に飛ぶかのフラグ 1なら画面に飛ぶ、0なら適当に飛ぶ
	std::vector< int >enemy_control;		//敵がどっちに飛ぶかの判定 1なら右に、0なら左に飛ぶ
	std::vector< int >enemy_distance;		//画面の中心から敵への距離
	std::vector< double >enemy_mag;			//敵が画面に飛ぶ際の拡大値
	std::vector< int >efects_flag;			//ビームが敵に当たった時のエフェクトの処理
	std::vector< bool >rotate_flag;
	std::vector< int >enemy_count;
	std::vector< int >enemy_pos_y;

	GraphMusic _graph_music;
	Angle angle = Angle( );
	Keyboard _keyboard = Keyboard( );
};

