#include "GameClear.h"
#include "Function.h"
#include "GameL/WinInputs.h"
#include "GameL/DrawTexture.h"
#include "GameL/DrawFont.h"
#include "GameL/SceneManager.h"
#include "GameL/UserData.h"
#include "GameHead.h"

//初期化
void CGameClear::Init()
{
	//色(白)
	ColorSet(1.0f, 1.0f, 1.0f, 1.0f, m_fColor);
	//色(黄色)
	ColorSet(1.0f, 1.0f, 0.0f, 1.0f, m_fColor_Yellow);

	//切り替え初期化
	m_bGoTitleorName = false;

	int iRankPosition = MAX_RANKING - 1;//11-1 -> 10

	if (((UserData*)Save::GetData())->m_iStageNum == STAGE_1)
	{
		//得点情報をステージ1のランキング最下位に登録			
		((UserData*)Save::GetData())->m_iRanking_st1[iRankPosition] = ((UserData*)Save::GetData())->m_iScore;
		strcpy_s(((UserData*)Save::GetData())->m_RankingName_st1[10], NO_NAME);

		//ランキングソートして順位を調べる
		m_iRanking = RankingSort(((UserData*)Save::GetData())->m_iRanking_st1, ((UserData*)Save::GetData())->m_RankingName_st1);
	}
	if (((UserData*)Save::GetData())->m_iStageNum == STAGE_2)
	{
		//得点情報をステージ2のランキング最下位に登録
		((UserData*)Save::GetData())->m_iRanking_st2[iRankPosition] = ((UserData*)Save::GetData())->m_iScore;
		strcpy_s(((UserData*)Save::GetData())->m_RankingName_st2[10], NO_NAME);

		//ランキングソートして順位を調べる
		m_iRanking = RankingSort(((UserData*)Save::GetData())->m_iRanking_st2, ((UserData*)Save::GetData())->m_RankingName_st2);
	}
	if (((UserData*)Save::GetData())->m_iStageNum == STAGE_3)
	{
		//得点情報をステージ3のランキング最下位に登録
		((UserData*)Save::GetData())->m_iRanking_st3[iRankPosition] = ((UserData*)Save::GetData())->m_iScore;
		strcpy_s(((UserData*)Save::GetData())->m_RankingName_st3[10], NO_NAME);

		//ランキングソートして順位を調べる
		m_iRanking = RankingSort(((UserData*)Save::GetData())->m_iRanking_st3, ((UserData*)Save::GetData())->m_RankingName_st3);
	}
}

