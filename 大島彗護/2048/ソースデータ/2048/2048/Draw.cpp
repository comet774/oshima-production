#include "Draw.h"
#include "DxLib.h"

const int BACK_BOX = 360;
const int INTERVAL = 8;
const int NUM_BOX_SIZE = 80;
const int BACK_POS_X = 140;
const int BACK_POS_Y = 70;
const int NO_BOX_C = GetColor( 186, 184, 182 );		//灰色
const int BACK_BOX_C = GetColor( 208, 199, 159 );	//クリーム色
const int WHITE = GetColor( 255, 255, 255 );		//白色
const int BLACK = GetColor( 0, 0, 0 );				//黒色

Draw::Draw( ):
num_pos_col( 0 ),
num_pos_row( 0 ),
block_num( 0 ),
box_color( 0 ),
str_color( 0 ),
type( 0 ),
sub( 0 ),
score( 0 ),
highscore( 0 ),
_game( new Game( ) ) {
	str_size = CreateFontToHandle( NULL, 100, 10 );
	
}

Draw::~Draw( ) {

}

void Draw::update( Game *game ) {
	score = game->getScore( );
	
	DrawBox( BACK_POS_X, BACK_POS_Y, BACK_POS_X + BACK_BOX, BACK_POS_Y + BACK_BOX, GetColor( 208, 199, 159 ), true );
	DrawString( 0, 0, "2048",BLACK );
	DrawFormatString( BACK_POS_X, 50, BLACK,"スコア: %d", score );

	//ブロックの表示処理
	for ( int i = 0; i < 4; i++ ) {
		for ( int j = 0; j < 4; j++ ) {
			num_pos_col = BACK_POS_X + ( i + 1 ) * INTERVAL + i * NUM_BOX_SIZE;
			num_pos_row = BACK_POS_Y + ( j + 1 ) * INTERVAL + j * NUM_BOX_SIZE;
			block_num = game->getBlock( i, j );

			if( block_num == 0 ) {
				DrawBox( num_pos_col, num_pos_row, num_pos_col + NUM_BOX_SIZE, num_pos_row + NUM_BOX_SIZE, NO_BOX_C, true ); 
				continue;
			}

			color( );

			DrawBox( num_pos_col, num_pos_row, num_pos_col + NUM_BOX_SIZE, num_pos_row + NUM_BOX_SIZE, box_color, true );
			DrawFormatString( num_pos_col + 35, num_pos_row + 30, str_color, "%d", block_num  );

		}
	}
	//ゲームオーバーの描画処理
	if( game->getFinish( ) ) {
		if( score > highscore ) {
			highscore = score;
		}

		SetDrawBlendMode( DX_BLENDMODE_ADD, 128 );
		DrawBox( 0, 0, 600, 600, WHITE, true );
		SetDrawBlendMode( DX_BLENDGRAPHTYPE_NORMAL, 0 );

		DrawStringToHandle( 170, 170, "FINISH", BLACK, str_size );
		DrawFormatString( 170, 300, BLACK, "ハイスコア: %d", highscore );
		DrawString( 170, 320, "再挑戦　Enterキー", BLACK );
	}
}

//ブロックの色の処理
void Draw::color( ) {
	int div = 0b1000;
	while ( 1 ) {
		if( block_num / div > 0 ){
			type++;
			div *= div;
			continue;
		}
		if( block_num != 0b0001 << sub ) {
			sub++;
			continue;
		}
		sub += type;
		sub -= ( type * 4 );
		sub *= 45;
		break;
	}

	switch( type ) {
	case 0:
		box_color = GetColor( 255 - sub, 255 - sub, 255 - sub );
		str_color = BLACK;
		break;
	case 1:
		box_color = GetColor( 255, sub, 0 );
		str_color = WHITE;
		break;
	case 2:
		box_color = GetColor( 255 - sub, 255, 0 );
		str_color = WHITE;
		break;
	case 3:
		box_color = GetColor( 0, 255, sub );
		str_color = WHITE;
		break;
	case 4:
		box_color = GetColor( 0, 255 - sub, 255 );
		str_color = WHITE;
		break;
	default:
		break;
	}

	type = 0;
	sub = 1;
}