#include "GameFlow.h"
#include "constfail.h"

GameFlow::GameFlow( ):
flow( GAMEFLOW_TITLE ) {
	title = new Title( );
}

GameFlow::~GameFlow( ) {
}

void GameFlow::update( Keyboard *key ) {
	switch( flow ) {
		case GAMEFLOW_TITLE:
			title->update( );
			if ( key->getKeyState( KEY_INPUT_RETURN ) == 1 ) {
				flow = GAMEFLOW_BATTLE;
				delete title;
				battle = new Battle( );
			}
			break;
		case GAMEFLOW_CHARACTORCHOICE:
			break;
		case GAMEFLOW_DUNGEONCHOICE:
			break;
		case GAMEFLOW_BATTLE:
			battle->update( key );
			flow = battle->nextScene( );
			if ( flow != GAMEFLOW_BATTLE ) {
				delete battle;
				if ( flow == GAMEFLOW_GAMEOVER ) {
					gameover = new GameOver( );
				}

				if ( flow == GAMEFLOW_GAMECLEAR ) {
					gameclear = new GameClear( );
				}
			}
			break;
		case GAMEFLOW_GAMECLEAR:
			gameclear->update( );
			if ( key->getKeyState( KEY_INPUT_RETURN ) == 1 ) {
				flow = GAMEFLOW_TITLE;
				delete gameclear;
				title = new Title( );
			}			
			break;
		case GAMEFLOW_GAMEOVER:
			gameover->update( );
			if ( key->getKeyState( KEY_INPUT_RETURN ) == 1 ) {
				flow = GAMEFLOW_TITLE;
				delete gameover;
				title = new Title( );
			}
			break;
		default:
			break;
	}
}
