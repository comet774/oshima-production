using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class DeleteOutOfCamera : MonoBehaviour {
	private void OnBecameInvisible( ) {
		Destroy( this.gameObject );
	}
}
