#pragma once

#include "GameL/SceneObjManager.h"
#include "Vector.h"

using namespace GameL;

//穴クラス
class CHole :public CObj
{
public:
	CHole(int x, int y);
	void Init();	//初期化
	void Action();	//更新
	void Draw();	//描画
private:
	
	//描画色
	float m_fColor[4];

	//位置
	Vector m_vPos;

};