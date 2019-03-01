#pragma once

#include "GameL/SceneManager.h"

#include "BackGround.h"
using namespace GameL;

//メインシーン
class CSceneMain:public CScene
{
public:
	void InitScene();
	void Scene();
private:
	void LoadTexture();
	int m_Count;

	//背景
	CBackGround* m_pBack1;
	CBackGround* m_pBack2;

	//スクロール方向
	bool m_bScroll;

};