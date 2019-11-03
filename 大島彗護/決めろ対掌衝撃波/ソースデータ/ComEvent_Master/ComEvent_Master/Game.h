#pragma once
#include "GraphMusic.h"
#include "Background.h"
#include "Timer.h"
#include "CutIn.h"
#include "Turret.h"
#include "Stamina.h"
#include "Ball.h"
#include "Angle.h"

class Game {
public:
	Game( );
	~Game( );
public:
	void update( const bool HARD_MODE );
	int getScore( ) const;
	bool check( );

private:
	void initialize( );
	void finalize( );
	void draw( );
	void drawTimer( );
	void drawTurret( );
	void drawFinish( );

private:
	bool init;			//初期化
	int now_time;		//ゲーム開始から計測してる時間
	int number_graph;	//制限時間
	int graph_size_x;	//スタミナ残量描画時の横の長さ
	int graph_size_y;	//スタミナ残量描画時の縦の長さ
						  
	GraphMusic _graph_music;
	Background *_background;
	Timer *_timer;
	CutIn *_cut_in;
	Turret *_turret;
	Stamina *_stamina;
	Ball *_ball;
	Angle _angle;
};

