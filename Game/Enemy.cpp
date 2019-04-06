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
			CEnemyBullet* pBullet = new CEnemyBullet(m_vPos, CVector::Create(1.0f , 0.0f));
			Objs::InsertObj(pBullet, OBJ_ENEMY_BULLET, 10);
		}
	}

	//当たり判定-----------------------------------------------------

	//HitBox更新
	CHitBox* hit_b = Hits::GetHitBox(this);
	hit_b->SetPos(m_vPos.x, m_vPos.y);

	//主人公の弾に当たると消滅
	if (hit_b->CheckElementHit(ELEMENT_CHARA_BULLET) == true)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}
	//--------------------------------------------------------------
}

//描画
void CEnemy::Draw()
{
	RECT_F src, dst;

	//切り取り位置
	RectSet(&src, 0.0f, 0.0f, 128.0f, 128.0f);

	//描画位置
	RectSet(&dst, m_vPos.y, m_vPos.x,ENEMY_SIZE ,ENEMY_SIZE);

	//描画
	Draw::Draw(OBJ_ENEMY, &src, &dst, m_fColor, 0.0f);
}
