#include "GameL/DrawTexture.h"
#include "GameL/HitBoxManager.h"

#include "ObjStar.h"
#include "GameHead.h"
#include "Function.h"


//コンストラクタ
CStar::CStar(int x, int y)
{
	m_fPos_x = (float)x * OBJ_SIZE;
	m_fPos_y = (float)y * OBJ_SIZE;
}

//初期化
void CStar::Init()
{
	//色セット
	ColorSet(1.0f, 1.0f, 1.0f, 1.0f, m_fColor);
	
	//当たり判定用HitBox作成
	Hits::SetHitBox(this, m_fPos_x , m_fPos_y, STAR_SIZE / 2.0f, STAR_SIZE / 2.0f, ELEMENT_STAR, OBJ_STAR, 1);
}

//更新
void CStar::Action()
{
	//HitBox更新
	CHitBox* hit_b = Hits::GetHitBox(this);
	//当たり判定の位置を星の中に収めるように移動
	hit_b->SetPos(m_fPos_x + (STAR_SIZE / 4.0f), m_fPos_y + (STAR_SIZE / 4.0f));

}

//描画
void CStar::Draw()
{
	RECT_F src, dst;

	//切り取り位置
	RectSet(&src, 0.0f, 0.0f, 128.0f, 128.0f);

	//描画位置
	RectSet(&dst, m_fPos_y, m_fPos_x, STAR_SIZE, STAR_SIZE);

	//描画
	Draw::Draw(OBJ_STAR, &src, &dst, m_fColor, 0.0f);
}