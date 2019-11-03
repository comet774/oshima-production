#include "GraphMusic.h"
#include "DxLib.h"

GraphMusic::GraphMusic( ) {
}

GraphMusic::~GraphMusic( ) {
	InitGraph( );
}

void GraphMusic::ReadTitle( ) {
	graph_title						= LoadGraph( "画像,音楽/No.1 タイトル一枚絵1-1.png" );
	graph_title_right				= LoadGraph( "画像,音楽/ちびきゃら1.png" );
	graph_title_left				= LoadGraph( "画像,音楽/ちびきゃら２.png" );
	graph_title_key					= LoadGraph( "画像,音楽/press space key ロゴ.png" );
	graph_title_start				= LoadGraph( "画像,音楽/No.25 ゲーム開始！＿ロゴ.png" );
	graph_text_teach_file			= LoadGraph( "画像,音楽/操作指南.png" );
	graph_text_staff					= LoadGraph( "画像,音楽/開発スタッフ.png" );


	sound_title						= LoadSoundMem( "画像,音楽/トップ画面無限ループbgm.mp3" );
	sound_game_start				= LoadSoundMem( "画像,音楽/トップ画面→ゲーム遷移の音.mp3" );
}

void GraphMusic::ReadOutset( ) {
	graph_start_movie					= LoadGraph( "画像,音楽/導入ムービー.mov" );
}

void GraphMusic::ReadGame( ) {
	graph_revolution					= LoadGraph( "画像,音楽/No.6 掌回転対応可能背景type2.PNG" ); 
	graph_hand							= LoadGraph( "画像,音楽/No.7 手.png" );
	graph_hole							= LoadGraph( "画像,音楽/No.14 当たり穴.png" );
	graph_game_start					= LoadGraph( "画像,音楽/No.25 ゲーム開始！＿ロゴ.png" );
	graph_text_cut_in					= LoadGraph( "画像,音楽/No.11 カットイン文字.png" );
	graph_border						= LoadGraph( "画像,音楽/No.12 カットイン外枠.png" );
	graph_player1_turret				= LoadGraph( "画像,音楽/No.15 BD版砲台1.PNG" );
	graph_player1_turret_down			= LoadGraph( "画像,音楽/No.16 BD版砲台1グロッキー.PNG" );
	graph_player1_stamina_frame			= LoadGraph( "画像,音楽/No.8 スタミナバー外枠＿1.png" );
	graph_player1_stamina_frame_down	= LoadGraph( "画像,音楽/No.13 （グロッキー)スタミナバー外枠＿1.png" );
	graph_player2_turret				= LoadGraph( "画像,音楽/No.15 BD版砲台2.PNG" );
	graph_player2_turret_down			= LoadGraph( "画像,音楽/No.16 BD版砲台2グロッキー.PNG" );
	graph_player2_stamina_frame			= LoadGraph( "画像,音楽/No.8 スタミナバー外枠＿2.png" );
	graph_player2_stamina_frame_down	= LoadGraph( "画像,音楽/No.13 (グロッキー)スタミナバー外枠＿2.png" );
	graph_stamina_back					= LoadGraph( "画像,音楽/No.10 スタミナバー残量_空.png" );
	graph_stamina_num					= LoadGraph( "画像,音楽/No.9 スタミナバー残量.png" );
	graph_combo							= LoadGraph( "画像,音楽/No.34 COMBO_　ロゴ文字.png" );
	graph_product						= LoadGraph( "画像,音楽/No.35 ×.png" );
	graph_mix_ball						= LoadGraph( "画像,音楽/No.4 合成光球.png" );


	graph_big_number[ 0 ]			= LoadGraph( "画像,音楽/No.31 デカ数字１.png" );
	graph_big_number[ 1 ]			= LoadGraph( "画像,音楽/No.31 デカ数字２.png" );
	graph_big_number[ 2 ]			= LoadGraph( "画像,音楽/No.31 デカ数字３.png" );

	graph_small_number[ 0 ]			= LoadGraph( "画像,音楽/No.24 数字ロゴ＿0.png" );
	graph_small_number[ 1 ]			= LoadGraph( "画像,音楽/No.24 数字ロゴ＿１.png" );
	graph_small_number[ 2 ]			= LoadGraph( "画像,音楽/No.24 数字ロゴ＿2.png" );
	graph_small_number[ 3 ]			= LoadGraph( "画像,音楽/No.24 数字ロゴ＿3.png" );
	graph_small_number[ 4 ]			= LoadGraph( "画像,音楽/No.24 数字ロゴ＿4.png" );
	graph_small_number[ 5 ]			= LoadGraph( "画像,音楽/No.24 数字ロゴ＿5.png" );
	graph_small_number[ 6 ]			= LoadGraph( "画像,音楽/No.24 数字ロゴ＿6.png" );
	graph_small_number[ 7 ]			= LoadGraph( "画像,音楽/No.24 数字ロゴ＿7.png" );
	graph_small_number[ 8 ]			= LoadGraph( "画像,音楽/No.24 数字ロゴ＿8.png" );
	graph_small_number[ 9 ]			= LoadGraph( "画像,音楽/No.24 数字ロゴ＿9.png" );
												  
	graph_china_girl[ 0 ]			= LoadGraph( "画像,音楽/No.17 導入発表導入1.png" );
	graph_china_girl[ 1 ]			= LoadGraph( "画像,音楽/No.17 結果発表導入2.png" );
	graph_china_girl[ 2 ]			= LoadGraph( "画像,音楽/No.17 結果発表導入3.png" );
	
	sound_countdown					= LoadSoundMem( "画像,音楽/321カウントダウン音声.mp3" );
	sound_beam						= LoadSoundMem( "画像,音楽/ゲーム画面→結果演出画面.mp3" );
	sound_turret_move				= LoadSoundMem( "画像,音楽/se_maoudamashii_system39.mp3" );
	sound_turret_fire				= LoadSoundMem( "画像,音楽/se_maoudamashii_battle_gun05.mp3" );
	sound_player_down				= LoadSoundMem( "画像,音楽/グロッキー発生se.mp3" );
	sound_hole_in					= LoadSoundMem( "画像,音楽/se_maoudamashii_retro03.mp3" );
	sound_mix						= LoadSoundMem( "画像,音楽/se_maoudamashii_retro25.mp3" );

	LoadDivGraph( "画像,音楽/No.5 合成弾_エフェクト_720×180.png", 4, 4, 1, 180, 180, graph_mix_ball_efects );
	LoadDivGraph( "画像,音楽/No.3 1P光球エフェクト_120×120＿差分3.png", 3, 3, 1, 128, 128, graph_player1_ball );
	LoadDivGraph( "画像,音楽/No.3 2P光球エフェクト_120×120＿差分3.png", 3, 3, 1, 128, 128, graph_player2_ball );
}

