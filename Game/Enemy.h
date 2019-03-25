#pragma once
#include "GameL/SceneObjManager.h"
#include "GameHead.h"
using namespace GameL;

//敵クラス
class CEnemy :public CObj
{
public:
	CEnemy(int x, int y) ;
	void Init();	//初期化
	void Action();	//更新
	void Draw();	//描画
private:
	float m_fColor[4];
	Vector m_vPos;
};