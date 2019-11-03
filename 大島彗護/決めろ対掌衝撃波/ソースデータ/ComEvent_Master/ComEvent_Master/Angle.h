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
	double angle_num[ 3600 ];	//角度
	double sin_num[ 3600 ];		//sinの値
	double cos_num[ 3600 ];		//cosの値

private:
	bool init;		//初期化したか

	double angle_x;	//角度のx値
	double angle_y;	//角度のy値
	int tan_angle;	//tanの角度

};

