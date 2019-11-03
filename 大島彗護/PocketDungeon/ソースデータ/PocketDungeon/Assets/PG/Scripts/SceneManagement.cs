using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class SceneManagement : MonoBehaviour {
	public string _start_scene = "";
	private static string _active_scene_name;
	private static Scene _active_scene;

	public void Start ( ) {
		_active_scene_name = _start_scene;
		SceneManager.LoadScene( _active_scene_name, LoadSceneMode.Additive );
		keepArgActiveScene( );
	} 

	public static void setScene( string scene ) {
		// 同じsceneがactiveかどうかを調べる
		if ( checkActiveSceneName( scene ) ) {
			return;
		}

		// 今実行されているsceneを保存
		string past = _active_scene_name;
		_active_scene_name = scene;

		// 新しいシーンに切り替える
		if ( checkActiveSceneName( past ) ) {
			unloadScene( past );
		}
		SceneManager.LoadScene( _active_scene_name, LoadSceneMode.Additive );

		keepArgActiveScene( );
	}

	public static void addScene( string scene ) {
		// 同じsceneがactiveかどうかを調べる
		if ( checkActiveSceneName( scene ) ) {
			return;
		}

		// sceneをaddする
		_active_scene_name = scene;
		SceneManager.LoadScene( _active_scene_name, LoadSceneMode.Additive );
		keepArgActiveScene( );
	}

	public static void unloadScene( string scene ) {
		// 同じsceneがactiveかどうかを調べる
		if ( !checkActiveSceneName( scene ) ) {
			return;
		}

		// sceneをunloadする
		SceneManager.UnloadSceneAsync( scene );

		if ( _active_scene_name == scene ) {
			_active_scene_name = "";
		}
		keepArgActiveScene( );
	}

	public static void reloadScene( ) {
		// sceneをreloadする
		string reload_scene = _active_scene_name;
		unloadScene( _active_scene_name );
		setScene( reload_scene );
	}

	private static bool checkActiveSceneName( string name ) {
		// sceneが存在するか検索する
		int scene_max = SceneManager.sceneCount;

		// scene( string )が存在するかチェック
		for ( int i = 0; i < scene_max; i++ ) {
			string getname = SceneManager.GetSceneAt( i ).name;
			Scene scene = SceneManager.GetSceneByName( getname );
			if ( name == getname && scene.isLoaded ) {
				return true;
			}
		}

		return false;
	}

	private static void keepArgActiveScene( ) {
		_active_scene = SceneManager.GetSceneByName( _active_scene_name );
	}

	public static void moveObjectToActiveScene( GameObject obj ) {
		// アクティブシーンを確認
		if ( !_active_scene.isLoaded ) {
			keepArgActiveScene( );
		}

		if ( !_active_scene.isLoaded ) {
			return;
		}
		SceneManager.MoveGameObjectToScene( obj, _active_scene );
	}
}
