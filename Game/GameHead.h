#pragma once

//オブジェクトネーム------------------------------
enum OBJ_NAME
{
	//ゲームで使うオブジェクトの名前
	//OBJ_○○と表記
	OBJ_NO_NAME,	//オブジェクト名無し(禁止)
	OBJ_BACK_GROUND,	//背景
	OBJ_MAP,			//マップ
	OBJ_BLACK_HOLE,		//ブラックホール
	OBJ_CHARA,			//キャラクタ
	OBJ_ENEMY,			//敵
	OBJ_ENEMY_BULLET,	//敵の弾
	OBJ_CHARA_BULLET,	//主人公の弾
	OBJ_STAR,			//星オブジェクト
	OBJ_ITEM_BIG,		//収集アイテムオブジェクト(大)
	OBJ_ITEM_SMALL,		//収集アイテムオブジェクト(小)
	OBJ_SCROLL_CHANGE,	//スクロールの切り変えオブジェクト
	OBJ_PLANE,			//地面
	OBJ_SCORE,			//スコア
	OBJ_TITLE,			//タイトル
	OBJ_GAME_OVER,		//ゲームオーバー
	OBJ_GAME_CLEAR,
	OBJ_HOLE_CENTER,	//穴の中心
	OBJ_GOAL,			//ゴール
	OBJ_CLEAR,			//クリア
};
//------------------------------------------------

//当たり判定属性----------------------------------
enum HIT_ELEMENTS
{
	ELEMENT_NULL,//属性無し 全ての属性と当たり判定が実行される
	//以下　同じ属性同士では当たり判定は実行されない
	//属性は追加可能だが、デバック時の色は初期設定分しか無い
	ELEMENT_CHARA,			//キャラクター
	ELEMENT_ENEMY,			//敵
	ELEMENT_ITEM,			//アイテム
	ELEMENT_STAGE,			//ステージ
	ELEMENT_DEATH,			//死亡判定
};
//------------------------------------------------

//------------------------------------------------
//セーブ＆ロードとシーン間のやり取りするデータ
struct UserData
{
	int m_iScore;	//スコア
};
//------------------------------------------------


//ゲーム内で使用されるグローバル変数・定数・列挙--


//スクロール
#define SIDE true			//横
#define VERTICAL false		//縦
#define SCROLL_SPEED 1.0f	//スクロール速度

//マップ
#define MAX_X 37
#define MAX_Y 10

//最大アイテム数
#define MAX_ITEM 4

//マップ数値
enum MAP_NUM
{
	MAP_NONE,		//何もない
	MAP_PLANE,		//地面
	MAP_BLACK_HOLE,	//ブラックホール
	MAP_STAR,		//星
	MAP_ENEMY,		//敵
	MAP_ITEM_SMALL,	//収集アイテム(大)
	MAP_ITEM_BIG,	//収集アイテム(小)
	MAP_SCROLL_CHANGE,//スクロールの切り替え
	MAP_GOAL,		//クリアアイテム
};

//アイテム用数値
enum ITEM_NUM
{
	ITEM_NONE,		//アイテム無し
	ITEM_BIG,		//アイテム(大)
	ITEM_SMALL,		//アイテム(小)
};

//オブジェクトサイズ
#define OBJ_SIZE		64.0f
#define BLACK_HOLE_SIZE	128.0f
#define HOLE_DEATH_SIZE 32.0f
#define ENEMY_SIZE		64.0f
#define BULLET_SIZE		32.0f
#define CHARA_SIZE		64.0f
#define STAR_SIZE		64.0f
#define ITEM_BIG_SIZE	64.0f
#define ITEM_SMALL_SIZE	32.0f
#define SCROLL_CHANGE_SIZE 64.0f
#define GOAL_SIZE		64.0f

//スコア
#define SCORE_BIG		1000;
#define SCORE_SMALL		 500;
#define SCORE_BONUS		 250;

#define PLANE_WIDTH	OBJ_SIZE
#define PLANE_HEIGHT 6.0f

//------------------------------------------------
//ゲーム内で使用するクラスヘッダ------------------


//------------------------------------------------

//ゲームシーンオブジェクトヘッダ------------------
#include "BackGround.h"
#include "Map.h"
#include "BlackHole.h"
#include "SceneMain.h"
#include "ObjMainChara.h"
#include "Enemy.h"
#include "EnemyBullet.h"
#include "CharaBullet.h"
#include "ObjStar.h"
#include "ObjCollectionItemBig.h"
#include "ObjCollectionItemSmall.h"
#include "ScrollChange.h"
#include "Plane.h"
#include "Score.h"
#include "Title.h"
#include "GameOver.h"
#include "GameClear.h"
#include "Goal.h"
//------------------------------------------------

//ゲームシーンクラスヘッダ------------------------
#include "SceneMain.h"
#include "SceneTitle.h"
#include "SceneGameOver.h"
#include "SceneGameClear.h"
//-----------------------------------------------

//シーンスタートクラス---------------------------
//ゲーム開始時のシーンクラス登録
#define SET_GAME_START CSceneMain
//-----------------------------------------------