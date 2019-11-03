using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System;

public class EventGoal : MonoBehaviour {

	public GameObject _player;
	public GameObject _gool_door;

	public float _player_speed = 0.1f;
	public int _door_open_speed = 60;
	public int _end_buf_frame = 10;

	public AudioSource _audio;
	public AudioClip _sound_clear;

	public bool _is_active = false;

	int _frame = 0;
	int _frame_player_move = 0;
	int _frame_door_close = 0;

	bool _player_move_end = false;

	public GameCanvasCaver _game_canvas;

	// Use this for initialization
	void Start () {
		
	}
	
	// Update is called once per frame
	void Update () {
		if ( _is_active ) {
			if ( _frame == 0 ) {
				init ();
			}
			if ( _frame == _door_open_speed ) {
				_gool_door.GetComponent< Door > ().OpenHalf();
			}
			if (_frame == _door_open_speed * 2) {
				_gool_door.GetComponent< Door > ().Open ();
			}

			if ( !_player_move_end && _frame > _door_open_speed * 2 ) {
				Vector3 p_to_gool = _gool_door.transform.position - _player.transform.position;
				Vector3 next = _player.transform.position;
				if ( Math.Abs( p_to_gool.x )  > _player_speed ) {
					if (_frame_player_move == 0) {
						_player.GetComponent< Animator > ().SetBool ("walk", true);
					}

					if ( p_to_gool.x > 0 ) {
						next.x = next.x + _player_speed;
					} else {
						next.x = next.x - _player_speed;
					}

				} else {
					_player.GetComponent< Animator > ().SetBool ("walk", false);
					_player.SetActive (false);
					_player_move_end = true;
				}

				_player.transform.position = next;
				_frame_player_move++;
			}

			if ( _player_move_end ) {
				if ( _frame_door_close == _door_open_speed ) {
					_gool_door.GetComponent< Door > ().OpenHalf ();
				}
				if ( _frame_door_close == _door_open_speed * 2 ) {
					_gool_door.GetComponent< Door > ().Close ();
				}
				if ( _frame_door_close >= _door_open_speed * 2 + _end_buf_frame ) {
					end ();
				}

				_frame_door_close++;
			}


			_frame++;
		}
	}
	private void init( ) {
		_player.GetComponent< Player > ().setEnd( );
		_player.GetComponent< Animator >( ).SetBool ("walk", false );
		_audio.PlayOneShot (_sound_clear);
		_game_canvas.gameObject.SetActive (false);
	}

	private void end( ) {
		GetComponent< SceneAction > ().changeScene ();
	}
}
