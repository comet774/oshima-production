#include "GraphMusic.h"
#include "DxLib.h"

GraphMusic::GraphMusic( ) {
}

GraphMusic::~GraphMusic( ) {
	InitGraph( );
}

void GraphMusic::ReadTitle( ) {
	graph_title						= LoadGraph( "�摜,���y/No.1 �^�C�g���ꖇ�G1-1.png" );
	graph_title_right				= LoadGraph( "�摜,���y/���т����1.png" );
	graph_title_left				= LoadGraph( "�摜,���y/���т����Q.png" );
	graph_title_key					= LoadGraph( "�摜,���y/press space key ���S.png" );
	graph_title_start				= LoadGraph( "�摜,���y/No.25 �Q�[���J�n�I�Q���S.png" );
	graph_text_teach_file			= LoadGraph( "�摜,���y/����w��.png" );
	graph_text_staff					= LoadGraph( "�摜,���y/�J���X�^�b�t.png" );


	sound_title						= LoadSoundMem( "�摜,���y/�g�b�v��ʖ������[�vbgm.mp3" );
	sound_game_start				= LoadSoundMem( "�摜,���y/�g�b�v��ʁ��Q�[���J�ڂ̉�.mp3" );
}

void GraphMusic::ReadOutset( ) {
	graph_start_movie					= LoadGraph( "�摜,���y/�������[�r�[.mov" );
}

