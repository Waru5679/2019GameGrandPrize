#pragma once
#include "GameL/SceneObjManager.h"
#include "Vector.h"
using namespace GameL;

//敵クラス
class CCharaBullet :public CObj
{
public:
	CCharaBullet(Vector vPos, Vector vMove);
	void Init();	//初期化
	void Action();	//更新
	void Draw();	//描画
private:
	float m_fColor[4];	//描画色
	Vector m_vPos;		//位置
	Vector m_vMove;		//移動
	float m_fRot;		//回転
	bool m_bInWindow;	//画面内かどうか
};