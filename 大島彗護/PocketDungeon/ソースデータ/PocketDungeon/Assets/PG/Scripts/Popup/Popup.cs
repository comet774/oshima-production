using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Popup : MonoBehaviour {
	public GameObject _parent;

	private string IMAGE_SCRIPT = "Image";

	public enum STOP_ITEM {
		STOP_ITEM_NONE,
		STOP_ITEM_BUTTON,
		STOP_ITEM_ALL_IMAGEDRAW,
		STOP_ITEM_ALL,
	};
	[ SerializeField ] STOP_ITEM _stop_item = STOP_ITEM.STOP_ITEM_NONE;
	[ SerializeField ] bool _tutorial = false;
	[ SerializeField ] List< string > _ignore_script = new List< string >( 1 ) { "MapData" };

	private void Start ( ) {
		if ( !_tutorial ) {
			this.gameObject.SetActive( false );
		} else {
			activePopup( );
		}
	}

	private void getChildren( GameObject parent, ref List< GameObject > list ) {
		Transform children = parent.GetComponentInChildren< Transform >( );

		// 子がなければリターン
		if ( children.childCount == 0 ) {
			return;
		}

		// 再起
		foreach ( Transform obj in children ) {
			list.Add( obj.gameObject );
			getChildren( obj.gameObject, ref list );
		}
	}

	public void activePopup( ) {
		if ( _parent == null ) {
			return;
		}

		switch ( _stop_item ) {
			case STOP_ITEM.STOP_ITEM_BUTTON:
				buttonStop( );
				break;

			case STOP_ITEM.STOP_ITEM_ALL_IMAGEDRAW:
				allStop( true );
				break;

			case STOP_ITEM.STOP_ITEM_ALL:
				allStop( false );
				break;
		}
		this.gameObject.SetActive( true );
	}

	private void allStop( bool image_draw = true ) {
		List< GameObject > children = new List< GameObject >( );
		getChildren( _parent, ref children );

		int count = children.Count;
		for ( int i = 0; i < count; i++ ) {
			Button button = children[ i ].GetComponent< Button >( );
			MonoBehaviour[ ] scripts = children[ i ].GetComponents< MonoBehaviour >( );
            Rigidbody2D rb = children[ i ].GetComponent< Rigidbody2D >( );

			foreach ( MonoBehaviour script in scripts ) {
				if ( script == null ) {
					continue;
				}

				string str = script.GetType( ).Name;
				if ( isIgnoreScript( str ) ) {
					continue;
				}

				if ( str != IMAGE_SCRIPT || !image_draw ) {
					script.enabled = false;
				}
			}

            if ( rb != null ) {
                rb.Sleep( );
            }

			if ( button != null ) {
    			button.enabled = false;
			}
		}
	}

	private void buttonStop( ) {
		List< GameObject > children = new List< GameObject >( );
		getChildren( _parent, ref children );

		int count = children.Count;
		for ( int i = 0; i < count; i++ ) {
			Button button = children[ i ].GetComponent< Button >( );
			if ( button == null ) {
				continue;
			}
			button.enabled = false;
		}
	}

	public void onClick( ) {
		if ( _parent == null ) {
			return;
		}

		List< GameObject > children = new List< GameObject >( );
		getChildren( _parent, ref children );

		int count = children.Count;
		for ( int i = 0; i < count; i++ ) {
			Button button = children[ i ].GetComponent< Button >( );
			MonoBehaviour[ ] scripts = children[ i ].GetComponents< MonoBehaviour >( );
            Rigidbody2D rb = children[ i ].GetComponent< Rigidbody2D >( );

			foreach ( MonoBehaviour script in scripts ) {
				if ( script == null ) {
					continue;
				}
				script.enabled = true;
			}

            if ( rb != null ) {
                rb.WakeUp( );
            }

			if ( button != null ) {
    			button.enabled = true;
			}
		}

		this.gameObject.SetActive( false );
	}

	private bool isIgnoreScript( string str ) {
		foreach ( string ignore in _ignore_script ) {
			if ( ignore == str ) {
				return true;
			}
		}

		return false;
	}
}
