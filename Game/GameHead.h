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
	ELEMENT_ITEM,
	ELEMENT_MAGIC,
	ELEMENT_FIELD,
	ELEMENT_RED,
	ELEMENT_GREEN,
	ELEMENT_BLUE,
	ELEMENT_BLACK,
	ELEMENT_WHITE,
};
//------------------------------------------------

//------------------------------------------------
//セーブ＆ロードとシーン間のやり取りするデータ
struct UserData
{
	int mSeveData;	//サンプルセーブデータ
	
};
//------------------------------------------------


//ゲーム内で使用されるグローバル変数・定数・列挙--

//ベクトル構造体
struct Vector
{
	float x;
	float y;
};

//スクロール
#define SIDE true		//横
#define VERTICAL false	//縦

//マップ
#define MAX_X 10
#define MAX_Y 10



//マップ数値
enum MAP_NUM
{
	MAP_NONE,	//何もない
	MAP_HOLE,	//穴
	MAP_ENEMY,	//敵
};

//オブジェクトサイズ
#define OBJ_SIZE	32.0f
#define HOLE_SIZE	32.0f
#define ENEMY_SIZE	32.0f

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
//------------------------------------------------

//ゲームシーンクラスヘッダ------------------------
#include "SceneMain.h"
//-----------------------------------------------

//シーンスタートクラス---------------------------
//ゲーム開始時のシーンクラス登録
#define SET_GAME_START CSceneMain 
//-----------------------------------------------