void GraphMusic::ReadGame( ) {
	graph_revolution					= LoadGraph( "�摜,���y/No.6 ����]�Ή��\�w�itype2.PNG" ); 
	graph_hand							= LoadGraph( "�摜,���y/No.7 ��.png" );
	graph_hole							= LoadGraph( "�摜,���y/No.14 �����茊.png" );
	graph_game_start					= LoadGraph( "�摜,���y/No.25 �Q�[���J�n�I�Q���S.png" );
	graph_text_cut_in					= LoadGraph( "�摜,���y/No.11 �J�b�g�C������.png" );
	graph_border						= LoadGraph( "�摜,���y/No.12 �J�b�g�C���O�g.png" );
	graph_player1_turret				= LoadGraph( "�摜,���y/No.15 BD�ŖC��1.PNG" );
	graph_player1_turret_down			= LoadGraph( "�摜,���y/No.16 BD�ŖC��1�O���b�L�[.PNG" );
	graph_player1_stamina_frame			= LoadGraph( "�摜,���y/No.8 �X�^�~�i�o�[�O�g�Q1.png" );
	graph_player1_stamina_frame_down	= LoadGraph( "�摜,���y/No.13 �i�O���b�L�[)�X�^�~�i�o�[�O�g�Q1.png" );
	graph_player2_turret				= LoadGraph( "�摜,���y/No.15 BD�ŖC��2.PNG" );
	graph_player2_turret_down			= LoadGraph( "�摜,���y/No.16 BD�ŖC��2�O���b�L�[.PNG" );
	graph_player2_stamina_frame			= LoadGraph( "�摜,���y/No.8 �X�^�~�i�o�[�O�g�Q2.png" );
	graph_player2_stamina_frame_down	= LoadGraph( "�摜,���y/No.13 (�O���b�L�[)�X�^�~�i�o�[�O�g�Q2.png" );
	graph_stamina_back					= LoadGraph( "�摜,���y/No.10 �X�^�~�i�o�[�c��_��.png" );
	graph_stamina_num					= LoadGraph( "�摜,���y/No.9 �X�^�~�i�o�[�c��.png" );
	graph_combo							= LoadGraph( "�摜,���y/No.34 COMBO_�@���S����.png" );
	graph_product						= LoadGraph( "�摜,���y/No.35 �~.png" );
	graph_mix_ball						= LoadGraph( "�摜,���y/No.4 ��������.png" );


	graph_big_number[ 0 ]			= LoadGraph( "�摜,���y/No.31 �f�J�����P.png" );
	graph_big_number[ 1 ]			= LoadGraph( "�摜,���y/No.31 �f�J�����Q.png" );
	graph_big_number[ 2 ]			= LoadGraph( "�摜,���y/No.31 �f�J�����R.png" );

	graph_small_number[ 0 ]			= LoadGraph( "�摜,���y/No.24 �������S�Q0.png" );
	graph_small_number[ 1 ]			= LoadGraph( "�摜,���y/No.24 �������S�Q�P.png" );
	graph_small_number[ 2 ]			= LoadGraph( "�摜,���y/No.24 �������S�Q2.png" );
	graph_small_number[ 3 ]			= LoadGraph( "�摜,���y/No.24 �������S�Q3.png" );
	graph_small_number[ 4 ]			= LoadGraph( "�摜,���y/No.24 �������S�Q4.png" );
	graph_small_number[ 5 ]			= LoadGraph( "�摜,���y/No.24 �������S�Q5.png" );
	graph_small_number[ 6 ]			= LoadGraph( "�摜,���y/No.24 �������S�Q6.png" );
	graph_small_number[ 7 ]			= LoadGraph( "�摜,���y/No.24 �������S�Q7.png" );
	graph_small_number[ 8 ]			= LoadGraph( "�摜,���y/No.24 �������S�Q8.png" );
	graph_small_number[ 9 ]			= LoadGraph( "�摜,���y/No.24 �������S�Q9.png" );
												  
	graph_china_girl[ 0 ]			= LoadGraph( "�摜,���y/No.17 �������\����1.png" );
	graph_china_girl[ 1 ]			= LoadGraph( "�摜,���y/No.17 ���ʔ��\����2.png" );
	graph_china_girl[ 2 ]			= LoadGraph( "�摜,���y/No.17 ���ʔ��\����3.png" );
	
	sound_countdown					= LoadSoundMem( "�摜,���y/321�J�E���g�_�E������.mp3" );
	sound_beam						= LoadSoundMem( "�摜,���y/�Q�[����ʁ����ʉ��o���.mp3" );
	sound_turret_move				= LoadSoundMem( "�摜,���y/se_maoudamashii_system39.mp3" );
	sound_turret_fire				= LoadSoundMem( "�摜,���y/se_maoudamashii_battle_gun05.mp3" );
	sound_player_down				= LoadSoundMem( "�摜,���y/�O���b�L�[����se.mp3" );
	sound_hole_in					= LoadSoundMem( "�摜,���y/se_maoudamashii_retro03.mp3" );
	sound_mix						= LoadSoundMem( "�摜,���y/se_maoudamashii_retro25.mp3" );

	LoadDivGraph( "�摜,���y/No.5 �����e_�G�t�F�N�g_720�~180.png", 4, 4, 1, 180, 180, graph_mix_ball_efects );
	LoadDivGraph( "�摜,���y/No.3 1P�����G�t�F�N�g_120�~120�Q����3.png", 3, 3, 1, 128, 128, graph_player1_ball );
	LoadDivGraph( "�摜,���y/No.3 2P�����G�t�F�N�g_120�~120�Q����3.png", 3, 3, 1, 128, 128, graph_player2_ball );
}

