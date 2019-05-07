#include "Ranking.h"
#include "Function.h"
#include "GameL/WinInputs.h"
#include "GameL/DrawFont.h"
#include "GameL/SceneManager.h"
#include "GameL/UserData.h"
#include "GameHead.h"

//初期化
void CRanking::Init()
{
	//フォントセット
	Font::SetStrTex(L"ランキング");

	//色
	ColorSet(1.0f, 1.0f, 1.0f, 1.0f, m_fColor);

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
}

//描画
void CRanking::Draw()
{
	Font::StrDraw(L"ランキング", 230.0f, 50.0f, 64.0f, m_fColor);

	//セレクトシーン戻り用案内表示
	Font::StrDraw(L"Enter で戻る",700.0f,580.0f,16.0f,m_fColor);

	//ランキング表示
	for (int i = 0; i < MAX_RANKING - 1; i++)
	{
		wchar_t str[256];
		swprintf_s(str, L"%2d位           %12d点", i + 1, ((UserData*)Save::GetData())->m_iRanking[i]);
		Font::StrDraw(str, 150, 150 + (45 * i), 32, m_fColor);
	}
}