#include "Ball.h"
#include "DxLib.h"
#include "Const.h"

Ball::Ball( ) {
	initialize( );
}

Ball::~Ball( ) {
	finalize( );
}

void Ball::initialize( ) {
	_angle = new Angle( );
	_graph_music.ReadGame( );
	
	player1.ball_pos_x.reserve( 10000 );
	player1.ball_pos_y.reserve( 10000 );
	player1.ball_cut_in.reserve( 10000 );
	player1.ball_angle.reserve( 10000 );
	player1.ball_start_angle.reserve( 10000 );
	player1.ball_radius.reserve( 10000 );
	player1.ball_acc.reserve( 10000 );
	player1.ball_speed.reserve( 10000 );
	player1.score.reserve( 10000 );
	player1.score_count.reserve( 10000 );
	player1.ball_efects.reserve( 10000 );
	player1.color_num = GetColor( 255, 255, 159 ); 

	player2.ball_pos_x.reserve( 10000 );
	player2.ball_pos_y.reserve( 10000 );
	player2.ball_cut_in.reserve( 10000 );
	player2.ball_angle.reserve( 10000 );
	player2.ball_start_angle.reserve( 10000 );
	player2.ball_radius.reserve( 10000 );
	player2.ball_acc.reserve( 10000 );
	player2.ball_speed.reserve( 10000 );
	player2.score.reserve( 10000 );
	player2.score_count.reserve( 10000 );
	player2.ball_efects.reserve( 10000 );
	player2.color_num = GetColor( 159, 230, 255 ); 

	ball_mix.ball_pos_x.reserve( 10000 );
	ball_mix.ball_pos_y.reserve( 10000 );
	ball_mix.ball_cut_in.reserve( 10000 );
	ball_mix.ball_angle.reserve( 10000 );
	ball_mix.ball_start_angle.reserve( 10000 );
	ball_mix.ball_radius.reserve( 10000 );
	ball_mix.score.reserve( 10000 );
	ball_mix.score_count.reserve( 10000 );
	ball_mix.ball_efects.reserve( 10000 );

	hole_in = false;
	mix = false;
	all_score = 0;
	magnification = 0;
	distance = 0;

	init = true;
}

void Ball::finalize( ) {
	delete _angle;
	_graph_music.DeleteGame( );

	_angle = nullptr;
	init = false;
}

