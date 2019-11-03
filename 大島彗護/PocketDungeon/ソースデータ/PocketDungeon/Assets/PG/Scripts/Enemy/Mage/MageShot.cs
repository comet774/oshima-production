using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MageShot : MonoBehaviour {
	private bool _exist = true;
	private const string PLAYER_TAG = "Player";
	private const string NONE_TAG = "Untagged";

	[ SerializeField ] private List< string > _ignore_tag = new List< string >( );

	public bool isExist( ) {
		return _exist;
	}

	private void OnTriggerEnter2D( Collider2D collision ) {
		// tagが設定されてないものは無視
		string object_tag = collision.gameObject.tag;
		if ( object_tag == NONE_TAG ) {
			return;
		}

		foreach ( string tag in _ignore_tag ) {
			if ( object_tag == tag ) {
				return;
			}
		}
		_exist = false;
	}

	private void OnBecameInvisible( ) {
		_exist = false;
	}
}
