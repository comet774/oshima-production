#include "GameClear.h"
#include "DxLib.h"
#include "constfail.h"

GameClear::GameClear( ) {

}


GameClear::~GameClear( ) {

}

void GameClear::update( ) {
	DrawString( 360, 260, "ゲームクリア!", WHITE );
	DrawString( 270, 300, "Enterキーを押してタイトル", WHITE );

}