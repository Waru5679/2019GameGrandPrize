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

	//ゲームを実行して1回のみ作動する
	static bool m_sbInit_Point = true;
	if (m_sbInit_Point == true)
	{
		//ランキング初期化
		for (int i = 0; i < MAX_RANKING; i++)
		{
			((UserData*)Save::GetData())->m_iRanking_st1[i] = 0;
		}
		for (int i = 0; i < MAX_RANKING; i++)
		{
			((UserData*)Save::GetData())->m_iRanking_st2[i] = 0;
		}
		for (int i = 0; i < MAX_RANKING; i++)
		{
			((UserData*)Save::GetData())->m_iRanking_st3[i] = 0;
		}

		//ロード
		Save::Open();

		//点数を0にする
		((UserData*)Save::GetData())->m_iScore = 0;

		m_sbInit_Point = false;
	}
	
	//ゲーム実行2回目以降ランキングセーブ
	if (m_sbInit_Point == false)
	{
		Save::Seve();
	}

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

	if (Input::GetTrrigerKey(VK_BACK) == true)
	{
		//ランキング初期化
		for (int i = 0; i < MAX_RANKING; i++)
		{
			((UserData*)Save::GetData())->m_iRanking_st1[i] = 0;
			((UserData*)Save::GetData())->m_iRanking_st2[i] = 0;
			((UserData*)Save::GetData())->m_iRanking_st3[i] = 0;
		}
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
