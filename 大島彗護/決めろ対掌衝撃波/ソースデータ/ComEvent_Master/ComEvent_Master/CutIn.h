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
	int getScalling( ) const;	//�Q�[�����Ղ̐^�񒆂̊g�k�̒l�擾
	int getGirlCount( ) const;	//�Q�[���I������̃J�b�g�C���̃J�E���g�擾
	int getGirlPos( ) const;	//�Q�[���I������̃J�b�g�C���̕\���ꏊ�擾
	int getGirlGraph( ) const;	//�Q�[���I������̃J�b�g�C���̖����ڎ擾

private:
	void initialize( );
	void finalize( );

private:
	bool init;		//������
	int belt_right;	//�E�ɗ�����
	int belt_left;	//���ɗ�����
	int scall;		//�^�񒆂̊g�k

	int girl_count;	//�Q�[���I������̃J�b�g�C���̃J�E���g
	int girl_pos;	//�Q�[���I������̃J�b�g�C���̕\���ꏊ
	int girl_graph;	//�Q�[���I������̃J�b�g�C���̖�����

};

