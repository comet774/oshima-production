using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Water : MonoBehaviour {
	SpriteRenderer main_sprite;

	public Sprite wall;
	public Sprite floor;

//	bool ice;

	Block _block;

	Vector2 my_idx;
	GameObject top_gameobject;

	// Use this for initialization
	void Start  ( ) {
		_block = GetComponent< Block >( );
		main_sprite = gameObject.GetComponent<SpriteRenderer>( );
	}

	// Update is called once per frame
	void Update ( ) {
		my_idx = _block.getIdx( );
		top_gameobject = _block.getIdxBlock(( int )my_idx.x, ( int )my_idx.y + 1 );
		main_sprite.sprite = Change( );
	}

	Sprite Change ( ) {
		if ( top_gameobject != null ) {
			return wall;
		}
		return floor;
	}
}