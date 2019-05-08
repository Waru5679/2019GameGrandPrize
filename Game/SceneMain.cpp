#include "SceneMain.h"
#include "GameL/DrawTexture.h"
#include "GameHead.h"
#include "main.h"
#include "GameL/UserData.h"
#include "Csv.h"
#include "GameL/Audio.h"

//初期化
void CSceneMain::InitScene()
{
	//テクスチャ読み込み
	LoadTexture();

	//音楽読み込み
	LoadAudio();

	//マップ情報読み込み
	m_pSideMap=CCsv::LoadCsv("Map/Stage1/Side.csv",SIDE_MAX_X,SIDE_MAX_Y);
	m_pVarticalMap = CCsv::LoadCsv("Map/Stage1/Vartical.csv", VARTICAL_MAX_X, VARTICAL_MAX_Y);

	//カウンタ初期化
	m_Count = 0;


	//スクロール方向
	m_bScroll = SIDE;

	//背景オブジェクト1
	m_pBack1 = new CBackGround(0.0f, 0.0f, SIDE);
	Objs::InsertObj(m_pBack1, OBJ_BACK_GROUND, 1);

	//背景オブジェクト2
	m_pBack2 = new CBackGround(WINDOW_SIZE_W, 0.0f, SIDE);
	Objs::InsertObj(m_pBack2, OBJ_BACK_GROUND, 1);

	//マップオブジェクト
	CMap* pMap = new CMap(m_pSideMap,m_pVarticalMap);
	Objs::InsertObj(pMap, OBJ_MAP, 100);

	//キャラクターオブジェクト
	CObjMainChara* pChara = new CObjMainChara();
	Objs::InsertObj(pChara, OBJ_CHARA, 10);

	//スコア表示オブジェクト
	CScore* pScore = new CScore();
	Objs::InsertObj(pScore, OBJ_SCORE, 10);

	//Debug用　スクロールチェンジ
	//CScrollChange* pScroll = new CScrollChange(0, 0,VARTICAL);
	//Objs::InsertObj(pScroll, OBJ_SCROLL_CHANGE, 10);

	//ボリューム調整
	Audio::Volume(-0.8f, 0);
	
	//スタート
	Audio::Start(0);

}

//実行中
void CSceneMain::Scene()
{
	
}


//スクロール切り替え
void CSceneMain::ScrollChange()
{
	//スクロール方向の切り替え
	m_bScroll = !(m_bScroll);

	//背景の位置とスクロール方向の変更

	//横→縦に変更
	if (m_bScroll == VARTICAL)
	{
		m_pBack1->SetScroll(0.0f, 0.0f, VARTICAL);
		m_pBack2->SetScroll(0.0f, WINDOW_SIZE_H, VARTICAL);
	}
	//縦→横に変更
	else
	{
		m_pBack1->SetScroll(0.0f, 0.0f, SIDE);
		m_pBack2->SetScroll(WINDOW_SIZE_W, 0.0f, SIDE);
	}
}

//テクスチャ読み込み
void CSceneMain::LoadTexture()
{
	//背景
	Draw::LoadImageW(L"Texture/BackGround.png", OBJ_BACK_GROUND, TEX_SIZE_512);

	//穴
	Draw::LoadImageW(L"Texture/BlackHole.png", OBJ_BLACK_HOLE, TEX_SIZE_128);

	//主人公
	Draw::LoadImageW(L"Texture/MainCharacter.png",OBJ_CHARA, TEX_SIZE_128);
	//敵
	Draw::LoadImageW(L"Texture/Enemy.png", OBJ_ENEMY, TEX_SIZE_256);

	//敵弾丸
	Draw::LoadImageW(L"Texture/EnemyBullet.png", OBJ_ENEMY_BULLET, TEX_SIZE_128);

	//主人公弾丸
	Draw::LoadImageW(L"Texture/PlayerBullet.png", OBJ_CHARA_BULLET, TEX_SIZE_128);

	//星
	Draw::LoadImageW(L"Texture/Planet.png", OBJ_STAR, TEX_SIZE_128);

	//収集アイテム
	Draw::LoadImageW(L"Texture/Collection.png", OBJ_ITEM_BIG, TEX_SIZE_128);
	Draw::LoadImageW(L"Texture/Collection.png", OBJ_ITEM_SMALL, TEX_SIZE_128);

	//スクロールのチェンジ
	Draw::LoadImageW(L"Texture/ScrollChange.png", OBJ_SCROLL_CHANGE, TEX_SIZE_128);

	//床
	Draw::LoadImageW(L"Texture/Plane.png", OBJ_PLANE, TEX_SIZE_128);

	//クリアアイテム読み込み
	Draw::LoadImageW(L"Texture/Clear.png", OBJ_GAME_CLEAR, TEX_SIZE_128);

	//上下移動する敵読み込み
	Draw::LoadImageW(L"Texture/Enemy2.png", OBJ_ENEMY_UPDOWN, TEX_SIZE_256);

}

//音楽読み込み
void CSceneMain::LoadAudio()
{
	//BGMtest
	Audio::LoadAudio(0, L"Audio/Test2.wav", BACK_MUSIC);
}