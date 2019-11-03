using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Door : MonoBehaviour {

	public SpriteRenderer _sp_rend;

	public Sprite _open;
	public Sprite _open_falf;
	public Sprite _close;

	public EventGoal _gool_event = null;
	// Use this for initialization

	public void Open( ) {
		_sp_rend.sprite = _open;
	}
	public void OpenHalf( ) {
		_sp_rend.sprite = _open_falf;
	}
	public void Close( ) {
		_sp_rend.sprite = _close;
	}

	void OnTriggerEnter2D( Collider2D other ) {
		if (other.gameObject.tag == "Player") {
			if ( _gool_event != null ) {
				_gool_event._is_active = true;
			}
		}
	}
}