//更新
void CGameClear::Action()
{
	//ステージ情報取得 ステージ1なら
	if (((UserData*)Save::GetData())->m_iStageNum == STAGE_1)
	{
		//ランキングの上位から探索
		for (int i = 0; i < MAX_RANKING - 1; i++)
		{

			//スコアとランキング内のスコア探索
			if (((UserData*)Save::GetData())->m_iScore == ((UserData*)Save::GetData())->m_iRanking_st1[i])
			{
				//ランキングが1位以外かつ同じスコアがある場合
				if (((UserData*)Save::GetData())->m_iRanking_st1[i] == ((UserData*)Save::GetData())->m_iRanking_st1[i - 1] && i != 0)
				{
					//ランキング順位保存
					((UserData*)Save::GetData())->m_RankingPos = i - 1;
				}
				else
				{
					//ランキング順位保存
					((UserData*)Save::GetData())->m_RankingPos = i;
				}

				//スコアが10位以内だった場合
				if (i < 10 && ((UserData*)Save::GetData())->m_iScore != 0)
				{
					//名前入力にする
					m_bGoTitleorName = true;

					//Enterで名前入力へ移る
					if (Input::GetTrrigerKey(VK_RETURN) == true)
					{
						Scene::SetScene(new CSceneNameInput());
						this->SetStatus(false);
					}
				}
				else
				{
					//タイトルにする
					m_bGoTitleorName = false;

					//Enterでタイトルへ移る
					if (Input::GetTrrigerKey(VK_RETURN) == true)
					{
						Scene::SetScene(new CSceneTitle());
						this->SetStatus(false);
					}
				}
			}
		}
	}
	//ステージ情報取得 ステージ2なら
	if (((UserData*)Save::GetData())->m_iStageNum == STAGE_2)
	{
		//ランキングの上位から探索
		for (int i = 0; i < MAX_RANKING - 1; i++)
		{

			//スコアとランキング内のスコア探索
			if (((UserData*)Save::GetData())->m_iScore == ((UserData*)Save::GetData())->m_iRanking_st2[i])
			{

				//ランキングが1位以外かつ同じスコアがある場合
				if (((UserData*)Save::GetData())->m_iRanking_st2[i] == ((UserData*)Save::GetData())->m_iRanking_st2[i - 1] && i != 0)
				{
					//ランキング順位保存
					((UserData*)Save::GetData())->m_RankingPos = i - 1;
				}
				else
				{
					//ランキング順位保存
					((UserData*)Save::GetData())->m_RankingPos = i;
				}

				//スコアが10位以内だった場合
				if (i < 10 && ((UserData*)Save::GetData())->m_iScore != 0)
				{
					//名前入力にする
					m_bGoTitleorName = true;

					//Enterで名前入力へ移る
					if (Input::GetTrrigerKey(VK_RETURN) == true)
					{
						Scene::SetScene(new CSceneNameInput());
						this->SetStatus(false);
					}
				}
				else
				{
					//タイトルにする
					m_bGoTitleorName = false;

					//Enterでタイトルへ移る
					if (Input::GetTrrigerKey(VK_RETURN) == true)
					{
						Scene::SetScene(new CSceneTitle());
						this->SetStatus(false);
					}
				}
			}
		}
	}
	//ステージ情報取得 ステージ3なら
	if (((UserData*)Save::GetData())->m_iStageNum == STAGE_3)
	{
		//ランキングの上位から探索
		for (int i = 0; i < MAX_RANKING - 1; i++)
		{

			//スコアとランキング内のスコア探索
			if (((UserData*)Save::GetData())->m_iScore == ((UserData*)Save::GetData())->m_iRanking_st3[i])
			{

				//ランキングが1位以外かつ同じスコアがある場合
				if (((UserData*)Save::GetData())->m_iRanking_st3[i] == ((UserData*)Save::GetData())->m_iRanking_st3[i - 1] && i != 0)
				{
					//ランキング順位保存
					((UserData*)Save::GetData())->m_RankingPos = i - 1;
				}
				else
				{
					//ランキング順位保存
					((UserData*)Save::GetData())->m_RankingPos = i;
				}

				//スコアが10位以内だった場合
				if (i < 10 && ((UserData*)Save::GetData())->m_iScore != 0)
				{
					//名前入力にする
					m_bGoTitleorName = true;

					//Enterで名前入力へ移る
					if (Input::GetTrrigerKey(VK_RETURN) == true)
					{
						Scene::SetScene(new CSceneNameInput());
						this->SetStatus(false);
					}
				}
				else
				{
					//タイトルにする
					m_bGoTitleorName = false;

					//Enterでタイトルへ移る
					if (Input::GetTrrigerKey(VK_RETURN) == true)
					{
						Scene::SetScene(new CSceneTitle());
						this->SetStatus(false);
					}
				}
			}
		}
	}
}

