#pragma once

#include "GameL/SceneObjManager.h"
#include "Vector.h"
#include "GameL/HitBoxManager.h"

using namespace GameL;

//ブラックホールクラス
class CBlackHole :public CObj
{
public:
	CBlackHole(int x, int y);
	void Init();	//初期化
	void Action();	//更新
	void Draw();	//描画
private:
	
	//描画色
	float m_fColor[4];

	//位置
	Vector m_vPos;
	Vector m_vDeathPos;	//死亡判定の位置

	//吸引力
	float m_fSuctionPower;

	//スクロールの向き
	bool m_bScroll;

	CHitBox* m_pSuction;	//吸引判定
	CHitBox* m_pDeath;		//死亡判定	
};