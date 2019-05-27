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
	void CreateSideFirst();		//横生成(初回)
	void CreateSideSecond();	//横生成(2回目以降)
	void CreateVerticalFirst();	//縦生成(初回)
	void CreateVerticalSecond();//縦生成(2回目以降)

	int m_iMapItem[MAX_ITEM];	//マップ内のアイテム数取得用配列
	int m_iMapLoop;				//マップ配列探索用変数
private:
	//マップデータ
	int m_SideMap[SIDE_MAX_Y][SIDE_MAX_X];	
	int m_VarticalMap[VARTICAL_MAX_Y][VARTICAL_MAX_X];
	
	float m_fColor[4];			//描画色
	bool m_bScroll;				//スクロールの状態取得
	float m_fScroll;			//スクロール移動
	bool m_bFirstTimeSide;		//生成横
	bool m_bFirstTimeVertical;	//生成縦
	bool m_bScrollChangeIs;		//スクロールチェンジ判定
	float m_fMovePos_x;			//スクロールした移動量保存用変数
	float m_fMovePos_y;
	int m_fMoveAddPos_x;		//2回目以降生成位置調整用変数
	int m_fMoveAddPos_y;
};