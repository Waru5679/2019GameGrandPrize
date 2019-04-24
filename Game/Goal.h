#pragma once
#include "GameL/SceneObjManager.h"
#include "Vector.h"

using namespace GameL;

//クリアアイテムクラス
class CGoal :public CObj
{
public:
	CGoal(int x, int y);

	void Init();	//初期化
	void Action();	//更新
	void Draw();	//描画

private:
	Vector m_vPos;	//位置

	//描画色
	float m_fColor[4];
};