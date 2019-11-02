#include <stdio.h>
#include "DxLib.h"
#include "Game.h"
#include "Draw.h"
#include "Keyboard.h"

void init( ) {
	SetDrawScreen( DX_SCREEN_BACK );
	ChangeWindowMode( TRUE );
	SetBackgroundColor( 255, 255, 255 );
}

int WINAPI WinMain ( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow ) {
	init( );
	
	if ( DxLib_Init( ) == -1 ) {
		return -1;
	}

	Game *_game = new Game( );
	Draw *_draw = new Draw( );
	Keyboard *keyboard = new Keyboard( );
	
	while( ProcessMessage( ) == 0 ){
		ClearDrawScreen( );
		keyboard->update( );

		if( keyboard->getKeyState( KEY_INPUT_ESCAPE ) > 0 ) {
			break;
		}


		_game->update( );
		_draw->update( _game );

		ScreenFlip( );
	}

	delete _game;
	delete _draw;
	delete keyboard;

	DxLib_End( );

	return 0;
}
