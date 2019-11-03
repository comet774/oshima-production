#pragma once
class Keyboard {
public:
	Keyboard( );
	~Keyboard( );
	
public:
	void update( );
	int getKeyState( int keycode );

private:
	char key[ 256 ] = { 0 };
	int cheak[ 256 ] = { 0 };
};

