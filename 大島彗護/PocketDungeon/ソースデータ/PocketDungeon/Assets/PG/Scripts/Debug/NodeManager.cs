using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class NodeManager : MonoBehaviour {
	/************************
	 * 1. private でPropertyを作成 
	 * 2. Start( ) でaddする
	 * 3. Update( ) で値を詰める
	 * 4. isUse( ) で渡す値に追加
	 ***********************/


	// tag
	public enum INIT_TAG {
		PLAYER_WALK_SPEED,
		PLAYER_FLIGHT_SPEED,
		PLAYER_JUMP_POWER,
		BLOCK_CREATE_NUM,
        MAGE_MAGIC_SPEED,

		STAGE_SELECT_1,
		STAGE_SELECT_2,
		STAGE_SELECT_3,
		STAGE_SELECT_4,
		STAGE_SELECT_5,
		STAGE_SELECT_6,
		STAGE_SELECT_7,
		STAGE_SELECT_8,
	};

	// struct
	public struct Property {
		public INIT_TAG tag;
		public bool use;
		public float value;

		public Property( INIT_TAG _tag, bool _use = false, float _value = 0.0f ) {
			tag = _tag;
			use = _use;
			value = _value;
		}
	};

	// values
	private static Property _player_walk_speed   = new Property( INIT_TAG.PLAYER_WALK_SPEED );
	private static Property _player_flight_speed = new Property( INIT_TAG.PLAYER_FLIGHT_SPEED );
	private static Property _player_jump_power   = new Property( INIT_TAG.PLAYER_JUMP_POWER );
	private static Property _block_create_num    = new Property( INIT_TAG.BLOCK_CREATE_NUM );
	private static Property _mage_magic_speed    = new Property( INIT_TAG.MAGE_MAGIC_SPEED );
	private static Property _stage_select_1      = new Property( INIT_TAG.STAGE_SELECT_1, true );
	private static Property _stage_select_2      = new Property( INIT_TAG.STAGE_SELECT_2, true );
	private static Property _stage_select_3      = new Property( INIT_TAG.STAGE_SELECT_3, true );
	private static Property _stage_select_4      = new Property( INIT_TAG.STAGE_SELECT_4, true );
	private static Property _stage_select_5      = new Property( INIT_TAG.STAGE_SELECT_5, true );
	private static Property _stage_select_6      = new Property( INIT_TAG.STAGE_SELECT_6, true );
	private static Property _stage_select_7      = new Property( INIT_TAG.STAGE_SELECT_7, true );
	private static Property _stage_select_8      = new Property( INIT_TAG.STAGE_SELECT_8, true );

	[ SerializeField ] private RectTransform _node = null;
	private Dictionary< INIT_TAG, RectTransform > _nodes = new Dictionary< INIT_TAG, RectTransform >( );

	// func
	private void Start( ) {
		addNode( _player_walk_speed   );
		addNode( _player_flight_speed );
		addNode( _player_jump_power   );
		addNode( _block_create_num    );
		addNode( _mage_magic_speed    );
		addNode( _stage_select_1    );
		addNode( _stage_select_2    );
		addNode( _stage_select_3    );
		addNode( _stage_select_4    );
		addNode( _stage_select_5    );
		addNode( _stage_select_6    );
		addNode( _stage_select_7    );
		addNode( _stage_select_8    );
	}
	private void Update( ) {
		foreach ( RectTransform obj in _nodes.Values ) {
			Node node = obj.GetComponent< Node >( );

			INIT_TAG tag = node.getTag( );
			switch ( tag ) {
				case INIT_TAG.PLAYER_WALK_SPEED  : node.inputValue( ref _player_walk_speed )   ; break;
				case INIT_TAG.PLAYER_FLIGHT_SPEED: node.inputValue( ref _player_flight_speed ) ; break;
				case INIT_TAG.PLAYER_JUMP_POWER  : node.inputValue( ref _player_jump_power )   ; break;
				case INIT_TAG.BLOCK_CREATE_NUM   : node.inputValue( ref _block_create_num )    ; break;
				case INIT_TAG.MAGE_MAGIC_SPEED   : node.inputValue( ref _mage_magic_speed )    ; break;
				case INIT_TAG.STAGE_SELECT_1     : node.inputValue( ref _stage_select_1 )      ; break;
				case INIT_TAG.STAGE_SELECT_2     : node.inputValue( ref _stage_select_2 )      ; break;
				case INIT_TAG.STAGE_SELECT_3     : node.inputValue( ref _stage_select_3 )      ; break;
				case INIT_TAG.STAGE_SELECT_4     : node.inputValue( ref _stage_select_4 )      ; break;
				case INIT_TAG.STAGE_SELECT_5     : node.inputValue( ref _stage_select_5 )      ; break;
				case INIT_TAG.STAGE_SELECT_6     : node.inputValue( ref _stage_select_6 )      ; break;
				case INIT_TAG.STAGE_SELECT_7     : node.inputValue( ref _stage_select_7 )      ; break;
				case INIT_TAG.STAGE_SELECT_8     : node.inputValue( ref _stage_select_8 )      ; break;
			}
		}
	}
	
	private void addNode( Property property ) {
		var obj = GameObject.Instantiate( _node ) as RectTransform;
		obj.GetComponent< Node >( ).initialize( property );
		obj.SetParent( transform, false );
		_nodes.Add( property.tag, obj );
	}

	// 外部への受け渡し
	public static void inputValue( INIT_TAG tag, ref int value ) {
		float get_val = 0.0f;
		if ( isUse( tag, out get_val ) ) {
			value = ( int )get_val;
		}
	}
	public static void inputValue( INIT_TAG tag, ref float value ) {
		float get_val = 0.0f;
		if ( isUse( tag, out get_val ) ) {
			value = get_val;
		}
	}
	public static void inputValue( INIT_TAG tag, ref double value ) {
		float get_val = 0.0f;
		if ( isUse( tag, out get_val ) ) {
			value = get_val;
		}
	}
	public static void inputValue( INIT_TAG tag, ref bool value ) {
		float get_val = 0.0f;
		value = isUse( tag, out get_val );
	}

	// 渡す値の選別
	private static bool isUse( INIT_TAG tag, out float value ) {
		Property property = new Property( );
		switch ( tag ) {
			case INIT_TAG.PLAYER_WALK_SPEED  : property = _player_walk_speed  ; break;
			case INIT_TAG.PLAYER_FLIGHT_SPEED: property = _player_flight_speed; break;
			case INIT_TAG.PLAYER_JUMP_POWER  : property = _player_jump_power  ; break;
			case INIT_TAG.BLOCK_CREATE_NUM   : property = _block_create_num   ; break;
			case INIT_TAG.MAGE_MAGIC_SPEED   : property = _mage_magic_speed   ; break;
			case INIT_TAG.STAGE_SELECT_1     : property = _stage_select_1     ; break;
			case INIT_TAG.STAGE_SELECT_2     : property = _stage_select_2     ; break;
			case INIT_TAG.STAGE_SELECT_3     : property = _stage_select_3     ; break;
			case INIT_TAG.STAGE_SELECT_4     : property = _stage_select_4     ; break;
			case INIT_TAG.STAGE_SELECT_5     : property = _stage_select_5     ; break;
			case INIT_TAG.STAGE_SELECT_6     : property = _stage_select_6     ; break;
			case INIT_TAG.STAGE_SELECT_7     : property = _stage_select_7     ; break;
			case INIT_TAG.STAGE_SELECT_8     : property = _stage_select_8     ; break;
		}																    
		value = property.value;
		return property.use;
	} 
}