void GraphMusic::ReadFinish( ) {
	graph_girl				= LoadGraph( "�摜,���y/�`���C�i��_����.png" );			

	graph_enemy[ 0 ]		= LoadGraph( "�摜,���y/�G�L����1.png" );
	graph_enemy[ 1 ]		= LoadGraph( "�摜,���y/�G�L����2.png" );
	graph_enemy[ 2 ]		= LoadGraph( "�摜,���y/�G�L����3.png" );

	graph_enemy_down[ 0 ]	= LoadGraph( "�摜,���y/�G�L����1_����.png" );
	graph_enemy_down[ 1 ]	= LoadGraph( "�摜,���y/�G�L���� 2_����.png" );
	graph_enemy_down[ 2 ]	= LoadGraph( "�摜,���y/�G�L����3_����.png" );

	graph_scroll_back[ 0 ]	= LoadGraph( "�摜,���y/�X�N���[���w�i1.png" );
	graph_scroll_back[ 1 ]	= LoadGraph( "�摜,���y/�X�N���[���w�i�Q.png" );



	LoadDivGraph( "�摜,���y/No.21�r�[���Ԃ��蓱���G�t�F�N�g_800�~700_����3.png", 3, 3, 1, 800, 700, graph_beam_start );
	LoadDivGraph( "�摜,���y/No.20 �r�[���Ԃ���G�t�F�N�g����_800�~700_����3.png", 3, 3, 1, 800, 700, graph_beam_hit );
	LoadDivGraph( "�摜,���y/No.22 �V�G�l���M�[�g�G�t�F�N�g_106�~1024_����20.png", 20, 19, 2, 106, 1024, graph_beam );
	LoadDivGraph( "�摜,���y/�W�����G�t�F�N�g_1280�~1024_����4.png", 4, 4, 1, 1280, 1024, graph_beam_efect );
	LoadDivGraph( "�摜,���y/impact_effect_512�~512_25.png", 25, 8, 4, 512, 512, graph_enemy_hit );

	sound_beam_hit	= LoadSoundMem( "�摜,���y/�G�l���M�[�Ԃ��艹.mp3" );


}

void GraphMusic::ReadResult( ) {
	graph_result_back					= LoadGraph( "�摜,���y/No.18 ���ʔ��\�@���o�w�i.png" );
	graph_tent							= LoadGraph( "�摜,���y/No.19 �X�N���[���f�ޏ�悹�p.png" );
	graph_lean							= LoadGraph( "�摜,���y/No.19 �X�N���[�����Ă�����.png" );
	graph_text_total_score				= LoadGraph( "�摜,���y/No.27 �݌v�̃X�R�A�́c.png" );
	graph_text_score					= LoadGraph( "�摜,���y/No.26 ����̃X�R�A�́c.png" );
	graph_text_more						= LoadGraph( "�摜,���y/No.28 ������x���H�@���S.png" );
	graph_text_yes						= LoadGraph( "�摜,���y/No.29 ���I.png" );
	graph_text_no						= LoadGraph( "�摜,���y/No.30 �ہc.png" );

	graph_small_number[ 0 ]			= LoadGraph( "�摜,���y/No.24 �������S�Q0.png" );
	graph_small_number[ 1 ]			= LoadGraph( "�摜,���y/No.24 �������S�Q�P.png" );
	graph_small_number[ 2 ]			= LoadGraph( "�摜,���y/No.24 �������S�Q2.png" );
	graph_small_number[ 3 ]			= LoadGraph( "�摜,���y/No.24 �������S�Q3.png" );
	graph_small_number[ 4 ]			= LoadGraph( "�摜,���y/No.24 �������S�Q4.png" );
	graph_small_number[ 5 ]			= LoadGraph( "�摜,���y/No.24 �������S�Q5.png" );
	graph_small_number[ 6 ]			= LoadGraph( "�摜,���y/No.24 �������S�Q6.png" );
	graph_small_number[ 7 ]			= LoadGraph( "�摜,���y/No.24 �������S�Q7.png" );
	graph_small_number[ 8 ]			= LoadGraph( "�摜,���y/No.24 �������S�Q8.png" );
	graph_small_number[ 9 ]			= LoadGraph( "�摜,���y/No.24 �������S�Q9.png" );

	sound_result_show					= LoadSoundMem( "�摜,���y/���ʃt�@���t�@�[��.mp3" );

}

void GraphMusic::ReadStaffRoll( ) {
	graph_staff_roll					= LoadGraph( "�摜,���y/�X�^�b�t�N���W�b�g���.png" );
}

void GraphMusic::ReadDiscription( ) {
	graph_teach_file					= LoadGraph( "�摜,���y/����w��ꖇ�G.png" );
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