using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Wand : MonoBehaviour {

	public GameObject _effect = null;

	public Player.HavingWand _wand_kind;

	// Use this for initialization
	void Start () {

	}
	
	// Update is called once per frame
	void Update () {
		
	}
	/*
	public void action( Vector3 pos ) {
		if ( _effect != null ) {
			Instantiate( _effect, pos, new Quaternion( ) );
		}
	}
	public void action( Vector3 pos, Vector2 vec ) {
		if ( _effect != null ) {
			GameObject obj = Instantiate( _effect, pos, new Quaternion( ) );
			obj.GetComponent< Magic >().setVec( vec );
		}
	}
	*/
}
