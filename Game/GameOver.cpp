#include "GameOver.h"
#include "Function.h"
#include "GameL/WinInputs.h"
#include "GameL/DrawFont.h"
#include "GameL/SceneManager.h"
#include "GameHead.h"


//初期化
void CGameOver::Init()
{
	//フォントセット
	Font::SetStrTex(L"ゲームオーバー");

	//色
	ColorSet(1.0f, 1.0f, 1.0f, 1.0f, m_fColor);
}

//更新
void CGameOver::Action()
{
	//Enterでタイトルへ
	if (Input::GetVKey(VK_RETURN) == true)
	{
		Scene::SetScene(new CSceneTitle());
		this->SetStatus(false);
	}
}

//描画
void CGameOver::Draw()
{
	Font::StrDraw(L"ゲームオーバー", 100.0f, 100.0f, 32.0f, m_fColor);
}
