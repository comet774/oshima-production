using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Player : MonoBehaviour {

	public float walk_speed = 50.0f;
    public float flight_speed = 70.0f;
	public float jump_power = 250.0f;
	public float magic_speed = 2.0f;
	public float max_speed = 10.0f;

	public GameObject _land_point = null;
    private LandPoint _lnd_p;

	public GameObject _pre_edit_effect = null;
	public GameObject _pre_effect_fire = null;
	public GameObject _pre_effect_ice  = null;
	public GameObject _pre_effect_thunder = null;

	bool _is_operatable = true;
	bool _is_end = false;
	public Animator _anim;
	public Transform _goal_point;
	public int _goal_flame = 60;


	public AudioSource _audio;
	public AudioClip _audio_jump;
	public AudioClip _audio_damage;

	public enum p_anim {
		stop,
		walk_right,
		walk_left,
	};

	// private
	enum PlayerState {
		wait,
		walk,
		jump,
	};
	enum AnimState {
		player_wait,
		player_walk,
	}

	public enum HavingWand {
		none,
		fire,
		ice,
		thunder,
	}


	// object buffer
	GameObject _obj_edit_effect = null;

	// 持ち物
	HavingWand _have_wand = HavingWand.none;
	public bool _have_key = false;

	bool f_walk_right = false;
	bool f_walk_left = false;

	bool _dir_is_right = true;

	Rigidbody2D rb;
	// Use this for initialization
	void Start () {
		rb = GetComponent<Rigidbody2D>( );
		NodeManager.inputValue( NodeManager.INIT_TAG.PLAYER_WALK_SPEED  , ref walk_speed );
		NodeManager.inputValue( NodeManager.INIT_TAG.PLAYER_FLIGHT_SPEED, ref flight_speed );
		NodeManager.inputValue( NodeManager.INIT_TAG.PLAYER_JUMP_POWER  , ref jump_power );
        _lnd_p = _land_point.GetComponent< LandPoint >( );
	}
	
	// Update is called once per frame
	void Update () {
		// 下に２行　デバッグよう
		//if ( Input.GetKey (KeyCode.RightArrow) ) { f_walk_right = true; } else { f_walk_right = false; };
		//if ( Input.GetKey (KeyCode.LeftArrow) ) { f_walk_left = true; } else { f_walk_left = false; };

		if ( _is_operatable ) {
			updateInput ();
		}

		// 速度制限
		Vector2 velocity_buf = rb.velocity;
		if ( velocity_buf.x < -max_speed ) {
			velocity_buf.x = -max_speed;
			rb.velocity = velocity_buf;
		}
		if ( velocity_buf.x > max_speed ) {
			velocity_buf.x = max_speed;
			rb.velocity = velocity_buf;
		}

	}

	void updateInput( ) {

        float speed = walk_speed;

        bool landing = _lnd_p._is_landing;
        if(!landing)
        {
            speed = flight_speed;
        }

		if ( f_walk_right ) {
			rb.AddForce( new Vector2( speed, 0f ) );
		}
		if ( f_walk_left ){
			rb.AddForce( new Vector2( -speed, 0f ) );
		}
		if ( Input.GetKeyDown( KeyCode.UpArrow ) ) {
			jump();
		}

		if (Input.GetKeyDown( KeyCode.Z ) ) {
			action();
		}
	}

	public void walkRight( ){
		if ( _is_operatable ) {
			f_walk_right = true;
			_dir_is_right = true;
			_anim.SetBool( "walk", true );
			Vector3 scale = transform.localScale;
			if ( scale.x < 0 ) {
				scale.x *= -1;
				transform.localScale = scale;
			}
		}
	}

	public void walkLeft( ){
		if (_is_operatable) {
			f_walk_left = true;
			_dir_is_right = false;
			_anim.SetBool ("walk", true);
			Vector3 scale = transform.localScale;
			if (scale.x > 0) {
				scale.x *= -1;
				transform.localScale = scale;
			}
		}
	}

	public void jump( ){
		if ( _is_operatable ) {
            if ( _lnd_p._is_landing ) {
				rb.AddForce( new Vector2( 0f, jump_power ) );
				_audio.PlayOneShot( _audio_jump );
            }
		}
	}
	public void action( ) {
		if (_is_operatable) {
			if (_have_wand != HavingWand.none) {
				GameObject use_effect = null;
				if (_have_wand == HavingWand.fire) {
					use_effect = _pre_effect_fire;
				} else if (_have_wand == HavingWand.ice) {
					use_effect = _pre_effect_ice;
				} else if (_have_wand == HavingWand.thunder) {
					use_effect = _pre_effect_thunder;
				}

				GameObject clone = null;
				if (_dir_is_right) {
					use_effect.GetComponent<SpriteRenderer> ().flipX = false;
					clone = Instantiate (use_effect, transform.position + new Vector3 (0.5f, 0, 0), transform.rotation);
					clone.GetComponent< Magic > ().setVec (new Vector2 (magic_speed, 0));
				} else {
					use_effect.GetComponent<SpriteRenderer> ().flipX = true;
					clone = Instantiate (use_effect, transform.position + new Vector3 (-0.5f, 0, 0), transform.rotation);
					clone.GetComponent< Magic > ().setVec (new Vector2 (-magic_speed, 0));
				}
				if ( clone != null ) {
					SceneManagement.moveObjectToActiveScene( clone );	
				}
				deleteWand ();
			}
		}
	}

	public void stopWalk( ) {
		if (_is_operatable) {
			f_walk_right = false;
			f_walk_left = false;
			_anim.SetBool ("walk", false);
		}
	}

	void OnCollisionEnter2D( Collision2D other ) {

		Wand buf_wand = other.gameObject.GetComponent< Wand >( );
		if ( buf_wand != null ) {
			_have_wand = buf_wand._wand_kind;
			Destroy( other.gameObject );
		}

		if ( _have_key == false ) {
			if ( other.gameObject.tag == "key" ) {
				_have_key = true;
				Destroy( other.gameObject );
			}
		}
	}
		

	private void deleteWand( ) {
		_have_wand = HavingWand.none;
	}

	public void OnDestroy( ) {
		//GetComponent< SceneAction > ().sceneChange ();
	}

	public void setEffectEdit( bool flag ) {
		if ( _pre_edit_effect != null ) {
			if ( flag ) {
				if ( _obj_edit_effect == null ) {
					_obj_edit_effect = Instantiate( _pre_edit_effect, transform.position, transform.rotation );
					_obj_edit_effect.transform.parent = transform;
					_obj_edit_effect.transform.localPosition = new Vector3(
						0,
						-0.25f,
						0
					);
				}
			} else {
				if ( _obj_edit_effect != null ) {
					Destroy( _obj_edit_effect );
					_obj_edit_effect = null;
				}
			}
		}
	}

	public void die( ) {
		//Destroy( this.gameObject );
		//
		//if ( _retry_popup ) {
		//	Popup popup = _retry_popup.GetComponent< Popup >( );
		//	popup.activePopup( );
		//}
	}

	public bool isWand( HavingWand wand ) {
		return ( wand == _have_wand );
	}

	public void setAnim ( p_anim anim ) {
		if ( p_anim.stop == anim ) {
			_anim.SetBool ("walk", false);
		}
		if ( p_anim.walk_left == anim ) {
			f_walk_left = true;
			_dir_is_right = false;
			_anim.SetBool ("walk", true);
			Vector3 scale = transform.localScale;
			if (scale.x > 0) {
				scale.x *= -1;
				transform.localScale = scale;
			}
		}
		if ( p_anim.walk_right == anim ) {
			f_walk_right = true;
			_dir_is_right = true;
			_anim.SetBool( "walk", true );
			Vector3 scale = transform.localScale;
			if ( scale.x < 0 ) {
				scale.x *= -1;
				transform.localScale = scale;
			}
		}
	}

	public void setOperatable( bool is_operatable ) {
		if (!_is_end) {
			_is_operatable = is_operatable; 
		}
	}
	public void setEnd( ) {
		_is_operatable = false;
		_is_end = true;
	}

	public bool getEnd( ) { 
		return _is_end;	
	}
}
