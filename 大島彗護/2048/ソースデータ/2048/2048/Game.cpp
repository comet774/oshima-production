#include "Game.h"
#include "DxLib.h"

const int SURFACE = 4;

Game::Game( ) :
ismove( true ),
skip( false ),
finish( false ),
num_col( true ),
num_row( true ),
score( 0 ),
rand_col( 0 ),
rand_row( 0 ),
rand_num( 0 ),
first( 2 ),
keyboard( new Keyboard( ) ) {
	for ( int i = 0; i < SURFACE; i++ ) {
		for ( int j = 0; j < SURFACE; j++ ) {
			blocks[ i ][ j ] = 0;
		}	
	}
}

Game::~Game( ) {
	delete keyboard;
}

void Game::update( ) {
	Init( );

	if ( ismove || first > 0 ) {
		finish = true;
		first--;
		while ( num_col ) {
			rand_col = GetRand( SURFACE - 1 );
			for ( int i = 0; i < SURFACE; i++ ) {
				if ( num_col == false ) {
					continue;
				}

				if ( blocks[ rand_col ][ i ] == 0 ) {
					num_col = false;
				}
			}
		}

		while ( num_row ) {
			rand_row = GetRand( SURFACE - 1 );
			if ( blocks[ rand_col ][ rand_row ] == 0 ) {
				num_row = false;
			}
		}

		rand_num = GetRand( 100 - 1 );

		if( rand_num > 20 ) {
			blocks[ rand_col ][ rand_row ] = 2;
		} else {
			blocks[ rand_col ][ rand_row ] = 4;
		}

		for ( int i = 0; i < SURFACE; i++ ){
			for ( int j = 0; j < SURFACE; j++ ) {
				if ( finish == false ) {
					continue;
				}

				if ( ( blocks[ i ][ j ] == blocks[ i + 1 ][ j ] && i != SURFACE - 1 ) ||
					 ( blocks[ i ][ j ] == blocks[ i ][ j + 1 ] && j != SURFACE - 1 ) || blocks[ i ][ j ] == 0 ) {
					finish = false;
					ismove = false;
					break;
				}
			}
		}
	}

	if ( finish ) {
		ismove = false;
		Retry( );
		return;
	}

	if ( first > 0 ) {
		return;
	}

	Action( );
}

int Game::getScore( ) {
	return score;
}

bool Game::getFinish( ) {
	return finish;
}

int Game::getBlock( int col, int row ) {
	return blocks[ col ][ row ];
}

void Game::Init( ) {
	num_col = true;
	num_row = true;
	rand_col = 0;
	rand_row = 0;
	keyboard->update( );
}

