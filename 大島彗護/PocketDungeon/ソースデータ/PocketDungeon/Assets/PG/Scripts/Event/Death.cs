using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Death : MonoBehaviour {
	public GameObject _player;
	public AudioClip AC;
	public AudioSource AS;
	public GameObject _retry_popup = null;
	public GameObject LeftSide;
	public GameObject RightSide;

	const string ENEMY_TAG = "Enemy";
	const string THORN_TAG = "Thorn";
	const string MAGE_SHOT_TAG = "MageShot";
	private List< string > _death_tags = new List< string > ( ) { ENEMY_TAG, THORN_TAG, MAGE_SHOT_TAG };

	public GameCanvasCaver _game_canvas;
	[ SerializeField ] private int _active_retry_frame = 0;
	bool _die = false;

	void OnCollisionEnter2D( Collision2D other ) {
		if ( !isKill( other.gameObject ) ) {
			return;
		}

		AS.PlayOneShot( AC );
		die( );
	}

	private void OnTriggerEnter2D( Collider2D other ) {
		if ( !isKill( other.gameObject ) ) {
			return;
		}

		AS.PlayOneShot( AC );
		die( );
	}
	private bool isKill( GameObject hit_obj ) {
		if ( _die ) {
			return false;
		}
		string tag = hit_obj.tag;

		bool kill = false;
		foreach ( string get_tag in _death_tags ) {
			if ( tag == get_tag ) {
				kill = true;
				break;
			}
		}

		if ( !kill ) {
			return false;
		}

		if ( tag == ENEMY_TAG && hit_obj.gameObject.GetComponent< Enemy >( ).isFrozen( ) ) {
			return false;
		}

		return true;
	}

	// Use this for initialization
	void Start () {
		_active_retry_frame = 0;
	}
	
	// Update is called once per frame
	void Update () {
		if(_active_retry_frame == 20) {
			MakePopUp();
		}

		if ( _die ) {
			_active_retry_frame = _active_retry_frame + 1;
		}
	}

	private void die (){
		_game_canvas.gameObject.SetActive (false);
		_player.GetComponent< Player >( ).setEnd( );
		_player.GetComponent< Player >( ).setAnim( Player.p_anim.stop );
		//_player.GetComponent< Rigidbody2D >( ).isKinematic = true;
		this.gameObject.transform.rotation = Quaternion.FromToRotation( Vector3.up, new Vector2( 1, 0 ) );
		_player.GetComponent< Player >( ).setAnim( Player.p_anim.stop );
		LeftSide.SetActive( false );
		RightSide.SetActive( false );
		_die = true;
	}

	public void MakePopUp( ) {
		if ( _retry_popup ) {
			Popup popup = _retry_popup.GetComponent< Popup >( );
			popup.activePopup( );
		}
	}
}
