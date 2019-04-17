#include "GameL/UserData.h"
#include "GameL/DrawFont.h"

#include "Score.h"
#include "GameHead.h"
#include "Function.h"

//初期化
void CScore::Init()
{
	//色セット
	ColorSet(1.0f, 1.0f, 1.0f, 1.0f, m_fColor);

	//得点の初期化
	((UserData*)Save::GetData())->m_iScore = 0;
}

//更新
void CScore::Action()
{

}

//描画
void CScore::Draw()
{
	//スコア表示
	wchar_t m_wSentence[128];
	swprintf_s(m_wSentence, L"Score : %d", ((UserData*)Save::GetData())->m_iScore);
	Font::StrDraw(m_wSentence, WINDOW_SIZE_W - 140.0f, 0.0f, 20.0f, m_fColor);
}