void Ball::update( const int GAME_COUNT, const int SHIFT, const bool HARD_MODE ) {
	if( hole_in ) {
		hole_in = false;
	}
	if ( mix ) {
		mix = false;
	}


	//合成弾生成
	for ( int i = player1.ball_min; i < player1.ball_max; i++ ) {
		for ( int k = player2.ball_min; k < player2.ball_max; k++ ) {
			distance = ( int )sqrt( pow( player1.ball_pos_x[ i ] - player2.ball_pos_x[ k ], 2 ) + pow( player1.ball_pos_y[ i ] - player2.ball_pos_y[ k ], 2 ) );

			if( player1.ball_pos_x[ i ] > 0 && player1.ball_pos_y[ i ] > 0 && player2.ball_pos_x[ k ] > 0 && player2.ball_pos_y[ k ] > 0 &&
				distance < BALL_DETERMINE && player1.ball_radius[ i ] > HOLE_AREA && player2.ball_radius[ k ] > HOLE_AREA &&
				player1.score[ i ] > 0 && player2.score[ k ] > 0 ) {

				ball_mix.ball_pos_x.push_back( ( player1.ball_pos_x[ i ] + player2.ball_pos_x[ k ] ) / 2 );
				ball_mix.ball_pos_y.push_back( ( player1.ball_pos_y[ i ] + player2.ball_pos_y[ k ] ) / 2 );
				ball_mix.ball_cut_in.reserve( 0 );
				ball_mix.ball_radius.push_back( player2.ball_radius[ k ] );
				ball_mix.ball_angle.push_back( ( player2.ball_angle[ k ] + ANGLE_RESERVE ) * 10 );
				if ( HARD_MODE ) {
					ball_mix.score.push_back( SCORE_MIX_HARD );
				} else {
					ball_mix.score.push_back( SCORE_MIX );
				}
				ball_mix.score_count.push_back( SCORE_DRAW_TIME );
				ball_mix.ball_efects.push_back( 4 * 40 );
				ball_mix.ball_max++;
				
				player1.ball_pos_x[ i ] = 0;
				player1.ball_pos_y[ i ] = 0;
				player1.ball_acc[ i ] = 0; 
				player1.score[ i ] = 0;

				player2.ball_pos_x[ k ] = 0;
				player2.ball_pos_y[ k ] = 0;
				player2.ball_acc[ k ] = 0;
				player2.score[ k ] = 0;

				mix = true;
			}
		}
	}




	//プレイヤー1の玉機動
	for ( int i = player1.ball_min; i < player1.ball_max ; i++ ) {
		if ( player1.ball_acc[ i ]  > 1 ) {
			player1.ball_pos_x[ i ] = _angle->cos_num[ player1.ball_start_angle[ i ] ] * player1.ball_speed[ i ] + PLAYER1_X - 75;
			player1.ball_pos_y[ i ] = _angle->sin_num[ player1.ball_start_angle[ i ] ] * player1.ball_speed[ i ] + PLAYER1_Y - 75;
			player1.ball_speed[ i ] += player1.ball_acc[ i ];
			player1.ball_acc[ i ] *= 0.5;
			if ( player1.ball_acc[ i ] < 1 ) {
				player1.ball_angle[ i ] = ( _angle->atan_angle1( ( int )CENTER_X, ( int )CENTER_Y, player1.ball_pos_x[ i ], player1.ball_pos_y[ i ] ) + ANGLE_RESERVE ) * 10;
				player1.ball_radius[ i ]= sqrt( pow( player1.ball_pos_x[ i ] - CENTER_X, 2 ) + pow( player1.ball_pos_y[ i ] - CENTER_Y, 2 ) );
			}
		} else {
			if ( player1.ball_radius[ i ] < 0  ) {
				if ( player1.score[ i ] == 0 ) {
					player1.ball_min += 1;
				}

			} else if( player1.ball_pos_x[ i ] > 0 || player1.ball_pos_y[ i ] > 0 ) {
				int player1_angle = player1.ball_angle[ i ] % 3600;
				player1.ball_pos_x[ i ] = _angle->cos_num[ player1_angle ] * player1.ball_radius[ i ] + CENTER_X - 50;
				player1.ball_pos_y[ i ] = _angle->sin_num[ player1_angle ] * player1.ball_radius[ i ] + CENTER_Y - 50;

			}
			if( GAME_COUNT < GAME_TIMER_HALF ){
				player1.ball_angle[ i ] += SHIFT * 3;
			} else if( GAME_COUNT > GAME_TIMER_HALF ){
				player1.ball_angle[ i ] -= SHIFT * 3; 
			}
			player1.ball_radius[ i ] -= SHIFT / 4;
		}

		if( player1.ball_pos_x[ i ] > 0 || player1.ball_pos_y[ i ] > 0 ) {
			DrawGraph( ( int )player1.ball_pos_x[ i ], ( int )player1.ball_pos_y[ i ], _graph_music.graph_player1_ball[ player1.ball_efects[ i ] % 3 ], TRUE );	
		}

		if ( player1.score[ i ] > 0 && player1.ball_radius[ i ] < 0 ) {
			if ( player1.score_count[ i ] == SCORE_DRAW_TIME && player1.score[ i ] != 0 ) {
				all_score += player1.score[ i ];
				hole_in = true;
				if ( HARD_MODE ) {
					magnification = 0;
				}
			}
			while ( player1.score[ i ] > 0 ) {
				DrawGraph(  ( int )CENTER_X + 150 - player1.pos_num * 50, ( int )CENTER_Y - 200, _graph_music.graph_small_number[ player1.score[ i ] % 10 ], TRUE );
				player1.score[ i ] /= 10;
				player1.pos_num++;
			}
			player1.pos_num = 0;
			player1.score_count[ i ]--;
			if ( player1.score_count[ i ] == 0 ) {
				player1.ball_min += 1;			
			}
		}
		player1.ball_efects[ i ]++;
	}

	//プレイヤー2の玉機動
	for ( int i = player2.ball_min; i < player2.ball_max ; i++ ) {
		if ( player2.ball_acc[ i ]  > 1 ) {
			player2.ball_pos_x[ i ] = _angle->cos_num[ player2.ball_start_angle[ i ] ] * player2.ball_speed[ i ] + PLAYER2_X - 75;
			player2.ball_pos_y[ i ] = _angle->sin_num[ player2.ball_start_angle[ i ] ] * player2.ball_speed[ i ] + PLAYER2_Y - 75;
			player2.ball_speed[ i ] += player2.ball_acc[ i ];
			player2.ball_acc[ i ] *= 0.5;
			if ( player2.ball_acc[ i ] < 1 ) {
				player2.ball_angle[ i ] = ( 180 - _angle->atan_angle2( ( int )CENTER_X, ( int )CENTER_Y, player2.ball_pos_x[ i ], player2.ball_pos_y[ i ] ) + ANGLE_RESERVE ) * 10;
				player2.ball_radius[ i ]= sqrt( pow(  CENTER_X - player2.ball_pos_x[ i ], 2 ) + pow( CENTER_Y - player2.ball_pos_y[ i ], 2 ) );
			}
		} else {
			if ( player2.ball_radius[ i ] < 0  ) {
				if ( player2.score[ i ] == 0 ) {
					player2.ball_min += 1;
				}
			} else if( player2.ball_pos_x[ i ] > 0 || player2.ball_pos_y[ i ] > 0 ) {
				int player2_angle = player2.ball_angle[ i ] % 3600;
				player2.ball_pos_x[ i ] = _angle->cos_num[ player2_angle ] * player2.ball_radius[ i ] + CENTER_X - 50;
				player2.ball_pos_y[ i ] = _angle->sin_num[ player2_angle ] * player2.ball_radius[ i ] + CENTER_Y - 50;
			}
			if( GAME_COUNT < GAME_TIMER_HALF ){
				player2.ball_angle[ i ] += SHIFT * 3;
			} else if( GAME_COUNT > GAME_TIMER_HALF ){
				player2.ball_angle[ i ] -= SHIFT * 3; 
			}
			player2.ball_radius[ i ] -= SHIFT / 4;
		}

		if( player2.ball_pos_x[ i ] > 0 || player2.ball_pos_y[ i ] > 0 ) {
			DrawGraph( ( int )player2.ball_pos_x[ i ], ( int )player2.ball_pos_y[ i ], _graph_music.graph_player2_ball[ player2.ball_efects[ i ] % 3 ], TRUE );	
		}

		if ( player2.score[ i ] > 0 && player2.ball_radius[ i ] < 0 ) {	
			if ( player2.score_count[ i ] == SCORE_DRAW_TIME ) {
				all_score += player2.score[ i ];
				hole_in = true;
				if ( HARD_MODE ) {
					magnification = 0;
				}
			}

			while ( player2.score[ i ] > 0 ) {
				DrawGraph(  ( int )CENTER_X - 150 - player2.pos_num * 50, ( int )CENTER_Y - 200, _graph_music.graph_small_number[ player2.score[ i ] % 10 ], TRUE );
				player2.score[ i ] /= 10;
				player2.pos_num++;
			}
			player2.pos_num = 0;
			player2.score_count[ i ]--;
			if ( player2.score_count[ i ] == 0 ) {
				player2.ball_min += 1;			
			}
		}
		player2.ball_efects[ i ]++;
	}

	//合成段表示
	for ( int i = ball_mix.ball_min; i < ball_mix.ball_max ; i++ ) {
		if ( ball_mix.ball_radius[ i ] < 0 ) {
			if ( ball_mix.score_count[ i ] == SCORE_DRAW_TIME ) {
				hole_in = true;
				magnification += 1;
				ball_mix.score[ i ] *= magnification;
				all_score += ball_mix.score[ i ];
			}
			while ( ball_mix.score[ i ] > 0 ) {
				DrawGraph( ( int )CENTER_X - ball_mix.pos_num * 50, ( int )CENTER_Y - 200, _graph_music.graph_small_number[ ball_mix.score[ i ] % 10 ], TRUE );
				ball_mix.score[ i ] /= 10;
				ball_mix.pos_num++;
			}
			ball_mix.pos_num = 0;
			ball_mix.score_count[ i ]--;
			if ( ball_mix.score_count[ i ] == 0 ) {
				ball_mix.ball_min += 1;			
			}

		} else if( ball_mix.ball_pos_x[ i ] > 0 || ball_mix.ball_pos_y[ i ] > 0 ) {
			int mix_angle = ball_mix.ball_angle[ i ] % 3600;
			ball_mix.ball_pos_x[ i ] = _angle->cos_num[ mix_angle ] * ball_mix.ball_radius[ i ] + CENTER_X - 50;
			ball_mix.ball_pos_y[ i ] = _angle->sin_num[ mix_angle ] * ball_mix.ball_radius[ i ] + CENTER_Y - 50;


			if( GAME_COUNT < GAME_TIMER_HALF ){
				ball_mix.ball_angle[ i ] += SHIFT * 3;
			} else if( GAME_COUNT > GAME_TIMER_HALF ){
				ball_mix.ball_angle[ i ] -= SHIFT * 3; 
			}
			ball_mix.ball_radius[ i ] -= SHIFT / 4;		

			DrawGraph( ( int )ball_mix.ball_pos_x[ i ], ( int )ball_mix.ball_pos_y[ i ], _graph_music.graph_mix_ball, TRUE );	

			if ( ball_mix.ball_efects[ i ] > 0 ) {
				ball_mix.ball_efects[ i ]--;
				DrawGraph( ( int )ball_mix.ball_pos_x[ i ], ( int )ball_mix.ball_pos_y[ i ], _graph_music.graph_mix_ball_efects[ ball_mix.ball_efects[ i ] / 40 ], TRUE );	
			}
		}

		ball_mix.color_num++;
	}


}

