using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Trigger : MonoBehaviour {
	public bool _colliding = false;
	public GameObject _batu_mark;

	private bool _is_draw = false;
	// Use this for initialization
	//void Start ( ) {
	//}
	
	// Update is called once per frame
	//void Update ( ) {
		/*
		if (_is_draw && _colliding ) {
			_batu_mark.SetActive (true);
		} else {
			_batu_mark.SetActive (false);
		}
		*/
	//}

	void OnTriggerEnter2D( Collider2D other ) {
		_colliding = true;
	}
	void OnTriggerStay2D( Collider2D other ) {
		_colliding = true;
	}

	void OnTriggerExit2D( Collider2D other ) {
		_colliding = false;
	}

	//void setActiveBatuMark( bool active ) {
	//	_batu_mark.SetActive ( active );
	//}
	public void setDraw( bool is_draw ) {
		_is_draw = is_draw;
	}
}
