#pragma once

class GraphMusic {
public:
	GraphMusic( );
	~GraphMusic( );

public:
	void ReadTitle( );
	void ReadOutset( );
	void ReadGame( );
	void ReadFinish( );
	void ReadResult( );
	void ReadStaffRoll( );
	void ReadDiscription( );
	void DeleteTitle( );
	void DeleteOutset( );
	void DeleteGame( );
	void DeleteFinish( );
	void DeleteResult( );
	void DeleteStaffRoll( );
	void DeleteDiscription( );

public:
	//Title
	int graph_title = 0;			//�^�C�g���̔w�i
	int graph_title_right = 0;		//�^�C�g����ʂ̉E�̃L����
	int graph_title_left = 0;		//�^�C�g����ʂ̍��̃L����
	int graph_title_key = 0;		//�Q�[���J�n�̂��߂̖���
	int graph_title_start = 0;		//�Q�[���J�n��m�点�郍�S
	int graph_text_teach_file = 0;	//�Q�[���̑��������
	int graph_text_staff = 0;		//�X�^�b�t���[��

	int sound_title = 0;			//�^�C�g���̋�
	int sound_game_start = 0;		//�Q�[���J�n��SE

	//Outset
	int graph_start_movie = 0;		//�`���̃��[�r�[

	//Game
	int graph_revolution;					//��]����w�i
	int graph_hand;							//�w�i�̎�
	int graph_hole;							//��ʒ����̌�
	int graph_game_start;					//�Q�[���J�n�̃��S
	int graph_text_cut_in;					//�J�b�g�C�����̃e�L�X�g
	int graph_border;						//�J�b�g�C�����̑�
	int graph_player1_turret;				//�v���C���[1�̃^���b�g
	int graph_player1_turret_down;			//�v���C���[1�̃^���b�g�̃_�E�����
	int graph_player1_stamina_frame;		//�v���C���[1�̃^���b�g
	int graph_player1_stamina_frame_down;	//�v���C���[1�̃^���b�g�̃_�E�����
	int graph_player2_turret;				//�v���C���[2�̃^���b�g
	int graph_player2_turret_down;			//�v���C���[2�̃^���b�g�̃_�E�����
	int graph_player2_stamina_frame;		//�v���C���[1�̃^���b�g
	int graph_player2_stamina_frame_down;	//�v���C���[1�̃^���b�g�̃_�E�����
	int graph_stamina_back;					//�X�^�~�i�Q�[�W�̔w�i
	int graph_stamina_num;					//�X�^�~�i�Q�[�W�̎c��
	int graph_combo;						//�R���{�̃e�L�X�g
	int graph_product;						//�~
	int graph_mix_ball;						//�����e

	int graph_big_number[ 3 ];				//�傫�Ȑ���
	int graph_small_number[ 10 ];			//�����Ȑ���
	int graph_china_girl[ 3 ];				//�Q�[���I������̃J�b�g�C��
	int graph_player1_ball[ 3 ];			//��1�̃G�t�F�N�g
	int graph_player2_ball[ 3 ];			//��2�̃G�t�F�N�g
	int graph_mix_ball_efects[ 4 ];			//�����e�̃G�t�F�N�g

	int sound_countdown;					//�J�E���g�_�E����SE
	int sound_beam;							//�Q�[���I������̑J�ډ��y
	int sound_turret_move;					//�^���b�g�����������̉�
	int sound_turret_fire;					//�^���b�g�̒e���ˉ�
	int sound_player_down;					//�X�^�~�i�؂�Ńv���C���[���_�E���������̉�
	int sound_hole_in;						//�{�[�������ɓ��������̉�
	int sound_mix;							//�����e�쐬���̉�
	
	//Finish
	int graph_girl;							//�`���C�i��

	int graph_scroll_back[ 2 ];				//�X�N���[���w�i
	int graph_beam_start[ 3 ];				//���߂͂ߔg����	
	int graph_beam[ 20 ];					//���߂͂ߔg
	int graph_beam_hit[ 3 ];				//���߂͂ߔg������������
	int graph_enemy_down[ 3 ];				//�G�_�E���C���X�g
	int graph_enemy[ 3 ];					//�G�C���X�g
	int graph_beam_efect[ 4 ];				//���߂͂ߔg�̃G�t�F�N�g
	int graph_enemy_hit[ 25 ];				//�G�Ƀr�[���������������̃G�t�F�N�g

	int sound_beam_hit;						//�G�ɂ��߂͂ߔg�����������̉�

	//Result
	int graph_result_back;					//���U���g�̔w�i
	int graph_tent;							//�e���g
	int graph_lean;
	int graph_text_total_score;
	int graph_text_score;
	int graph_text_more;
	int graph_text_yes;
	int graph_text_no;

	int sound_result_show;

	//StaffRoll
	int graph_staff_roll;

	//Discription
	int graph_teach_file;

};
