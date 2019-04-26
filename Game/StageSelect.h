#pragma once

#include "GameL/SceneObjManager.h"

using namespace GameL;

//ステージセレクトクラス
class CStageSelect : public CObj
{
public:
	CStageSelect() {};
	void Init();		//初期化
	void Action();		//更新
	void Draw();		//描画
private:
	//描画色
	float m_fColor[4];

	//ステージ＆ランキングセレクト判定
	int SelectNum;
};