#pragma once

class CutIn {
public:
	CutIn( );
	~CutIn( );

public:
	void update_belt( int timer );
	void update_girl( );
	int getBeltRight( ) const;
	int getBeltLeft( ) const;
	int getScalling( ) const;	//ゲーム中盤の真ん中の拡縮の値取得
	int getGirlCount( ) const;	//ゲーム終了直後のカットインのカウント取得
	int getGirlPos( ) const;	//ゲーム終了直後のカットインの表示場所取得
	int getGirlGraph( ) const;	//ゲーム終了直後のカットインの枚数目取得

private:
	void initialize( );
	void finalize( );

private:
	bool init;		//初期化
	int belt_right;	//右に流れる帯
	int belt_left;	//左に流れる帯
	int scall;		//真ん中の拡縮

	int girl_count;	//ゲーム終了直後のカットインのカウント
	int girl_pos;	//ゲーム終了直後のカットインの表示場所
	int girl_graph;	//ゲーム終了直後のカットインの枚数目

};

