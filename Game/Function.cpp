#include "Function.h"
#include "GameL\WinInputs.h"
#include "GameHead.h"

//Rectに値をセットする関数
//引数　1～4：上下左右それぞれにセットしたい値
//引数　5	：値を入れたい場所
void RectSet(RECT_F* rect,float top, float left, float Size_x, float Size_y)
{
	rect->m_top		= top;
	rect->m_left	= left;
	rect->m_right	= rect->m_left + Size_x;
	rect->m_bottom	= rect->m_top + Size_y;
}


//色をセットする関数
void ColorSet(float r, float g, float b, float a, float color[4])
{
	color[0] = r;
	color[1] = g;
	color[2] = b;
	color[3] = a;
}

//画面内かのチェック
bool WindowInCheck(Vector vPos,Vector vSize)
{
	if (vPos.x + vSize.x < 0.0f)
		return false;
	if (vPos.y + vSize.y < 0.0f)
		return false;
	if (vPos.y > WINDOW_SIZE_H)
		return false;
	if (vPos.x > WINDOW_SIZE_W)
		return false;

	return true;
}

