#pragma once
#include "GameL/SceneObjManager.h"

//スコアクラス
using namespace GameL;
class CScore :public CObj
{
public:
	void Init();	//初期化
	void Action();	//更新
	void Draw();	//描画

	//描画色
	float m_fColor[4];

	//スコアの位置
	float m_fPos_x;
	float m_fPos_y;
};