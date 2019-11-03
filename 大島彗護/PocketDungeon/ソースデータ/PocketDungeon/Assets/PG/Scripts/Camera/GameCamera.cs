using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GameCamera : MonoBehaviour {
	const int DRAW_RANGE = 5;
	const double LITTLE_ERROR = 0.1;
	const int STANDARD_X = 16;
	const int STANDARD_Y = 12;

	enum CAMERA_STATE {
		CAMERA_STATE_NORMAL,
		CAMERA_STATE_SCROLL,
		CAMERA_STATE_COME_BACK,
		CAMERA_STATE_STOP
	}

	public Camera _camera;
	public GameObject _target;
	public MapData _map;

	public float buf_x = 3;
	public float buf_y = 3;

	public int rec_x = STANDARD_X;
	public int rec_y = STANDARD_Y;


	Vector2 _map_size;

	Vector3 before_pos = new Vector3( 0, 0, 0 );
	Vector3 scroll_range;
	CAMERA_STATE camera_state = CAMERA_STATE.CAMERA_STATE_NORMAL;
	CAMERA_STATE stop_state = CAMERA_STATE.CAMERA_STATE_NORMAL;
	// Use this for initialization
	void Start ( ) {
		_map_size = _map.getSize ( );
	}
	
	// Update is called once per frame
	void Update ( ) {
		Vector3 truth_pos = Input.mousePosition;
		Vector3 mouse_pos = _camera.ScreenToWorldPoint( truth_pos );
		//マウス操作
		bool th = Input.GetKeyDown( KeyCode.Mouse0 );
		bool push = Input.GetMouseButton( 0 );

		//タッチ操作
	//	th = ( 0 != Input.touchCount );
	//	if (th) {
	//		mouse_pos = _camera.ScreenToWorldPoint(Input.touches[0].deltaPosition);
	//	}

		if ( _map_size.x > STANDARD_X || _map_size.y > STANDARD_Y ) {
			if ( th && ( -3 < mouse_pos.y - _camera.transform.position.y && !( mouse_pos.y - _camera.transform.position.y > 3 && mouse_pos.x - _camera.transform.position.x < -5 ) ) &&
				camera_state == CAMERA_STATE.CAMERA_STATE_NORMAL ) {
				camera_state = CAMERA_STATE.CAMERA_STATE_SCROLL;
			}
		}
		if( th ) {
			Debug.Log( mouse_pos - _camera.transform.position );
		}
		if (camera_state == CAMERA_STATE.CAMERA_STATE_NORMAL) {
			_target.GetComponent<Player> ( ).setOperatable( true );
		} else {
			_target.GetComponent<Player> ( ).setOperatable ( false );
		}

		if( _target.GetComponent<Player>( ).getEnd( ) ) { 
			return;
		}

		switch( camera_state ) { 
			case CAMERA_STATE.CAMERA_STATE_NORMAL:
				normal( );
				break;
			case CAMERA_STATE.CAMERA_STATE_SCROLL:
				if ( push ) {
					scroll( mouse_pos );
				} else { 
					before_pos = new Vector3( 0, 0, 0 );
					if ( scroll_range != new Vector3 ( 0, 0, 0 ) ) {
						inertia( );
					}
				}
				break;
			case CAMERA_STATE.CAMERA_STATE_COME_BACK:
				come_back( );
				break;
			case  CAMERA_STATE.CAMERA_STATE_STOP:
				break;
			default:
				break;
		}

		Vector3 m_to_c = _camera.transform.position - _map.transform.position;
		if ( m_to_c.x < rec_x / 2 ) {
			_camera.transform.position = new Vector3(
				_map.transform.position.x + rec_x / 2,
				_camera.transform.position.y,
				_camera.transform.position.z
			);
		}
		else if ( m_to_c.x > _map_size.x - rec_x / 2 ) {
			_camera.transform.position = new Vector3(
				_map.transform.position.x + ( _map_size.x - rec_x / 2 ),
				_camera.transform.position.y,
				_camera.transform.position.z
			);
		}
		if ( m_to_c.y < rec_y / 2 ) {
			_camera.transform.position = new Vector3 (
				_camera.transform.position.x,
				_map.transform.position.y + rec_y / 2,
				_camera.transform.position.z
			);
		}
		else if ( m_to_c.y > _map_size.y - rec_y / 2 ) {
			_camera.transform.position = new Vector3 (
				_camera.transform.position.x,
				_map.transform.position.y + ( _map_size.y - rec_y / 2 ),
				_camera.transform.position.z
			);
		}
	}

    void normal( ) { 
    	Vector3 c_to_p = _target.transform.position - _camera.transform.position;
		if ( c_to_p.x > rec_x / 2 - buf_x ) { // right
			_camera.transform.position = 
				new Vector3( 
					_target.transform.position.x - ( rec_x / 2 - buf_x ),
					_camera.transform.position.y,
					_camera.transform.position.z
				);
		} else if ( c_to_p.x < rec_x / -2 + buf_x ) { // left
			_camera.transform.position = 
				new Vector3 (
					_target.transform.position.x + ( rec_x / 2 - buf_x ),
					_camera.transform.position.y,
					_camera.transform.position.z
				);
		}
		if ( c_to_p.y > rec_y / 2 - buf_y ) { //  ue
			_camera.transform.position = new Vector3 (
				_camera.transform.position.x,
				_target.transform.position.y - ( rec_y / 2 - buf_y ),
				_camera.transform.position.z
			);
		} else if ( c_to_p.y < rec_y / -2 + buf_y ) { // under
			_camera.transform.position = new Vector3 (
				_camera.transform.position.x,
				_target.transform.position.y + ( rec_y / 2 - buf_y ),
				_camera.transform.position.z
			);
		}
    }

    void scroll( Vector3 mouse_pos ) {
		if ( before_pos == new Vector3( 0, 0, 0 ) ) { 
			before_pos = mouse_pos;
			return;
		}

		scroll_range = mouse_pos - before_pos;

		if (scroll_range.x > LITTLE_ERROR || scroll_range.x < -LITTLE_ERROR) {
			_camera.transform.position = new Vector3 (
				_camera.transform.position.x - scroll_range.x,
				_camera.transform.position.y,
				_camera.transform.position.z
			);
		}
		if ( scroll_range.y > LITTLE_ERROR || scroll_range.y < -LITTLE_ERROR ) {
			_camera.transform.position = new Vector3(
				_camera.transform.position.x,
				_camera.transform.position.y - scroll_range.y,
				_camera.transform.position.z
			);
		} 
		before_pos = mouse_pos - scroll_range;
	}

	void inertia( ) {
		_camera.transform.position -= scroll_range; 

		if ( scroll_range.x > 0 ) {
			scroll_range.x -= ( float )0.1;
			if (scroll_range.x < 0) {
				scroll_range.x = 0;
			}
		} else if( scroll_range.x < 0 ) {
			scroll_range.x += ( float )0.1;
			if (scroll_range.x > 0) {
				scroll_range.x = 0;
			}
		}

		if ( scroll_range.y > 0 ) {
			scroll_range.y -= ( float )0.1;
			if (scroll_range.y < 0) {
				scroll_range.y = 0;
			}
		} else if( scroll_range.y < 0 ) {
			scroll_range.y += ( float )0.1;
			if (scroll_range.y > 0) {
				scroll_range.y = 0;
			}
		}
	}

    void come_back( ) {
		Vector3 c_to_p = _target.transform.position - _camera.transform.position;

		if ( c_to_p.x > DRAW_RANGE ) { 
			_camera.transform.position = new Vector3(
				_camera.transform.position.x + ( float )0.5,
				_camera.transform.position.y,
				_camera.transform.position.z
			);
		} else if ( c_to_p.x < -DRAW_RANGE ) {
			_camera.transform.position = new Vector3(
				_camera.transform.position.x - ( float )0.5,
				_camera.transform.position.y,
				_camera.transform.position.z
			);
		}
		if ( c_to_p.y > DRAW_RANGE ) {
			_camera.transform.position = new Vector3(
				_camera.transform.position.x,
				_camera.transform.position.y + ( float )0.5,
				_camera.transform.position.z
			);
		} else if ( c_to_p.y < -DRAW_RANGE ) {
			_camera.transform.position = new Vector3(
				_camera.transform.position.x,
				_camera.transform.position.y - ( float )0.5,
				_camera.transform.position.z
			);
		}

		Vector3 m_to_c = _camera.transform.position - _map.transform.position;
		bool correct_x = c_to_p.x < DRAW_RANGE && c_to_p.x > -DRAW_RANGE;
		bool correct_y = c_to_p.y < DRAW_RANGE && c_to_p.y > -DRAW_RANGE;
		bool border_x = m_to_c.x < rec_x / 2 || m_to_c.x > _map_size.x - rec_x / 2; 
		bool border_y = m_to_c.y < rec_y / 2 || m_to_c.y > _map_size.y - rec_y / 2; 

		if ( ( correct_x && correct_y ) || ( border_x && correct_y ) || ( correct_x && border_y ) ) { 
			camera_state = CAMERA_STATE.CAMERA_STATE_NORMAL;
			before_pos = new Vector3( 0, 0, 0 );
		}
	}

	public void cameraComeBack( ) {
		if ( camera_state == CAMERA_STATE.CAMERA_STATE_SCROLL ) {
			camera_state = CAMERA_STATE.CAMERA_STATE_COME_BACK;
		}
	}

	public void cameraStop( ) {
		stop_state = camera_state;
		camera_state = CAMERA_STATE.CAMERA_STATE_STOP;
	}

	public void cameraRelease( ) {
		camera_state = stop_state;
	}
}
