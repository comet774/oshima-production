using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Node : MonoBehaviour {
	// parent enum
	private NodeManager.INIT_TAG _tag;

    // Children
    const string TEXT_NAME_TAG   = "ParameterName";
    const string TEXT_NAME_VALUE = "ParameterValue";

    private Text _parameter_name = null;
    private Text _parameter_value = null;
    private Slider _slider = null;
    private InputField _input_field = null;
	private Toggle _toggle = null;

    // 値を変更する変数
	[ SerializeField ] private int _slider_length = 5;
    private float  _input_value_float = 0.0f;
	private bool   _use = false;
	

	// 初期化関数
	public void initialize( NodeManager.Property property ) {
		inputComponent( );
		_tag = property.tag;
		_use = property.use;

		changeName( _tag );
		changeValue( property.value );
		resetSlider( property.value );
		resetToggle( _use );
	}

    // func
    private void inputComponent( ) {
        Text[ ] texts = GetComponentsInChildren< Text >( );
        foreach ( Text text in texts ) {
            if ( text.name == TEXT_NAME_TAG ) {
                _parameter_name = text;
            }
            if ( text.name == TEXT_NAME_VALUE ) {
                _parameter_value = text;
            }
        }

        _slider      = GetComponentInChildren< Slider >( );
        _input_field = GetComponentInChildren< InputField >( );
		_toggle      = GetComponentInChildren< Toggle >( );
    }

	// get
	public NodeManager.INIT_TAG getTag( ) {
		return _tag;
	}
	public void inputValue( ref NodeManager.Property property ) {
		property.use = _use;
		property.value = _input_value_float;
	}

	// dynamic
	public void slide( float value ) {
		changeValue( value );
	}
	public void inputFieldValue(  ) {
		float value = float.Parse( _input_field.text );
		resetSlider( value );
		changeValue( value );
	}
	public void toggle( ) {
		_use = _toggle.isOn;
	}

	private void changeName( NodeManager.INIT_TAG tag ) {
		_parameter_name.text = tag.ToString( );
	}

	private void changeValue( float value ) {
		// 値を入れる
		_input_value_float = value;

		_slider.value = value;
		_input_field.text = value.ToString( );
		_parameter_value.text = value.ToString( );
	}

	// init
	private void resetSlider( float center_value = 0.0f ) {
        float length = ( center_value * _slider_length );
		if ( length == 0 ) {
			length = 1;
		}
		if ( length < 0 ) {
			length *= -1;
		}

        _slider.maxValue = length;
        _slider.minValue = center_value - length;
		_slider.value = center_value;
	}
	private void resetToggle( bool toggle ) {
		_toggle.isOn = toggle;
	}
}
