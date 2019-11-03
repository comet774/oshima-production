#include "Background.h"
#include "Const.h"

Background::Background( ) {
	initialize( );
}


Background::~Background( ) {
	finalize( );
}

void Background::update( int timer ) {
	int time = timer;

	if ( time != 0 ) { 
		if ( GAME_TIME - time > GAME_TIMER_HALF ) {				//§ŒÀŠÔ‚ª”¼•ªˆÈã‚Ì‚Ìˆ—
			if (  convert < BACK_SPIN_MAX && time % BACK_SPIN_FREEM == 0 ) { 
				convert++;
			}
			spin += convert;

		} else if ( GAME_TIME - time  == GAME_TIMER_HALF ) {	//§ŒÀŠÔ‚ª”¼•ª‚É‚È‚Á‚½‚Ìˆ—
			if ( convert > 0 ) {
				convert -= 2;
				
			}
			if ( convert < 0 ) {
				convert = 0;
			}
			spin += convert;

		} else if ( GAME_TIME - time < GAME_TIMER_HALF ) {		//§ŒÀŠÔ‚ª”¼•ª–¢–‚Ì‚Ìˆ—
			if (  convert < BACK_SPIN_MAX && time % BACK_SPIN_FREEM == 0 ) { 
				convert++;
			}
			spin -= convert; 

		}
	}
}

void Background::initialize( ) {
	_angle = new Angle( );
	spin = ANGLE_RESERVE;
	convert = 0;

	init = true;
}

void Background::finalize( ) {
	delete _angle;

	_angle = nullptr;
	init = false;
}

double Background::getAngle( ) {
	double change_angle = _angle->angle_num[ spin % ANGLE_MAX ];

	return change_angle;
}

int Background::getConvert( ) const {

	return convert;
}