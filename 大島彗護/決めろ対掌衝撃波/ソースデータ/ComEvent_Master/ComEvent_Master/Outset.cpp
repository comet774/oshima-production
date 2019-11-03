#include "Outset.h"
#include "DxLib.h"
#include "Const.h"

Outset::Outset( ) {
	initialize( );
}

Outset::~Outset( ) {
	finalize( );
}

void Outset::update( ) {
	PlayMovieToGraph( _graph_music.graph_start_movie );
	DrawExtendGraph( 0, 0, WIDTH, HEIGHT, _graph_music.graph_start_movie, TRUE );

}

void Outset::initialize( ) {
	_graph_music.ReadOutset( );
	_keyboard = new Keyboard( );

	next = false;
	init = true;
}

void Outset::finalize( ) {
	_graph_music.DeleteOutset( );
	delete _keyboard;

	_keyboard = nullptr;
	init = false;
}

bool Outset::check( ) {
	_keyboard->update( );
	if ( _keyboard->check( KEY_INPUT_SPACE ) == 1 || GetMovieStateToGraph( _graph_music.graph_start_movie ) == 0 ) { 
		PauseMovieToGraph( _graph_music.graph_start_movie );
		SeekMovieToGraph( _graph_music.graph_start_movie, 0 );
		next = true;
	}
	
	return next;
}

