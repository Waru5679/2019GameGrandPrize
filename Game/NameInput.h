#pragma once

#include "GameL/SceneObjManager.h"

using namespace GameL;

//名前入力クラス
class CNameInput :public CObj
{
public:
	CNameInput() {};
	void Init();	//初期化
	void Action();	//更新
	void Draw();	//描画
private:
	float m_fColor[4];
};