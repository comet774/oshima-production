using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GoolPoint : MonoBehaviour {

	void OnTriggerEnter2D( Collider2D other ) {
		GameObject obj = other.gameObject;
		Destroy( obj );
	}
}
