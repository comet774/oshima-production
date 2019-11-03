#include "Game.h"
#include "DxLib.h"
#include "Const.h"

Game::Game( ) {
	initialize( );
}

Game::~Game( ) {
	finalize( );
}

void Game::update( const bool HARD_MODE ) {

	_timer->update( );
	now_time = _timer->getTimer( );
	_background->update( now_time );
	if ( _timer->getCutInTime( ) > 0 ) {
		_cut_in->update_belt( _timer->getCutInTime( ) );
	}
	_stamina->update( now_time );
	_turret->update( now_time, _stamina->getPlayer1Overheat( ), _stamina->getPlayer2Overheat( ) );
	
	if ( _timer->getGameState( ) ) {
		if( _turret->getTurret1Fire( ) ) {
			_stamina->Player1Fire( );
			_ball->Player1Fire( _turret->getPlayer1Angle( ) * 10 + 900 );

		}

		if( _turret->getTurret2Fire( ) ) {
			_stamina->Player2Fire( );
			_ball->Player2Fire( _turret->getPlayer2Angle( ) * 10 + 900 );
		}

		if ( now_time > GAME_TIME ) {
			_cut_in->update_girl( );
		}
	}
	draw( );
	_ball->update( now_time, _background->getConvert( ), HARD_MODE );
	drawFinish( );
}

void Game::initialize( ) {
	_graph_music.ReadGame( );
	_background = new Background( );
	_timer = new Timer( );
	_cut_in = new CutIn( );
	_turret = new Turret( );
	_stamina = new Stamina( );
	_ball = new Ball( );
	_angle = Angle( );
	now_time = 0;
	number_graph = 0;

	GetGraphSize( _graph_music.graph_stamina_num, &graph_size_x, &graph_size_y );

	init = true;
}

void Game::finalize( ) {
	_graph_music.DeleteGame( );
	delete _background;
	delete _timer;
	delete _cut_in;
	delete _turret;
	delete _stamina;
	delete _ball;

	_background = nullptr;
	_timer = nullptr;
	_turret = nullptr;
	_stamina = nullptr;
	_ball = nullptr;

	init = false;
}

void Game::draw( ) {
	if ( _cut_in->getGirlGraph( ) < 1 ) {
		DrawRotaGraph( ( int )CENTER_X + 100, ( int )CENTER_Y - 50, 1.0, _background->getAngle( ), _graph_music.graph_revolution, TRUE, FALSE );
		DrawGraph( 0, 0, _graph_music.graph_hand, TRUE );
		DrawGraph( ( int )CENTER_X - 75, ( int )CENTER_Y - 100, _graph_music.graph_hole, TRUE );
	}
	//Timerの描画処理

	drawTimer( );
	drawTurret( );
	
	
	//発射台の効果音処理
	if ( _turret->getTurretMove( ) ) {
		PlaySoundMem( _graph_music.sound_turret_move, DX_PLAYTYPE_BACK, TRUE );
	}

	if( _turret->getTurret1Fire( ) ) {
		PlaySoundMem( _graph_music.sound_turret_fire, DX_PLAYTYPE_BACK, TRUE );
	}
	if( _turret->getTurret2Fire( ) ) {
		PlaySoundMem( _graph_music.sound_turret_fire, DX_PLAYTYPE_BACK, TRUE );
	}

	if ( _ball->getHoleIn( ) ) {
		PlaySoundMem( _graph_music.sound_hole_in, DX_PLAYTYPE_BACK, TRUE );
	}

	if ( _ball->getMix( ) ) {
		PlaySoundMem( _graph_music.sound_mix, DX_PLAYTYPE_BACK, TRUE );
	}

}

void Game::drawTimer( ) {
		if ( _timer->getGameState( ) ) {	//ゲーム
		
		number_graph = ( GAME_TIME - now_time ) / 100 + 1;

		if( now_time <= GAME_TIME ){
			int number_graph_ten = number_graph / 10;
			int number_graph_one = number_graph % 10;

			if ( number_graph_ten > 0 ) {
				DrawGraph( WIDTH - 200, 50, _graph_music.graph_small_number[ number_graph_ten ], TRUE );
			}
			DrawGraph( WIDTH - 150, 50, _graph_music.graph_small_number[ number_graph_one ], TRUE );
		}
		if ( _timer->getCutInTime( ) > 0 ) {
			DrawExtendGraph( 0, ( int )CENTER_Y - _cut_in->getScalling( ), ( int )WIDTH, ( int )CENTER_Y + _cut_in->getScalling( ), _graph_music.graph_text_cut_in, TRUE );
			DrawRotaGraph( _cut_in->getBeltRight( ), ( int )CENTER_Y + 10 + _cut_in->getScalling( ), 1.0, 0, _graph_music.graph_border, TRUE, TRUE );
			DrawRotaGraph( _cut_in->getBeltLeft( ), ( int )CENTER_Y - 10 - _cut_in->getScalling( ), 1.0, DX_PI, _graph_music.graph_border, TRUE, TRUE );

		}

	} else {	//スタート
		if( now_time <= START_TIMER + START_TIMAR_GO ) {
			number_graph = ( START_TIMER - now_time ) / REAL_TIME;
			if ( START_TIMER - now_time >= 0 ) {
				DrawGraph( ( int )CENTER_X - 300, ( int )CENTER_Y - 300, _graph_music.graph_big_number[ number_graph ], TRUE );
			} else {
				DrawGraph( ( int )CENTER_X - 250, ( int )CENTER_Y - 75, _graph_music.graph_game_start, TRUE );
			}
		}
		if ( _timer->getTimer( ) == 1 ) {
			PlaySoundMem( _graph_music.sound_countdown, DX_PLAYTYPE_BACK, TRUE );
		}
	}
}

