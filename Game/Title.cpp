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
		Scene::SetScene(new CSceneMain());
		this->SetStatus(false);
	}
}

//描画
void CTitle::Draw()
{
	RECT_F Src, Dst;

	//切り取り
	RectSet(&Src, 0.0f, 0.0f, 800.0f, 600.0f);

	//描画位置
	RectSet(&Dst, 0.0f, 0.0f, WINDOW_SIZE_W, WINDOW_SIZE_H);

	//描画
	Draw::Draw(OBJ_BACK_GROUND, &Src, &Dst, m_fColor, 0.0f);

}
