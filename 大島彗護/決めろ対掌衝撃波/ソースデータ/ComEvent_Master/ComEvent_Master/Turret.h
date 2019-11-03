#pragma once
#include "Keyboard.h"

class Turret {
public:
	Turret( );
	~Turret( );

public:
	void update( const int GAME_TIMER, const bool PLAYER1_OVERHEAT, const bool PLAYER2_OVERHEAT );
	bool getTurretMove( ) const;
	bool getTurret1Fire( ) const;
	bool getTurret2Fire( ) const;
	int getPlayer1Angle( ) const;
	int getPlayer1AngleDown( ) const;
	int getPlayer2Angle( ) const;
	int getPlayer2AngleDown( ) const;

private:
	void initialize( );
	void finalize( );


private:
	bool init;
	bool turret_move;		//タレットが動いてるかどうか
	bool turret1_fire;		//タレット1が弾を撃ったかどうか
	bool turret2_fire;		//タレット2が弾を撃ったかどうか
	bool player1_down;		//プレイヤー1がダウン状態の時に振る方向,trueで右,falseで左
	bool player2_down;		//プレイヤー2がダウン状態の時に振る方向,trueで右,falseで左
	int player1_angle;		//プレイヤー1のタレットが向いてる方向
	int player2_angle;		//プレイヤー2のタレットが向いてる方向
	int player1_angle_down;	//プレイヤー1のダウン状態のタレットが向いてる方向
	int player2_angle_down;	//プレイヤー2のダウン状態のタレットが向いてる方向

	Keyboard *_keyboard;
};

