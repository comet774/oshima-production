#include "CutIn.h"
#include "DxLib.h"
#include "Const.h"

CutIn::CutIn( ) {
	initialize( );
}


CutIn::~CutIn( ) {
	finalize( );
}

void CutIn::initialize( ) {
	belt_right = -BELT_POS;
	belt_left = WIDTH + BELT_POS;
	scall = 0;

	girl_count = 0;
	girl_pos = WIDTH * ( -1 );
	girl_graph = 0;
	
	init = true;
}

void CutIn::finalize( ) {
	init = false;
}

void CutIn::update_belt( int count ) {
	if (  count > 25 && count < 175 ) {
		if( count < 50  && scall < 200 ) {
			scall += CUT_IN_EXPAND_SPEED;
		}
		if( count > 150 && scall > 0 ) {
			scall -= CUT_IN_EXPAND_SPEED;
		}
		belt_right += 7;
		belt_left -= 7;

	} else {
		belt_right += CUT_IN_FRAME_SPEED;
		belt_left -= CUT_IN_FRAME_SPEED;
	}
}

void CutIn::update_girl( ) {
	girl_count++;	
	if ( girl_pos != 0) {
		girl_pos += 32;
	}

	if ( girl_count > 90 ) {
		girl_graph++;
		girl_pos = WIDTH * ( -1 );
		girl_count = 0;
	}
}

int CutIn::getBeltRight( ) const {
	return belt_right;
}

int CutIn::getBeltLeft( ) const {
	return belt_left;
}

int CutIn::getScalling( ) const {
	return scall;
}

int CutIn::getGirlCount( ) const {
	return girl_count;
}

int CutIn::getGirlPos( ) const {
	return girl_pos;
}

int CutIn::getGirlGraph( ) const {
	return girl_graph;
}
