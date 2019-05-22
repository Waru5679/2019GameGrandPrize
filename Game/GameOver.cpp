#include "GameOver.h"
#include "Function.h"
#include "GameL/WinInputs.h"
#include "GameL/DrawFont.h"
#include "GameL/SceneManager.h"
#include "GameL/UserData.h"
#include "GameHead.h"


//初期化
void CGameOver::Init()
{
	//色
	ColorSet(1.0f, 1.0f, 1.0f, 1.0f, m_fColor);
	//色(赤)
	ColorSet(0.8f, 0.0f, 0.0f, 1.0f, m_fColor_Red);
	//色(黄色)
	ColorSet(1.0f, 1.0f, 0.0f, 1.0f, m_fColor_Yellow);

	//ループ初期化
	m_iLoop = 0;


	//2019-05-13  
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
void CGameOver::Action()
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
				//ランキング順位保存
				((UserData*)Save::GetData())->m_RankingPos = i;

				//Enterでタイトルか名前入力へ移る
				if (Input::GetTrrigerKey(VK_RETURN) == true)
				{
					//スコアが10位以内だった場合
					if (i < 10 && ((UserData*)Save::GetData())->m_iScore != 0)
					{
						Scene::SetScene(new CSceneNameInput());
						this->SetStatus(false);
					}
					else
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

				//ランキング順位保存
				((UserData*)Save::GetData())->m_RankingPos = i;

				//Enterでタイトルか名前入力へ移る
				if (Input::GetTrrigerKey(VK_RETURN) == true)
				{
					//スコアが10位以内だった場合
					if (i < 10 && ((UserData*)Save::GetData())->m_iScore != 0)
					{
						Scene::SetScene(new CSceneNameInput());
						this->SetStatus(false);
					}
					else
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

				//ランキング順位保存
				((UserData*)Save::GetData())->m_RankingPos = i;

				//Enterでタイトルか名前入力へ移る
				if (Input::GetTrrigerKey(VK_RETURN) == true)
				{
					//スコアが10位以内だった場合
					if (i < 10 && ((UserData*)Save::GetData())->m_iScore != 0)
					{
						Scene::SetScene(new CSceneNameInput());
						this->SetStatus(false);
					}
					else
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
void CGameOver::Draw()
{

	RECT_F Dst, Src;

	//切り取り位置
	RectSet(&Src,0.0f, 0.0f, 800.0f, 600.0f);

	//描画位置
	RectSet(&Dst, 0.0f, 0.0f, WINDOW_SIZE_W, WINDOW_SIZE_H);

	//描画
	Draw::Draw(OBJ_BACK_GROUND, &Src, &Dst, m_fColor, 0.0f);

	Font::StrDraw(L"GAME OVER", 200.0f, 30.0f, 90.0f, m_fColor_Red);


	//画面右に自分の得点表示
	wchar_t str_score[256];
	Font::StrDraw(L"Your Score", 460.0f, 200.0f, 40.0f, m_fColor_Yellow);

	swprintf_s(str_score, L"%12d点", ((UserData*)Save::GetData())->m_iScore);
	Font::StrDraw(str_score, 400.0f, 250.0f, 32.0f, m_fColor_Yellow);

	//ランキング表示
	if (((UserData*)Save::GetData())->m_iStageNum == STAGE_1)
	{
		//ランキング表示
		for (int i = 0; i < MAX_RANKING - 1; i++)
		{

			//自分の順位を持ってきてそれをifでとって表示する
			wchar_t str[256];

			//自分の順位探索
			if (((UserData*)Save::GetData())->m_RankingPos == i)
			{
				//同じスコアが並んでない場合
				if (((UserData*)Save::GetData())->m_iRanking_st1[i] != ((UserData*)Save::GetData())->m_iRanking_st1[i - 1])
				{
					swprintf_s(str, L"%2d位%12d点", i + 1, ((UserData*)Save::GetData())->m_iRanking_st1[i]);
					Font::StrDraw(str, 10, 150 + (45 * i), 32, m_fColor_Yellow);
				}
				//同じスコアが並んでいる場合
				else
				{
					swprintf_s(str, L"%2d位%12d点", i, ((UserData*)Save::GetData())->m_iRanking_st1[i]);
					Font::StrDraw(str, 10, 150 + (45 * (i-1)), 32, m_fColor_Yellow);

					swprintf_s(str, L"%2d位%12d点", i + 1, ((UserData*)Save::GetData())->m_iRanking_st1[i]);
					Font::StrDraw(str, 10, 150 + (45 * i), 32, m_fColor);
				}
			}
			else
			{
				swprintf_s(str, L"%2d位%12d点", i + 1, ((UserData*)Save::GetData())->m_iRanking_st1[i]);
				Font::StrDraw(str, 10, 150 + (45 * i), 32, m_fColor);
			}
			
			//名前表示
			wchar_t str_name[256];
			char name[6];
			strcpy_s(name, ((UserData*)Save::GetData())->m_RankingName_st1[i]);

			//charからwchar_tに指定したサイズ分コピー
			size_t* size = nullptr;
			mbstowcs_s(size, str_name, 12, name, 12);

			Font::StrDraw(str_name, 100.0f, 150.0f + (45.0f * i), 32.0f, m_fColor);

		}
	}
	if (((UserData*)Save::GetData())->m_iStageNum == STAGE_2)
	{
		//ランキング表示
		for (int i = 0; i < MAX_RANKING - 1; i++)
		{
			wchar_t str[256];
			swprintf_s(str, L"%2d位           %12d点", i + 1, ((UserData*)Save::GetData())->m_iRanking_st2[i]);
			Font::StrDraw(str, 50, 150 + (30 * i), 20, m_fColor);

			//自分の順位探索
			if (((UserData*)Save::GetData())->m_RankingPos == i)
			{
				//同じスコアが並んでない場合
				if (((UserData*)Save::GetData())->m_iRanking_st2[i] != ((UserData*)Save::GetData())->m_iRanking_st2[i - 1])
				{
					swprintf_s(str, L"%2d位%12d点", i + 1, ((UserData*)Save::GetData())->m_iRanking_st2[i]);
					Font::StrDraw(str, 10, 150 + (45 * i), 32, m_fColor_Yellow);
				}
				//同じスコアが並んでいる場合
				else
				{
					swprintf_s(str, L"%2d位%12d点", i, ((UserData*)Save::GetData())->m_iRanking_st2[i]);
					Font::StrDraw(str, 10, 150 + (45 * (i - 1)), 32, m_fColor_Yellow);

					swprintf_s(str, L"%2d位%12d点", i + 1, ((UserData*)Save::GetData())->m_iRanking_st2[i]);
					Font::StrDraw(str, 10, 150 + (45 * i), 32, m_fColor);
				}
			}
			else
			{
				swprintf_s(str, L"%2d位%12d点", i + 1, ((UserData*)Save::GetData())->m_iRanking_st2[i]);
				Font::StrDraw(str, 10, 150 + (45 * i), 32, m_fColor);
			}
		}
	}
	if (((UserData*)Save::GetData())->m_iStageNum == STAGE_3)
	{
		//ランキング表示
		for (int i = 0; i < MAX_RANKING - 1; i++)
		{
			wchar_t str[256];
			swprintf_s(str, L"%2d位           %12d点", i + 1, ((UserData*)Save::GetData())->m_iRanking_st3[i]);
			Font::StrDraw(str, 50, 150 + (30 * i), 20, m_fColor);

			//自分の順位探索
			if (((UserData*)Save::GetData())->m_RankingPos == i)
			{
				//同じスコアが並んでない場合
				if (((UserData*)Save::GetData())->m_iRanking_st3[i] != ((UserData*)Save::GetData())->m_iRanking_st3[i - 1])
				{
					swprintf_s(str, L"%2d位%12d点", i + 1, ((UserData*)Save::GetData())->m_iRanking_st3[i]);
					Font::StrDraw(str, 10, 150 + (45 * i), 32, m_fColor_Yellow);
				}
				//同じスコアが並んでいる場合
				else
				{
					swprintf_s(str, L"%2d位%12d点", i, ((UserData*)Save::GetData())->m_iRanking_st3[i]);
					Font::StrDraw(str, 10, 150 + (45 * (i - 1)), 32, m_fColor_Yellow);

					swprintf_s(str, L"%2d位%12d点", i + 1, ((UserData*)Save::GetData())->m_iRanking_st3[i]);
					Font::StrDraw(str, 10, 150 + (45 * i), 32, m_fColor);
				}
			}
			else
			{
				swprintf_s(str, L"%2d位%12d点", i + 1, ((UserData*)Save::GetData())->m_iRanking_st3[i]);
				Font::StrDraw(str, 10, 150 + (45 * i), 32, m_fColor);
			}
		}
	}
}
