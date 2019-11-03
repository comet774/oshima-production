using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class KeyOpenDoor : MonoBehaviour {
    
	void OnCollisionEnter2D( Collision2D other ) {
		Player player = other.gameObject.GetComponent<Player>();
		if ( other.gameObject.tag == "Player" && player._have_key == true ) {
			player._have_key = false;
			Destroy( transform.gameObject );
		}
	}
}
