#include "GameL/DrawTexture.h"
#include "GameL/HitBoxManager.h"
#include "GameL/UserData.h"

#include "ObjCollectionItemSmall.h"
#include "GameHead.h"
#include "Function.h"


//コンストラクタ
CCollectionItemSmall::CCollectionItemSmall(int x, int y,int number)
{
	m_fPos_x = (float)x * OBJ_SIZE;
	m_fPos_y = (float)y * OBJ_SIZE;
	m_iPosition = number;
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
	//シーンの状態取得
	CSceneMain* m_pScene = dynamic_cast<CSceneMain*>(Scene::GetScene());
	m_bScroll = m_pScene->GetScroll();
	
	//スクロールが横の時左へ動く
	if (m_bScroll == SIDE)
	{
		m_fPos_x -= SCROLL_SPEED;
	}
	//縦なら下へ動く
	else
	{
		m_fPos_y += SCROLL_SPEED;
	}

	//HitBox更新
	CHitBox* hit_b = Hits::GetHitBox(this);
	hit_b->SetPos(m_fPos_x, m_fPos_y);

	//主人公に当たると消滅
	if (hit_b->CheckElementHit(ELEMENT_PLAYER) == true)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);

		//スコアに+500する
		((UserData*)Save::GetData())->m_iScore += SCORE_SMALL;

		//Map取得
		CMap* m_pMap = dynamic_cast<CMap*>(Objs::GetObj(OBJ_MAP));
		//Map内のm_iMapItem[]の中身の今の数値を0にする
		m_pMap->m_iMapItem[m_iPosition] = ITEM_NONE;
		//Map.cpp内のm_iMapItem[]に今の数値-1して直前の数値が0ならボーナス加算
		if (m_pMap->m_iMapItem[m_iPosition - 1] == ITEM_NONE)
		{
			((UserData*)Save::GetData())->m_iScore += SCORE_BONUS;
		}

	}

	//アイテム(小)オブジェクトが画面外へ出ると削除する
	//画面左端
	if (m_fPos_x + ITEM_SMALL_SIZE < 0)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}
	//画面下端
	if (m_fPos_y > WINDOW_SIZE_H)
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