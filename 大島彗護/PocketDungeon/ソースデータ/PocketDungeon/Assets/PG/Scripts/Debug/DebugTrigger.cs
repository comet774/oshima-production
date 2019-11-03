using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class DebugTrigger : MonoBehaviour {
	
	[ SerializeField ] private float _radius = 0.5f;
	private float _time;

	private void Update( ) {
		bool hit = false;
		for ( int i = 0; i < Input.touchCount; i++ ) {
			Touch touch = Input.GetTouch( i );
			Vector2 touch_pos = Camera.main.ScreenToWorldPoint( touch.position );
			float a = touch_pos.x - this.transform.position.x;
			float b = touch_pos.y - this.transform.position.y;
			if ( a * a + b * b <= _radius * _radius ) {
				_time += Time.deltaTime;
				hit = true;
				break;
			}
		}

		if ( !hit ) {
			_time = 0;
		}
	}

	public float getTime( ) {
		return _time;
	}

	private void OnDrawGizmos( ) {
		Gizmos.DrawSphere( this.transform.position, _radius );
	}
}
