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
	int graph_title = 0;			//タイトルの背景
	int graph_title_right = 0;		//タイトル画面の右のキャラ
	int graph_title_left = 0;		//タイトル画面の左のキャラ
	int graph_title_key = 0;		//ゲーム開始のための命令
	int graph_title_start = 0;		//ゲーム開始を知らせるロゴ
	int graph_text_teach_file = 0;	//ゲームの操作説明書
	int graph_text_staff = 0;		//スタッフロール

	int sound_title = 0;			//タイトルの曲
	int sound_game_start = 0;		//ゲーム開始のSE

	//Outset
	int graph_start_movie = 0;		//冒頭のムービー

	//Game
	int graph_revolution;					//回転する背景
	int graph_hand;							//背景の手
	int graph_hole;							//画面中央の穴
	int graph_game_start;					//ゲーム開始のロゴ
	int graph_text_cut_in;					//カットイン時のテキスト
	int graph_border;						//カットイン時の帯
	int graph_player1_turret;				//プレイヤー1のタレット
	int graph_player1_turret_down;			//プレイヤー1のタレットのダウン状態
	int graph_player1_stamina_frame;		//プレイヤー1のタレット
	int graph_player1_stamina_frame_down;	//プレイヤー1のタレットのダウン状態
	int graph_player2_turret;				//プレイヤー2のタレット
	int graph_player2_turret_down;			//プレイヤー2のタレットのダウン状態
	int graph_player2_stamina_frame;		//プレイヤー1のタレット
	int graph_player2_stamina_frame_down;	//プレイヤー1のタレットのダウン状態
	int graph_stamina_back;					//スタミナゲージの背景
	int graph_stamina_num;					//スタミナゲージの残量
	int graph_combo;						//コンボのテキスト
	int graph_product;						//×
	int graph_mix_ball;						//合成弾

	int graph_big_number[ 3 ];				//大きな数字
	int graph_small_number[ 10 ];			//小さな数字
	int graph_china_girl[ 3 ];				//ゲーム終了直後のカットイン
	int graph_player1_ball[ 3 ];			//球1のエフェクト
	int graph_player2_ball[ 3 ];			//球2のエフェクト
	int graph_mix_ball_efects[ 4 ];			//合成弾のエフェクト

	int sound_countdown;					//カウントダウンのSE
	int sound_beam;							//ゲーム終了直後の遷移音楽
	int sound_turret_move;					//タレットが動いた時の音
	int sound_turret_fire;					//タレットの弾発射音
	int sound_player_down;					//スタミナ切れでプレイヤーがダウンした時の音
	int sound_hole_in;						//ボールが穴に入った時の音
	int sound_mix;							//合成弾作成時の音
	
	//Finish
	int graph_girl;							//チャイナ娘

	int graph_scroll_back[ 2 ];				//スクロール背景
	int graph_beam_start[ 3 ];				//かめはめ波初動	
	int graph_beam[ 20 ];					//かめはめ波
	int graph_beam_hit[ 3 ];				//かめはめ波が当たった時
	int graph_enemy_down[ 3 ];				//敵ダウンイラスト
	int graph_enemy[ 3 ];					//敵イラスト
	int graph_beam_efect[ 4 ];				//かめはめ波のエフェクト
	int graph_enemy_hit[ 25 ];				//敵にビームが当たった時のエフェクト

	int sound_beam_hit;						//敵にかめはめ波当たった時の音

	//Result
	int graph_result_back;					//リザルトの背景
	int graph_tent;							//テント
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
