#include "Plane.h"
#include "GameHead.h"
#include "Function.h"
#include "GameL/HitBoxManager.h"

CPlane::CPlane(int x, int y)
{
	m_vPos.x = 100.0f;//(float)x * OBJ_SIZE;
	m_vPos.y = 500.0f;//(float)y * OBJ_SIZE;
}

//初期化
void CPlane::Init()
{
	//色
	ColorSet(1.0f, 1.0f, 1.0f, 1.0f, m_fColor);

	//当たり判定セット
	Hits::SetHitBox(this, m_vPos.x, m_vPos.y, PLANE_WIDTH , PLANE_HEIGHT, ELEMENT_PLANE, OBJ_PLANE, 1);

}

//更新
void CPlane::Action()
{

}

//描画
void CPlane::Draw()
{

	RECT_F src, dst;

	//切り取り位置
	RectSet(&src, 0.0f, 0.0f, 128.0f, 128.0f);

	//描画位置
	RectSet(&dst, m_vPos.y, m_vPos.x, OBJ_SIZE, OBJ_SIZE);

	//描画
	Draw::Draw(OBJ_PLANE, &src, &dst, m_fColor, 0.0f);
}