void GraphMusic::ReadFinish( ) {
	graph_girl				= LoadGraph( "画像,音楽/チャイナ娘_俯瞰.png" );			

	graph_enemy[ 0 ]		= LoadGraph( "画像,音楽/敵キャラ1.png" );
	graph_enemy[ 1 ]		= LoadGraph( "画像,音楽/敵キャラ2.png" );
	graph_enemy[ 2 ]		= LoadGraph( "画像,音楽/敵キャラ3.png" );

	graph_enemy_down[ 0 ]	= LoadGraph( "画像,音楽/敵キャラ1_やられ.png" );
	graph_enemy_down[ 1 ]	= LoadGraph( "画像,音楽/敵キャラ 2_やられ.png" );
	graph_enemy_down[ 2 ]	= LoadGraph( "画像,音楽/敵キャラ3_やられ.png" );

	graph_scroll_back[ 0 ]	= LoadGraph( "画像,音楽/スクロール背景1.png" );
	graph_scroll_back[ 1 ]	= LoadGraph( "画像,音楽/スクロール背景２.png" );



	LoadDivGraph( "画像,音楽/No.21ビームぶつかり導入エフェクト_800×700_差分3.png", 3, 3, 1, 800, 700, graph_beam_start );
	LoadDivGraph( "画像,音楽/No.20 ビームぶつかりエフェクト持続_800×700_差分3.png", 3, 3, 1, 800, 700, graph_beam_hit );
	LoadDivGraph( "画像,音楽/No.22 新エネルギー波エフェクト_106×1024_差分20.png", 20, 19, 2, 106, 1024, graph_beam );
	LoadDivGraph( "画像,音楽/集中線エフェクト_1280×1024_差分4.png", 4, 4, 1, 1280, 1024, graph_beam_efect );
	LoadDivGraph( "画像,音楽/impact_effect_512×512_25.png", 25, 8, 4, 512, 512, graph_enemy_hit );

	sound_beam_hit	= LoadSoundMem( "画像,音楽/エネルギーぶつかり音.mp3" );


}

