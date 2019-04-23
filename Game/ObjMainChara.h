#pragma once
//使用するヘッダー
#include "GameL/SceneObjManager.h"
#include "GameL/HitBoxManager.h"

#include "Vector.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：主人公
class CObjMainChara : public CObj
{
public:

	void Init();	//イニシャライズ

	void SideMove();		//移動横
	void VarticalMove();	//移動縦

	void SideInput();		//横の入力
	void VarticalInput();	//縦の入力
	   
	void Action();	//アクション
	void Draw();	//ドロー

	Vector GetPos() { return m_vPos; }

	//床とのヒット
	void PlaneHit(Vector vPos);

	//ブラックホールとのヒット処理
	void HitBlackHole(Vector Vec);

private:
	Vector m_vPos;			//位置
	Vector m_vMove;			//移動
	Vector m_vPlanePos;		//地面の位置

	float m_fDirection;		//向き
	bool m_bDirection;		//向き 右向き:false 左向き:true
	float m_fGravity;		//重力
	bool m_bScroll;			//スクロールの向き
	bool m_bHitGround;
	bool m_bBullet_FireIs;	//弾丸制御

	bool m_bIsHitBlackHole;//ブラックホールヒット判定

	//描画色
	float m_fColor[4];

	CHitBox* m_pBody;	//キャラの当たり判定胴体用
	CHitBox* m_pLeg;	//キャラの当たり判定足用
};