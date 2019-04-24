#include "GameL/HitBoxManager.h"
#include "GameL/SceneManager.h"

#include "Enemy.h"
#include "Function.h"
#include "GameHead.h"

//コンストラクタ
CEnemy::CEnemy(int x, int y)
{
	//位置
	m_vPos.x = (float)x * OBJ_SIZE;
	m_vPos.y = (float)y * OBJ_SIZE;
}

//初期化
void CEnemy::Init()
{
	//色
	ColorSet(1.0f, 1.0f, 1.0f, 1.0f, m_fColor);
	
	//カウンタ
	m_Count = 0;
	
	//移動
	//画面内に入ると縦をゆっくり動くようにする
	if (m_vPos.y > 0.0f)
	{
		m_fvy = 0.2f;
	}
	//画面外
	else
	{
		m_fvy = SCROLL_SPEED;
	}
	//画面半分より左なら右移動
	if (m_vPos.x < WINDOW_SIZE_W / 2.0f)
	{
		m_fvx = 1.0f;
	}
	//画面半分より右なら左移動
	else
	{
		m_fvx = -1.0f;
	}

	//弾丸用速度
	m_fSpeed.x = 1.0f;
	m_fSpeed.y = 1.0f;

	//主人公の位置取得
	CObjMainChara* obj_pChara = new CObjMainChara();
	m_fChara = obj_pChara->GetPos();

	//当たり判定用HitBox作成
	Hits::SetHitBox(this, m_vPos.x, m_vPos.y, ENEMY_SIZE, ENEMY_SIZE, ELEMENT_ENEMY, OBJ_ENEMY, 1);
}

//更新
void CEnemy::Action()
{
	
	//位置の更新
	m_vPos.x += m_fvx;
	m_vPos.y += m_fvy;

	//攻撃-----------------------------------------------------------
	//カウンタ更新
	m_Count++;
	if (m_Count > 10000)
		m_Count = 0;

	if (m_Count % SHOT_TIME == 0)
	{
		//キャラクタのポインタ
		CObjMainChara* pChara = dynamic_cast<CObjMainChara*>(Objs::GetObj(OBJ_CHARA));

		//キャラクタの位置を取得
		if (pChara != nullptr)
		{
			Vector vCharaPos = pChara->GetPos();

			//弾生成
			CEnemyBullet* pBullet = new CEnemyBullet(m_vPos, CVector::Create(vCharaPos.x - 240.0f , vCharaPos.y));
			Objs::InsertObj(pBullet, OBJ_ENEMY_BULLET, 10);
		}
	}
	//---------------------------------------------------------------

	//当たり判定-----------------------------------------------------

	//HitBox更新
	CHitBox* hit_b = Hits::GetHitBox(this);
	hit_b->SetPos(m_vPos.x, m_vPos.y);

	//主人公の弾に当たると消滅
	if (hit_b->CheckObjNameHit(OBJ_CHARA_BULLET) != nullptr)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}
	//--------------------------------------------------------------

	//アイテム(大)オブジェクトが画面端へ出ると削除
	//右移動の時画面右端
	if (m_fvx > 0 && m_vPos.x > WINDOW_SIZE_W)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}
	else if (m_fvx < 0 && m_vPos.x + ENEMY_SIZE < 0)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}

	//画面下端
	if (m_vPos.y > WINDOW_SIZE_H)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}

}

//描画
void CEnemy::Draw()
{
	RECT_F src, dst;

	//切り取り位置
	RectSet(&src, 0.0f, 0.0f, 256.0f, 256.0f);

	//描画位置
	RectSet(&dst, m_vPos.y, m_vPos.x,ENEMY_SIZE ,ENEMY_SIZE);

	//描画
	Draw::Draw(OBJ_ENEMY, &src, &dst, m_fColor, 0.0f);
}
