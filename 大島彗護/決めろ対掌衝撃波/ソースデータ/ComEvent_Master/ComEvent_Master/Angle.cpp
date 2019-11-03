#include "Angle.h"
#include "DxLib.h"
#include "Const.h"
#include <math.h>

Angle::Angle( ) {
	initialize( );
}

Angle::~Angle( ) {
	finalize( );
}

int Angle::atan_angle1( int center_x, int center_y, double player_x, double player_y ) {
	angle_x = sqrt( pow( player_x - ( double )center_x, 2 ) );
	angle_y = sqrt( pow( player_y - ( double )center_y, 2 ) );
	tan_angle = ( int ) ( atan2( angle_y, angle_x ) * 180 / DX_PI );

	return tan_angle;
}

int Angle::atan_angle2( int center_x, int center_y, double player_x, double player_y ) {
	angle_x = sqrt( pow( ( double )center_x - player_x, 2 ) );
	angle_y = sqrt( pow( ( double )center_y - player_y, 2 ) );
	tan_angle = ( int ) ( atan2( angle_y, angle_x ) * 180 / DX_PI );

	return tan_angle;
}

void Angle::initialize( ) {
	for ( int i = 0; i < ANGLE_MAX; i++ ) {
		angle_num[ i ] = i * DX_PI / ANGLE_HALF;
		sin_num[ i ] = sin( angle_num[ i ] );
		cos_num[ i ] = cos( angle_num[ i ] );
	}
	angle_x = 0;
	angle_y = 0;
	tan_angle = 0;
	init = true;
}

void Angle::finalize( ) {
	init = false;
}