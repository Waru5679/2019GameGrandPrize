#pragma once
#include "GameL/SceneObjManager.h"
#include "GameHead.h"

using namespace GameL;

//マップクラス
class CMap :public CObj
{
public:
	CMap(int* pSideMap, int* pVarticalMap);
	void Init();	//初期化
	void Action();	//更新
	void Draw();	//描画
	void CreateSide();	//横生成
	void CreateVertical();//縦生成

	int m_iMapItem[MAX_ITEM];	//マップ内のアイテム数取得用配列
	int m_iMapLoop;				//マップ配列探索用変数
private:
	//マップデータ
	int m_SideMap[SIDE_MAX_Y][SIDE_MAX_X];	
	int m_VarticalMap[VARTICAL_MAX_Y][VARTICAL_MAX_X];
	
	float m_fColor[4];			//描画色
	bool m_bScroll;				//スクロールの状態取得
	float m_fScroll;			//スクロール移動
};