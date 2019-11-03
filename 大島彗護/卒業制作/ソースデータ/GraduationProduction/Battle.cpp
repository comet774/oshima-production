#include "Battle.h"
#include "constfail.h"

Battle::Battle( ) {
	Initialize( );
}

Battle::~Battle( ) {
	Finalize( );
}


void Battle::update( Keyboard *key ) {
	_key = key;

	drawBattle( );
	battleflow( );
	interval++;
}

int Battle::nextScene( ) {
	return next_flow;
}

//初期化及びExcelデータの受け取り
void Battle::Initialize( ) {
	_read_E = new ReadExcel( );

	if ( _read_E->Read( ) == -1 ) {
		DrawString( 0, 0, "csvデータの読み込みに失敗しました。", WHITE );

	}

	for ( int i = 0; i < _read_E->setMax( ); i++ ) {
		_enemydata.push_back( INITENEMY );
		for ( int j = 0; j < STATE_NUM; j++ ) {
			switch ( j ) {
				case ENEMYSTATES_HIERARCHY:
					 _enemydata[ i ].hierarchy = _read_E->setNum( ENEMYSTATES_HIERARCHY, i );
					break;
				case ENEMYSTATES_NUMBER:
					 _enemydata[ i ].number = _read_E->setNum( ENEMYSTATES_NUMBER, i );
					break;
				case ENEMYSTATES_SHAPE:
					 _enemydata[ i ].shape = _read_E->setNum( ENEMYSTATES_SHAPE, i );
					break;
				case ENEMYSTATES_COLOR:
					 _enemydata[ i ].color = _read_E->setNum( ENEMYSTATES_COLOR, i );
					break;
				case ENEMYSTATES_HP:
					 _enemydata[ i ].hp = _read_E->setNum( ENEMYSTATES_HP, i );
					break;
				case ENEMYSTATES_ATTACK:
					 _enemydata[ i ].attack = _read_E->setNum( ENEMYSTATES_ATTACK, i );
					break;
				case ENEMYSTATES_DEFENCE:
					_enemydata[ i ].defence = _read_E->setNum( ENEMYSTATES_DEFENCE, i );
					break;
				default:
					break;
			}
		}
		hierarchy_max = _enemydata[ i ].hierarchy;
	}

	isDecideAction = false;
	isDecideTarget = false;
	isPlayerAction = false;
	isEnemyAction = false;
	isDefence = false;
	isPushEnter = false;
	drawInit = true;
	_playerdata = INITPLAYER;
	player_hp_max = _playerdata.hp;
	hierarchy = 1;
	next_flow = GAMEFLOW_BATTLE;
	interval = 0;
	attack_enemy_num = 0;
	damage = 0;
	target_row = 0;
	target_ad = 0;
	draw_enemy_num = 0;
	defeat_enemy = 0;
	defeat_enemy_num = 0;
	hiera_enemy = 0;
}

void Battle::Finalize( ) {

}

