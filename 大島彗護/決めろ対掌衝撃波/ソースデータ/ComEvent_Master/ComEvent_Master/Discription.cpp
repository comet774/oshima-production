#include "Discription.h"
#include "DxLib.h"

Discription::Discription( ) {
	initialize( );
}


Discription::~Discription( ) {
	finalize( );
}

void Discription::update( ) {
	DrawGraph( 0, 0, _graph_music.graph_teach_file, TRUE );	
}

bool Discription::check( ) {
	_keyboard->update( );
	if ( _keyboard->check( KEY_INPUT_BACK ) == 1 ) {
		return true;
	}
	return false;
}

void Discription::initialize( ) {
	_keyboard = new Keyboard( );
	_graph_music.ReadDiscription( );
}

void Discription::finalize( ) {
	delete _keyboard;
	_graph_music.DeleteDiscription( );
}