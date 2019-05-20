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
	//描画色(黄色)
	float m_fColor_Yellow[4];
	//描画色(赤)
	float m_fColor_Red[4];
	//順位を保存する用
	int m_iRanking;
	//ループ用
	int m_iLoop;
};