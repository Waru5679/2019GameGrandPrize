#pragma once
#include "GameL/SceneObjManager.h"
#include "Vector.h"

using namespace GameL;

//敵上下クラス
class CEnemyUpDown :public CObj
{
public:
	CEnemyUpDown(int x, int y);
	void Init();	//初期化
	void Action();	//更新
	void Draw();	//描画

private:
	float m_fColor[4];	//描画色
	Vector m_vPos;		//位置
	Vector m_vBulletMove;//弾の向き
	float m_fvx;		//移動ベクトル
	float m_fvy;		
	int m_Count;		//カウンタ
	int m_iBulletCount;	//バレットカウンタ
};