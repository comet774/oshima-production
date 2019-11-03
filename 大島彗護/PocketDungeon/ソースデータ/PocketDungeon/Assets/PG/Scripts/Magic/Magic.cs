using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Magic : MonoBehaviour {

	public Vector3 _vec;
	public float _speed = 0;
	public MAGIC_TYPE _type;
	public AudioSource _audio;
	public AudioClip _clip_magic;

	public enum MAGIC_TYPE {
		FIRE,
		ICE,
		THUNDER
	};
	// Use this for initialization
	void Start ( ) {
		_audio.PlayOneShot( _clip_magic );
	}
	
	// Update is called once per frame
	void Update ( ) {
		transform.position = transform.position + _vec;
	}

	public void setVec( Vector2 vec ) {
		if (_speed == 0 ) {
			_vec = vec;
		} else {
			_vec = vec.normalized * _speed;
		}
	}


	void OnTriggerEnter2D ( Collider2D other ) {
		if ( other.gameObject.tag != "Player" ) {
			if (other.isTrigger == false ) {
				Destroy (transform.gameObject);
			}
		}
	}
}
