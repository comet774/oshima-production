#include "Timer.h"
#include "Const.h"
#include "DxLib.h"

Timer::Timer( ) {
	initialize( );
}

Timer::~Timer( ) {
	finalize( );
}

void Timer::update( ) {
	if( game ) {
		game_update( );
	} else {
		start_update( );
	}
}

int Timer::getTimer( ) const {
	if( game ) {
		return game_count;
	}
	return start_count;
}

bool Timer::getGameState( ) const {
	return game;
}

int Timer::getCutInTime( ) const {
	return convert_time;
}

void Timer::initialize( ) {
	start_count = 0;
	game_count = 0;
	convert_time = 0;

	game = false;
	init = true;
}

void Timer::finalize( ) {
	init = false;
}

void Timer::start_update( ) {
	start_count++;
	if (  start_count > START_TIMER + START_TIMAR_GO ) {
		game = true;
	}
}

void Timer::game_update( ) {
	if ( game_count == GAME_TIMER_HALF ) {
		convert_time++;
		if ( convert_time > 200 ) {
			game_count++;
		}
	} else {
		game_count++;
	}
}