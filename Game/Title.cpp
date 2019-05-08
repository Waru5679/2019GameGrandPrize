#include "Title.h"
#include "Function.h"
#include "GameL/WinInputs.h"
#include "GameL/DrawFont.h"
#include "GameL/SceneManager.h"
#include "GameL/UserData.h"
#include "GameHead.h"

//初期化
void CTitle::Init()
{
	//フォントセット
	Font::SetStrTex(L"タイトル");

	//色
	ColorSet(1.0f, 1.0f, 1.0f, 1.0f, m_fColor);

}

//更新
void CTitle::Action()
{
	//Enterでメインへ
	if (Input::GetTrrigerKey(VK_RETURN) == true)
	{
		Scene::SetScene(new CSceneStageSelect());
		this->SetStatus(false);
	}
}

//描画
void CTitle::Draw()
{
	Font::StrDraw(L"タイトル", 100.0f, 100.0f, 32.0f, m_fColor);
}
