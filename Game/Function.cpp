#include "Function.h"
#include "GameL\WinInputs.h"
#include "GameHead.h"

//Rectに値をセットする関数
//引数　1〜4：上下左右それぞれにセットしたい値
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

//高さと幅から直角三角形があると仮定しその角度を求める。
//引数1  float w	；幅
//引数2	 float h	：高さ
//戻り値 float		：角度(0°〜　360°)
//内容
float GetAtan2Angle(float w, float h)
{
	//atan2で角度を求める
	float r = atan2(h, w)*180.0f / 3.14f;

	//-180°〜-0° 180°〜360°に変換
	if (r < 0)
	{
		r = 360 - abs(r);
	}

	return r;
}


//---UnitVec関数
//引数1   float* vx  :ベクトルのX成分のポインタ
//引数2   float* vy  :ベクトルのY成分のポインタ
//戻り値 bool		 :ture=計算成功　false=計算失敗
bool UnitVec(float* vx, float* vy)
{
	//ベクトルの長さを求める(三平方の定理)
	float r = 0.0f;
	r = (*vx) * (*vx) + (*vy) * (*vy);
	r = sqrt(r);

	//長さが0かどうか調べる
	if (r == 0.0f)
	{
		//0なら計算失敗
		return false;
	}
	else
	{
		//正規化を行い、vxとvyの参照先の値を変更
		(*vx) = 1.0f / r * (*vx);
		(*vy) = 1.0f / r * (*vy);
	}

	//計算成功
	return true;
}