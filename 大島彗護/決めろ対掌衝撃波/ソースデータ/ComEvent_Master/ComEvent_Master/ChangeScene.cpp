#include "ChangeScene.h"
#include "Const.h"

ChangeScene::ChangeScene( ) {
	initialize( );
}

ChangeScene::~ChangeScene( ) {
	finalize( );
}

void ChangeScene::update( ) {
	switch( scene_num ) {
		case TITLE:
			_title->update( );
			if ( _title->check( ) ) {
				hard_mode = _title->getHardMode( );	
				delete _title;
				
				_title = nullptr;
				_outset = new Outset( );
				scene_num = OUTSET;
				break;
			}

			if ( _title->getStaffRoll( ) ) {
				delete _title;

				_title = nullptr;
				_staff_roll = new StaffRoll( );
				scene_num = STAFF_ROLL;
				break;
			}

			if ( _title->getDiscription( ) ) {
				delete _title;
				
				_title = nullptr;
				_discription = new Discription( );
				scene_num = DISCRIPTION;
			}
			break;
		case OUTSET:
			_outset->update( );
			if ( _outset->check( ) ) {
				delete( _outset );

				_outset = nullptr;
				_game = new Game( );
				scene_num = GAME;
			}
			break;
		case GAME:
			_game->update( hard_mode );

			if( _game->check( ) ) {
				total_score += _game->getScore( );
				before_score = now_score;
				now_score = _game->getScore( );
				delete _game;

				_game = nullptr;
				_finish = new Finish( );
				scene_num = FINISH;
			}

			break;
		case FINISH:
			_finish->update( now_score );

			if( _finish->check( ) ) {
				delete _finish;

				_finish = nullptr;
				_result = new Result( );
				scene_num = RESULT;
			}
			break;
		case RESULT:
			_result->update( now_score );
			if ( _result->check( ) ) {
				if( _result->getSelect( ) ) {
					_outset = new Outset( );
					scene_num = OUTSET;
				} else {
					_title = new Title( );
					scene_num = TITLE;
				}
			}

			break;
		case STAFF_ROLL:
			_staff_roll->update( );
			if ( _staff_roll->check( ) ) {
				delete _staff_roll;

				_staff_roll = nullptr;
				_title = new Title( );
				scene_num = TITLE;
			}

			break;
		case DISCRIPTION:
			_discription->update( );
			if ( _discription->check( ) ) {
				delete _discription;

				_discription = nullptr;
				_title = new Title( );
				scene_num = TITLE;
			}

			break;
		default:
		break;
	}
}

void ChangeScene::initialize( ) {
	scene_num = TITLE;
	hard_mode = false;
	_title = new Title( );
	_outset = nullptr;
	_game = nullptr;
	_finish = nullptr;
	_result = nullptr;
	_staff_roll = nullptr;
	_discription = nullptr;
	now_score = 0;
	total_score = 0;
	before_score = 0;

	init = true;
}

void ChangeScene::finalize( ) {
	init = false;
}