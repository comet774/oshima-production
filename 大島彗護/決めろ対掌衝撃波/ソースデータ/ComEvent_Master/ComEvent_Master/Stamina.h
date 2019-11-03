#pragma once
class Stamina {
public:
	Stamina( );
	~Stamina( );

public:
	void update( const int game_timer );
	bool getPlayer1Overheat( ) const;
	bool getPlayer2Overheat( ) const;
	int getPlayer1Gauge( ) const;
	int getPlayer2Gauge( ) const;
	void Player1Fire( ); 
	void Player2Fire( );

private:
	void initialize( );
	void finalize( );

private:
	bool init;				//初期化
	bool player1_overheat;	//プレイヤー1のスタミナが0になったか
	bool player2_overheat;	//プレイヤー2のスタミナが0になったか
	int player1_gauge;		//プレイヤー1のスタミナ数値
	int player2_gauge;		//プレイヤー2のスタミナ数値
	int	player1_count;		//プレイヤー1のスタミナ回復時間の計測
	int	player2_count;		//プレイヤー2のスタミナ回復時間の計測
	int start_count; 		//最初のスタミナ回復の計測
};

