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
	int flow;					//現在のフロー
	int next_flow;				//次のフロー
	int action;					//プレイヤーのアクション
	int target;					//対象
	int hierarchy;				//現階層
	int hierarchy_max;			//最下層
	int interval;				//間隔
	int damage;					//ダメージ
	int attack_enemy_num;		//攻撃する敵の番号
	int target_row;				//攻撃する敵を選択する時の文字の列
	int target_ad;				//targetの調整
	int draw_enemy_num;			//敵を描画した回数
	int defeat_enemy;			//その階層で倒した敵の数
	int defeat_enemy_num;		//倒した敵の数
	int hiera_enemy;			//その階層の敵の数
	int player_hp_max;			//プレイヤーの最大体力
	bool isDecideAction;		//プレイヤーのコマンドの決定有無
	bool isDecideTarget;		//プレイヤーの対象の決定有無
	bool isPlayerAction;		//プレイヤーが行動したか
	bool isEnemyAction;			//敵が全て行動したか
	bool isDefence;				//プレイヤーが防御したか
	bool isPushEnter;			//Enterキーを押したか
	bool isPushBack;			//BackSpaceキーを押したか
	bool firstMessege;			//敵の出現時のコメント表示
	bool drawInit;				//敵出現時の最初のメッセージのしたかどうか
	struct playerdata _playerdata;

	std::vector < struct enemydata > _enemydata;
	

	ReadExcel *_read_E;
	Keyboard *_key;
};
