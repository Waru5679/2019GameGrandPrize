#pragma once
#include "GameL/SceneObjManager.h"

using namespace GameL;

//収集アイテムクラス 以下アイテム
class CCollectionItemSmall : public CObj
{
public:
	CCollectionItemSmall(int x, int y,int number);
	void Init();	//初期化
	void Action();	//更新
	void Draw();	//描画

private:
	//描画色
	float m_fColor[4];

	//アイテムの位置
	float m_fPos_x;
	float m_fPos_y;

	//スコアの場所探索用
	int m_iPosition;

	//スクロールの向き
	bool m_bScroll;
};