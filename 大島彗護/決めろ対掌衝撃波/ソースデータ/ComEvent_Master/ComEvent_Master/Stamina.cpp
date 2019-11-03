#include "Stamina.h"
#include "Const.h"


Stamina::Stamina( ) {
	initialize( );
}


Stamina::~Stamina( ) {
	finalize( );
}

void Stamina::initialize( ) {
	player1_overheat = false;
	player2_overheat = false;
	player1_gauge = 0;
	player2_gauge = 0;
	player1_count = 0;
	player2_count = 0;
	start_count = 0;

	init = true;
}

void Stamina::finalize( ) {
	player1_overheat = false;
	player2_overheat = false;
	player1_gauge = 0;
	player2_gauge = 0;
	player1_count = 0;
	player2_count = 0;
	start_count = 0;

	init = false;
}

void Stamina::update( const int game_timer ) {
	if ( game_timer > 0 && game_timer != GAME_TIMER_HALF && game_timer < GAME_TIME ) {
		if ( player1_gauge < 1  ) {
			player1_overheat = true;
			player1_gauge = 0;

		} else if ( player1_gauge >= 100 ) {
			player1_overheat = false;
			player1_gauge = 100;
		}

		if( player1_gauge < 100 ) {
			player1_count++;
			if ( player1_count % 5 == 0 ) {
				player1_gauge += BULLET;
			}
		}

		if ( player2_gauge < 1  ) {
			player2_overheat = true;
			player2_gauge = 0;

		} else if ( player2_gauge >= 100 ) {
			player2_overheat = false;
			player2_gauge = 100;
		}

		if( player2_gauge < 100 ) {
			player2_count++;
			if ( player2_count % 5 == 0 ) {
				player2_gauge += BULLET;
			}
		}
	} else if ( game_timer == 0 && player1_gauge < 100 && player2_gauge < 100 ) {
		start_count++;
		if ( start_count % 2 == 0 ) {
			player1_gauge ++;
			player2_gauge ++;
		}
	} 
}

void Stamina::Player1Fire( ) {
	player1_gauge -= STAMINA_SUB;

}

void Stamina::Player2Fire( ) {
	player2_gauge -= STAMINA_SUB;
}


bool Stamina::getPlayer1Overheat( ) const {
	return player1_overheat;
}

bool Stamina::getPlayer2Overheat( ) const {
	return player2_overheat;
}

int Stamina::getPlayer1Gauge( ) const {
	return player1_gauge;
}

int Stamina::getPlayer2Gauge( ) const {
	return player2_gauge;
}