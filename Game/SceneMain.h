#pragma once

#include "GameL/SceneManager.h"
#include "GameHead.h"

using namespace GameL;

//メインシーン
class CSceneMain:public CScene
{
public:
	void InitScene();	//初期化
	void Scene();		//実行中

	bool GetScroll() { return m_bScroll; }
private:
	void LoadTexture();	//テクスチャ読み込み
	int m_Count;	//タイムカウンタ

	//マップポインタ
	int* m_pMap;

	//背景ポインタ
	CBackGround* m_pBack1;
	CBackGround* m_pBack2;

	//スクロール方向
	bool m_bScroll;
};