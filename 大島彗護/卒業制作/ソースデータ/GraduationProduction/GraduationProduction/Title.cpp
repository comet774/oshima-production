#include "Title.h"
#include "DxLib.h"
#include "constfail.h"

Title::Title( ) {
	title_str_size = CreateFontToHandle( NULL, 100, 10 );
}


Title::~Title( ) {

}

void Title::update( ) {
	DrawStringToHandle( 200, 200, "タイトル", WHITE, title_str_size );
	DrawString( 270, 340, "Enterキーを押してゲームスタート", WHITE );
	
}