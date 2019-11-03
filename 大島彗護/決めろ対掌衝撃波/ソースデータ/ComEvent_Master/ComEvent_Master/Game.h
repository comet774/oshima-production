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
	bool init;
	int now_time;
	int number_graph;
	int graph_size_x;
	int graph_size_y;

	GraphMusic _graph_music;
	Background *_background;
	Timer *_timer;
	CutIn *_cut_in;
	Turret *_turret;
	Stamina *_stamina;
	Ball *_ball;
	Angle _angle;
};

