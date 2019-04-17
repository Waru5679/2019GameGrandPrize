#include "ScrollChange.h"
#include "GameHead.h"
#include "Function.h"
#include "GameL/HitBoxManager.h"

//コンストラクタ
CScrollChange::CScrollChange(int x, int y)
{
	m_vPos.x = (float)x * OBJ_SIZE;
	m_vPos.y = (float)y * OBJ_SIZE;
}

//初期化
void CScrollChange::Init()
{
	//色
	ColorSet(1.0f, 1.0f, 1.0f, 1.0f, m_fColor);

//	Hits::SetHitBox(this,m_vPos.x,m_vPos.y,SCROLL_CHANGE_SIZE, SCROLL_CHANGE_SIZE,)
}

//更新
void CScrollChange::Action()
{

}

//描画
void CScrollChange::Draw()
{
	RECT_F src, dst;

	//切り取り位置
	RectSet(&src, 0.0f, 0.0f, 128.0f, 128.0f);

	//描画位置
	RectSet(&dst, m_vPos.y, m_vPos.x, SCROLL_CHANGE_SIZE, SCROLL_CHANGE_SIZE);

	//描画
	Draw::Draw(OBJ_SCROLL_CHANGE, &src, &dst, m_fColor, 0.0f);
}