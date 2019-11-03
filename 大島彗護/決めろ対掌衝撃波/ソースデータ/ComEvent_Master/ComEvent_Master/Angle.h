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
	double angle_num[ 3600 ];	//�p�x
	double sin_num[ 3600 ];		//sin�̒l
	double cos_num[ 3600 ];		//cos�̒l

private:
	bool init;		//������������

	double angle_x;	//�p�x��x�l
	double angle_y;	//�p�x��y�l
	int tan_angle;	//tan�̊p�x

};

