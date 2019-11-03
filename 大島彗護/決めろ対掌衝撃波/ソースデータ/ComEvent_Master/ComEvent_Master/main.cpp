#include "Dxlib.h"
#include "Const.h"
#include "ChangeScene.h"
#include "Keyboard.h"

void Setscreen( ) {
	SetGraphMode( WIDTH, HEIGHT, 16 );
	SetDrawArea( 0, 0, WIDTH, HEIGHT );
	SetDrawMode( DX_DRAWMODE_NEAREST );
	SetDrawBlendMode( DX_BLENDMODE_NOBLEND, 0 );
	SetDrawBright( 0, 0, 0 );
	SetFullScreenResolutionMode( DX_FSRESOLUTIONMODE_NATIVE );
	SetFullScreenScalingMode( DX_FSSCALINGMODE_BILINEAR );
	ChangeWindowMode( TRUE );
}

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow ) {

	Setscreen( );


	if( DxLib_Init( ) == -1 ) {
		return -1;
	}

	SetDrawScreen( DX_SCREEN_BACK );

	Keyboard *keyboard = new Keyboard( );
	ChangeScene *scene = new ChangeScene( );

	while( ProcessMessage( ) == 0 ) {
		keyboard->update( );

		if( keyboard->check( KEY_INPUT_ESCAPE ) ) {
			break;
		}		
		
		ClearDrawScreen( );
		scene->update( );
		ScreenFlip( );
	}

	delete keyboard;
	delete scene;
	DxLib_End( );
	return 0;
}