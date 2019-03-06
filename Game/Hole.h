#pragma once

#include "GameL/SceneObjManager.h"

using namespace GameL;

//穴クラス
class CHole :public CObj
{
public:
	CHole(int y, int x);
	void Init();	//初期化
	void Action();	//更新
	void Draw();	//描画
private:
	
	//描画色
	float m_fColor[4];

	//背景の位置
	float m_fPos_x;
	float m_fPos_y;

};