#pragma once

class Angle {
public:
	Angle( );
	~Angle( );

public:
	int atan_angle1( int center_x, int center_y, double player_x, double player_y );
	int atan_angle2( int center_x, int center_y, double player_x, double player_y );

private:
	void initialize( );
	void finalize( );

public:
	double angle_num[ 3600 ];
	double sin_num[ 3600 ];
	double cos_num[ 3600 ];

private:
	bool init;

	double angle_x;
	double angle_y;
	int tan_angle;

};

