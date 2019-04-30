#pragma once
#include "GameL/SceneObjManager.h"
#include "Vector.h"

using namespace GameL;

//スクロールの切り替えクラス
class CScrollChange :public CObj
{
public:
	CScrollChange(int x, int y,bool bScroll);
	
	void Init();	//初期化
	void Action();	//更新
	void Draw();	//描画

private:
	Vector m_vPos;	//位置
	Vector m_vHitSize;	//当たり判定用サイズ
	
	//描画色
	float m_fColor[4];
	bool m_bScroll;
};