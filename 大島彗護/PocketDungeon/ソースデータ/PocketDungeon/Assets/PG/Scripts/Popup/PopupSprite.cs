using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

[ ExecuteInEditMode ]
public class PopupSprite : MonoBehaviour {

    [ SerializeField ] private Sprite _sprite = null;
    private Image _image = null;
    
    private void Update( ) {
        if ( _image == null ) {
            _image = GetComponentInChildren< Image >( );
        }

        if ( _image != null && _sprite != null ) {
            _image.sprite = _sprite;
        }
    }
}
