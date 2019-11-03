using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class MapData:MonoBehaviour {
	const int PLAYER_PUT_BLOCK_IDX = 9;
	const string SHOW_BLOCK_CREATE_NUM_TAG = "BlockCreatePossibleNum";

	public Camera _camera;

	// GameObject _waku;
	//public GameObject _floor_block;
	//public GameObject _brue_block;

	[SerializeField]
	public GameObject[] _objs;

	public float Z_POS = 0;

	public bool _start_waku_draw = true;

	public Vector2 _deb;
	public Vector3 _deb_mouse;

	public int[] _map_data;

	public int _x = 15;
	public int _y = 12;

	public int _no_touch_x = 330;
	public int _no_touch_y = 1240;

	public int _edit_num = 3;

    public  AudioSource _audio;
	//public string test;

	//  private;
    private AudioClip _sound_block_edit;

	private GameObject _waku_master;
	private GameObject _block_master;
	private GameObject _block_not_changed;/////// 
	private GameObject _trigger_master;

	private bool _edit_mode;

	[ SerializeField ] private string _option_button_tag = "OptionButton";
	private GameObject _option_button = null;
	private GameObject _show_block_create_num = null;

	MapData( ) {
	_map_data = new int[ 180 ] {
			0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
			1,1,1,1,1,1,1,1,1,1,1,1,2,1,2,
		};

	_x = 15;
	_y = 12;
	

	}
	MapData( int size ) {
		_map_data = new int[ size ];
	}

	// Use this for initialization
	void Start( ) {
		// option buttonを取得
		if ( _option_button_tag != "" ) {
			_option_button = GameObject.FindGameObjectWithTag( _option_button_tag );
		} else {
			Debug.Log( "not found [ OptionButton ]" );
		}

		// debug mode 
		int edit_num = 0;
		NodeManager.inputValue( NodeManager.INIT_TAG.BLOCK_CREATE_NUM, ref edit_num );
		_edit_num += edit_num;

		// ShowBlockCreatePossibleNumオブジェクトを取得
		_show_block_create_num = GameObject.FindGameObjectWithTag( SHOW_BLOCK_CREATE_NUM_TAG );

	////////////////////////////////////
		/// waku
		_waku_master = new GameObject( "M_waku" );
		_waku_master.transform.parent = transform;

		for( int i = 0; i < _map_data.Length; i++ ) {
			if ( _objs[ 8 ] != null ) {
				GameObject waku_c = Instantiate( _objs[ 8 ], getPosFromIDX( i % _x,i / _x ), transform.rotation );
				waku_c.name = ( i % _x ).ToString( ) + "_" + ( i / _x ).ToString( ) + "_" + "waku";
				waku_c.transform.parent = _waku_master.transform;
			}
		}

		/////////////////////////////////////
		/// block
		_block_master = new GameObject( "M_block" );
		Rigidbody2D rb2_b = _block_master.AddComponent< Rigidbody2D > ();
		rb2_b.constraints = RigidbodyConstraints2D.FreezeAll;
		_block_master.transform.parent = transform;

		for ( int i = 0; i < _map_data.Length; i++ ) {
			GameObject block_pre = null;
			for ( int j = 0; j < _objs.Length; j++ ) {
				if ( _map_data[ i ] == j ) {
					block_pre = _objs[ j ];
				}
			}
			/*
			if ( _map_data[ i ] == 1 ) {
				block_pre = _floor_block;
			} else if ( _map_data[ i ] == 2 ) {
				block_pre = _brue_block;
			} 
			*/

			if ( block_pre != null ) {
				//GameObject block_d;
				//block_d = Instantiate( block_pre, getPosFromIDX( i % _x, _y - ( i / _x ) - 1 ), transform.rotation );
				//block_d.name = ( i % _x ).ToString( ) + "_" + ( _y - ( i / _x ) - 1 ).ToString( );// + "_" + _floor_block.name;
				//block_d.transform.parent = _block_master.transform;

				createBlock( block_pre,new Vector2( i % _x,_y - ( i / _x ) - 1 ) );
			}
		}
		/////////////////////////////////////
		/// trigger
		_trigger_master = new GameObject( "M_trigger" );
		Rigidbody2D rb2_t = _trigger_master.AddComponent< Rigidbody2D > ();
		rb2_t.constraints = RigidbodyConstraints2D.FreezeAll;
		_trigger_master.transform.parent = transform;
		for ( int i = 0; i < _map_data.Length; i++ ) {
			if ( _objs[ 7 ] != null ) {
				createBlock( _objs[ 7 ], new Vector2( i % _x, _y - ( i / _x ) - 1 ), _trigger_master );
			}
		}



		GameObject obj_buf = new GameObject ( );
		obj_buf.AddComponent< BoxCollider2D > ( );
		obj_buf.transform.position = transform.position + ( new Vector3 (-0.5f, ( float )_y / 2, transform.position.z ) );
		obj_buf.transform.localScale = new Vector3( 1, _y, 1 );
		obj_buf.name = "side_left";
		obj_buf.transform.parent = transform;

		obj_buf = new GameObject ( );
		obj_buf.AddComponent< BoxCollider2D > ( );
		obj_buf.transform.position = transform.position + new Vector3( _x + 0.5f, ( float )_y / 2, transform.position.z );
		obj_buf.transform.localScale = new Vector3( 1, _y, 1 );
		obj_buf.name = "side_rigth";
		obj_buf.transform.parent = transform;

		obj_buf = new GameObject ( );
		obj_buf.AddComponent< BoxCollider2D > ( );
		obj_buf.transform.position = transform.position + new Vector3( ( float )_x / 2, 0.5f + _y, transform.position.z );
		obj_buf.transform.localScale = new Vector3( _x, 1, 1 );
		obj_buf.name = "side_up";
		obj_buf.transform.parent = transform;

		obj_buf = new GameObject ( );
		obj_buf.AddComponent< BoxCollider2D > ( );
		obj_buf.transform.position = transform.position + new Vector3( (float)_x / 2, -0.5f, transform.position.z );
		obj_buf.transform.localScale = new Vector3( _x, 1, 1 );
		obj_buf.name = "side_under";
		obj_buf.transform.parent = transform;


		// change_buffer
		_block_not_changed = new GameObject( "M_buf" );
		_block_not_changed.transform.parent = transform;

		changeEditMode( false );
	}

	//-//-//-//-//-//-//-//-//-//-//-//-//-//-//-//-//-//-//-//-//-//-//-//-//-//-//-//-//
	//-//-//-//-//-//-//-//-//-//-//-//-//-//-//-//-//-//-//-//-//-//-//-//-//-//-//-//-//
	//-//-//-//-//-//-//-//-//-//-//-//-//-//-//-//-//-//-//-//-//-//-//-//-//-//-//-//-//
	// Update is called once per frame
	void Update( ) {

		// 残り設置数の表示
		updateShowLimitBlock( );

		Vector3 mou_pos = new Vector3( );
		Vector3 scr_m_pos = Input.mousePosition;
		_deb_mouse = scr_m_pos;
		mou_pos = _camera.ScreenToWorldPoint( scr_m_pos );
		_deb = getIDXFromPos( mou_pos );

		bool th = Input.GetKeyDown( KeyCode.Mouse0 );
	//	bool th = ( 0 != Input.touchCount );
	//	if (th) {
	//		mou_pos = _camera.ScreenToWorldPoint(Input.touches[0].deltaPosition);mou_pos = _camera.ScreenToWorldPoint(Input.touches[0].deltaPosition);
	//	}

		if(_edit_mode && !( scr_m_pos.x < _no_touch_x && scr_m_pos.y > _no_touch_y ) ) {
			if( th && (_deb.x >= 0 && _deb.y >= 0 && _deb.x < _x && _deb.y < _y) ) {
				int reslut = 0;
				Transform tra = getBlockTransform( _deb, _trigger_master );

				if ( tra != null ) {
					if ( tra.gameObject.GetComponent< Trigger > ( )._colliding == false ) {
						reslut = changeBlockBuffer( _deb, _objs[ 9 ] );
					}
				}
				if ( reslut == 1 ) {
					_edit_num--;
					_audio.PlayOneShot( _sound_block_edit );
				} else if ( reslut == 2 ) {
					_edit_num++;
					_audio.PlayOneShot( _sound_block_edit );
				}
			}
		}

	//  仮　あとで治す
		/*
		if(Input.GetKeyDown(KeyCode.C)) {
			clearBufferBlock();
		}
		if(Input.GetKeyDown(KeyCode.S)) {
		applayBufferBlock();
		}
		*/
	}

	private void updateShowLimitBlock( ) {
		if( !_edit_mode ){
			return;
		}
	}

	public void createBlock( GameObject clone, Vector2 idx ) {
		GameObject cloned;
		cloned = Instantiate( clone,getPosFromIDX( ( int )idx.x, ( int )idx.y ), transform.rotation );
		cloned.name = ( idx.x ).ToString( ) + "_" + ( idx.y ).ToString( );// + "_" + _floor_block.name;
		cloned.transform.parent = _block_master.transform;
		Block br = cloned.transform.GetComponent< Block > ( );
		br.setIdx( ( int )idx.x, ( int )idx.y );
	}
	public void createBlock( GameObject clone, Vector2 idx, GameObject parent ) {
		GameObject cloned;
		cloned = Instantiate( clone, getPosFromIDX( ( int )idx.x, ( int )idx.y ), transform.rotation );
		cloned.name = ( idx.x ).ToString( ) + "_" + ( idx.y ).ToString( );// + "_" + _floor_block.name;
		cloned.transform.parent = parent.transform;
		Block br = cloned.transform.GetComponent< Block > ( );
		br.setIdx( ( int )idx.x, ( int )idx.y );
		if ( parent == _block_not_changed ) {
			cloned.GetComponent< SpriteRenderer >( ).color = new Color( 1f, 1f, 1f, 0.5f );
		}
	}
	public void createBlock( int block_number, Vector2 idx, GameObject parent ) { //  最新
		GameObject cloned;
		cloned = Instantiate( _objs[ block_number ], getPosFromIDX( ( int )idx.x, ( int )idx.y ), transform.rotation );
		cloned.name = ( idx.x ).ToString( ) + "_" + ( idx.y ).ToString( );
		cloned.transform.parent = parent.transform;
		Block br = cloned.transform.GetComponent< Block > ( );
		br.setIdx( ( int )idx.x, ( int )idx.y );
	}


	public void changeBlock( Vector2 IDX, GameObject block ) {
		Transform chen = getBlockTransform( IDX );
		//Transform tra = _block_master.transform.GetChild( );
		if ( chen == null ) {
			createBlock( block, IDX );
		} else {
			Destroy( chen.gameObject );
		}
	}
	public int changeBlockBuffer( Vector2 IDX, GameObject block ) {
		int result = 0;
		Transform chen = getBlockTransform( IDX );
		Transform chen_b = getBlockTransform( IDX, _block_not_changed );
		//Transform tra = _block_master.transform.GetChild( );
		if ( chen == null && chen_b == null ) {
			if ( _edit_num > 0 ) {////////////
				result = 1;
				createBlock ( block, IDX, _block_not_changed );
			}
		} else {
			if( chen_b != null ) {
				Destroy( chen_b.gameObject );
				result = 2;
			}
		}
		return result;
	}

	public string cheakBlock( Vector2 idx ) {
		Transform cheak = getBlockTransform( idx );
		return cheak.name;
	}

	public Transform getBlockTransform( Vector2 idx ) {
		//Transform target = _block_master.transform.FindChild( idx.x.ToString( ) + "_" + idx.y.ToString( ) );
		Transform target = null;
		for( int i = 0; i < _block_master.transform.childCount; i++ ) {
			Transform tar = _block_master.transform.GetChild( i );
			Block br = tar.GetComponent< Block > ( );
			if( br._idx.x == idx.x && br._idx.y == idx.y ) {
				target = tar;
				break;
			}
		}
		return target;
	}
	public Transform getBlockTransform( Vector2 idx, GameObject parent ) {
		//Transform target = _block_master.transform.FindChild( idx.x.ToString( ) + "_" + idx.y.ToString( ) );
		Transform target = null;
		for( int i = 0; i < parent.transform.childCount; i++ ) {
			Transform tar = parent.transform.GetChild( i );
			Block br = tar.GetComponent< Block > ( );
			if( ( int )br._idx.x == ( int )idx.x && ( int )br._idx.y == ( int )idx.y) {
				target = tar;
				break;
			}
		}
		return target;
	}

	public void applayBufferBlock( ) {
		int num = _block_not_changed.transform.childCount;
		for( int i = 0; i < num; i++ ) {
			Transform tra = _block_not_changed.transform.GetChild (num - i - 1);
			tra.gameObject.GetComponent< SpriteRenderer > ().color = new Color (1f, 1f, 1f, 1f);
			tra.parent = _block_master.transform;
		}
	}

	public void clearBufferBlock( ) {
		int num = _block_not_changed.transform.childCount;
		for( int i = 0; i < num; i++ ) {
			Destroy( _block_not_changed.transform.GetChild( i ).gameObject );
		}
	}


	public GameObject getBlock( Vector2 idx ) {// null error
		Transform tra = getBlockTransform( idx );
		if ( tra == null ) {
			return null;
		}
		return tra.gameObject;
	}

	public void changeEditMode( bool flag ) {
		_edit_mode = flag;
		_waku_master.SetActive( flag );
		if ( !flag ) {
			applayBufferBlock( );
		}
		changeStateOptionButton( );
		changeStateBlockCreatePossibleNum( );
	}

	public void changeEditMode( ) {
		bool flag = !_edit_mode;
		_edit_mode = flag;
		_waku_master.SetActive( flag );
	
		if( !flag ) {
			applayBufferBlock( );
		}
		changeStateOptionButton( );
		changeStateBlockCreatePossibleNum( );
	}

	private void changeStateOptionButton( ) {
		if ( _option_button == null ) {
			return;
		}

		if ( _edit_mode ) {
			_option_button.SetActive( false );
		} else {
			_option_button.SetActive( true );
		}
	}

	private void changeStateBlockCreatePossibleNum( ) {
		if ( _show_block_create_num == null ) {
			return;
		}

		if ( _edit_mode ) {
			_show_block_create_num.SetActive( true );
		} else {
			_show_block_create_num.SetActive( false );
		}
	}

	public void resetMapData( int size_x, int size_y, int[ ] map ) {
		_map_data = new int[ size_x * size_y ];
		_x = size_x;
		_y = size_y;
	
		for( int i = 0; i < size_x * size_y; i++ ) {
			_map_data[ i ] = map[ i ];
		}
	
	}
	public void setPrefab( int size,Object[ ] obj ) {
		_objs = new GameObject[ size ];
		for( int i = 0; i < size; i++ ) {
			if( obj[ i ] == null ) {
				_objs[ i ] = null;
			} else {
				_objs[ i ] = ( obj[ i ] ) as GameObject;			
			}
		}
	}

	/// //////////////
	/// get 系関数
	public Vector3 getPosFromIDX( int x, int y ) {
		Vector3 pos = transform.position;
		pos += new Vector3( x + 0.5f, y + 0.5f, Z_POS );
		return pos;
	}

	public Vector2 getIDXFromPos( Vector3 pos ) {
		pos -= transform.position;
	
		Vector2 ans = new Vector2( );
		ans.x = Mathf.FloorToInt( pos.x );
		ans.y = Mathf.FloorToInt( pos.y );

		return ans;
	}

	public Vector2 getSize( ) {
		return new Vector2 ( _x, _y );
	}

	public GameObject getBlockMaster( ) {
		return _block_master;
	}

	void OnDrawGizmos( ) {
		Gizmos.color = new Color ( 0, 0, 1 );
		Gizmos.DrawWireCube( transform.position + new Vector3( _x / 2.0f, _y / 2.0f, 0 ), new Vector3( _x, _y, 1 ) );
		for( int i = 0; i < _x * _y; i++ ) {
			Gizmos.DrawWireCube( getPosFromIDX( i % _x, i / _x ), new Vector3( 1, 1, 1 ) );
			if ( _map_data[ ( _x * ( _y - ( i / _x ) - 1 ) ) + ( i % _x ) ] != 0 ) {
				Gizmos.DrawCube(getPosFromIDX( i % _x, i / _x ),new Vector3( 1, 1, 1 ) );
			}
		}
	}

	public bool isEdit( ) {
		return _edit_mode;
	}

	public bool isEditMode( ) {
		return _edit_mode;
	}

	public SpriteRenderer getPutBlockImage( ) {
		return _objs[ PLAYER_PUT_BLOCK_IDX ].GetComponent< SpriteRenderer >( );
	}

	public int getEditNum( ) {
		return _edit_num;
	}
    public void setAudio( AudioSource audio ) {
        _audio = audio;
    }
    public void setAudioClip( AudioClip sound_block_edit ) {
        _sound_block_edit = sound_block_edit;
    }
	public GameObject getTriggerMaster( ) {
		return _trigger_master;
	}
}
