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
	bool init;			//初期化したか
	bool hole_in;		//穴に入ったか
	bool mix;			//合成したか
	int magnification;	//合成弾が穴に入った回数
	int distance;		//1プレイヤー,2プレイヤーのボール間の距離
	int all_score;		//スコア

	struct Player {
		std::vector< int > ball_angle{ 0 };			//穴から見たボールの角度
		std::vector< int > ball_start_angle{ 0 };	//ボールが発射された時の発射台の角度
		std::vector< int > score{ 0 };				//ボールのスコア
		std::vector< int > score_count{ 0 };		//ボールが穴に入った時のスコアの表示時間
		std::vector< double > ball_radius{ 0 };		//穴とボールの距離
		std::vector< double > ball_pos_x{ 0 };		//ボールのx座標
		std::vector< double > ball_pos_y{ 0 };		//ボールのy座標
		std::vector< double > ball_speed{ 0 };		//ボールのスピード
		std::vector< double > ball_acc{ 0 };		//ボールが発射された時の直進スピード
		std::vector< int > ball_efects{ 0 };		//ボールのエフェクト

		int ball_min = 1;			//穴に入ったボールの数
		int ball_max = 1;			//発射されたボールの総数
		int color_num = 0;			//ボールの色
		int pos_num = 0;			//ボールが穴に入った時のスコアの表示位置
	};

	struct Player player1;
	struct Player player2;
	struct Player ball_mix;

	Angle *_angle;
	GraphMusic _graph_music;
};

