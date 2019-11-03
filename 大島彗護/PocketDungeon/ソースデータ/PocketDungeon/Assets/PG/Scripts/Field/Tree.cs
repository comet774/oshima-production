using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Tree : MonoBehaviour {

	public GameObject _burn;

	public int _burn_time = 60;

	SpriteRenderer _main_sprite;
	bool _is_burning = false;

	// Use this for initialization
	void Start () {
		_burn.SetActive( false );
	}
	
	// Update is called once per frame
	void Update () {
		if ( _is_burning ) {
			_burn_time--;
			if (_burn_time < 0) {
				Destroy (transform.gameObject);
			}
		}
		
	}

	void OnTriggerEnter2D( Collider2D other ) {
		if (other.gameObject.tag == "FireBall") {
			_is_burning = true;
			_burn.SetActive( true );
		}
	}
}
