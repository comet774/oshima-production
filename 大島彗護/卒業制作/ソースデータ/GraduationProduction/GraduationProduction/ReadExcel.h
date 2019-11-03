#pragma once
#include <vector>
#include "constfail.h"

class ReadExcel {
public:
	ReadExcel( );
	~ReadExcel( );

public:
	int Read( );
	int setNum( int state, int enemynumber );
	int setMax( );

private:
	void Initialize( );
	void Finalize( );
	void ChoiceColor( int col, int read_color );

	int StringToInt( std::string str );
	std::string IntToString( int _int );

private:

	std::vector< struct enemydata > _enemydata;
};

