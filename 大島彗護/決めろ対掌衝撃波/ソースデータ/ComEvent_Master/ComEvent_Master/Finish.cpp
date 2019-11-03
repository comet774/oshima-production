#include "Finish.h"
#include "Const.h"
#include "DxLib.h"

Finish::Finish( ) {
	 initialize( );
}

Finish::~Finish( ) {
	finalize( );
}

void Finish::initialize( ) {
	_graph_music.ReadFinish( );
	_keyboard = Keyboard( );
	start_count = 0;
	result_count = 0;
	enemy_num = 0;
	back_y = 0;
	stop_y = 0;
	last_flag = 0;
	last_five = false;

	init = true;
}

void Finish::finalize( ) {
	_graph_music.DeleteFinish( );

	enemy.clear( );
	enemy_flag.clear( );
	enemy_control.clear( );
	enemy_distance.clear( );
	enemy_mag.clear( );
	efects_flag.clear( );
	rotate_flag.clear( );
	enemy_count.clear( );
	enemy_pos_y.clear( );

	std::vector< int >( ).swap( enemy );
	std::vector< int >( ).swap( enemy_flag );
	std::vector< int >( ).swap( enemy_control );
	std::vector< int >( ).swap( enemy_distance );
	std::vector< double >( ).swap( enemy_mag );
	std::vector< int >( ).swap( efects_flag );
	std::vector< bool >( ).swap( rotate_flag );
	std::vector< int >( ).swap( enemy_count );
	std::vector< int >( ).swap( enemy_pos_y );

	last_five = false;
	init = false;
}

