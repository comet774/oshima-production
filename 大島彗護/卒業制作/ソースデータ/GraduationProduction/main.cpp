#include <stdio.h>
#include "DxLib.h"
#include "constfail.h"
#include "GameFlow.h"
#include "Keyboard.h"
#include "ReadExcel.h"

void init ( ){
	SetDrawScreen( DX_SCREEN_BACK );
	ChangeWindowMode( TRUE );
	SetGraphMode( SCREEN_SIZE_X,  SCREEN_SIZE_Y, 32 );
//	SetFullScreenResolutionMode( DX_FSRESOLUTIONMODE_DESKTOP )


}

int WINAPI WinMain ( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow ) {
	init( );

	if ( DxLib_Init( ) == -1 ) {
		DrawString( 0, 0, "DxLib_Init( )ƒGƒ‰[", WHITE );
		return -1;
	}

	GameFlow *game_f = new GameFlow( );
	Keyboard *key = new Keyboard( );
	ReadExcel *readE = new ReadExcel( );

	if ( readE->Read( ) == -1 ) {
		return -1;
	}

//	int test = readE->setNum( ENEMYSTATES_ATTACK, 1 );
//
//	DrawFormatString( 0,0, WHITE,"%d", test );
//	WaitKey( );

	//for ( int i = 0; i < 5; i++  ) {
	//	int enemy_pos_x = ( i + 1 ) * ( DRAW_SHAPE_SIZE + DRAW_SHAPE_INTERVAL );
	//
	//	switch( i ) {
	//		case SHAPE_BOX:
	//			DrawBox( enemy_pos_x, DRAW_ENEMY_Y_POS, enemy_pos_x + DRAW_SHAPE_SIZE, DRAW_ENEMY_Y_POS + DRAW_SHAPE_SIZE, WHITE, false );
	//			break;
	//		case SHAPE_TRIANGLE:
	//			DrawTriangle( enemy_pos_x, DRAW_ENEMY_Y_POS + DRAW_SHAPE_SIZE, enemy_pos_x + DRAW_SHAPE_SIZE / 2, DRAW_ENEMY_Y_POS, enemy_pos_x + DRAW_SHAPE_SIZE, DRAW_ENEMY_Y_POS + DRAW_SHAPE_SIZE, WHITE, false );
	//			break;
	//		case SHAPE_SIXSTAR:
	//			DrawTriangle( enemy_pos_x, DRAW_ENEMY_Y_POS + DRAW_SHAPE_SIZE, enemy_pos_x + DRAW_SHAPE_SIZE / 2,	DRAW_ENEMY_Y_POS, enemy_pos_x + DRAW_SHAPE_SIZE, DRAW_ENEMY_Y_POS + DRAW_SHAPE_SIZE, WHITE, false );
	//			DrawTriangle( enemy_pos_x, DRAW_ENEMY_Y_POS, enemy_pos_x + DRAW_SHAPE_SIZE / 2, DRAW_ENEMY_Y_POS + DRAW_SHAPE_SIZE, enemy_pos_x + DRAW_SHAPE_SIZE, DRAW_ENEMY_Y_POS, WHITE, false );
	//			break;
	//		case SHAPE_X:
	//			DrawLine( enemy_pos_x, DRAW_ENEMY_Y_POS, enemy_pos_x + DRAW_SHAPE_SIZE,	DRAW_ENEMY_Y_POS + DRAW_SHAPE_SIZE, WHITE );
	//			DrawLine( enemy_pos_x, DRAW_ENEMY_Y_POS + DRAW_SHAPE_SIZE, enemy_pos_x + DRAW_SHAPE_SIZE,	DRAW_ENEMY_Y_POS, WHITE );
	//			break;
	//		default:
	//			break;
	//		}
	//}
	//
	//WaitKey( );

	while( ProcessMessage( ) == 0 ) {
		ClearDrawScreen( );
		key->update( );
		
		if ( key->getKeyState( KEY_INPUT_ESCAPE ) == 1 ) {
			break;
		}

		game_f->update( key );

		WaitTimer( 60 );

		ScreenFlip( );
	}

	delete game_f;
	delete key;

	DxLib_End( );
	return 0;
}