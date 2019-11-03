#include "Title.h"
#include "DxLib.h"
#include "Const.h"

Title::Title( ) {
	initialize( );
}


Title::~Title( ) {
	finalize( );
}

void Title::update( ) {
	_keyboard->update( );
	DrawGraph( 0, 0, _graph_music.graph_title, TRUE );

	DrawGraph( -50,  right_pos + 50, _graph_music.graph_title_right, TRUE );
	DrawGraph( WIDTH - 450,  left_pos + 50, _graph_music.graph_title_left, TRUE );
	
	if (  right_pos > 100 ) {
		right_direction = 0;
	} else if ( right_pos < 0 ) {
		right_direction = 1;
	}

	if ( right_direction ) {
		 right_pos += TITLE_MOVE_SPEED;
	} else {
		 right_pos -= TITLE_MOVE_SPEED;
	}

	if (  left_pos > 100 ) {
		 left_direction = 0;
	}
	else if (  left_pos < 0 ) {
		 left_direction = 1;
	}

	if (  left_direction ) {
		 left_pos += TITLE_MOVE_SPEED;
	}
	else {
		 left_pos -= TITLE_MOVE_SPEED;
	}

	if ( _keyboard->check( KEY_INPUT_SPACE ) == 1 || _keyboard->check( KEY_INPUT_H ) == 1 || count > 0 ) {
		game = true;
		if ( count == 0 ) {
			PlaySoundMem( _graph_music.sound_game_start, DX_PLAYTYPE_BACK );
			ChangeVolumeSoundMem( 255 * 60 / 100, _graph_music.sound_title );
			hard_mode = false;
		}

		count++;
		
		if ( _keyboard->check( KEY_INPUT_H ) == 1 ) {
			hard_mode = true;
		}

		if ( count % 40 > 0 && count % 40 < 21 ) {
			DrawGraph( ( int )CENTER_X - 250, ( int )CENTER_Y, _graph_music.graph_title_start, TRUE );
			DrawGraph( ( int )CENTER_X - 75,  ( int )CENTER_Y + 130, _graph_music.graph_title_key, TRUE );
		}

		if ( count > REAL_TIME * 4 ) {
			next = true;
			count = 0;
		}
	} else {
		if ( CheckSoundMem( _graph_music.sound_title ) == 0 ) {
			PlaySoundMem( _graph_music.sound_title, DX_PLAYTYPE_LOOP );
		}
		DrawGraph( ( int )CENTER_X - 250, ( int )CENTER_Y, _graph_music.graph_title_start, TRUE );
		DrawGraph( ( int )CENTER_X - 75,  ( int )CENTER_Y + 130, _graph_music.graph_title_key, TRUE );
	}

	if ( _keyboard->check( KEY_INPUT_RIGHT ) == 1 && game == false ) {
		option = true;
	}
	if ( _keyboard->check( KEY_INPUT_LEFT ) == 1 && game == false ) {
		option = false;
	}



	if ( option ) {
		DrawGraph( 50, HEIGHT - 200, _graph_music.graph_text_teach_file, TRUE );
		DrawGraph( WIDTH - 500, HEIGHT - 300, _graph_music.graph_text_staff, TRUE );
		
	} else {
		DrawGraph( 50, HEIGHT - 300, _graph_music.graph_text_teach_file, TRUE );
		DrawGraph( WIDTH - 500, HEIGHT - 200, _graph_music.graph_text_staff, TRUE );
	
	}

	if ( _keyboard->check( KEY_INPUT_RETURN ) == 1 && game == false ) {
		if ( option ) {
			staff_roll = true;
		} else {
			discription = true;
		}
	}
}

void Title::initialize( ) {
	_graph_music.ReadTitle( );
	_keyboard = new Keyboard( );
	
	right_pos = GetRand( 100 );
	left_pos = GetRand( 100 );
	right_direction = GetRand( 1 );
	left_direction = GetRand( 1 );
	hard_mode = false;	
	next = false;
	staff_roll = false;
	discription = false;
	option = false;
	game = false;

	init = true;
}

void Title::finalize( ) {
	_graph_music.DeleteTitle( );
	delete _keyboard;
	_keyboard = nullptr;

	right_pos = 0;
	left_pos = 0;
	right_direction = 0;
	left_direction = 0;
	count = 0;
	hard_mode = false;	
	next = false;
	staff_roll = false;
	discription = false;
	next = false;
	option = false;
	game = false;

	init = false;
}

bool Title::check( ) {
	if ( next ) {
		StopSoundMem( _graph_music.sound_title );
		ChangeVolumeSoundMem( 255, _graph_music.sound_title );
	}
	return next;
}

bool Title::getHardMode( ) const {
	return hard_mode;
}

bool Title::getStaffRoll( ) const {
	return staff_roll;
}

bool Title::getDiscription( ) const {
	return discription;
}