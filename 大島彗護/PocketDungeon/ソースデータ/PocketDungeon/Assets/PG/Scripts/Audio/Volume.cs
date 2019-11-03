using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Audio;
using UnityEngine.UI;

public class Volume : MonoBehaviour {

	public AudioMixer _mixer;
	public string _parameter_name;
	private Slider _slider;

	private void Start( ) {
		_slider = GetComponentInChildren< Slider >( );
		if ( _slider == null ) {
			return;
		}

		float init_vol = getFloat( );
		_slider.value = init_vol;
	}
	public void changeMusicVolume( float vol ){
		_mixer.SetFloat(_parameter_name, vol );
	}

	private float getFloat( ) {
		float vol = 0.0f;
		bool result = _mixer.GetFloat( _parameter_name, out vol );

		return vol;
	}
}
