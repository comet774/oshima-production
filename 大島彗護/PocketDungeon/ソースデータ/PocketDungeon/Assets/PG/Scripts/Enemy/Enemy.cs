using System.Collections;
using System.Collections.Generic;
using UnityEngine;

[ RequireComponent( typeof( Rigidbody2D ) ) ]
[ RequireComponent( typeof( BoxCollider2D ) ) ]
public class Enemy : MonoBehaviour {
	
	private const string TAG_PLAYER = "Player";
	private const string TAG_FIRE_BALL = "FireBall";
	private const string TAG_ICE_BALL  = "IceBall";
	private const string TAG_THUNDER_BALL = "ThunderBall";

	private const string TAG_CONDITION_PARALYSIS = "Paralysis";
	private const string TAG_CONDITION_FROZEN = "Frozen";

	// enum
	protected enum MOVE_ANIM {
		MoveRight,
		MoveLeft,
	}

	protected enum ACTION_ANIM {
		Attack,
	};

	private enum CONDITION_ANIM {
		ConditionNone,
		ConditionFrozen,
		ConditionFire,
		ConditionParalysis,
	};


	// arg
	public GameObject _map;
	private MOVE_ANIM _move_anim;
	private ACTION_ANIM _action_anim;
	private CONDITION_ANIM _condition_anim = CONDITION_ANIM.ConditionNone;
	private string _run_anim;
	private bool _frozen = false;
	private bool _paralysis = false;
	[ SerializeField ] private List< string > _resist = new List< string >( );

	private Animator _anim;
	private BoxCollider2D _frozen_collider;
	private Rigidbody2D _rb;

	// script
	private MapData _data;


	// function //
	protected void initialize( ) {
		_anim = GetComponent< Animator >( );
		_move_anim = MOVE_ANIM.MoveLeft;
		_data = _map.GetComponent< MapData >( );
		_frozen_collider = GetComponent< BoxCollider2D >( );
		_frozen_collider.enabled = false;
		_rb = GetComponent< Rigidbody2D >( );
	}

	protected void setMoveDir( MOVE_ANIM dir ) {
		_move_anim = dir;
	}
	
	protected MOVE_ANIM getMoveDir( ) {
		return _move_anim;
	}

	protected void refrectDir( ) {
		MOVE_ANIM before = this.getMoveDir( );
		MOVE_ANIM result = before;
		switch ( before ) {
			case MOVE_ANIM.MoveLeft:
				result = MOVE_ANIM.MoveRight;
				break;

			case MOVE_ANIM.MoveRight:
				result = MOVE_ANIM.MoveLeft;
				break;
		}
		SpriteRenderer renderer = GetComponent< SpriteRenderer >( );
		renderer.flipX = !renderer.flipX;
		setMoveDir( result );
	}
	
	protected void runMoveAnim( ) {
		string anim_string = _move_anim.ToString( );
		_anim.Play( anim_string, 0, 0.0f );

		_run_anim = anim_string;
	}

	protected void runAttackAnim( ) {
		_anim.Play( ACTION_ANIM.Attack.ToString( ), 0, 0.0f );
		_action_anim = ACTION_ANIM.Attack;
		_run_anim = _action_anim.ToString( );
	}

	private void runConditionAnim( CONDITION_ANIM condition ) {
		_anim.Play( condition.ToString( ), 0, 0.0f );
		_condition_anim = condition;
		_run_anim = _condition_anim.ToString( );

		if ( condition == CONDITION_ANIM.ConditionFire ) {
			return;
		}

		// 炎以外は特殊処理
		_frozen = false;
		_paralysis = false;
		_frozen_collider.enabled = false;
		_rb.constraints = RigidbodyConstraints2D.None;

		if ( condition == CONDITION_ANIM.ConditionFrozen ) {
			_frozen = true;
			_frozen_collider.enabled = true;
			_rb.constraints = RigidbodyConstraints2D.FreezeAll;
		}
		if ( condition == CONDITION_ANIM.ConditionParalysis ) {
			_paralysis = true;
			_rb.constraints = RigidbodyConstraints2D.FreezeAll;
		}
	}

	public bool isRunningSomeoneAnim( ) {
		var info_action = _anim.GetCurrentAnimatorStateInfo( 0 );
	
		bool run = false;
		if ( info_action.normalizedTime < 1 ) {
			run = true;
		}
		if ( _frozen || _paralysis ) {
			run = true;
		}
		
		return run;
	}

	protected Vector2 convPosToMapIdx( Vector3 pos ){
		Vector2 idx = _data.getIDXFromPos( pos );
		return idx;
	}

	protected bool isExistBlock( Vector2 idx ){
		Transform obj = _data.getBlockTransform( idx );
		// ブロックがなければ
		bool exist = true;
		if ( obj == null ) {
			exist = false;
		}
		return exist;
	}


	void OnCollisionEnter2D( Collision2D other ) {
		if ( isRunningSomeoneAnim( ) && _run_anim == CONDITION_ANIM.ConditionFire.ToString( ) ) {
			return;
		}

		if ( _frozen ) {
			return;
		}

		if ( other.gameObject.tag == TAG_PLAYER ) {
			Player player = other.gameObject.GetComponent< Player >( );
			player.die( );
		}
	}

	void OnTriggerEnter2D( Collider2D collider ) {
		string object_tag = collider.gameObject.tag;
		if ( object_tag != TAG_FIRE_BALL &&
			 object_tag != TAG_ICE_BALL  &&
			 object_tag != TAG_THUNDER_BALL ) {
			return;
		}

		int count = _resist.Count;
		bool resist = false;
		for ( int i = 0; i < count; i++ ) {
			if ( _resist[ i ] == collider.tag ) {
				resist = true;
				break;
			}
		}

		// 球を消す
		Destroy( collider.gameObject );

		if ( resist ) {
			return;
		}

		// 状態以上のアニメーションをする
		if ( object_tag == TAG_FIRE_BALL ) {
			runConditionAnim( CONDITION_ANIM.ConditionFire );
		}

		if ( object_tag == TAG_ICE_BALL ) {
			runConditionAnim( CONDITION_ANIM.ConditionFrozen );
		}

		if ( object_tag == TAG_THUNDER_BALL ) {
			runConditionAnim( CONDITION_ANIM.ConditionParalysis );
		}
	}

	public bool isFrozen( ) {
		return _frozen;
	}

	public void die( ) {
		Destroy( this.gameObject );
	}
}
