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
	void Draw();	//描画

private:
	//描画色
	float m_fColor[4];
	int m_iRankChenge;		//ページ切り替え用変数
	bool m_bChangeLeftIs;	//連打判定回避用左
	bool m_bChangeRightIs;	//連打判定回避用右
};