#include "Keyboard.h"
#include "DxLib.h"

Keyboard::Keyboard( ) {

}

Keyboard::~Keyboard( ) {

}

void Keyboard::update( ) {
	GetHitKeyStateAll( key );

	for ( int i = 0; i < 256; i++ ) {
		if ( key[ i ] ) {
			cheak[ i ]++;
		} else {
			cheak[ i ] = 0;
		}

	}
}

int Keyboard::getKeyState( int keycode ) {
	return cheak[ keycode ];
}