using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Block:MonoBehaviour {

	public enum TYPE {
		Floor,
		Water,
		Iron,
		Waku,
	};
    
	MapData _parent_map;
	public Vector2 _idx;
	public TYPE _type;

	// Use this for initialization
	void Start( ) {
		_parent_map = GetComponentInParent< MapData > ( );
		//_idx = new Vector2Int ( 0,0 );
	}

	// Update is called once per frame
	//¥--------------------------------------------------------------------------------//
	//¥--------------------------------------------------------------------------------//
	//¥--------------------------------------------------------------------------------
	public Vector2 getIdx( ) { // 自分の親からみたインデックスを取得

		return new Vector2( _idx.x, _idx.y );
	}

	public GameObject getIdxBlock( int x, int y ) { // 自分の親から見たインデックスのGameObject の取得
		return _parent_map.getBlock( new Vector2( x, y ) );
	}

	public GameObject getBlockMaster( ) {
		return _parent_map.getBlockMaster ( );
	}

	public Vector2 getBlcokNum( ) {
		Vector2 stage_num = new Vector2( 
			_parent_map.getSize( ).x,
			_parent_map.getSize( ).y
			);

		return stage_num;
	}

	//¥--------------------------------------------------------------------------------//
	//¥--------------------------------------------------------------------------------//
	//¥--------------------------------------------------------------------------------//

	public void setIdx( int x,int y ) {
		_idx.x = x;
		_idx.y = y;
	}
    
    //	public GameObject getMapBlock(int idx_x,int idx_y) {
    //	return _parent_map.getBlock(new Vector2(idx_x,idx_x));
    //	}


}
