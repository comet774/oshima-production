#pragma once


class Timer {
public:
	Timer( );
	~Timer( );

public:
	void update( );
	int getTimer( ) const;		//現在のカウントの取得
	bool getGameState( ) const;	//ゲーム開始かゲーム中か見分ける
	int getCutInTime( ) const;	//カットイン時のカウント取得

private:
	void initialize( );
	void finalize( );
	void start_update( );	//ゲーム開始時のカウント処理
	void game_update( );	//ゲーム中のカウント処理

private:
	bool init;				//初期化
	bool game;				//true = game, false = start
	int start_count;		//ゲーム開始時のカウント
	int game_count;			//ゲーム中のカウント
	int convert_time;		//カットインのカウント

};