void Ball::Player1Fire( int turret_angle ) {
	player1.ball_pos_x.push_back( 0 );
	player1.ball_pos_y.push_back( 0 );
	player1.ball_cut_in.push_back( 0 );
	player1.ball_angle.push_back( 0 );
	player1.ball_radius.push_back( 0 );
	player1.ball_start_angle.push_back( turret_angle );
	player1.ball_acc.push_back( 100 );
	player1.ball_speed.push_back( 10 );
	player1.score.push_back( SCORE_NORMAL );
	player1.score_count.push_back( SCORE_DRAW_TIME );
	player1.ball_efects.push_back( 0 );

	player1.ball_max += 1;
	player1.Battered++;
}

void Ball::Player2Fire( int turret_angle ) {
	player2.ball_pos_x.push_back( 0 );
	player2.ball_pos_y.push_back( 0 );
	player2.ball_cut_in.push_back( 0 );
	player2.ball_angle.push_back( 0 );
	player2.ball_radius.push_back( 0 );
	player2.ball_start_angle.push_back( turret_angle - 1 );
	player2.ball_acc.push_back( 100 );
	player2.ball_speed.push_back( 10 );
	player2.score.push_back( SCORE_NORMAL );
	player2.score_count.push_back( SCORE_DRAW_TIME );
	player2.ball_efects.push_back( 0 );

	player2.ball_max += 1;
	player2.Battered++;
}

int Ball::getMagnification( ) const {
	return magnification;
}

bool Ball::getHoleIn( ) const {
	return hole_in;
}

bool Ball::getMix( ) const {
	return mix;
}

int Ball::getAllScore( ) const {
	return all_score;
}