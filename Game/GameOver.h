#pragma once

#include "GameL/SceneObjManager.h"

using namespace GameL;

//ゲームオーバークラス
class CGameOver :public CObj
{
public:
	CGameOver() {};
	void Init();	//初期化
	void Action();	//更新
	void Draw();	//描画

	
private:

	//描画色
	float m_fColor[4];
	//ランキング探索用(1回のみ)
};