//戦闘シーンの全体処理
void Battle::battleflow( ) {
	isPushEnter = false;
	isPushBack = false;
	switch( flow ) {
		case BATTLEFLOW_PLAYERCHOICE:
			if ( !isDecideAction ) {
				actionChoice( );
				if ( action == COMMAND_DEFENCE && isDecideAction ) {
					isDecideTarget = true;
				}
				break;
			}
			if ( !isDecideTarget ) {
				targetChoice( );
				
				break;
			}
			flow = BATTLEFLOW_INTERVAL;

			break;	

		case BATTLEFLOW_INTERVAL:
			target_ad = defeat_enemy_num;

			if ( defeat_enemy > 0 ) {
				//その階層で生存している敵の中で一番左にいる敵を探す
				for ( int i = defeat_enemy_num; i < hiera_enemy + defeat_enemy_num; i++ ) {
					if ( _enemydata[ i ].hp > 0 ) {
						target_ad = i;
						break;
					}
				}
				//プレイヤーが選択した対象に調整
				for ( int i = target_ad; i < target + target_ad; i++ ) {
					if ( _enemydata[ i ].hp == 0 ) {
						target++;
					} 
				}
			
			}
			target += target_ad;
			while ( 1 ) {
				if ( _enemydata[ target ].hp > 0 ) {
					flow = BATTLEFLOW_PLAYERATTACK;
					interval = 0;
					break;
				}
				target++;
			}

			break;
		case BATTLEFLOW_PLAYERATTACK:
			if ( !isPlayerAction ) {
				playerActtion( );
			}

			if( interval % 30 == 0 ) {
				flow = BATTLEFLOW_ENEMYATTACK;
				interval = 0;
				if ( defeat_enemy == hiera_enemy ) {
					flow = BATTLEFLOW_NEXT;
				}

			}
			break;
		case BATTLEFLOW_ENEMYATTACK:
			if( attack_enemy_num >= hiera_enemy || ( _playerdata.hp == 0 && interval == 0 ) ) {
				flow = BATTLEFLOW_NEXT;
				break;
			}

			if ( !isEnemyAction ) {
				enemyActtion( );

			}
			break;
		case BATTLEFLOW_NEXT:
			isDecideAction = false;
			isDecideTarget = false;
			isPlayerAction = false;
			isEnemyAction = false;
			attack_enemy_num = 0;
			damage = 0;
			target = 0;

			if ( isDefence ) {
				_playerdata.defence -= 2;
				isDefence = false;
			}

			if ( defeat_enemy == hiera_enemy ) {
				hierarchy++;
				drawInit = true;
				defeat_enemy_num += defeat_enemy;
				defeat_enemy = 0;
				_playerdata.hp += 3;
				if ( _playerdata.hp > player_hp_max ) {
					_playerdata.hp = player_hp_max;
				}
			}

			if ( _playerdata.hp <= 0 ) {
				next_flow = GAMEFLOW_GAMEOVER;
			}
			
  			if ( hierarchy > _enemydata[ _read_E->setMax( ) - 1 ].hierarchy ) {
			//game finish. player is winner
				next_flow = GAMEFLOW_GAMECLEAR;
			}

			if ( _playerdata.hp > 0 ) {
				flow = BATTLEFLOW_PLAYERCHOICE;
			}

			break;
		default:
			break;
	}	

}

//プレイヤーのコマンド選択
void Battle::actionChoice( ) {
	isPushEnter = isDecideAction;
	action = keyChoice( action );

	if ( isPushEnter ) {
		isDecideAction = true;
	}

	if ( action > COMMAND_DEFENCE ) {
		action = COMMAND_DEFENCE;
	}
}

//対象選択
void Battle::targetChoice( ) {
	isPushEnter = isDecideTarget;
	target = keyChoice( target );

	if ( isPushBack ) {
		isDecideAction = false;
	} else if ( isPushEnter ) {
		isDecideTarget = true;
	}

	if ( target > target_row - 1 ) {
		target = target_row - 1;
	}

	
}

//プレイヤーが選択したコマンドの処理
void Battle::playerActtion( ) {
	switch( action ) {
		case COMMAND_ATTACK:
			damage = 0;
			damage = damageMath( _playerdata.attack, _enemydata[ target ].defence );
			
			_enemydata[ target ].hp = damageMath( _enemydata[ target ].hp, _playerdata.attack, _enemydata[ target ].defence );
			
			if( _enemydata[ target ].hp <= 0 ) {
				defeat_enemy++;
			}

			break;
		case COMMAND_DEFENCE:
			isDefence = true;
			break;
		default:
			break;
	}

	if ( isDefence ) {
		_playerdata.defence += 2;
	}

	isPlayerAction = true;
}

//Enemyのコマンド処理
void Battle::enemyActtion( ) {
	if ( _enemydata[ attack_enemy_num + defeat_enemy_num ].hierarchy != hierarchy || _enemydata[ attack_enemy_num + defeat_enemy_num ].hp <= 0 ) {
		attack_enemy_num++;
		isEnemyAction = false;
		interval = 0;
		return;
	}
	
	if( !isEnemyAction ) {
		damage = 0;
		damage = damageMath( _enemydata[ attack_enemy_num + defeat_enemy_num ].attack, _playerdata.defence );
		_playerdata.hp = damageMath( _playerdata.hp, _enemydata[ attack_enemy_num + defeat_enemy_num ].attack, _playerdata.defence );
		isEnemyAction = true;
	}
}

