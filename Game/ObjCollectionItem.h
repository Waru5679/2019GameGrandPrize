#pragma once
#include "GameL/SceneObjManager.h"

using namespace GameL;

//収集アイテムクラス 以下アイテム
class CCollectionItem : public CObj
{
public:
	CCollectionItem(int x, int y);
	void Init();	//初期化
	void Action();	//更新
	void Draw();	//描画

	//描画色
	float m_fColor[4];

	//アイテムの位置
	float m_fPos_x;
	float m_fPos_y;
};