#pragma once
//使用するヘッダー
#include "GameL/SceneObjManager.h"
#include "Vector.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：主人公
class CObjMainChara : public CObj
{
public:
	CObjMainChara() {};
	~CObjMainChara() {};
	void Init();	//イニシャライズ
	void Action();	//アクション
	void Draw();	//ドロー
	Vector GetPos() { return m_vPos; }
	void Move();//移動

private:
	Vector m_vPos;//位置
	float m_fvx;	//移動ベクトル
	float m_fvy;
	float m_fDirection;	//向き
	bool m_bDirection;	//向き 右向き:false 左向き:true
	float m_fGravity;	//重力
	bool m_bScroll;		//スクロールの向き
	bool m_bHitGround;	
	bool m_bBullet_FireIs;//弾丸制御

	//描画色
	float m_fColor[4];
};