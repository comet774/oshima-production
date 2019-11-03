using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class StageActiveTrigger : MonoBehaviour {

	[ SerializeField ] private int _stage_num = 1;
	bool _active = true;


	void Start ( ) {
		NodeManager.INIT_TAG tag = NodeManager.INIT_TAG.STAGE_SELECT_1;

		switch ( _stage_num ) {
			case 1: tag = NodeManager.INIT_TAG.STAGE_SELECT_1; break;
			case 2: tag = NodeManager.INIT_TAG.STAGE_SELECT_2; break;
			case 3: tag = NodeManager.INIT_TAG.STAGE_SELECT_3; break;
			case 4: tag = NodeManager.INIT_TAG.STAGE_SELECT_4; break;
			case 5: tag = NodeManager.INIT_TAG.STAGE_SELECT_5; break;
			case 6: tag = NodeManager.INIT_TAG.STAGE_SELECT_6; break;
			case 7: tag = NodeManager.INIT_TAG.STAGE_SELECT_7; break;
			case 8: tag = NodeManager.INIT_TAG.STAGE_SELECT_8; break;
			default:
				return;
		}

		NodeManager.inputValue( tag, ref _active );

		if ( !_active ) {
			this.gameObject.SetActive( false );
		}
	}

}
