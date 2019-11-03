using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class P_Block : MonoBehaviour {
	SpriteRenderer main_sprite;
	Collider2D box_collider;

	public Sprite frame;
	public Sprite p_block;
	public int number;
	public int width = 32;
	public int height = 24;

	Block _block;
	Switch _switch;
	public bool on_off;


	// Use this for initialization
	void Start( ) {
		_block = GetComponent< Block > ( );
		box_collider = GetComponent< Collider2D > ( );
		main_sprite = gameObject.GetComponent< SpriteRenderer > ( );

        for ( int i = 0; i < height; i++ ) {
        	for ( int j = 0; j < width; j++ ) {
        		if ( _block.getIdxBlock( j, i ) == null ) {
                	continue;
                }
                Switch child = _block.getIdxBlock( j, i ).GetComponent< Switch > ( );
				if ( child != null && child.number == number ) {
                        _switch = child;
                }
            }
        }
        
        if ( on_off ) {
			box_collider.isTrigger = false;
			main_sprite.sprite = p_block;
            on_off = false;
        } else {
			box_collider.isTrigger = true;
			main_sprite.sprite = frame;
		}
	}

    // Update is called once per frame
    void Update( ) {
		if (_switch == null) {
			Debug.Log( number );
			Debug.Log( "上の番号のSwitch_Blockがありません" );
			return;
		}

        if ( on_off != _switch.on_off ) {
		    on_off = _switch.on_off;
		    box_collider.isTrigger = !box_collider.isTrigger;
			if ( main_sprite.sprite == frame ) {
				main_sprite.sprite = p_block;
				return;
			}
			main_sprite.sprite = frame;
		}
		}
	    

}