void Game::drawTurret( ) {
	//プレイヤー1のタレット処理
	DrawGraph( ( int ) PLAYER1_X - 292, ( int ) PLAYER1_Y + 56, _graph_music.graph_stamina_back, TRUE );
	DrawRectGraph( ( int ) PLAYER1_X - 292, ( int ) PLAYER1_Y + 56, 0, 0, _stamina->getPlayer1Gauge( ) * graph_size_x / 100, graph_size_y, _graph_music.graph_stamina_num, TRUE, FALSE );
	if( _stamina->getPlayer1Overheat( ) && _timer->getGameState( ) ) {
		if ( _stamina->getPlayer1Gauge( ) < 1  ) {
			PlaySoundMem( _graph_music.sound_player_down, DX_PLAYTYPE_BACK );
		}
		DrawGraph( ( int ) PLAYER1_X - 300, ( int ) PLAYER1_Y + 50, _graph_music.graph_player1_stamina_frame_down, TRUE );
		DrawRotaGraph2( ( int )PLAYER1_X, ( int )PLAYER1_Y, 100, 100, 1.0f, _angle.angle_num[ _turret->getPlayer1AngleDown( ) ], _graph_music.graph_player1_turret_down, TRUE );
	} else {
		DrawGraph( ( int ) PLAYER1_X - 300, ( int ) PLAYER1_Y + 50, _graph_music.graph_player1_stamina_frame, TRUE );	
		DrawRotaGraph2( ( int )PLAYER1_X, ( int )PLAYER1_Y, 100, 100, 1.0f, _angle.angle_num[ _turret->getPlayer1Angle( ) * 10 ], _graph_music.graph_player1_turret, TRUE );	
	}

	//プレイヤー2のタレット処理
	DrawGraph( ( int ) PLAYER2_X + 108, ( int ) PLAYER2_Y + 56, _graph_music.graph_stamina_back, TRUE );
	DrawRectGraph( ( int ) PLAYER2_X + 108, ( int ) PLAYER2_Y + 56, 0, 0, _stamina->getPlayer2Gauge( ) * graph_size_x / 100, graph_size_y, _graph_music.graph_stamina_num, TRUE, FALSE );
	if( _stamina->getPlayer2Overheat( ) && _timer->getGameState( ) ) {
		if ( _stamina->getPlayer2Gauge( ) < 1  ) {
			PlaySoundMem( _graph_music.sound_player_down, DX_PLAYTYPE_BACK );
		}
		DrawGraph( ( int ) PLAYER2_X + 100, ( int ) PLAYER2_Y + 50, _graph_music.graph_player2_stamina_frame_down, TRUE );
 		DrawRotaGraph2( ( int )PLAYER2_X, ( int )PLAYER2_Y, 100, 100, 1.0, _angle.angle_num[ _turret->getPlayer2AngleDown( ) ], _graph_music.graph_player2_turret_down, TRUE );
	} else {
		DrawGraph( ( int ) PLAYER2_X + 100, ( int ) PLAYER2_Y + 50, _graph_music.graph_player2_stamina_frame, TRUE );	
 		DrawRotaGraph2( ( int )PLAYER2_X, ( int )PLAYER2_Y, 100, 100, 1.0, _angle.angle_num[ _turret->getPlayer2Angle( ) * 10 ], _graph_music.graph_player2_turret, TRUE );
	}
	
	 
	DrawGraph( 10, 70, _graph_music.graph_combo, TRUE );
	DrawGraph( 80, 70, _graph_music.graph_product, TRUE );
	if ( _ball->getMagnification( ) / 10 > 0 ) {
		DrawGraph( 130, 70, _graph_music.graph_small_number[ _ball->getMagnification( ) / 10 ], TRUE );	
	} 
	DrawGraph( 180, 70, _graph_music.graph_small_number[ _ball->getMagnification( ) % 10 ], TRUE );	
}

void Game::drawFinish( ) {
	//ゲーム終了直後の処理
	if ( now_time > GAME_TIME && _timer->getGameState( ) ) {
		if( _cut_in->getGirlCount( ) == 1 && _cut_in->getGirlGraph( ) == 0 ) {
			PlaySoundMem( _graph_music.sound_beam, DX_PLAYTYPE_BACK );
		}

		for( int i = 0; i < _cut_in->getGirlGraph( ) + 1; i++ ) {
			if ( _cut_in->getGirlGraph( ) == i ) {
				DrawGraph( _cut_in->getGirlPos( ), 0, _graph_music.graph_china_girl[ i ], TRUE );
			} else {
				DrawGraph( 0, 0, _graph_music.graph_china_girl[ i ], TRUE );
			}
		}
	}
}

int Game::getScore( ) const {
	return _ball->getAllScore( );
}

bool Game::check( ) {
	if ( _cut_in->getGirlGraph( ) > 2 ) {
		return true;
	}
	return false;
}