#include "StaffRoll.h"
#include "DxLib.h"

StaffRoll::StaffRoll( ) {
	initialize( );

}

StaffRoll::~StaffRoll( ) {
	finalize( );
}

void StaffRoll::update( ) {
	DrawGraph( 0, 0, _graph_music.graph_staff_roll, TRUE );
}

bool StaffRoll::check( ) {
	_keyboard->update( );
	if ( _keyboard->check( KEY_INPUT_BACK ) == 1 ) {
		return true;
	}
	return false;
}

void StaffRoll::initialize( ) {
	_keyboard = new Keyboard( );
	_graph_music.ReadStaffRoll( );
}

void StaffRoll::finalize( ) {
	delete _keyboard;
	_graph_music.DeleteStaffRoll( );
}
