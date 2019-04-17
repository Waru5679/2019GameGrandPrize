#include "GameL/DrawTexture.h"
#include "GameL/HitBoxManager.h"

#include "ObjCollectionItemSmall.h"
#include "GameHead.h"
#include "Function.h"


//コンストラクタ
CCollectionItemSmall::CCollectionItemSmall(int x, int y)
{
	m_fPos_x = (float)x * OBJ_SIZE;
	m_fPos_y = (float)y * OBJ_SIZE;
}

//初期化
void CCollectionItemSmall::Init()
{
	//色セット
	ColorSet(1.0f, 1.0f, 1.0f, 1.0f, m_fColor);


	//当たり判定用HitBox作成
	Hits::SetHitBox(this, m_fPos_x, m_fPos_y, ITEM_SMALL_SIZE, ITEM_SMALL_SIZE, ELEMENT_ITEM_SMALL, OBJ_ITEM_SMALL, 1);

}

void CCollectionItemSmall::Action()
{
	//HitBox更新
	CHitBox* hit_b = Hits::GetHitBox(this);
	hit_b->SetPos(m_fPos_x, m_fPos_y);

	//主人公に当たると消滅
	if (hit_b->CheckElementHit(ELEMENT_PLAYER) == true)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}

}

//描画
void CCollectionItemSmall::Draw()
{
	RECT_F src, dst;

	//切り取り位置
	RectSet(&src, 0.0f, 0.0f, 128.0f, 128.0f);

	//描画位置
	RectSet(&dst, m_fPos_y, m_fPos_x, ITEM_SMALL_SIZE, ITEM_SMALL_SIZE);

	//描画
	Draw::Draw(OBJ_ITEM_BIG, &src, &dst, m_fColor, 0.0f);
}