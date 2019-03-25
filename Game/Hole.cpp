#include "Hole.h"
#include "GameHead.h"
#include "Function.h"
#include "GameL/DrawTexture.h"

//コンストラクタ
CHole::CHole(int y, int x)
{
	m_fPos_x = (float)x * OBJ_SIZE;
	m_fPos_y = (float)y * OBJ_SIZE;

}

//初期化
void CHole::Init()
{
	//色
	ColorSet(1.0f, 1.0f, 1.0f, 1.0f, m_fColor);

}

//更新
void CHole::Action()
{

}

//描画
void CHole::Draw()
{
	RECT_F src, dst;

	//切り取り位置
	RectSet(&src, 0.0f, 0.0f, 256.0f, 256.0f);

	//描画位置
	RectSet(&dst, m_fPos_y, m_fPos_x, HOLE_SIZE, HOLE_SIZE);
	
	//描画
	Draw::Draw(OBJ_HOLE, &src, &dst, m_fColor, 0.0f);

}