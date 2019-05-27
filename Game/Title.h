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

	char m_cName[6];	//名前初期化用

	int m_iTime;		//文字の点滅用タイム
	bool m_bTime_Flag;	//文字の点滅用フラグ　true:表示時 false:消えてる時
};