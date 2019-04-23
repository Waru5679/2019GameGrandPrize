#include "GameClear.h"
#include "Function.h"
#include "GameL/WinInputs.h"
#include "GameL/DrawFont.h"
#include "GameL/SceneManager.h"
#include "GameHead.h"

//初期化
void CGameClear::Init()
{
	//フォントセット
	Font::SetStrTex(L"ゲームクリア");

	//色
	ColorSet(1.0f, 1.0f, 1.0f, 1.0f, m_fColor);
}

//更新
void CGameClear::Action()
{
	//エンターでタイトルへ
	if (Input::GetTrrigerKey(VK_RETURN) == true)
	{
		Scene::SetScene(new CSceneTitle());
		this->SetStatus(false);
	}
}

//描画
void CGameClear::Draw()
{
	Font::StrDraw(L"ゲームクリア", 100.0f, 100.0f, 32.0f, m_fColor);
}