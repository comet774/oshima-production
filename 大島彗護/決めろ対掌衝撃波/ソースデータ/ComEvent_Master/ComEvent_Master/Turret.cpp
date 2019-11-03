#include "Turret.h"
#include "Const.h"
#include "DxLib.h"

Turret::Turret( ) {
	initialize( );
}

Turret::~Turret( ) {
	finalize( );
}

void Turret::initialize( ) {
	_keyboard = new Keyboard( );
	turret_move = false;
	turret1_fire = false;
	turret2_fire = false;
	player1_angle = INIT_TURRET_ANGLE;
	player2_angle = INIT_TURRET_ANGLE;

	init = true;
}

void Turret::finalize( ) {
	delete _keyboard;

	_keyboard = nullptr;

	init = false;
}

void Turret::update( const int GAME_TIMER, const bool PLAYER1_OVERHEAT, const bool PLAYER2_OVERHEAT ) {
	_keyboard->update( );
	turret_move = false;
	turret1_fire = false;
	turret2_fire = false;

	if ( GAME_TIMER	> 0 && GAME_TIMER != GAME_TIMER_HALF ) {
		if ( GAME_TIMER < GAME_TIME ) {
			if( _keyboard->check( KEY_INPUT_RIGHT ) > 0 && player1_angle < 180 ) {
				player1_angle += BATTERY_NUM;
				turret_move = true;
			}

			if( _keyboard->check( KEY_INPUT_LEFT ) > 0 && player1_angle > 90 ) {
				player1_angle -= BATTERY_NUM;
				turret_move = true;
			}

			if( _keyboard->check( KEY_INPUT_C ) > 0 && player2_angle < 270 ) {
				player2_angle += BATTERY_NUM;
				turret_move = true;
			}

			if( _keyboard->check( KEY_INPUT_Z ) > 0 && player2_angle > 180 ) {
				player2_angle -= BATTERY_NUM;
				turret_move = true;
			}

			if ( PLAYER1_OVERHEAT == false && _keyboard->check( KEY_INPUT_RETURN ) == 1 ) {
				turret1_fire = true;
			}

			if ( PLAYER2_OVERHEAT == false && _keyboard->check( KEY_INPUT_SPACE ) == 1 ) {
				turret2_fire = true;
			}
		}
	}

	if( PLAYER1_OVERHEAT ) {
		if ( player1_angle_down > 3800 ) {
			player1_down = false;
		}
		if ( player1_angle_down < 3400 ) {
			player1_down = true;
		}

		if ( player1_down ) {
			player1_angle_down += 20;
		} else {
			player1_angle_down -= 20;
		}
	} 

	if( PLAYER2_OVERHEAT ) {
		if ( player2_angle_down > 3800 ) {
			player2_down = false;
		}
	
		if ( player2_angle_down < 3400 ) {
			player2_down = true;
		}

		if ( player2_down ) {
			player2_angle_down += 20;
		} else {
			player2_angle_down -= 20;
		}
	}
}

bool Turret::getTurretMove( ) const {
	return turret_move;
}

bool Turret::getTurret1Fire( ) const {
	return turret1_fire;
}

bool Turret::getTurret2Fire( ) const {
	return turret2_fire;
}

int Turret::getPlayer1Angle( ) const {
	return player1_angle;
}

int Turret::getPlayer1AngleDown( ) const {
	return player1_angle_down;
}

int Turret::getPlayer2Angle( ) const {
	return player2_angle;
}

int Turret::getPlayer2AngleDown( ) const {
	return player2_angle_down;
}
