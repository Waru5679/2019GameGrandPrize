#include "GameL/HitBoxManager.h"
#include "GameL/SceneManager.h"

#include "EnemyBullet.h"
#include "Function.h"
#include "GameHead.h"
#include "Function.h"

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

	//画面内
	m_bInWindow=true;

	m_bShot = true;

	//当たり判定用HitBox作成
	Hits::SetHitBox(this, m_vPos.x, m_vPos.y, 32.0f, 32.0f, ELEMENT_ENEMY_BULLET, OBJ_ENEMY_BULLET, 1);
}

//更新
void CEnemyBullet::Action()
{
	//移動

	if (m_bShot == true)
	{
		/*CObjMainChara* obj_chara = new CObjMainChara();

		float x = obj_chara->GetPos.x - m_vPos.x;
		float y = obj_chara->GetPos.y - m_vPos.y;
		float ar = GetAtan2Angle(x, -y);

		float br = GetAtan2Angle(m_vMove.x, m_vMove.y);

		float r = 3.14f / 180.0f;

		if (ar < br)
		{
			m_vMove.x = m_vMove.x * cos(r) - m_vMove.y * sin(r);
			m_vMove.y = m_vMove.y * cos(r) - m_vMove.x * sin(r);
		}
		else
		{
			m_vMove.x = m_vMove.x * cos(r) - m_vMove.y * sin(r);
			m_vMove.y = m_vMove.y * cos(r) - m_vMove.x * sin(r);
		}
		UnitVec(&m_vMove.x, &m_vMove.y);*/

	}

	m_vPos = CVector::Add(m_vPos, m_vMove);

	//画面内か調べる
	m_bInWindow = WindowInCheck(m_vPos, CVector::Create(BULLET_SIZE, BULLET_SIZE));

	//当たり判定----------------------------------------------

	//Hitbox更新
	CHitBox* hit_b = Hits::GetHitBox(this);
	hit_b->SetPos(m_vPos.x, m_vPos.y);

	//画面内なら消す
	if (m_bInWindow == false)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}

	//---------------------------------------------------------
}

//描画
void CEnemyBullet::Draw()
{
	RECT_F src, dst;

	//切り取り位置
	RectSet(&src, 0.0f, 0.0f, 128.0f, 128.0f);

	//描画位置
	RectSet(&dst, m_vPos.y, m_vPos.x, ENEMY_SIZE, ENEMY_SIZE);

	//描画
	Draw::Draw(OBJ_ENEMY_BULLET, &src, &dst, m_fColor, m_fRot);
}
