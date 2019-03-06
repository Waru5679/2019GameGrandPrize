#pragma once
#include "GameL/SceneObjManager.h"
#include "GameHead.h"

using namespace GameL;

//マップクラス
class CMap :public CObj
{
public:
	CMap(int map[MAX_Y][MAX_X]);
	void Init();	//初期化
	void Action();	//更新
	void Draw();	//描画
	void Create();	//生成
private:
	int m_Map[MAX_Y][MAX_X];	//マップデータ
	float m_fColor[4];			//描画色
};