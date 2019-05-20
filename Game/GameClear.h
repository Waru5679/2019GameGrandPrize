#pragma once

#include "GameL/SceneObjManager.h"

using namespace GameL;

//ゲームクリアクラス
class CGameClear :public CObj
{
public:
	CGameClear() {};
	void Init();	//初期化
	void Action();	//更新
	void Draw();	//描画

private:
	//描画色
	float m_fColor[4];
	float m_fColor_Yellow[4];

	//順位を保存する用
	int m_iRanking;
};