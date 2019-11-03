using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PopupButton : MonoBehaviour {
	public GameObject _popup;

	public void activePopup( ) {
		_popup.SetActive( true );
		_popup.GetComponent< Popup >( ).activePopup( );
	}
}
