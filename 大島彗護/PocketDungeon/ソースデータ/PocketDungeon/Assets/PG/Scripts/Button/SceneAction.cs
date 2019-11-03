using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class SceneAction : MonoBehaviour {

	public string next;

	public void changeScene( ) {
		SceneManagement.setScene( next );
	}

	public void addScene( ) {
		SceneManagement.addScene( next );
	}
	public void unloadScene( ) {
		SceneManagement.unloadScene( next );
	}

	public void reloadScene( ) {
		SceneManagement.reloadScene( );
	}
}
