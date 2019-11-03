#pragma once
#include "Keyboard.h"

class Game {
public:
	Game( );
	~Game( );
public:
	void update( );
	int getScore( );
	bool getFinish( );
	int getBlock( int col, int row );

private:
	void Init( );
	void GameInit( );
	void Action( );
	void Retry( );
private:

	bool ismove;			//ブロックを動かしたか
	bool skip;				//ブロックを動かしたときブロックの間に空白ができたか
	bool finish;			//ゲームオーバーかどうか
	bool num_col;			//ブロックのランダム生成時に横位置が決定したか
	bool num_row;			//ブロックのランダム生成時に縦位置が決定したか
	int blocks[ 4 ][ 4 ];	//生成されたブロック群
	int score;				//スコア
	int rand_col;			//ブロックのランダム生成時の横位置の数字
	int rand_row;			//ブロックのランダム生成時の縦位置の数字
	int rand_num;			//ブロック生成時の数字指定のランダム要素
	int first;				//最初のブロックの生成回数
	Keyboard *keyboard;

	
};

