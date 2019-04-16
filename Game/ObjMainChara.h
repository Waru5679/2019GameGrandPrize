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

	void SideMove();		//移動横
	void VarticalMove();	//移動縦

	void SideInput();		//横の入力
	void VarticalInput();	//縦の入力
	   
	void Action();	//アクション
	void Draw();	//ドロー

	Vector GetPos() { return m_vPos; }

private:
	Vector m_vPos;	//位置
	Vector m_vMove;	//移動

	float m_fDirection;	//向き
	bool m_bDirection;	//向き 右向き:false 左向き:true
	float m_fGravity;	//重力
	bool m_bScroll;		//スクロールの向き
	bool m_bHitGround;
	bool m_bBullet_FireIs;//弾丸制御

	//描画色
	float m_fColor[4];
};