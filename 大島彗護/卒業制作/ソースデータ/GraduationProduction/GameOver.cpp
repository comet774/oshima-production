#include "GameOver.h"
#include "DxLib.h"
#include "constfail.h"

GameOver::GameOver( ) {

}


GameOver::~GameOver( ) {
}

void GameOver::update( ) {
	DrawString( 360, 260, "�Q�[���I�[�o�[", WHITE );
	DrawString( 270, 300, "Enter�L�[�������ă^�C�g��", WHITE );
}

int GameOver::nextFlow( ) {
	return flow;
}

void GameOver::nextChoice( ) {
	
}