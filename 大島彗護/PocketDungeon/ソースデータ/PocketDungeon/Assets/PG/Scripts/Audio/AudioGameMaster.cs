using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class AudioGameMaster : MonoBehaviour {

	public AudioSource _jump;
	public AudioSource _button;
	public AudioSource _clear_game;
	public AudioSource _damage;
	public AudioSource _die;
	public AudioSource _magic;
	public AudioSource _block_set;

	// Use this for initialization
	void Start ( ) {
		
	}
	

	public void playJump( ) {
		_jump.PlayOneShot( _jump.clip );
	}
	public void playButton( ) {
		_button.PlayOneShot(_button.clip);
	}
	public void playGameClear( ) {
		_clear_game.PlayOneShot(_clear_game.clip);
	}
	public void playDamage(){
		_damage.PlayOneShot(_damage.clip);
	}
	public void playDie(){
		_die.PlayOneShot(_die.clip);
	}
	public void playMagic( ) {
		_magic.PlayOneShot(_magic.clip);
	}
	public void playBlockSet( ) {
		_block_set.PlayOneShot( _block_set.clip );
	}
}
