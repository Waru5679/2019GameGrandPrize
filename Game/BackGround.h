#pragma once

#include "GameL/SceneObjManager.h"

using namespace GameL;

//背景クラス
class CBackGround :public CObj
{
public:
	//コンストラクタ
	CBackGround(float Pos_x, float Pos_y, bool Scroll);

	void Init();	//初期化
	void Action();	//更新
	void Draw();	//描画

	//スクロールのセット
	void SetScroll(float Pos_x, float Pos_y,bool Scroll);
private:
	float m_fColor[4];	//描画色
	
	//スクロール方向の管理
	bool m_bScroll;

	//背景1の位置
	float m_fPos_x;	
	float m_fPos_y;
};