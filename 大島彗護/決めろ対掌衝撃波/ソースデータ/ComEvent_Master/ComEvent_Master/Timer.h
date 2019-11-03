#pragma once


class Timer {
public:
	Timer( );
	~Timer( );

public:
	void update( );
	int getTimer( ) const;		//���݂̃J�E���g�̎擾
	bool getGameState( ) const;	//�Q�[���J�n���Q�[��������������
	int getCutInTime( ) const;	//�J�b�g�C�����̃J�E���g�擾

private:
	void initialize( );
	void finalize( );
	void start_update( );	//�Q�[���J�n���̃J�E���g����
	void game_update( );	//�Q�[�����̃J�E���g����

private:
	bool init;				//������
	bool game;				//true = game, false = start
	int start_count;		//�Q�[���J�n���̃J�E���g
	int game_count;			//�Q�[�����̃J�E���g
	int convert_time;		//�J�b�g�C���̃J�E���g

};

