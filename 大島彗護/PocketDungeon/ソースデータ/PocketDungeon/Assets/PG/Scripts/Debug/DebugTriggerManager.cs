using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class DebugTriggerManager : MonoBehaviour {

	static int _trigger_time = 5;
	[ SerializeField ] private List< GameObject > _trigger = new List< GameObject >( );

	private void Update( ) {
		foreach ( GameObject obj in _trigger ) {
			DebugTrigger trigger = obj.GetComponent< DebugTrigger >( );
			if ( trigger.getTime( ) < _trigger_time ) {
				return;
			}
		}

		SceneManagement.setScene( "Debug" );
	}
}
