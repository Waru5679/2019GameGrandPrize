#pragma once
#include "GameL/SceneObjManager.h"
#include "Vector.h"
using namespace GameL;

//敵弾丸クラス
class CEnemyBullet :public CObj
{
public:
	CEnemyBullet(Vector vPos, Vector vMove);
	void Init();
	void Action();
	void Draw();
private:
	float m_fColor[4];	//描画色
	Vector m_vPos;		//位置
	Vector m_vMove;		//移動
	Vector m_vBulletDir;//弾の向き
	float m_fRot;		//回転
	bool m_bInWindow;	//画面内かどうか
};