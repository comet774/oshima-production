#include "GameOver.h"
#include "DxLib.h"
#include "constfail.h"

GameOver::GameOver( ) {

}


GameOver::~GameOver( ) {
}

void GameOver::update( ) {
	DrawString( 360, 260, "ゲームオーバー", WHITE );
	DrawString( 270, 300, "Enterキーを押してタイトル", WHITE );
}

int GameOver::nextFlow( ) {
	return flow;
}

void GameOver::nextChoice( ) {
	
}