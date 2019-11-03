#include "ReadExcel.h"
#include "constfail.h"
#include <string>
#include <fstream>
#include <sstream>
//#include <iostream>

const char *F_ENEMYSTATES = "ExcelData/Update_Enemy_States.csv";

ReadExcel::ReadExcel( ) {
	Initialize( );
}

ReadExcel::~ReadExcel( ) {
	Finalize( );
}

int ReadExcel::Read( ) {
	std::ifstream of_enemystates( F_ENEMYSTATES );
	if ( !of_enemystates.is_open( ) ) {
		return -1;
	}
	std::string str;
	std::string save;
	const char COMMA = ',';
	int type = 0;
	int col = 0;

	while ( std::getline( of_enemystates, str ) ) {
		std::istringstream work( str );

		while ( std::getline( work, save, COMMA ) ) {

			if ( col != 0 ) {
				switch ( type % STATE_NUM ) {
					case ENEMYSTATES_HIERARCHY:
						_enemydata[ col - 1 ].hierarchy = StringToInt( save.c_str( ) );
						break;
					case ENEMYSTATES_NUMBER:
						_enemydata[ col - 1 ].number = StringToInt( save.c_str( ) );
						break;
					case ENEMYSTATES_SHAPE:
						_enemydata[ col - 1 ].shape = StringToInt( save.c_str( ) );
						break;
					case ENEMYSTATES_COLOR:
						ChoiceColor( col, StringToInt( save.c_str( ) ) );
						break;
					case ENEMYSTATES_HP:
						_enemydata[ col - 1 ].hp = StringToInt( save.c_str( ) );
						break;
					case ENEMYSTATES_ATTACK:
						_enemydata[ col - 1 ].attack = StringToInt( save.c_str( ) );
						break;
					case ENEMYSTATES_DEFENCE:
						_enemydata[ col - 1 ].defence = StringToInt( save.c_str( ) );
						break;
					default:
						break;
				}
			}
			
			type++;
			if ( type % STATE_NUM == 0 ) {
				_enemydata.push_back( INITENEMY );
				col++;
			}
		}

	}

	_enemydata.pop_back( );

	return 0;
}

int ReadExcel::setNum( int state, int enemynumber ) {
	if ( _enemydata.size( ) <= enemynumber ) {
		return -1;
	}

	switch ( state ) {
		case ENEMYSTATES_HIERARCHY:
			return _enemydata[ enemynumber ].hierarchy;
			break;
		case ENEMYSTATES_NUMBER:
			return _enemydata[ enemynumber ].number;
			break;
		case ENEMYSTATES_SHAPE:
			return _enemydata[ enemynumber ].shape;
			break;
		case ENEMYSTATES_COLOR:
			return _enemydata[ enemynumber ].color;
			break;
		case ENEMYSTATES_HP:
			return _enemydata[ enemynumber ].hp;
			break;
		case ENEMYSTATES_ATTACK:
			return _enemydata[ enemynumber ].attack;
			break;
		case ENEMYSTATES_DEFENCE:
			return _enemydata[ enemynumber ].defence;
			break;
		default:
			DrawString( 0, 0, "そんなステータス無いです", WHITE );
			return 0;
			break;
	}
	return 0;
}

int ReadExcel::setMax( ) {
	return ( int )_enemydata.size( );
}

void ReadExcel::Initialize( ) {
	_enemydata.reserve( 10 );
}

void ReadExcel::Finalize( ) {

}

void ReadExcel::ChoiceColor( int col, int read_color ) {
	int color = read_color;

	switch( color ) {
		case COLOR_RED:
			_enemydata[ col - 1 ].color = RED;
			break;
		case COLOR_BLUE:
			_enemydata[ col - 1 ].color = BLUE;
			break;
		case COLOR_GREEN:
			_enemydata[ col - 1 ].color = GREEN;
			break;							
		case COLOR_WHITE:
			_enemydata[ col - 1 ].color = WHITE;
			break;		
		default:
			break;
	}
}

int ReadExcel::StringToInt( std::string str ) {
	int num;
	std::stringstream sstr;
	sstr << str;
	sstr >> num;

	return num;
}

std::string ReadExcel::IntToString( int _int ) {
	std::string num;
	std::stringstream sstr;
	sstr << _int;
	sstr >> num;

	return num;
}