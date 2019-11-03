using System.Collections;
using System.Collections.Generic;
using UnityEngine;

[ RequireComponent( typeof( MageAttack ) ) ]
public class Mage : Enemy {
	public bool _draw_detect_player = false;
	public bool _draw_move_range = false;

	[ SerializeField ] private GameObject _center = null;
	[ SerializeField ] private GameObject _under1 = null;
	[ SerializeField ] private GameObject _under2 = null;
    [ SerializeField ] private GameObject _player = null;

	[ SerializeField ] private float _detect_player_x  = 5.0f;
	[ SerializeField ] private float _detect_player_y  = 5.0f;

	[ SerializeField ] private int _move_range_left  = 3;
	[ SerializeField ] private int _move_range_right = 3;

	[ SerializeField ] private bool _move = true;


	private Vector3 _base_pos = new Vector3( );
	private int _move_x = 0;

    private bool _attack = false;
	private bool _turn = false;

	enum DETECT_TYPE {
		DETECT_TYPE_WALL,
		DETECT_TYPE_FALL
	};

	private void Start( ) {
		_base_pos = _center.transform.position;
		initialize( );
	}

	public void Update( ){
        if ( isRunningSomeoneAnim( ) ) {
            return;
        }
		if ( _attack ) {
			checkFlip( );
			_attack = false;
		}

		detectPlayer( );

        if ( _attack ) {
			attack( );
		} else {
            move( );
        }
	}

	private void detectPlayer( ) {
		if ( _attack ) {
			return;
		}
		if ( _player == null ) {
			return;
		}

		Vector3 player_pos = _player.transform.position;
		Vector3 mage_pos = _center.transform.position;

		float half_range_x = _detect_player_x / 2;
		float half_range_y = _detect_player_y / 2;

		if ( mage_pos.x - half_range_x < player_pos.x && player_pos.x < mage_pos.x + half_range_x &&
			 mage_pos.y - half_range_y < player_pos.y && player_pos.y < mage_pos.y + half_range_y ) {
			_attack = true;
		}
	}

	private bool decisionTurn( Transform children, DETECT_TYPE type ) {
		Vector2 vec = convPosToMapIdx( children.transform.position );
		if ( getMoveDir( ) == MOVE_ANIM.MoveRight ) {
			vec.x += 1;
		} else {
			vec.x -= 1;
		}

		bool turn = false;
		switch ( type ) {
		case DETECT_TYPE.DETECT_TYPE_FALL:
			turn = !isExistBlock( vec );
			break;

		case DETECT_TYPE.DETECT_TYPE_WALL:
			turn = isExistBlock (vec);
			break;
		}

		return turn;
	}

    private void move( ) {
		if ( !_move ) {
			return;
		}

   		bool fall = false;
		if ( decisionTurn( _under1.transform, DETECT_TYPE.DETECT_TYPE_FALL ) ) {
			if ( decisionTurn( _under2.transform, DETECT_TYPE.DETECT_TYPE_FALL ) ) {
				fall = true;
			}
		}
		bool wall = false;
		if ( decisionTurn( _center.transform, DETECT_TYPE.DETECT_TYPE_WALL ) ) {
			wall = true;
		}

		if ( fall || wall || ( _move_x <= -_move_range_left || _move_range_right <= _move_x ) ) {
			refrectDir( );
		}

		MOVE_ANIM dir = getMoveDir( );
		if ( dir == MOVE_ANIM.MoveLeft ) {
			_move_x--;
		} else {
			_move_x++;
		}

		runMoveAnim( );
		Debug.Log( "move" );
    }

    private void attack( ) {
        Vector2 dir = ( _player.transform.position - this.transform.position ).normalized;

        bool right = true;
        if ( dir.x < 0 ) {
            right = false;
        }

        SpriteRenderer render = GetComponent< SpriteRenderer >( );
        MOVE_ANIM now_dir = getMoveDir( );
        if ( right && now_dir == MOVE_ANIM.MoveLeft ) {
            render.flipX = !render.flipX;
			_turn = true;
        }
        if ( !right && now_dir == MOVE_ANIM.MoveRight ) {
            render.flipX = !render.flipX;
			_turn = true;
        }

		MageAttack fire_magic = GetComponent< MageAttack >( );
		if ( !fire_magic.isReload( ) ) {
			return;
		}

		runAttackAnim( );

		fire_magic.setDir( dir );
    }

	private void checkFlip( ) {
		if ( !_turn ) {
			return;
		}
		SpriteRenderer render = GetComponent< SpriteRenderer >( );
		render.flipX = !render.flipX;
		_turn = false;
	}

	private void OnDrawGizmos( ) {
		if ( _draw_detect_player ) {
			Gizmos.color = new Color( 1f, 0, 0, 0.3f );
			Gizmos.DrawCube( _center.transform.position, new Vector3( _detect_player_x, _detect_player_y ) );
		}

		if ( _draw_move_range ) {
			Vector3 vec = _center.transform.position;
			if ( _base_pos != new Vector3( ) ) {
				vec = _base_pos;
			}
			vec.x -= _move_range_left;

			Gizmos.color = new Color( 0, 1f, 0, 0.3f );
			Gizmos.DrawLine( vec, new Vector3( vec.x + _move_range_left + _move_range_right, vec.y ) );
		}
	}
}
