#pragma once
#include "GameL/SceneObjManager.h"
#include "Vector.h"
using namespace GameL;

//星クラス
class CStar :public CObj
{
public:
	CStar(int x, int y);

	void Init();	//初期化
	void Action();	//更新
	void Draw();	//描画

private:
	//描画色
	float m_fColor[4];

	//星の位置
	Vector m_vPos;

	//スクロールの向き
	bool m_bScroll;
};