//描画
void CGameClear::Draw()
{
	RECT_F Dst, Src;

	//切り取り位置
	RectSet(&Src, 0.0f, 0.0f, 800.0f, 600.0f);

	//描画位置
	RectSet(&Dst, 0.0f, 0.0f, WINDOW_SIZE_W, WINDOW_SIZE_H);

	//描画
	Draw::Draw(OBJ_BACK_GROUND, &Src, &Dst, m_fColor, 0.0f);

	//タイトルシーン案内表示
	if (m_bGoTitleorName == true)
	{
		//trueなら名前入力移行案内
		Font::StrDraw(L"Enter で名前入力", 650.0f, 580.0f, 16.0f, m_fColor);
	}
	else
	{
		//falseならタイトル移行案内
		Font::StrDraw(L"Enter でタイトル", 650.0f, 580.0f, 16.0f, m_fColor);
	}

	//ランキング表示
	if (((UserData*)Save::GetData())->m_iStageNum == STAGE_1)
	{
		//ゲームクリア文字表示
		Font::StrDraw(L"Stage Clear", 250.0f, 10.0f, 64.0f, m_fColor_Yellow);

		//ランキング表示
		for (int i = 0; i < MAX_RANKING - 1; i++)
		{
			wchar_t str[256];
			
			//自分の順位探索
			if (((UserData*)Save::GetData())->m_RankingPos == i && ((UserData*)Save::GetData())->m_iScore != 0)
			{
				swprintf_s(str, L"%2d位           %12d点", i + 1, ((UserData*)Save::GetData())->m_iRanking_st1[i]);
				Font::StrDraw(str, 110.0f, 150.0f + (43.0f * i), 40.0f, m_fColor_Yellow);
			}
			else
			{
				swprintf_s(str, L"%2d位           %12d点", i + 1, ((UserData*)Save::GetData())->m_iRanking_st1[i]);
				Font::StrDraw(str, 110.0f, 150.0f + (43.0f * i), 40.0f, m_fColor);
			}

			//名前表示
			wchar_t str_name[256];
			char name[6];
			strcpy_s(name, ((UserData*)Save::GetData())->m_RankingName_st1[i]);

			//charからwchar_tに指定したサイズ分コピー
			size_t* size = nullptr;
			mbstowcs_s(size, str_name, 12, name, 12);

			Font::StrDraw(str_name, 330.0f, 150.0f + (43.0f * i), 40.0f, m_fColor);

		}
	}
	if (((UserData*)Save::GetData())->m_iStageNum == STAGE_2)
	{
		//ゲームクリア文字表示
		Font::StrDraw(L"Stage Clear", 250.0f, 10.0f, 64.0f, m_fColor_Yellow);

		wchar_t str[256];

		//ランキング表示
		for (int i = 0; i < MAX_RANKING - 1; i++)
		{
			//自分の順位探索
			if (((UserData*)Save::GetData())->m_RankingPos == i && ((UserData*)Save::GetData())->m_iScore != 0)
			{
				swprintf_s(str, L"%2d位           %12d点", i + 1, ((UserData*)Save::GetData())->m_iRanking_st2[i]);
				Font::StrDraw(str, 110.0f, 150.0f + (43.0f * i), 40.0f, m_fColor_Yellow);
			}
			else
			{
				swprintf_s(str, L"%2d位           %12d点", i + 1, ((UserData*)Save::GetData())->m_iRanking_st2[i]);
				Font::StrDraw(str, 110.0f, 150.0f + (43.0f * i), 40.0f, m_fColor);
			}

			//名前表示
			wchar_t str_name[256];
			char name[6];
			strcpy_s(name, ((UserData*)Save::GetData())->m_RankingName_st2[i]);

			//charからwchar_tに指定したサイズ分コピー
			size_t* size = nullptr;
			mbstowcs_s(size, str_name, 12, name, 12);

			Font::StrDraw(str_name, 330.0f, 150.0f + (43.0f * i), 40.0f, m_fColor);

		}
	}
	if (((UserData*)Save::GetData())->m_iStageNum == STAGE_3)
	{
		//ゲームクリア文字表示
		Font::StrDraw(L"Game Clear", 250.0f, 10.0f, 64.0f, m_fColor_Yellow);

		wchar_t str[256];

		//ランキング表示
		for (int i = 0; i < MAX_RANKING - 1; i++)
		{
			//自分の順位探索
			if (((UserData*)Save::GetData())->m_RankingPos == i && ((UserData*)Save::GetData())->m_iScore != 0)
			{
				swprintf_s(str, L"%2d位           %12d点", i + 1, ((UserData*)Save::GetData())->m_iRanking_st3[i]);
				Font::StrDraw(str, 110.0f, 150.0f + (43.0f * i), 40.0f, m_fColor_Yellow);
			}
			else
			{
				swprintf_s(str, L"%2d位           %12d点", i + 1, ((UserData*)Save::GetData())->m_iRanking_st3[i]);
				Font::StrDraw(str, 110.0f, 150.0f + (43.0f * i), 40.0f, m_fColor);
			}

			//名前表示
			wchar_t str_name[256];
			char name[6];
			strcpy_s(name, ((UserData*)Save::GetData())->m_RankingName_st3[i]);

			//charからwchar_tに指定したサイズ分コピー
			size_t* size = nullptr;
			mbstowcs_s(size, str_name, 12, name, 12);

			Font::StrDraw(str_name, 330.0f, 150.0f + (43.0f * i), 40.0f, m_fColor);

		}
	}
	
}