using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Iron : MonoBehaviour {
	SpriteRenderer main_sprite;

	public Sprite normal;
	public Sprite electrical;

	Block _block;
	Block_Thunder _thunder;

	Vector2 my_idx;
	GameObject top;
	GameObject under;
	GameObject right;
	GameObject left;

	// Use this for initialization
	void Start  ( ) {
		_block = GetComponent < Block > ( );
		_thunder = GetComponent < Block_Thunder > ( );
		main_sprite = gameObject.GetComponent<SpriteRenderer>( );
		main_sprite.sprite = normal;
		my_idx = _block.getIdx ( );
	}

	// Update is called once per frame
	void Update ( ) {
		updatePos( );
		Energization( );
		main_sprite.sprite = Change( );
	}

	Sprite Change( ) {
		if( _thunder.getElergization( ) ) {
			if ( this.tag == "Iron" ) {
				this.tag = "Iron_Thunder";
			}
			return electrical;
		} else {
			if ( this.tag == "Iron_Thunder" ) {
				this.tag = "Iron";
			}
			return normal;
		}
	}

	void Energization( ) {
		if ( _thunder.getFlag( ) == false ) {
			if ( top != null ) {
				if ( top.tag == "Iron_Thunder" ) {
					_thunder.setFlag( true );
				}
			}
			if ( under != null ) {
				if ( under.tag == "Iron_Thunder" ) {
					_thunder.setFlag( true );
				}
			}
			if ( right != null ) {
				if ( right.tag == "Iron_Thunder" ) {
					_thunder.setFlag( true );
				}
			}
			if ( left != null ) {
				if ( left.tag == "Iron_Thunder" ) {
					_thunder.setFlag( true );
				}
			}
		}
	}

	void updatePos( ) {
		top = _block.getIdxBlock ( ( int )my_idx.x, ( int )my_idx.y + 1 );
		under = _block.getIdxBlock ( ( int )my_idx.x, ( int )my_idx.y - 1 );
		left = _block.getIdxBlock ( ( int )my_idx.x - 1, ( int )my_idx.y );
		right = _block.getIdxBlock ( ( int )my_idx.x + 1, ( int )my_idx.y );
	}
}
