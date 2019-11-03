using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MageAttack : MonoBehaviour {
	[ SerializeField ] private GameObject _shot = null;
	[ SerializeField ] private float _speed = 0.1f;
    [ SerializeField ] private int RELOAD_TIME = 5;

	private Vector2 _shot_dir = new Vector2( );
	private GameObject _clone;
    private float _reloading_time = 999.999f;

    void Start( ) {
        NodeManager.inputValue( NodeManager.INIT_TAG.MAGE_MAGIC_SPEED, ref _speed );
    }
	private void Update( ) {
        reload( );

		if ( _clone == null ) {
			return;
		}

		if ( !_clone.GetComponent< MageShot >( ).isExist( ) ) {
			Destroy( _clone );
			return;
		}

		Rigidbody2D rb = _clone.GetComponent< Rigidbody2D >( );
		rb.AddForce( _shot_dir * _speed );
	}

    private void reload ( ){
         _reloading_time += Time.deltaTime;
    }

	public void setDir( Vector2 dir ) {
		_shot_dir = dir;
		createShot( );
	}

	private void createShot( ) {
		_clone = Instantiate( _shot, this.gameObject.transform.position, Quaternion.FromToRotation( Vector3.right, _shot_dir ) );
        _reloading_time = 0.0f;
		SceneManagement.moveObjectToActiveScene( _clone );
	}

	public bool isReload( ) {
		return ( _clone == null && _reloading_time > RELOAD_TIME );
	}
}
