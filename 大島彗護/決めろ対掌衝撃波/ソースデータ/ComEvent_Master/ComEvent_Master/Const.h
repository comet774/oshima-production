

//�ȉ��͕ύX�s��
const int WIDTH					= 1280;						//��ʂ̉���	
const int HEIGHT				= 1024;						//��ʂ̏c��
const int ANGLE_RESERVE			= 1080;						//�p�x�̗]���l
const int REAL_TIME				= 60;						//�����̎���
const double CENTER_X			= WIDTH * 0.5;				//��ʂ�x���̒��S
const double CENTER_Y			= HEIGHT * 0.5;				//��ʂ�y���̒��S
const double PLAYER1_X			= WIDTH - 100;				//�v���C���[1�̃{�[���̏���x���W
const double PLAYER1_Y			= HEIGHT - 100;				//�v���C���[1�̃{�[���̏���y���W
const double PLAYER2_X			= 100;						//�v���C���[2�̃{�[���̏���x���W
const double PLAYER2_Y			= HEIGHT - 100;				//�v���C���[2�̃{�[���̏���y���W
const int ANGLE_MAX				= 3600;						//�ő�p�x
const int ANGLE_HALF			= 1800;						//�ő�p�x�̔���
const int INIT_TURRET_ANGLE		= 180;						//�^���b�g�̏����p�x
const int TURRET_DOWN_ANGLE		= 3600;						//�X�^�~�i�؂�̃^���b�g�̊�{�p�x
const int MEMORY					= 500;					//vector�̗e��
const int ENEMY_TYPE_NUMBER		= 3;						//���o���ʂɏo�Ă���G�̎�ނ̐�
const double ENEMY_BLOWS_TIME	= REAL_TIME * 2;			//���ʉ��o���̓G��������ԉ��o�����鎞��
const int ENEMY_X				= ( int )CENTER_X - 150;	//���ʉ��o���̓G��X���̈ʒu
const int INIT_EFECT			= 100;						//���ʉ��o���̃G�t�F�N�g�̏����ݒ�

enum SCENE {
	TITLE,
	OUTSET,
	GAME,
	FINISH,
	RESULT,
	STAFF_ROLL,
	DISCRIPTION,
	MAX_SCENE
};

//�ȉ��͕ύX��
const int TITLE_MOVE_SPEED		= 1;				//�^�C�g���̃L�����N�^�[�̈ړ��X�s�[�h
const int START_TIMER			= 3 * REAL_TIME;	//�Q�[���J�n���O�̃J�E���g			
const int START_TIMAR_GO		= 60;				//�Q�[���X�^�[�g�̃��S�\������
const int GAME_TIME				= 30 * 100;			//��������,100�͌Œ�
const int GAME_TIMER_HALF		= GAME_TIME / 2;	//�������Ԕ���
const int BELT_POS				= 1600;				//�J�b�g�C�����̏㉺�̃x���g�̏����ʒu
const int CUT_IN_TIMER			= 2 * 100;			//�J�b�g�C���̕\������
const int CUT_IN_FRAME_SPEED	= 45;				//�J�b�g�C�����̘g�̗����X�s�[�h
const int CUT_IN_EXPAND_SPEED	= 8;				//�J�b�g�C�����̉摜�̊g��X�s�[�h
const int BATTERY_NUM			= 3;				//���ˑ�̌����ύX���̒l
const int BATTERU_ACCELERATION	= 100;				//���˂����Ƃ��̏����x
const int BULLET				= 3;				//���ˑ�̃Q�[�W�̉񕜑��x
const int HOLE_AREA				= 100;				//�����s�͈�
const int STAMINA_MAX			= 100;				//�X�^�~�i�̍ő�l
const int STAMINA_SUB			= 12;				//�X�^�~�i�̌����l
const int BALL_DETERMINE		= 64;				//�����e�̓����蔻��
const int SCORE_MAX				= 10 * 10000;		//�X�R�A�{�[�h�̍ő�ϋv�l
const int SCORE_MAX_HARD		= 53 * 10000;		//�n�[�h���[�h���̃X�R�A�{�[�h�̍ő�ϋv�l
const int BLACKBOX_X			= 500;				//�X�R�A�{�[�h��X�l
const int BLACKBOX_Y			= 400;				//�X�R�A�{�[�h��Y�l
const int BACK_SPIN_MAX			= 300;				//��]�w�i�̍ő�l
const int BACK_SPIN_FREEM		= 20;				//��]�w�i�̌v�Z���o				1= 1�t���[��
const int SCORE_DRAW_TIME		= 1 * 100;			//�Q�[�����̃X�R�A�̕\������
const int SCORE_NORMAL			= 300;				//�ʏ�e�̓��_
const int SCORE_MIX				= 100;				//�����e�̓��_
const int SCORE_MIX_HARD		= 500;				//�n�[�h���[�h���̍����e�̓��_
const int BACK_SCROLL			= 20;				//���o���ʂ̃X�N���[�����x
const int ONE_ENEMY_SCORE		= 2000;				//�G��̂ɑ΂���X�R�A
const double EXPAND_NUM			= 0.04;				//�G�̊g��l
const int ENEMY_SPECE			= 200;				//���ʉ��o���̓G�����̊Ԋu
const double STOP_FIRST			= REAL_TIME * 2.5;	//���ʉ��o���̍ŏ��̓G��~����
const double STOP_SECOND		= REAL_TIME * 3.5;	//���ʉ��o����2��ڂ̓G��~����
const int SPECIAL_ENEMY			= 5;				//���ʉ��o���̓��ʉ��o�̊Ԋu( n�̖ڂ̓G�����ʉ��o������ )