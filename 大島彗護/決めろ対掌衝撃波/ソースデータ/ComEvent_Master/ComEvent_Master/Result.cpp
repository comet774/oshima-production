#include "Result.h"
#include "Const.h"
#include "DxLib.h"

Result::Result( ) {
	initialize( );
}

Result::~Result( ) {
	finalize( );
}

void Result::initialize( ) {
	_graph_music.ReadResult( );
	_keyboard = Keyboard( );
	select = 0;
	now_score = 0;
	score_num = 1;
	once = true;

	init =true;
}

void Result::finalize( ) {
	_graph_music.DeleteResult( );

	init = false;
}

void Result::update( const int score ) {
	_keyboard.update( );
	score_num = 1;
	now_score = score;
	
	DrawGraph( 0, 0, _graph_music.graph_result_back, TRUE );
	DrawGraph( ( int )CENTER_X - 402, -6, _graph_music.graph_lean, TRUE );

	if ( once ) {
		PlaySoundMem( _graph_music.sound_result_show, DX_PLAYTYPE_BACK );
		once = false;
	}

	DrawGraph( 10, 100, _graph_music.graph_text_score, TRUE );
	while ( now_score > 0 ) {

		DrawGraph(  ( int )WIDTH - 10 - 50 * score_num , 130, _graph_music.graph_small_number[ now_score % 10 ], TRUE );
		now_score /= 10;
		score_num++;
	}

	if ( _keyboard.check( KEY_INPUT_RIGHT ) == 1 ) {
		select = false;
	}
	if ( _keyboard.check( KEY_INPUT_LEFT ) == 1 ) {
		select = true;
	}

	DrawGraph( 50, 700, _graph_music.graph_text_more, TRUE );

	if ( select ) {
		DrawGraph( 50, 850, _graph_music.graph_text_yes, TRUE );
		DrawGraph( 400, 900, _graph_music.graph_text_no, TRUE );
	} else {
		DrawGraph( 50, 900, _graph_music.graph_text_yes, TRUE );
		DrawGraph( 400, 850, _graph_music.graph_text_no, TRUE );
	}
}

bool Result::check( ) {
	if ( _keyboard.check( KEY_INPUT_RETURN ) == 1 ) {
		StopSoundMem( _graph_music.sound_result_show );
		return true;
	}
	return false;
}

bool Result::getSelect( ) const {
	return select;
}