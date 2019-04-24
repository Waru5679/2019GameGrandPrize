#include "GameL/HitBoxManager.h"
#include "GameL/SceneManager.h"

#include "EnemyBullet.h"
#include "Function.h"
#include "GameHead.h"

//コンストラクタ
CEnemyBullet::CEnemyBullet(Vector vPos,Vector vMove)
{
	//位置
	m_vPos = vPos;
	
	//移動
	m_vMove = vMove;
}

//初期化
void CEnemyBullet::Init()
{
	//色
	ColorSet(1.0f, 1.0f, 1.0f, 1.0f, m_fColor);

	//回転
	m_fRot = 0.0f;

	//画面外
	m_bInWindow=true;

	m_bShot = true;
	m_fShotTime = 0.0f;

	//当たり判定用HitBox作成
	Hits::SetHitBox(this, m_vPos.x, m_vPos.y, BULLET_SIZE, BULLET_SIZE, ELEMENT_ENEMY, OBJ_ENEMY_BULLET, 1);
}

//更新
void CEnemyBullet::Action()
{
	if (m_bShot == true)
	{
		CObjMainChara* pChara = dynamic_cast<CObjMainChara*>(Objs::GetObj(OBJ_CHARA));

		//主人公のポジションセット
		Vector m_vPos_Chara = pChara->GetPos();
		m_vPos_Chara.x = m_vPos_Chara.x - m_vPos.x;
		m_vPos_Chara.y = m_vPos_Chara.y - m_vPos.y;

		//主人公の角度を取る
		float m_fAngle_Chara = GetAtan2Angle(m_vPos_Chara.x, -m_vPos_Chara.y);
		//自分の弾(EnemyBullet)の角度を取る
		float m_fAngle_Bullet = GetAtan2Angle(m_vMove.x, -m_vMove.y);


		//角度1°
		float r = 3.14f / 180.0f;

		//arよりbrが低い場合移動方向に+1°加える
		//違う場合移動方向に-1°加える
		if (m_fAngle_Chara < m_fAngle_Bullet)
		{
			m_vMove.x = m_vMove.x * cos(r) - m_vMove.y * sin(r);
			m_vMove.y = m_vMove.y * cos(r) + m_vMove.x * sin(r);
		}
		else
		{
			m_vMove.x = m_vMove.x * cos( r) - m_vMove.y * sin( r);
			m_vMove.y = m_vMove.y * cos(-r) + m_vMove.x * sin(-r);
		}

		//正規化
		UnitVec(&m_vMove.x, &m_vMove.y);	
		m_bShot = false;
	}

	m_vPos = CVector::Add(m_vPos, m_vMove);

	//画面外か調べる
	m_bInWindow = WindowInCheck(m_vPos, CVector::Create(BULLET_SIZE, BULLET_SIZE));

	//当たり判定

	//Hitbox更新
	CHitBox* hit_b = Hits::GetHitBox(this);
	hit_b->SetPos(m_vPos.x, m_vPos.y);

	//主人公に当たるとゲームオーバーへ移行
	if (hit_b->CheckObjNameHit(OBJ_CHARA) != nullptr)
	{
		//自身を削除
	//	this->SetStatus(false);
	//	Hits::DeleteHitBox(this);
		//ゲームオーバー
	//	Scene::SetScene(new CSceneGameOver());
	}

	//画面外なら消す
	if (m_bInWindow == false)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}

}

//描画
void CEnemyBullet::Draw()
{
	RECT_F src, dst;

	//切り取り位置
	RectSet(&src, 0.0f, 0.0f, 128.0f, 128.0f);

	//描画位置
	RectSet(&dst, m_vPos.y, m_vPos.x, BULLET_SIZE, BULLET_SIZE);

	//描画
	Draw::Draw(OBJ_ENEMY_BULLET, &src, &dst, m_fColor, m_fRot);
}
