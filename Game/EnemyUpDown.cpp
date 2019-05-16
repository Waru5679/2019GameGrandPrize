#include "GameL/HitBoxManager.h"
#include "GameL/SceneManager.h"

#include "EnemyUpDown.h"
#include "Function.h"
#include "GameHead.h"

//コンストラクタ
CEnemyUpDown::CEnemyUpDown(int x, int y)
{
	//位置
	m_vPos.x = (float)x * OBJ_SIZE;
	m_vPos.y = (float)y * OBJ_SIZE;
}

//初期化
void CEnemyUpDown::Init()
{
	//色
	ColorSet(1.0f, 1.0f, 1.0f, 1.0f, m_fColor);

	//カウンタ
	m_Count = 0;

	//移動
	m_fvx = 0.0f;
	m_fvy = SCROLL_SPEED;

	m_vBulletMove.x = 0.0f;
	m_vBulletMove.y = SCROLL_SPEED;

	//当たり判定用HitBox作成
	Hits::SetHitBox(this, m_vPos.x, m_vPos.y, ENEMY_SIZE, ENEMY_SIZE, ELEMENT_ENEMY,OBJ_ENEMY_UPDOWN, 1);
}

//更新
void CEnemyUpDown::Action()
{
	//移動
	if (m_vPos.y >= 0)
	{
		m_Count++;

		if (m_Count >= 360.0f)
		{
			m_fvy = -SCROLL_SPEED;
		}
		else if(m_Count >= 180.0f)
		{
			m_fvy = 0.0f;
		}

	}

	//位置の更新
	m_vPos.x += m_fvx;
	m_vPos.y += m_fvy;

	//カウンタ更新
	m_iBulletCount++;
	if (m_iBulletCount > 10000)
		m_iBulletCount = 0;

	if (m_iBulletCount % SHOT_TIME == 0)
	{
		//弾生成
		CEnemyBullet* pBullet = new CEnemyBullet(m_vPos, m_vBulletMove);
		Objs::InsertObj(pBullet, OBJ_ENEMY_BULLET, 50);
		
	}


	//HitBox更新
	CHitBox* hit_b = Hits::GetHitBox(this);
	hit_b->SetPos(m_vPos.x, m_vPos.y);

	//主人公の弾に当たると消滅
	if (hit_b->CheckObjNameHit(OBJ_CHARA_BULLET) != nullptr)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}

	//カウントが3秒以上で画面外に出たら削除
	if (m_Count >= 180.0f)
	{
		if (m_vPos.y + ENEMY_SIZE < 0)
		{
			this->SetStatus(false);
			Hits::DeleteHitBox(this);
		}
	}

}

//描画
void CEnemyUpDown::Draw()
{
	RECT_F src, dst;

	//切り取り位置
	RectSet(&src, 0.0f, 0.0f, 256.0f, 256.0f);

	//描画位置
	RectSet(&dst, m_vPos.y, m_vPos.x, ENEMY_SIZE, ENEMY_SIZE);

	//描画
	Draw::Draw(OBJ_ENEMY_UPDOWN, &src, &dst, m_fColor, 0.0f);
}