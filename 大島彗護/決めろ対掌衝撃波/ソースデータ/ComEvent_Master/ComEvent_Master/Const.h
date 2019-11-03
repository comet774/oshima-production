

//以下は変更不可
const int WIDTH					= 1280;						//画面の横幅	
const int HEIGHT				= 1024;						//画面の縦幅
const int ANGLE_RESERVE			= 1080;						//角度の余分値
const int REAL_TIME				= 60;						//現実の時間
const double CENTER_X			= WIDTH * 0.5;				//画面のx軸の中心
const double CENTER_Y			= HEIGHT * 0.5;				//画面のy軸の中心
const double PLAYER1_X			= WIDTH - 100;				//プレイヤー1のボールの初期x座標
const double PLAYER1_Y			= HEIGHT - 100;				//プレイヤー1のボールの初期y座標
const double PLAYER2_X			= 100;						//プレイヤー2のボールの初期x座標
const double PLAYER2_Y			= HEIGHT - 100;				//プレイヤー2のボールの初期y座標
const int ANGLE_MAX				= 3600;						//最大角度
const int ANGLE_HALF			= 1800;						//最大角度の半分
const int INIT_TURRET_ANGLE		= 180;						//タレットの初期角度
const int TURRET_DOWN_ANGLE		= 3600;						//スタミナ切れのタレットの基本角度
const int MEMORY					= 500;					//vectorの容量
const int ENEMY_TYPE_NUMBER		= 3;						//演出結果に出てくる敵の種類の数
const double ENEMY_BLOWS_TIME	= REAL_TIME * 2;			//結果演出時の敵が吹っ飛ぶ演出をする時間
const int ENEMY_X				= ( int )CENTER_X - 150;	//結果演出時の敵のX軸の位置
const int INIT_EFECT			= 100;						//結果演出時のエフェクトの初期設定

enum SCENE {
	TITLE,
	OUTSET,
	GAME,
	FINISH,
	RESULT,
	STAFF_ROLL,
	DISCRIPTION,
	MAX_SCENE
};

//以下は変更可
const int TITLE_MOVE_SPEED		= 1;				//タイトルのキャラクターの移動スピード
const int START_TIMER			= 3 * REAL_TIME;	//ゲーム開始直前のカウント			
const int START_TIMAR_GO		= 60;				//ゲームスタートのロゴ表示時間
const int GAME_TIME				= 30 * 100;			//制限時間,100は固定
const int GAME_TIMER_HALF		= GAME_TIME / 2;	//制限時間半分
const int BELT_POS				= 1600;				//カットイン時の上下のベルトの初期位置
const int CUT_IN_TIMER			= 2 * 100;			//カットインの表示時間
const int CUT_IN_FRAME_SPEED	= 45;				//カットイン時の枠の流れるスピード
const int CUT_IN_EXPAND_SPEED	= 8;				//カットイン時の画像の拡大スピード
const int BATTERY_NUM			= 3;				//発射台の向き変更時の値
const int BATTERU_ACCELERATION	= 100;				//発射したときの初速度
const int BULLET				= 3;				//発射台のゲージの回復速度
const int HOLE_AREA				= 100;				//合成不可範囲
const int STAMINA_MAX			= 100;				//スタミナの最大値
const int STAMINA_SUB			= 12;				//スタミナの減少値
const int BALL_DETERMINE		= 64;				//合成弾の当たり判定
const int SCORE_MAX				= 10 * 10000;		//スコアボードの最大耐久値
const int SCORE_MAX_HARD		= 53 * 10000;		//ハードモード時のスコアボードの最大耐久値
const int BLACKBOX_X			= 500;				//スコアボードのX値
const int BLACKBOX_Y			= 400;				//スコアボードのY値
const int BACK_SPIN_MAX			= 300;				//回転背景の最大値
const int BACK_SPIN_FREEM		= 20;				//回転背景の計算感覚				1= 1フレーム
const int SCORE_DRAW_TIME		= 1 * 100;			//ゲーム中のスコアの表示時間
const int SCORE_NORMAL			= 300;				//通常弾の得点
const int SCORE_MIX				= 100;				//合成弾の得点
const int SCORE_MIX_HARD		= 500;				//ハードモード時の合成弾の得点
const int BACK_SCROLL			= 20;				//演出結果のスクロール速度
const int ONE_ENEMY_SCORE		= 2000;				//敵一体に対するスコア
const double EXPAND_NUM			= 0.04;				//敵の拡大値
const int ENEMY_SPECE			= 200;				//結果演出時の敵同時の間隔
const double STOP_FIRST			= REAL_TIME * 2.5;	//結果演出時の最初の敵停止時間
const double STOP_SECOND		= REAL_TIME * 3.5;	//結果演出時の2回目の敵停止時間
const int SPECIAL_ENEMY			= 5;				//結果演出時の特別演出の間隔( n体目の敵が特別演出をする )