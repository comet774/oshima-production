using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class GameCanvasCaver : MonoBehaviour {

	public Player _player;
	public MapData _map;
	public Camera _camera;
	public Canvas _canvas;

	public GameObject _edit_not_change;

	public int _edit_num = 0;

    public Image _edit_button_image;
    public Sprite _image_edit_walk;
    public Sprite _image_edit_magic;

    public AudioClip _sound_block_set;
	public UnityEngine.Audio.AudioMixerGroup _mixer;

	public Image _magic_button_image;
	public Sprite _wand_fire;
	public Sprite _wand_ice;
	public Sprite _wand_thunder;

	public AudioClip _se_edit_change;
	public AudioSource _audio;

	public EventGoal _event_goal;

    /// <summary>
    /// 
    private GameCamera _g_camera;

	void Start ( ) {
		_canvas.GetComponent<Canvas> ().worldCamera = _camera;

		if (_edit_num != 0) {
			int edit_num = 0;
			NodeManager.inputValue( NodeManager.INIT_TAG.BLOCK_CREATE_NUM, ref edit_num );
			_map._edit_num = _edit_num + edit_num;
		}
        _map.setAudioClip( _sound_block_set );
		_map._audio.outputAudioMixerGroup = _mixer;
		_map._camera = _camera;

        _g_camera = _camera.gameObject.GetComponent< GameCamera > ();

		_player.gameObject.GetComponent< Death > ()._game_canvas = this.gameObject.GetComponent< GameCanvasCaver > ();
		_g_camera._target = _player.gameObject;
		_g_camera._map = _map;
		_event_goal._game_canvas = this.gameObject.GetComponent< GameCanvasCaver > ();
		_event_goal._player = _player.gameObject;
	}

	void Update( ) {
		if ( _map != null ) {
			_edit_not_change.SetActive( !_map.isEdit( ) );
		}
		updateEditNum ();
		updateActionButton ();
	}

	public void walkRight( ){
		_player.walkRight ();
	}

	public void walkLeft( ){
		_player.walkLeft ();
	}

	public void jump( ){
		_player.jump ();
	}

	public void action( ) {
		_player.action ();
	}

	public void stopWalk( ) {
		_player.stopWalk ();
	}

	public void cameraComeBack( ) {
		_g_camera.cameraComeBack( );
	}

	public void cameraStop( ) {
		_g_camera.cameraStop( );
	}

	public void changeEdit( ) {
		_map.changeEditMode ( );
		_player.stopWalk ( );
		if ( _map.isEdit( ) ) {
			_player.setEffectEdit( true );
            _edit_button_image.sprite = _image_edit_magic;
			setTriggerMarkAll ( true );
			_g_camera.cameraStop( );
		} else {
			_player.setEffectEdit( false );
            _edit_button_image.sprite = _image_edit_walk;
			setTriggerMarkAll ( false );
			_g_camera.cameraRelease( );
		}
		_audio.PlayOneShot (_se_edit_change);
	}

	public void updateEditNum ( ) {
		_edit_num = _map._edit_num;
	}

	// prirvate
	void updateActionButton( ) {
		GameObject mb_image = _magic_button_image.gameObject;
		if        ( _player.isWand( Player.HavingWand.none    ) &&    mb_image.activeSelf ) {
			mb_image.SetActive (false);
		} else if ( _player.isWand( Player.HavingWand.fire    ) && ( !mb_image.activeSelf || mb_image != _wand_fire ) ) {
			mb_image.SetActive (true);
			_magic_button_image.sprite = _wand_fire;
		} else if ( _player.isWand( Player.HavingWand.ice     ) && ( !mb_image.activeSelf || mb_image != _wand_ice ) ) {
			mb_image.SetActive (true);
			_magic_button_image.sprite = _wand_ice;
		} else if ( _player.isWand( Player.HavingWand.thunder ) && ( !mb_image.activeSelf || mb_image != _wand_thunder ) ) {
			mb_image.SetActive (true);
			_magic_button_image.sprite = _wand_thunder;
		}
	}

	void setTriggerMarkAll( bool active ) {
		//GameObject obj = _map.getTriggerMaster ();
		//for (int i = 0; i < obj.transform.childCount; i++) {
		//	obj.transform.GetChild (i).GetComponent< Trigger >( ).setDraw( active );
		//}
	}
}
