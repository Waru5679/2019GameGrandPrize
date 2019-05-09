#include "Ranking.h"
#include "Function.h"
#include "GameL/WinInputs.h"
#include "GameL/DrawFont.h"
#include "GameL/SceneManager.h"
#include "GameL/UserData.h"
#include "GameHead.h"

#define Page_1 0
#define Page_2 1
#define Page_3 2

//初期化
void CRanking::Init()
{
	//フォントセット
	Font::SetStrTex(L"ランキング");

	//色
	ColorSet(1.0f, 1.0f, 1.0f, 1.0f, m_fColor);
	
	m_iRankChenge = Page_1;
	m_bChangeRightIs = false;
	m_bChangeLeftIs = false;
}

//更新
void CRanking::Action()
{
	//Enterでメニュー画面に戻る
	if (Input::GetTrrigerKey(VK_RETURN) == true)
	{
		Scene::SetScene(new CSceneStageSelect());
		this->SetStatus(false);
	}

	if (Input::GetTrrigerKey(VK_RIGHT) == true)
	{
		if (m_bChangeRightIs == true)
		{
			if (m_iRankChenge == Page_1)
			{
				m_iRankChenge = Page_2;
			}
			else if (m_iRankChenge == Page_2)
			{
				m_iRankChenge = Page_3;
			}
			m_bChangeRightIs = false;
		}
	}
	else
	{
		m_bChangeRightIs = true;
	}

	if (Input::GetTrrigerKey(VK_LEFT) == true)
	{
		if (m_bChangeLeftIs == true)
		{
			if (m_iRankChenge == Page_2)
			{
				m_iRankChenge = Page_1;
			}
			else if (m_iRankChenge == Page_3)
			{
				m_iRankChenge = Page_2;
			}
		}
		m_bChangeLeftIs = false;
	}
	else
	{
		m_bChangeLeftIs = true;
	}

}

//描画
void CRanking::Draw()
{
	Font::StrDraw(L"ランキング", 230.0f, 0.0f, 64.0f, m_fColor);

	//セレクトシーン戻り用案内表示
	Font::StrDraw(L"Enter で戻る",700.0f,580.0f,16.0f,m_fColor);

	if (m_iRankChenge == Page_1)
	{
		Font::StrDraw(L"ステージ1", 320.0f, 80.0f, 32.0f, m_fColor);

		//ランキング表示
		for (int i = 0; i < MAX_RANKING - 1; i++)
		{
			wchar_t str[256];
			swprintf_s(str, L"%2d位           %12d点", i + 1, ((UserData*)Save::GetData())->m_iRanking_st1[i]);
			Font::StrDraw(str, 150, 150 + (45 * i), 32, m_fColor);
		}
	}
	if (m_iRankChenge == Page_2)
	{
		Font::StrDraw(L"ステージ2", 320.0f, 80.0f, 32.0f, m_fColor);

		//ランキング表示
		for (int i = 0; i < MAX_RANKING - 1; i++)
		{
			wchar_t str[256];
			swprintf_s(str, L"%2d位           %12d点", i + 1, ((UserData*)Save::GetData())->m_iRanking_st2[i]);
			Font::StrDraw(str, 150, 150 + (45 * i), 32, m_fColor);
		}
	}
	if (m_iRankChenge == Page_3)
	{
		Font::StrDraw(L"ステージ3", 320.0f, 80.0f, 32.0f, m_fColor);

		//ランキング表示
		for (int i = 0; i < MAX_RANKING - 1; i++)
		{
			wchar_t str[256];
			swprintf_s(str, L"%2d位           %12d点", i + 1, ((UserData*)Save::GetData())->m_iRanking_st3[i]);
			Font::StrDraw(str, 150, 150 + (45 * i), 32, m_fColor);
		}
	}
}