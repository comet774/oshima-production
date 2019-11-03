#pragma once
#include "Angle.h"

class Background {
public:
	Background( );
	~Background( );

public:
	void update( int timer );
	double getAngle( );
	int getConvert( ) const;

private:
	void initialize( );
	void finalize( );

private:
	bool init;		//初期化したか
	int spin;		//回転のスピード
	int convert;	//回転の加速値

	Angle *_angle;

};

