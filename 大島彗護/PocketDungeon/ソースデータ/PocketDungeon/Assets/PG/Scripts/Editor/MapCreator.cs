using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEditor;

public class MapCreator:EditorWindow {

	private const int X_MAX = 100;
	private const int Y_MAX = 100;
	private const int XY_MAX = X_MAX * Y_MAX;
	private const int BLOCK_MAX = 15;

	private int _x_blocks = 16;
	private int _y_blocks = 12;
	private string _name;
	GameObject _data;
	MapData _map;

	public int[] _num;
	public Object[ ] _objs;

	private Object _input_data = null;

	[MenuItem("Window/Pocket/MapCreator")]
	static void init() {
		MapCreator map = EditorWindow.GetWindow<MapCreator>(true,"MapCreator");
		//_data = new MapData( );
		map._num = new int[XY_MAX]; // 25 * 25 
		map._objs = new GameObject[BLOCK_MAX];
		//_data.AddComponent< MapData >( );
		//_map = _data.GetComponent< MapData >( );
	}

	void OnGUI() {
		_x_blocks = EditorGUILayout.IntField("x block num",_x_blocks);
		_y_blocks = EditorGUILayout.IntField("y block num",_y_blocks);
		_name = EditorGUILayout.TextField("name",_name);

		EditorGUILayout.Space();

		_input_data = EditorGUILayout.ObjectField( "copy_map", _input_data, typeof( MapData ), true );
		{ // _input_data があったらコピーして消す。
			if ( _input_data != null  ) {
				MapData copy_map_dat = _input_data as MapData;
				if ( copy_map_dat != null ) {
					_x_blocks = copy_map_dat._x;
					_y_blocks = copy_map_dat._y;
					for ( int i = 0; i < _x_blocks * _y_blocks; i++ ) {
						_num[ i ] = copy_map_dat._map_data[ i ];
					}
					for ( int i = 0; i < BLOCK_MAX; i++ ) {
						_objs[ i ] = copy_map_dat._objs[ i ];
					}
				}
				_input_data = null;
			}
		}

		EditorGUILayout.Space();

		if(_x_blocks < 1 || _x_blocks > X_MAX) {
			_x_blocks = 1;
		}
		if(_y_blocks < 1 || _y_blocks > Y_MAX) {
			_y_blocks = 1;
		}

		for(int i = 0;i < _y_blocks;i++) {
			EditorGUILayout.BeginHorizontal();
			{
				for(int j = 0;j < _x_blocks;j++) {
					_num[i * _x_blocks + j] = EditorGUILayout.IntField(_num[i * _x_blocks + j]);
					if(_num[i * _x_blocks + j] < 0 || _num[i * _x_blocks + j] > BLOCK_MAX) {
						_num[i * _x_blocks + j] = 0;
					}
				}
			}
			EditorGUILayout.EndHorizontal();
		}

		EditorGUILayout.Space();

		for(int i = 0;i < BLOCK_MAX;i++) {
			string lab = (i).ToString();
			if(i == 0) {
				lab += " 何も入れないの推奨";
			};
			if (i == 4) {
				lab += " Switchブロック";
			}
			if (i == 5) {
				lab += " 初期状態で存在しているswitchブロック";
			}
			if (i == 6) {
				lab += " 初期状態で消えているswitchブロック";
			}
			if(i == 7) {
				lab += " trigger_block";
			};
			if(i == 8) {
				lab += " ブロックの枠";
			};
			if(i == 9) {
				lab += " 主人公の作り出すブロック";
			};

		_objs[i] = EditorGUILayout.ObjectField(lab,_objs[i],typeof(Object),true);
		}


		if(GUILayout.Button("create")) {
			create();
		}
	}

