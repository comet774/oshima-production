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
	bool init;				//������
	bool player1_overheat;	//�v���C���[1�̃X�^�~�i��0�ɂȂ�����
	bool player2_overheat;	//�v���C���[2�̃X�^�~�i��0�ɂȂ�����
	int player1_gauge;		//�v���C���[1�̃X�^�~�i���l
	int player2_gauge;		//�v���C���[2�̃X�^�~�i���l
	int	player1_count;		//�v���C���[1�̃X�^�~�i�񕜎��Ԃ̌v��
	int	player2_count;		//�v���C���[2�̃X�^�~�i�񕜎��Ԃ̌v��
	int start_count; 		//�ŏ��̃X�^�~�i�񕜂̌v��
};

