using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class ShowBlockCreatePossible : MonoBehaviour {
	[ SerializeField ] private Text _create_possible_num = null;
	[ SerializeField ] private Image _create_block = null;
	[ SerializeField ] private GameObject _mapdata = null;

	private MapData _mapdata_script = null;
	private int _edit_num = 0;

	// Use this for initialization
	private void Start ( ) {
		if ( _mapdata != null ) {
			_mapdata_script = _mapdata.GetComponent< MapData >( );
			_create_block.sprite = _mapdata_script.getPutBlockImage( ).sprite;
		}
	}

	private void Update( ) {
		if ( _mapdata_script == null ) {
			return;
		}

		if ( !_mapdata_script.isEditMode( ) ) {
			return;
		}

		if ( _mapdata_script._edit_num == _edit_num ) {
			return;
		}

		_edit_num = _mapdata_script._edit_num;
		_create_possible_num.text = _mapdata_script._edit_num.ToString( );
	}
}