	void create() {
	if(_name.Length > 0) {

	GameObject obj = new GameObject();
	obj.name = _name;
	obj.AddComponent<MapData>();
    var audio = obj.AddComponent< AudioSource >( );
	MapData dat = obj.GetComponent<MapData>();
	dat.resetMapData(_x_blocks,_y_blocks,_num);
	dat.setPrefab(BLOCK_MAX,_objs);
    dat.setAudio( audio );
	}
	Close();
	/*
	GameObject obj = new GameObject( );
	obj.AddComponent< MapData >( );

	UnityEditor.PrefabUtility.CreatePrefab ("Assets/Mo/" + _name + ".prefab", obj );

	// これをしないとMeshが保存されない！
	UnityEditor.AssetDatabase.SaveAssets ();
	*/
	}
}

/*   inspector の変更
[CustomEditor( typeof( MapManager ) )]
public class MapManagerEditor : Editor {


	public override void OnInspectorGUI ()
	{
		MapManager obj_map = target as MapManager;

		base.OnInspectorGUI ();
		EditorGUILayout.BeginHorizontal ();
		{
			obj_map._x = EditorGUILayout.IntField ( obj_map._x );
		}
		EditorGUILayout.EndHorizontal ();


	}

}*/

/* ////////////////////////////////////////////////////////////////
   ////////////////////////////////////////////////////////////////
   ////////////////////////////////////////////////////////////////
using UnityEngine;
using UnityEditor;
using System.Collections;

public class CreateBuoys : EditorWindow {
	private GameObject parent;
	private GameObject prefab;
	private int numX = 1;
	private int numY = 1;
	private int numZ = 1;
	private float intervalX = 1;
	private float intervalY = 1;
	private float intervalZ = 1;

	[MenuItem("GameObject/Create Other/Create Buoys")]
	static void Init() {
		EditorWindow.GetWindow<CreateBuoys>(true, "Create Buoys");
	}

	void OnEnable() {
		if (Selection.gameObjects.Length > 0) parent = Selection.gameObjects[0];
	}

	void OnSelectionChange() {
		if (Selection.gameObjects.Length > 0) prefab = Selection.gameObjects[0];
		Repaint();
	}

	void OnGUI() {
		try {
			parent = EditorGUILayout.ObjectField("Parent", parent, typeof(GameObject), true) as GameObject;
			prefab = EditorGUILayout.ObjectField("Prefab", prefab, typeof(GameObject), true) as GameObject;

			GUILayout.Label("X : ", EditorStyles.boldLabel);
			numX = int.Parse(EditorGUILayout.TextField("num", numX.ToString()));
			intervalX = int.Parse(EditorGUILayout.TextField("interval", intervalX.ToString()));

			GUILayout.Label("Y : ", EditorStyles.boldLabel);
			numY = int.Parse(EditorGUILayout.TextField("num", numY.ToString()));
			intervalY = int.Parse(EditorGUILayout.TextField("interval", intervalY.ToString()));

			GUILayout.Label("Z : ", EditorStyles.boldLabel);
			numZ = int.Parse(EditorGUILayout.TextField("num", numZ.ToString()));
			intervalZ = int.Parse(EditorGUILayout.TextField("interval", intervalZ.ToString()));

			GUILayout.Label("", EditorStyles.boldLabel);
			if (GUILayout.Button("Create")) Create();
		} catch (System.FormatException) {}
	}

	private void Create() {
		if (prefab == null) return;

		int count = 0;
		Vector3 pos;

		pos.x = -(numX - 1) * intervalX / 2;
		for (int x = 0; x < numX; x++) {
			pos.y = -(numY - 1) * intervalY / 2;
			for (int y = 0; y < numY; y++) {
				pos.z = -(numZ - 1) * intervalZ / 2;
				for (int z = 0; z < numZ; z++) {
					GameObject obj = Instantiate(prefab, pos, Quaternion.identity) as GameObject;
					obj.name = prefab.name + count++;
					if (parent) obj.transform.parent = parent.transform;
					Undo.RegisterCreatedObjectUndo(obj, "Create Buoys");

					pos.z += intervalZ;
				}
				pos.y += intervalY;
			}
			pos.x += intervalX;
		}
	}
}*/
