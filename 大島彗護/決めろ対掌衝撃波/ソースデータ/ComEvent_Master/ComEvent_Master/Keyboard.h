#pragma once
class Keyboard
{
public:
	Keyboard();
	~Keyboard();

public:
	void update( );
	int check( int keycode );

private:
	int key_num[ 256 ] = { 0 };
	char check_keyboard[ 256 ] = { 0 };
};

