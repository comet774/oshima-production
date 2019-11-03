 using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Slime : Enemy {
	public bool _draw_move_range = false;

	[ SerializeField ] private GameObject _center = null;
	[ SerializeField ] private GameObject _under1 = null;
	[ SerializeField ] private GameObject _under2 = null;
	[ SerializeField ] private int _move_range_left  = 3;
	[ SerializeField ] private int _move_range_right = 3;

	private Vector3 _base_pos = new Vector3( );
	private int _move_x = 0;

	enum DETECT_TYPE {
		DETECT_TYPE_WALL,
		DETECT_TYPE_FALL
	};

	private void Start( ) {
		_base_pos = _center.transform.position;
		initialize( );
	}

	public void Update( ) {
		if ( isRunningSomeoneAnim( ) ) {
			return;
		}
		move( );
	}

	private void move( ) {
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

	private void OnDrawGizmos( ) {
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
