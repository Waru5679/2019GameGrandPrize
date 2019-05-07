#pragma once

#include "GameL/SceneObjManager.h"

using namespace GameL;

//ランキングクラス
class CRanking :public CObj
{
public:
	CRanking() {};
	void Init();	//初期化
	void Action();	//更新
	void Draw();
private:
	//描画色
	float m_fColor[4];
};