#pragma once
#include "ReadExcel.h"
#include "Keyboard.h"
#include <vector>

class Battle {
public:
	Battle( );
	~Battle( );

public:
	void update( Keyboard *key );
	int  nextScene( );

private:
	void Initialize( );
	void Finalize( );
	void battleflow( );
	void actionChoice( );
	void targetChoice( );
	void playerActtion( );
	void enemyActtion( );
	int damageMath( int target_hp, int attack, int defence );
	int damageMath( int attack, int defence );

	int keyChoice( int selection );
	void drawInitialize( );
	void drawBattle( );

private:
	int flow;					//���݂̃t���[
	int next_flow;				//���̃t���[
	int action;					//�v���C���[�̃A�N�V����
	int target;					//�Ώ�
	int hierarchy;				//���K�w
	int hierarchy_max;			//�ŉ��w
	int interval;				//�Ԋu
	int damage;					//�_���[�W
	int attack_enemy_num;		//�U������G�̔ԍ�
	int target_row;				//�U������G��I�����鎞�̕����̗�
	int target_ad;				//target�̒���
	int draw_enemy_num;			//�G��`�悵����
	int defeat_enemy;			//���̊K�w�œ|�����G�̐�
	int defeat_enemy_num;		//�|�����G�̐�
	int hiera_enemy;			//���̊K�w�̓G�̐�
	int player_hp_max;			//�v���C���[�̍ő�̗�
	bool isDecideAction;		//�v���C���[�̃R�}���h�̌���L��
	bool isDecideTarget;		//�v���C���[�̑Ώۂ̌���L��
	bool isPlayerAction;		//�v���C���[���s��������
	bool isEnemyAction;			//�G���S�čs��������
	bool isDefence;				//�v���C���[���h�䂵����
	bool isPushEnter;			//Enter�L�[����������
	bool isPushBack;			//BackSpace�L�[����������
	bool firstMessege;			//�G�̏o�����̃R�����g�\��
	bool drawInit;				//�G�o�����̍ŏ��̃��b�Z�[�W�̂������ǂ���
	struct playerdata _playerdata;

	std::vector < struct enemydata > _enemydata;
	

	ReadExcel *_read_E;
	Keyboard *_key;
};
