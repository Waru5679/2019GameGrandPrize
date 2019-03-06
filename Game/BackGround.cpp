#include "BackGround.h"
#include "GameL/DrawTexture.h"
#include "Function.h"
#include "main.h"
#include "GameHead.h"

//コンストラクタ
CBackGround::CBackGround(float Pos_x, float Pos_y, bool Scroll)
{
	//位置
	m_fPos_x = Pos_x;
	m_fPos_y = Pos_y;

	//スクロール
	m_bScroll = Scroll;
}

//初期化
void CBackGround::Init()
{
	//色
	ColorSet(1.0f, 1.0f, 1.0f, 1.0f, m_fColor);
}

//更新
void CBackGround::Action()
{
	//横スクロール
	if (m_bScroll == SIDE)
	{
		//位置
		m_fPos_x += -5.0f;
		m_fPos_y += 0.0f;

		//背景の右端が画面左に行くと戻す
		if (m_fPos_x + WINDOW_SIZE_W < 0.0f)
			m_fPos_x = WINDOW_SIZE_W;
	}

	//縦スクロール
	else
	{
		//位置
		m_fPos_x += 0.0f;
		m_fPos_y += -5.0f;

		//背景の下端が画面上に行くと戻す
		if (m_fPos_y + WINDOW_SIZE_H < 0.0f )
			m_fPos_y = WINDOW_SIZE_H;
	}
}

//描画
void CBackGround::Draw()
{
	//切り取り位置設定
	RECT_F src, dst;
	RectSet(&src, 0.0f, 0.0f, 256.0f, 256.0f);

	//描画位置設定
	RectSet(&dst, m_fPos_y,m_fPos_x, WINDOW_SIZE_W, WINDOW_SIZE_H);

	//描画
	Draw::Draw(OBJ_BACK_GROUND, &src, &dst, m_fColor, 0.0f);
}

//スクロールのセット
void CBackGround::SetScroll(float Pos_x, float Pos_y, bool Scroll)
{
	//位置
	m_fPos_x = Pos_x;
	m_fPos_y = Pos_y;

	//スクロール
	m_bScroll = Scroll;
}