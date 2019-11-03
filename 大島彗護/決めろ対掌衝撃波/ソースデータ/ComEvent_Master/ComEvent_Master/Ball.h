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
	bool init;
	bool hole_in;
	bool mix;
	int magnification;
	int distance;
	int all_score;

	struct Player {
		std::vector< int > ball_angle{ 0 };
		std::vector< int > ball_start_angle{ 0 };
		std::vector< int > ball_cut_in{ 0 };
		std::vector< int > score{ 0 };
		std::vector< int > score_count{ 0 };
		std::vector< double > ball_radius{ 0 };
		std::vector< double > ball_pos_x{ 0 };
		std::vector< double > ball_pos_y{ 0 };
		std::vector< double > ball_speed{ 0 };
		std::vector< double > ball_acc{ 0 };
		std::vector< int > ball_efects{ 0 };

		int ball_min = 1;
		int ball_max = 1;
		int Battered = 0;
		int color_num = 0;
		int pos_num = 0;
		int letter[ 3 ] = { 0 };
	};

	struct Player player1;
	struct Player player2;
	struct Player ball_mix;

	Angle *_angle;
	GraphMusic _graph_music;
};