void Finish::update( const int score ) {
	_keyboard.update( );
	if ( start_count == 0 ) {
		enemyPop( score );
	}

	DrawGraph( 0, 0 - ( back_y % HEIGHT ), _graph_music.graph_scroll_back[ ( back_y / HEIGHT ) % 2 ], TRUE );
	DrawGraph( 0, ( int )HEIGHT - ( back_y % HEIGHT ), _graph_music.graph_scroll_back[ ( ( back_y / HEIGHT ) + 1 ) % 2 ], TRUE );
	result_count++;

	//ビームの初動
	if ( start_count < 30 ) {
		DrawRotaGraph( ( int )CENTER_X, 50, 1, DX_PI,  _graph_music.graph_beam_start[ start_count / 10 ], TRUE );
		start_count++;

	}



	//ビーム処理
	if ( start_count >= 30 ) {
		DrawRotaGraph( ( int )CENTER_X, 50, 1, DX_PI, _graph_music.graph_beam[ result_count % 20 ], TRUE );	
		for ( int i = 0; i < enemy_num; i++ ) {
			DrawGraph( WIDTH - 512, 0, _graph_music.graph_enemy_hit[ efects_flag[ i ] ], TRUE );
			DrawRotaGraph( 256, 256, 1, 0, _graph_music.graph_enemy_hit[ efects_flag[ i ] ], TRUE, TRUE );
			if ( efects_flag[ i ] < 25 ) {
				DrawGraph( 240, 100, _graph_music.graph_beam_hit[ result_count % 3 ], TRUE );	
			}
		}

		for ( int i = 0; i < enemy_num; i++ ) { 
			const int ENEMY_Y = HEIGHT + i * ENEMY_SPECE - back_y;

			if ( enemy_distance[ i ] < 610 ) {
				if ( ENEMY_Y <= CENTER_Y ) {
					if( efects_flag[ i ] == 100 ) {
						efects_flag[ i ] = 0;
					}

					if ( efects_flag[ i ] < 25 ) {
						//エフェクト
						efects_flag[ i ]++;
					}
					//敵ふっとばし処理
					double pos_x = ( CENTER_X + angle.cos_num[ enemy_control[ i ] * 10 ] * enemy_distance[ i ] * 10 );
					double pos_y = ( CENTER_Y + angle.sin_num[ enemy_control[ i ] * 10 ] * enemy_distance[ i ] * 10 );
					

					if ( enemy_flag[ i ] ) {
						if ( enemy_mag[ i ] < 2 ) {
							enemy_pos_y[ i ] = ( int )pos_y;
							DrawRotaGraph( ( int ) ( pos_x ), enemy_pos_y[ i ], enemy_mag[ i ], angle.angle_num[ enemy_distance[ i ] * 75 ], _graph_music.graph_enemy_down[ enemy[ i ] ], TRUE );
							enemy_mag[ i ] += EXPAND_NUM;
						} else if ( enemy_mag[ i ] >= 2 ) {

							if ( enemy_count[ i ] < ENEMY_BLOWS_TIME ){
								rotate_flag[ i ] = FALSE;
							} else if ( enemy_count[ i ] < STOP_FIRST ) {
								enemy_pos_y[ i ] += ( int ) ( ( enemy_count[ i ] - ENEMY_BLOWS_TIME ) * 0.25 );
							} else if ( enemy_count[ i ] < STOP_SECOND ) {
							} else if ( enemy_count[ i ] >= STOP_SECOND ) {
								enemy_pos_y[ i ] += ( int ) ( enemy_count[ i ] - STOP_SECOND );
								if ( i == last_flag && enemy_pos_y[ i ] > HEIGHT + 300 ) {
									last_five = true;
								}
							}

							DrawRotaGraph( ( int ) ( pos_x ), enemy_pos_y[ i ], enemy_mag[ i ], angle.angle_num[ enemy_distance[ i ] * 50 ], _graph_music.graph_enemy_down[ enemy[ i ] ], TRUE );

							enemy_count[ i ]++;
						}
					} else {
						if ( ( pos_x )  > 0 - 300 && ( pos_x ) < WIDTH ) { 
							enemy_pos_y[ i ] = ( int )pos_y;
							DrawRotaGraph( ( int ) ( pos_x ), enemy_pos_y[ i ], enemy_mag[ i ], angle.angle_num[ enemy_distance[ i ] * 50 ], _graph_music.graph_enemy_down[ enemy[ i ] ], TRUE );
						}
					}
					if ( rotate_flag[ i ] ) {
						enemy_distance[ i ]++;
					}

				} else {
					DrawGraph( ENEMY_X, ENEMY_Y, _graph_music.graph_enemy[ enemy[ i ] ], TRUE );
				}

			}
		}

		DrawGraph( 0, 0, _graph_music.graph_beam_efect[ result_count % 4 ], TRUE );
		PlaySoundMem( _graph_music.sound_beam_hit, DX_PLAYTYPE_LOOP, FALSE );
		
		back_y += BACK_SCROLL;
	}

	if ( back_y < 100 ) {
		DrawGraph( ( int ) CENTER_X - 50, 0 - back_y, _graph_music.graph_girl, TRUE );
	}
}

void Finish::enemyPop( const int score ) {
	enemy_num = score / ONE_ENEMY_SCORE;
	last_flag = SPECIAL_ENEMY * ( enemy_num / SPECIAL_ENEMY ) - 1;
	if ( last_flag <= 0 ) {
		last_five = true;
	}


	for ( int i = 0; i < enemy_num; i++ ) {
		enemy.push_back( GetRand( ENEMY_TYPE_NUMBER -1 ) );
		enemy_control.push_back( GetRand( 1 ) );
		enemy_distance.push_back( 0 );
		enemy_mag.push_back( 1 );
		efects_flag.push_back( 100 );
		rotate_flag.push_back( TRUE );
		enemy_count.push_back( 0 );
		enemy_pos_y.push_back( 0 );

		if ( ( i + 1 ) % SPECIAL_ENEMY == 0 ) {
			enemy_flag.push_back( 1 );
			if ( enemy_control[ i ] ) {
				enemy_control[ i ] = 30;
			} else {
				enemy_control[ i ] = 150;
			}
		} else {
			enemy_flag.push_back( 0 );
			if ( enemy_control[ i ] ) {
				enemy_control[ i ] = 45;
			} else {
				enemy_control[ i ] = 135;
			}
		}
	}

}

bool Finish::check( ) {
	if ( enemy_num == 0 || ( last_five && enemy_pos_y.back( ) > HEIGHT + 10 ) ) {
		return true;
	}

	return false;
}
