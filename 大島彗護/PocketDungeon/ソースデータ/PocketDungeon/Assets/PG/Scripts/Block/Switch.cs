using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Switch : MonoBehaviour {
	SpriteRenderer main_sprite;

	public enum ON_DIRECTION {
		UP,
		UNDER,
		RIGHT,
		LEFT
	}

	public Sprite switch_on;
	public Sprite switch_off;
	public bool on_off;
	public int number;
	public ON_DIRECTION Surface;

	bool first;

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
		_thunder = GetComponent< Block_Thunder > ( );
		main_sprite = gameObject.GetComponent< SpriteRenderer > ( );
		my_idx = _block.getIdx( );
		first = true;
		isDirection( );
	}

	// Update is called once per frame
	void Update ( ) {
		updatePos( );
		Energization( );
		main_sprite.sprite = Change( );
	}

	Sprite Change( ) {
		if( on_off ) {
			return switch_on;
		} 
		return switch_off;
	}

	void Energization( ) {
		if( _thunder.getElergization( ) ) {
			if ( first ) {
				on_off = !on_off;
			}
			first = false;
			return;
		}
 
		if ( _thunder.getFlag( ) == false ) {
			if ( top != null ) {
				if ( top.tag == "Iron_Thunder" ) {
					if ( first ) {
						on_off = !on_off;
					}
					_thunder.setFlag( true );
					first = false;
					return;
				}
			}
			if ( under != null ) {
				if ( under.tag == "Iron_Thunder" ) {
					if ( first ) {
						on_off = !on_off;
					}
					_thunder.setFlag( true );
					first = false;
					return;
				}
			}
			if ( right != null ) {
				if ( right.tag == "Iron_Thunder" ) {
					if ( first ) {
						on_off = !on_off;
					}
					_thunder.setFlag( true );
					first = false;
					return;
				}
			}
			if ( left != null ) {
				if ( left.tag == "Iron_Thunder" ) {
					if ( first ) {
						on_off = !on_off;
					}
					_thunder.setFlag( true );
					first = false;
					return;
				}
			}
			first = true;
		}
	}

	void updatePos( ) {
		top = _block.getIdxBlock ( ( int )my_idx.x, ( int )my_idx.y + 1 );
		under = _block.getIdxBlock ( ( int )my_idx.x, ( int )my_idx.y - 1 );
		left = _block.getIdxBlock ( ( int )my_idx.x - 1, ( int )my_idx.y );
		right = _block.getIdxBlock ( ( int )my_idx.x + 1, ( int )my_idx.y );
	}

	void isDirection ( ) {
		if ( Surface == ON_DIRECTION.UP ) {
			this.transform.rotation = Quaternion.Euler( 0, 0, 180 );
		}

		if ( Surface == ON_DIRECTION.UNDER ) {
			this.transform.rotation = Quaternion.Euler( 0, 0, 0 );
		}

		if ( Surface == ON_DIRECTION.LEFT ) {
			this.transform.rotation = Quaternion.Euler( 0, 0, 270 );
		}

		if ( Surface == ON_DIRECTION.RIGHT ) {
			this.transform.rotation = Quaternion.Euler( 0, 0, 90 );
		}

	}
}