void GraphMusic::ReadResult( ) {
	graph_result_back					= LoadGraph( "画像,音楽/No.18 結果発表　演出背景.png" );
	graph_tent							= LoadGraph( "画像,音楽/No.19 スクリーン素材上乗せ用.png" );
	graph_lean							= LoadGraph( "画像,音楽/No.19 スクリーン立てかけ板.png" );
	graph_text_total_score				= LoadGraph( "画像,音楽/No.27 累計のスコアは….png" );
	graph_text_score					= LoadGraph( "画像,音楽/No.26 今回のスコアは….png" );
	graph_text_more						= LoadGraph( "画像,音楽/No.28 もう一度やる？　ロゴ.png" );
	graph_text_yes						= LoadGraph( "画像,音楽/No.29 是！.png" );
	graph_text_no						= LoadGraph( "画像,音楽/No.30 否….png" );

	graph_small_number[ 0 ]			= LoadGraph( "画像,音楽/No.24 数字ロゴ＿0.png" );
	graph_small_number[ 1 ]			= LoadGraph( "画像,音楽/No.24 数字ロゴ＿１.png" );
	graph_small_number[ 2 ]			= LoadGraph( "画像,音楽/No.24 数字ロゴ＿2.png" );
	graph_small_number[ 3 ]			= LoadGraph( "画像,音楽/No.24 数字ロゴ＿3.png" );
	graph_small_number[ 4 ]			= LoadGraph( "画像,音楽/No.24 数字ロゴ＿4.png" );
	graph_small_number[ 5 ]			= LoadGraph( "画像,音楽/No.24 数字ロゴ＿5.png" );
	graph_small_number[ 6 ]			= LoadGraph( "画像,音楽/No.24 数字ロゴ＿6.png" );
	graph_small_number[ 7 ]			= LoadGraph( "画像,音楽/No.24 数字ロゴ＿7.png" );
	graph_small_number[ 8 ]			= LoadGraph( "画像,音楽/No.24 数字ロゴ＿8.png" );
	graph_small_number[ 9 ]			= LoadGraph( "画像,音楽/No.24 数字ロゴ＿9.png" );

	sound_result_show					= LoadSoundMem( "画像,音楽/結果ファンファーレ.mp3" );

}

void GraphMusic::ReadStaffRoll( ) {
	graph_staff_roll					= LoadGraph( "画像,音楽/スタッフクレジット画面.png" );
}

void GraphMusic::ReadDiscription( ) {
	graph_teach_file					= LoadGraph( "画像,音楽/操作指南一枚絵.png" );
}

void GraphMusic::DeleteTitle( ) {
	DeleteGraph( graph_title );
	DeleteGraph( graph_title_right );
	DeleteGraph( graph_title_left );
	DeleteGraph( graph_title_key );
	DeleteGraph( graph_title_start );
	DeleteGraph( graph_text_teach_file );
	DeleteGraph( graph_text_staff );
	
	DeleteSoundMem( sound_title );
	DeleteSoundMem( sound_game_start );

	graph_title = 0;
	graph_title_right = 0;
	graph_title_left = 0;
	graph_title_key = 0;
	graph_title_start = 0;
	graph_text_teach_file = 0;
	graph_text_staff = 0;

	sound_title = 0;
	sound_game_start = 0;
}

void GraphMusic::DeleteOutset( ) {
	DeleteGraph( graph_start_movie );

	graph_game_start = 0;
}

