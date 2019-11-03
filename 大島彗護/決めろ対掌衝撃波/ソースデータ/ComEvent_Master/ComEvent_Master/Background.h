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
	bool init;
	int spin;
	int convert;

	Angle *_angle;

};

