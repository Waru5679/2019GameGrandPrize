#pragma once
#include "GameL/SceneObjManager.h"
#include "Vector.h"
using namespace GameL;

#define SHOT_TIME 60

//敵クラス
class CEnemy :public CObj
{
public:
	CEnemy(int x, int y) ;
	void Init();	//初期化
	void Action();	//更新
	void Draw();	//描画
private:
	float m_fColor[4];	//描画色
	Vector m_vPos;		//位置
	float m_fvx;		//移動ベクトル
	float m_fvy;		
	int m_Count;		//カウンタ
	Vector m_fChara;	//キャラの位置取得用
	Vector m_fSpeed;	//速度
	bool m_bInWindow;	//画面内かどうか
};