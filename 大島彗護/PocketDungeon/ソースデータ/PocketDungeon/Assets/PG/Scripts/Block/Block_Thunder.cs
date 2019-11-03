using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Block_Thunder : MonoBehaviour {

	const int ONE_SECOND = 1;
	const int FINISH_SECOND = 2;

	public bool _flag;
	bool _energization;

	double total_time;
	int total_seconds;

	// Use this for initialization
	void Start ( ) {
		_flag = false;
		_energization = false;
	}
	
	// Update is called once per frame
	void Update ( ) {
		if ( !_flag ) {
			if ( total_time > 0 || total_seconds > 0 ) {
				total_time = 0;
				total_seconds = 0;
			}
			return;
		}

		countTimer( );

		if ( total_seconds >= ONE_SECOND ) {
			_energization = true;	
		}

		if ( total_seconds > FINISH_SECOND ) {
			_flag = false;
			_energization = false;
		}
	}

	void OnTriggerEnter2D( Collider2D other ) {
		if ( other.gameObject.tag == "ThunderBall" ) {
			_flag = true;
			_energization = true;
			total_time = 1;
		}
	}

	public void setFlag( bool flag ) {
		_flag = flag;
	}

	public	bool getFlag ( ) {
		return _flag;
	}

	public	bool getElergization ( ) {
		return _energization;
	}

	void countTimer( ) {
		total_time += Time.deltaTime;
		total_seconds = ( int )total_time;
	}
}