//ダメージ計算処理
int Battle::damageMath( int target_hp, int attack, int target_defence ) {
	if ( attack - target_defence < 0 ) {
		return target_hp;
	}
	
	int hp = 0;
	
	hp = target_hp - ( attack - target_defence );
	
	if ( hp < 0 ) {
		hp = 0;
	}

	return hp;
}

int Battle::damageMath( int attack, int target_defence ) {
	int damage = 0;

	damage = attack - target_defence;

	if ( damage < 0 ) {
		damage = 0;
	}

	return damage;

}

//プレイヤーがコマンド選択時のキーボード処理
int Battle::keyChoice(int  selection ) {
	if( _key->getKeyState( KEY_INPUT_UP ) == 1 ) {
		selection--;
		if ( selection < 0 ) {
			selection = 0;
		}
	}

	if( _key->getKeyState( KEY_INPUT_DOWN ) == 1 ) {
		selection++;
	}

	if( _key->getKeyState( KEY_INPUT_RETURN ) == 1 ) {
		isPushEnter = true;
	}

	if ( _key->getKeyState( KEY_INPUT_BACK ) == 1 ) {
		isPushBack = true;
	}

	return selection;
	
} 

//描画の初期化
void Battle::drawInitialize( ) {
	hiera_enemy = 0;
	for ( int i = defeat_enemy_num; i < _read_E->setMax( ); i++ ) {
		if ( _enemydata[ i ].hierarchy == hierarchy ) {
			hiera_enemy++;
		}
	
	}
		
	firstMessege = true;
	
	drawInit = false;
}

