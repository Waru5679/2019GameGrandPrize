#include "StageSelect.h"
#include "Function.h"
#include "GameL/WinInputs.h"
#include "GameL/DrawFont.h"
#include "GameL/SceneManager.h"
#include "GameL/UserData.h"
#include "GameHead.h"

#define STAGE_1 1
#define STAGE_2 2
#define STAGE_3 3
#define RANKING 4

//初期化
void CStageSelect::Init()
{
	//フォントセット
	Font::SetStrTex(L"ステージセレクト");

	//色
	ColorSet(1.0f, 1.0f, 1.0f, 1.0f, m_fColor);

	//セレクト用数値
	SelectNum = 1;
}

//更新
void CStageSelect::Action()
{
	//ステージやランキングの上に来た場合文字の表示をでかくする数値を追加する
	if (SelectNum == STAGE_1)
	{
		if (Input::GetTrrigerKey(VK_RETURN) == true)
		{
			//ステージ１へ移動
			((UserData*)Save::GetData())->m_iStageNum = STAGE_1;
			Scene::SetScene(new CSceneMain(STAGE_1));
			this->SetStatus(false);
		}
		//右キーを押すとStage2にする
		if (Input::GetTrrigerKey(VK_RIGHT) == true)
		{
			SelectNum = STAGE_2;
		}
		//下キーを押すとランキングにする
		if (Input::GetTrrigerKey(VK_DOWN) == true)
		{
			SelectNum = RANKING;
		}

	}
	
	if (SelectNum == STAGE_2)
	{
		if (Input::GetTrrigerKey(VK_RETURN) == true)
		{
			//ステージ2へ移動
			((UserData*)Save::GetData())->m_iStageNum = STAGE_2;
			Scene::SetScene(new CSceneMain(STAGE_2));
			this->SetStatus(false);
		}
		//左キーを押すとStage1にする
		if (Input::GetTrrigerKey(VK_LEFT) == true)
		{
			SelectNum = STAGE_1;
		}
		//右キーを押すとStage3にする
		if (Input::GetTrrigerKey(VK_RIGHT) == true)
		{
			SelectNum = STAGE_3;
		}
		//下キーを押すとランキングにする
		if (Input::GetTrrigerKey(VK_DOWN) == true)
		{
			SelectNum = RANKING;
		}
	}

	if (SelectNum == STAGE_3)
	{
		if (Input::GetTrrigerKey(VK_RETURN) == true)
		{
			//ステージ3へ移動
			((UserData*)Save::GetData())->m_iStageNum = STAGE_3;
			Scene::SetScene(new CSceneMain(STAGE_3));
			this->SetStatus(false);
		}
		//左キーを押すとStage2にする
		if (Input::GetTrrigerKey(VK_LEFT) == true)
		{
			SelectNum = STAGE_2;
		}
		//下キーを押すとランキングにする
		if (Input::GetTrrigerKey(VK_DOWN) == true)
		{
			SelectNum = RANKING;
		}
	}

	if (SelectNum == RANKING)
	{
		if (Input::GetTrrigerKey(VK_RETURN) == true)
		{
			//ランキング表示
			Scene::SetScene(new CSceneRanking);
			this->SetStatus(false);
		}
		//左キーを押すとStage2にする
		if (Input::GetTrrigerKey(VK_UP) == true)
		{
			SelectNum = STAGE_2;
		}
	}

}

//描画
void CStageSelect::Draw()
{
	//SelectNumの数値によって文字を大きくする
	if (SelectNum == STAGE_1)
	{
		Font::StrDraw(L"ステージ1", 35.0f, 200.0f, 48.0f, m_fColor);
	}
	else
	{
		Font::StrDraw(L"ステージ1", 50.0f, 200.0f, 32.0f, m_fColor);
	}
	if (SelectNum == STAGE_2)
	{
		Font::StrDraw(L"ステージ2", 285.0f, 200.0f, 48.0f, m_fColor);
	}
	else
	{
		Font::StrDraw(L"ステージ2", 320.0f, 200.0f, 32.0f, m_fColor);
	}
	if (SelectNum == STAGE_3)
	{
		Font::StrDraw(L"ステージ3", 550.0f, 200.0f, 48.0f, m_fColor);
	}
	else
	{
		Font::StrDraw(L"ステージ3", 590.0f, 200.0f, 32.0f, m_fColor);
	}
	if (SelectNum == RANKING)
	{
		Font::StrDraw(L"ランキング", 280.0f, 450.0f, 48.0f, m_fColor);
	}
	else
	{
		Font::StrDraw(L"ランキング", 310.0f, 450.0f, 32.0f, m_fColor);
	}
}