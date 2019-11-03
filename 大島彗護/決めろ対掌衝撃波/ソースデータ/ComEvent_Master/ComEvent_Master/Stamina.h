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
	bool init;
	bool player1_overheat;
	bool player2_overheat;
	int player1_gauge;
	int player2_gauge;
	int	player1_count;
	int	player2_count;
	int start_count; 
};