//戦闘シーンの描画
void Battle::drawBattle( ) {
	if ( drawInit ) {
		drawInitialize( );
	}

	if( firstMessege ) {
		for ( int i = 0; i < hiera_enemy; i++ ) {
			DrawFormatString( 30, 410 + i * STRING_ROW_INTERVAL, WHITE, "Enemy%dが現れた", _enemydata[ i + defeat_enemy_num ].number );
		}
	}
	
	draw_enemy_num = 0;

	for ( int i = 0; i < _read_E->setMax( ); i++ ) {
		int enemy_pos_x = HALF_SCREEN_SIZE_X - DRAW_SHAPE_SIZE / 2 * hiera_enemy + draw_enemy_num * ( DRAW_SHAPE_SIZE + DRAW_SHAPE_INTERVAL );
		
		if ( _enemydata[ i ].hierarchy == hierarchy ) {
			draw_enemy_num++;
			if ( _enemydata[ i ].hp > 0 ) {
				switch( _enemydata[ i ].shape ) {
				case SHAPE_BOX:
					DrawBox( enemy_pos_x, DRAW_ENEMY_Y_POS, enemy_pos_x + DRAW_SHAPE_SIZE, DRAW_ENEMY_Y_POS + DRAW_SHAPE_SIZE, _enemydata[ i ].color, false );
					break;
				case SHAPE_TRIANGLE:
					DrawTriangle( enemy_pos_x, DRAW_ENEMY_Y_POS + DRAW_SHAPE_SIZE, enemy_pos_x + DRAW_SHAPE_SIZE / 2, DRAW_ENEMY_Y_POS, enemy_pos_x + DRAW_SHAPE_SIZE, DRAW_ENEMY_Y_POS + DRAW_SHAPE_SIZE, _enemydata[ i ].color, false );
					break;
				case SHAPE_SIXSTAR:
					DrawTriangle( enemy_pos_x, DRAW_ENEMY_Y_POS + DRAW_SHAPE_SIZE, enemy_pos_x + DRAW_SHAPE_SIZE / 2,	DRAW_ENEMY_Y_POS, enemy_pos_x + DRAW_SHAPE_SIZE, DRAW_ENEMY_Y_POS + DRAW_SHAPE_SIZE, _enemydata[ i ].color, false );
					DrawTriangle( enemy_pos_x, DRAW_ENEMY_Y_POS, enemy_pos_x + DRAW_SHAPE_SIZE / 2, DRAW_ENEMY_Y_POS + DRAW_SHAPE_SIZE, enemy_pos_x + DRAW_SHAPE_SIZE, DRAW_ENEMY_Y_POS, _enemydata[ i ].color, false );
					break;
				case SHAPE_X:
					DrawLine( enemy_pos_x, DRAW_ENEMY_Y_POS, enemy_pos_x + DRAW_SHAPE_SIZE,	DRAW_ENEMY_Y_POS + DRAW_SHAPE_SIZE, _enemydata[ i ].color );
					DrawLine( enemy_pos_x, DRAW_ENEMY_Y_POS + DRAW_SHAPE_SIZE, enemy_pos_x + DRAW_SHAPE_SIZE,	DRAW_ENEMY_Y_POS, _enemydata[ i ].color );
					break;
				default:
					break;
				}
			}
		}
	}
	
	DrawBox( 10, 400, 500, 590, WHITE, false );
	DrawBox( 510, 400, 790, 590, WHITE, false );

	DrawString ( 520, 410, "Player1", WHITE );
	DrawFormatString( 520, 430, WHITE, "HP %d", _playerdata.hp );
	DrawFormatString( 520, 450, WHITE, "Attack %d", _playerdata.attack );
	DrawFormatString( 520, 470, WHITE, "Defence %d", _playerdata.defence );

	DrawFormatString( 660, 10, WHITE, "現在 %d/%d階層", hierarchy, hierarchy_max );

	if ( firstMessege ) {
		WaitTimer( 1000 );
		firstMessege = false;
		return;
	}

	switch ( flow ) {
		case BATTLEFLOW_PLAYERCHOICE:
			if ( !isDecideAction ) {
				DrawString ( 30, 410, "攻撃\n防御", WHITE );
				DrawString ( 20, 410 + action * 20,	">", WHITE );
				break;
			}

			if ( !isDecideTarget ) {
				target_row = 0;
				for ( int i = 0; i < _read_E->setMax( ); i++ ) {
					if ( _enemydata[ i ].hierarchy == hierarchy && _enemydata[ i ].hp > 0 ) {
						DrawFormatString( 30, 410 + target_row * STRING_ROW_INTERVAL, WHITE, "Enemy%d		HP %d", _enemydata[ i ].number, _enemydata[ i ].hp );
						target_row++;
					}
				}
				DrawString ( 20, 410 + target * 20, ">", WHITE );
				break;
			}

			break;	
		case BATTLEFLOW_PLAYERATTACK:
			if ( action == COMMAND_DEFENCE ) {
				DrawString( 20, 410, "プレイヤーは防御の姿勢を構えてる", WHITE );
			} else {
				if( interval < 15 ) {
					DrawFormatString( 20, 410, WHITE, "プレイヤーはEnemy%dに攻撃!", _enemydata[ target ].number );
					break;
				}

				if ( interval < 30 ) {
					DrawFormatString( 20, 410, WHITE, "プレイヤーはEnemy%dに%dのダメージを与えた", _enemydata[ target ].number, damage );
				}
			
			}
			
			break;
		case BATTLEFLOW_ENEMYATTACK:
			if ( attack_enemy_num >= hiera_enemy ) {
				break;
			}

			if( interval < 15 ) {
				DrawFormatString( 20, 410, WHITE, "Enemy%dはプレイヤーに攻撃!", _enemydata[ attack_enemy_num + defeat_enemy_num ].number );
				break;
			}

			if ( interval < 30 ) {
				DrawFormatString( 20, 410, WHITE, "Enemy%dはプレイヤーに%dのダメージを与えた", _enemydata[ attack_enemy_num + defeat_enemy_num ].number, damage );
			} else {
				interval = 0;
				attack_enemy_num++;
				isEnemyAction = false;
			}

			break;
		case BATTLEFLOW_NEXT:
			if ( _playerdata.hp <= 0 ) {
				DrawString( 30, 410, "あなたはお亡くなりになりました…", WHITE );
				WaitTimer( 1800 );
			}

			break;
		default:
			break;
	}	 
}






