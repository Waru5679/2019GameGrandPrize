#pragma once

#include "GameL/SceneObjManager.h"

using namespace GameL;

//タイトルクラス
class CTitle :public CObj
{
public:
	CTitle() {};
	void Init();	//初期化
	void Action();	//更新
	void Draw();	//描画
private:

	//描画色(白)
	float m_fColor[4];
	//描画色(黄色)
	float m_fColor_Yellow[4];

	char m_cName[6];
};