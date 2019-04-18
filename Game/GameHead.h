#pragma once

//オブジェクトネーム------------------------------
enum OBJ_NAME
{
	//ゲームで使うオブジェクトの名前
	//OBJ_○○と表記
	OBJ_NO_NAME,	//オブジェクト名無し(禁止)
	OBJ_BACK_GROUND,//背景
	OBJ_MAP,		//マップ
	OBJ_HOLE,		//穴
	OBJ_CHARA,		//キャラクタ
	OBJ_ENEMY,		//敵
	OBJ_ENEMY_BULLET,//敵の弾
	OBJ_CHARA_BULLET,//主人公の弾
	OBJ_STAR,		 //星オブジェクト
	OBJ_ITEM_BIG,	 //収集アイテムオブジェクト(大)
	OBJ_ITEM_SMALL,	 //収集アイテムオブジェクト(小)
	OBJ_SCORE,		 //スコア
	OBJ_SCROLL_CHANGE,//スクロールの切り変えオブジェクト
};
//------------------------------------------------

//当たり判定属性----------------------------------
enum HIT_ELEMENTS
{
	ELEMENT_NULL,//属性無し 全ての属性と当たり判定が実行される
	//以下　同じ属性同士では当たり判定は実行されない
	//属性は追加可能だが、デバック時の色は初期設定分しか無い
	ELEMENT_PLAYER,
	ELEMENT_ENEMY,
	ELEMENT_ITEM_BIG,
	ELEMENT_ITEM_SMALL,
	ELEMENT_CHARA_BULLET,
	ELEMENT_ENEMY_BULLET,
	ELEMENT_STAR,
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
#define SIDE true		//横
#define VERTICAL false	//縦

//マップ
#define MAX_X 10
#define MAX_Y 10

//最大アイテム数
#define MAX_ITEM 4

//マップ数値
enum MAP_NUM
{
	MAP_NONE,		//何もない
	MAP_HOLE,		//穴
	MAP_ENEMY,		//敵
	MAP_STAR,		//星
	MAP_ITEM_BIG,	//収集アイテム(大)
	MAP_ITEM_SMALL,	//収集アイテム(小)
	MAP_SCROLL_CHANGE,//スクロールの切り替え
};

//アイテム用数値
enum ITEM_NUM
{
	ITEM_BIG,		//アイテム(大)
	ITEM_SMALL,		//アイテム(小)
};

//オブジェクトサイズ
#define OBJ_SIZE		32.0f
#define HOLE_SIZE		32.0f
#define ENEMY_SIZE		64.0f
#define BULLET_SIZE		32.0f
#define CHARA_SIZE		64.0f
#define STAR_SIZE		64.0f
#define ITEM_BIG_SIZE	64.0f
#define ITEM_SMALL_SIZE	32.0f
#define SCROLL_CHANGE_SIZE 64.0f

//スコア
#define SCORE_BIG		1000;
#define SCORE_SMALL		 500;
#define SCORE_BONUS		 250;

//------------------------------------------------
//ゲーム内で使用するクラスヘッダ------------------


//------------------------------------------------

//ゲームシーンオブジェクトヘッダ------------------
#include "BackGround.h"
#include "Map.h"
#include "Hole.h"
#include "SceneMain.h"
#include "ObjMainChara.h"
#include "Enemy.h"
#include "EnemyBullet.h"
#include "CharaBullet.h"
#include "ObjStar.h"
#include "ObjCollectionItemBig.h"
#include "ObjCollectionItemSmall.h"
#include "ScrollChange.h"
#include "Score.h"
//------------------------------------------------

//ゲームシーンクラスヘッダ------------------------
#include "SceneMain.h"
//-----------------------------------------------

//シーンスタートクラス---------------------------
//ゲーム開始時のシーンクラス登録
#define SET_GAME_START CSceneMain 
//-----------------------------------------------