void GraphMusic::DeleteGame( ) {
	DeleteGraph( graph_revolution );
	DeleteGraph( graph_hand );
	DeleteGraph( graph_hole );
	DeleteGraph( graph_text_cut_in );
	DeleteGraph( graph_border );
	DeleteGraph( graph_player1_turret );
	DeleteGraph( graph_player1_turret_down );
	DeleteGraph( graph_player1_stamina_frame );
	DeleteGraph( graph_player1_stamina_frame_down );
	DeleteGraph( graph_player2_turret );
	DeleteGraph( graph_player2_turret_down );
	DeleteGraph( graph_player2_stamina_frame );
	DeleteGraph( graph_player2_stamina_frame_down );
	DeleteGraph( graph_stamina_back );
	DeleteGraph( graph_stamina_num );
	DeleteGraph( graph_combo );
	DeleteGraph( graph_product );
	DeleteGraph( graph_mix_ball );

	for ( int i = 0; i < 3; i++ ) {
		DeleteGraph( graph_big_number[ i ] );
		graph_big_number[ i ] = 0;
	}

	for ( int i = 0; i < 10; i++ ) {
		DeleteGraph( graph_small_number[ i ] );
		graph_small_number[ i ] = 0;
	}

	for ( int i = 0; i < 3; i++ ) {
		DeleteGraph( graph_china_girl[ i ] );
		graph_china_girl[ i ] = 0;
	}

	for ( int i = 0; i < 3; i++ ) {
		DeleteGraph( graph_player1_ball[ i ] );
		graph_player1_ball[ i ] = 0;
	}

	for ( int i = 0; i < 3; i++ ) {
		DeleteGraph( graph_player2_ball[ i ] );
		graph_player2_ball[ i ] = 0;
	}

	for ( int i = 0; i < 4; i++ ) {
		DeleteGraph( graph_mix_ball_efects[ i ] );
		graph_mix_ball_efects[ i ] = 0;
	}

	DeleteSoundMem( sound_countdown );
	DeleteSoundMem( sound_beam );
	DeleteSoundMem( sound_turret_move );
	DeleteSoundMem( sound_turret_fire );
	DeleteSoundMem( sound_player_down );
	DeleteSoundMem( sound_hole_in );
	DeleteSoundMem( sound_mix );

	graph_revolution = 0;
	graph_hand = 0;
	graph_hole = 0;
	graph_text_cut_in = 0;
	graph_border = 0;
	graph_player1_turret = 0;
	graph_player1_turret_down = 0;
	graph_player1_stamina_frame = 0;
	graph_player1_stamina_frame_down = 0;
	graph_player2_turret = 0;
	graph_player2_turret_down = 0;
	graph_player2_stamina_frame = 0;
	graph_player2_stamina_frame_down = 0;
	graph_stamina_back = 0;
	graph_stamina_num = 0;
	graph_combo = 0;
	graph_product = 0;

	sound_countdown = 0;
	sound_beam = 0;
	sound_turret_move = 0;
	sound_turret_fire = 0;
	sound_player_down = 0;
	sound_hole_in = 0;
	sound_mix = 0;
}

void GraphMusic::DeleteFinish( ) {
	DeleteGraph( graph_girl );

	for ( int i = 0; i < 3; i++ ) {
		DeleteGraph( graph_enemy[ i ] );
		graph_enemy[ i ] = 0;
	}

	for ( int i = 0; i < 3; i++ ) {
		DeleteGraph( graph_enemy_down[ i ] );
		graph_enemy_down[ i ] = 0;
	}
	
	for ( int i = 0; i < 3; i++ ) {
		DeleteGraph( graph_beam_start[ i ] );
		graph_beam_start[ i ] = 0;
	}

	for ( int i = 0; i < 3; i++ ) {
		DeleteGraph( graph_beam_hit[ i ] );
		graph_beam_hit[ i ] = 0;
	}

	for ( int i = 0; i < 20; i++ ) {
		DeleteGraph( graph_beam[ i ] );
		graph_beam[ i ] = 0;
	}

	for ( int i = 0; i < 4; i++ ) {
		DeleteGraph( graph_beam_efect[ i ] );
		graph_beam_efect[ i ] = 0;
	}

	for ( int i = 0; i < 2; i++ ) {
		DeleteGraph( graph_scroll_back[ i ] );
		graph_scroll_back[ i ] = 0;
	}

	for ( int i = 0; i < 25; i++ ) {
		DeleteGraph( graph_enemy_hit[ i ] );
		graph_enemy_hit[ i ] = 0;
	}

	DeleteSoundMem( sound_beam_hit );

	graph_girl = 0;

	sound_beam_hit = 0;
}

void GraphMusic::DeleteResult( ) {
	DeleteGraph( graph_result_back );
	DeleteGraph( graph_tent );
	DeleteGraph( graph_lean );
	DeleteGraph( graph_text_total_score );
	DeleteGraph( graph_text_score );
	DeleteGraph( graph_text_more );
	DeleteGraph( graph_text_yes );
	DeleteGraph( graph_text_no );

	DeleteSoundMem( sound_result_show );

	for ( int i = 0; i < 10; i++ ) {
		DeleteGraph( graph_small_number[ i ] );
		graph_small_number[ i ] = 0;
	}

	graph_result_back = 0;
	graph_tent = 0;
	graph_lean = 0;
	graph_text_total_score = 0;
	graph_text_score = 0;
	graph_text_more = 0;
	graph_text_yes = 0;
	graph_text_no = 0;

	sound_result_show = 0;
}

void GraphMusic::DeleteStaffRoll( ) {
	DeleteGraph( graph_staff_roll );

	graph_staff_roll = 0;
}

void GraphMusic::DeleteDiscription( ) {
	DeleteGraph( graph_teach_file );

	graph_teach_file = 0;
}