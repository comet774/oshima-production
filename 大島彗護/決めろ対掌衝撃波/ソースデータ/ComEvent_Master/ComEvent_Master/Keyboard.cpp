#include "Keyboard.h"
#include "DxLib.h"


Keyboard::Keyboard( ) {
}


Keyboard::~Keyboard( ) {
}

void Keyboard::update( ) {
	GetHitKeyStateAll( check_keyboard );
	for ( int i = 0; i < 256; i++ ) {
		if ( check_keyboard[ i ] ) {
			key_num[ i ]++;
		} else {
			key_num[ i ] = 0;
		}
	}
}

int Keyboard::check ( int KeyCode ) {
	return key_num[ KeyCode ];
}