//ƒ{ƒ^ƒ“‘€ì
void Game::Action( ) {
	if ( keyboard->getKeyState( KEY_INPUT_UP ) == 1 ) {
		for ( int i = 0; i < SURFACE; i++ ) {
			for ( int j = 0; j < SURFACE - 1; j++ ) {
				for ( int k = j + 1; k < SURFACE; k++ ){
					if ( skip || blocks[ i ][ j ] == 0 ) {
						continue;
					}

					if ( blocks[ i ][ j ] == blocks[ i ][ k ] ) {
						score += blocks[ i ][ j ];
						blocks[ i ][ j ] <<= 1;
						blocks[ i ][ k ] = 0;
						ismove = true;
						skip = true;
					}

					if ( blocks[ i ][ k ] > 0 && blocks[ i ][ j ] != blocks[ i ][ k ] ) {
						skip = true;
					}
				}
				skip = false;
			}

			for ( int j = 0; j < SURFACE; j++ ) {
				if ( blocks[ i ][ j ] == 0 || j == 0 ) {
					continue;
				}

				for ( int k = 0; k < j; k++ ) {
					if ( blocks[ i ][ k ] == 0 ) {
						blocks[ i ][ k ] = blocks[ i ][ j ];
						blocks[ i ][ j ] = 0;
						ismove = true;
					}
				}
			}
		}
		return;
	}

	if ( keyboard->getKeyState( KEY_INPUT_DOWN ) == 1 ) {
		for ( int i = 0; i < SURFACE; i++ ) {
			for ( int j = 0; j < SURFACE - 1; j++ ) {
				for ( int k = j + 1; k < SURFACE; k++ ){
					if ( skip || blocks[ i ][ ( SURFACE - 1 ) - j ] == 0 ) {
						continue;
					}

					if ( blocks[ i ][ ( SURFACE - 1 ) - j ] == blocks[ i ][ ( SURFACE - 1 ) - k ] ) {
						score += blocks[ i ][ ( SURFACE - 1 ) - j ];
						blocks[ i ][ ( SURFACE - 1 ) - j ] <<= 1;
						blocks[ i ][ ( SURFACE - 1 ) - k ] = 0;
						ismove = true;
						skip = true;
					}

					if ( blocks[ i ][ ( SURFACE - 1 ) - k ] > 0 && blocks[ i ][ ( SURFACE - 1 ) - j ] != blocks[ i ][ ( SURFACE - 1 ) - k ] ) {
						skip = true;
					}
				}
				skip = false;
			}

			for ( int j = 0; j < SURFACE; j++ ) {
				if ( blocks[ i ][ ( SURFACE - 1 ) - j ] == 0 || j == 0 ) {
					continue;
				}

				for ( int k = 0; k < j; k++ ) {
					if ( blocks[ i ][ ( SURFACE - 1 ) - k ] == 0 ) {
						blocks[ i ][ ( SURFACE - 1 ) - k ] = blocks[ i ][ ( SURFACE - 1 ) - j ];
						blocks[ i ][ ( SURFACE - 1 ) - j ] = 0;
						ismove = true;
					}
				}
			}
		}
		
		return;
	}

	if ( keyboard->getKeyState( KEY_INPUT_LEFT ) == 1 ) {
		for ( int i = 0; i < SURFACE; i++ ) {
			for ( int j = 0; j < SURFACE - 1; j++ ) {
				for ( int k = j + 1; k < SURFACE; k++ ){
					if ( skip || blocks[ j ][ i ] == 0 ) {
						continue;
					}

					if ( blocks[ j ][ i ] == blocks[ k ][ i ] ) {
						score += blocks[ j ][ i ];
						blocks[ j ][ i ] <<= 1;
						blocks[ k ][ i ] = 0;
						ismove = true;
						skip = true;
					}

					if ( blocks[ k ][ i ] > 0 && blocks[ j ][ i ] != blocks[ k ][ i ] ) {
						skip = true;
					}
				}
				skip = false;
			}

			for ( int j = 0; j < SURFACE; j++ ) {
				if ( blocks[ j ][ i ] == 0 || j == 0 ) {
					continue;
				}

				for ( int k = 0; k < j; k++ ) {
					if ( blocks[ k ][ i ] == 0 ) {
						blocks[ k ][ i ] = blocks[ j ][ i ];
						blocks[ j ][ i ] = 0;
						ismove = true;
					}
				}
			}
		}
		return;
	}

	if ( keyboard->getKeyState( KEY_INPUT_RIGHT ) == 1 ) {
		for ( int i = 0; i < SURFACE; i++ ) {
			for ( int j = 0; j < SURFACE - 1; j++ ) {
				for ( int k = j + 1; k < SURFACE; k++ ){
					if ( skip || blocks[ ( SURFACE - 1 ) - j ][ i ] == 0 ) {
						continue;
					}

					if ( blocks[ ( SURFACE - 1 ) - j ][ i ] == blocks[ ( SURFACE - 1 ) - k ][ i ] ) {
						score += blocks[ ( SURFACE - 1 ) - j ][ i ];
						blocks[ ( SURFACE - 1 ) - j ][ i ] <<= 1;
						blocks[ ( SURFACE - 1 ) - k ][ i ] = 0;
						ismove = true;
						skip = true;
					}

					if ( blocks[ ( SURFACE - 1 ) - k ][ i ] > 0 && blocks[ ( SURFACE - 1 ) - j ][ i ] != blocks[ ( SURFACE - 1 ) - k ][ i ] ) {
						skip = true;
					}
				}
				skip = false;
			}

			for ( int j = 0; j < SURFACE; j++ ) {
				if ( blocks[ ( SURFACE - 1 ) - j ][ i ] == 0 || j == 0 ) {
					continue;
				}

				for ( int k = 0; k < j; k++ ) {
					if ( blocks[ ( SURFACE - 1 ) - k ][ i ] == 0 ) {
						blocks[ ( SURFACE - 1 ) - k ][ i ] = blocks[ ( SURFACE - 1 ) - j ][ i ];
						blocks[ ( SURFACE - 1 ) - j ][ i ] = 0;
						ismove = true;
					}
				}
			}
		}
		return;
	}
}

void Game::GameInit( ) {
	ismove = true;
	skip = false;
	num_col = true;
	num_row = true;
	score = 0;
	rand_col = 0;
	rand_row = 0;
	rand_num = 0;
	first = 2; 

	for ( int i = 0; i < SURFACE; i++ ) {
		for ( int j = 0; j < SURFACE; j++ ) {
			blocks[ i ][ j ] = 0;
		}	
	}
}

void Game::Retry( ) {
	if ( keyboard->getKeyState( KEY_INPUT_RETURN ) ) {
		GameInit( );
	}
}