using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class LandPoint : MonoBehaviour {
	public bool _is_landing = false;
	// Use this for initialization
	void Start () {
		
	}
	
	// Update is called once per frame
	void Update () {
		
	}

	void OnTriggerStay2D( Collider2D other ) {
		if (other.isTrigger == false && other.gameObject.tag != "Wand" ) {
			_is_landing = true;
		}
	}
	void OnTriggerExit2D( Collider2D other ) {
		if (other.isTrigger == false) {
			_is_landing = false;
		}
	}
}
