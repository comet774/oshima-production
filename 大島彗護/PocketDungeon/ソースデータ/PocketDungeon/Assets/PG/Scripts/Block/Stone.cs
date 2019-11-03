using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Stone : MonoBehaviour {
	const string MAIN_CAMERA = "MainCamera";
	SpriteRenderer main_sprite;

	Block _block;

	public Sprite wall;
	public Sprite floor;

	Vector2 my_idx;
	GameObject top;
	GameObject under;
	GameObject right;
	GameObject left;
	Vector2 stage = new Vector2( 0, 0 );

	// Use this for initialization
	void Start  ( ) {
		_block = GetComponent < Block > ( );
		main_sprite = gameObject.GetComponent<SpriteRenderer>( );
}

	// Update is called once per frame
	void Update ( ) {
		if ( stage == new Vector2( 0, 0 ) ) { 
			stage = _block.getBlcokNum( );
			my_idx = _block.getIdx( );
		}
		getBlockExist( );
		main_sprite.sprite = Change( );
	}
	
	Sprite Change ( ) {
		if ( top != null ) {
			return wall;
		}
		return floor;
	}

	void getBlockExist( ) {
		if ( top == null ) {
			top = _block.getIdxBlock( ( int )my_idx.x, ( int )my_idx.y + 1 );
		}
		if ( under == null ) {
			under = _block.getIdxBlock( ( int )my_idx.x, ( int )my_idx.y - 1 );
		}
		if ( right == null ) {
			right = _block.getIdxBlock( ( int )my_idx.x + 1, ( int )my_idx.y );
		}
		if ( left == null ) {
			left = _block.getIdxBlock( ( int )my_idx.x - 1, ( int )my_idx.y );
		}

		if ( top && under && right && left ) { 
			GetComponent<Collider2D> ( ).enabled = false;	
		}
	}

	void deleateCollision( ) { 
	
		
	}
}