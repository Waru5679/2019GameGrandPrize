#include "ObjStar.h"
#include "GameHead.h"
#include "Function.h"
#include "GameL/DrawTexture.h"

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
}

//更新
void CStar::Action()
{

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