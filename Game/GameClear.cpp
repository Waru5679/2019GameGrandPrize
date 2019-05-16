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
	//色
	ColorSet(1.0f, 1.0f, 1.0f, 1.0f, m_fColor);
	ColorSet(1.0f, 1.0f, 0.0f, 1.0f, m_fColorS);

	int iRankPosition = MAX_RANKING - 1;//11-1 -> 10

	if (((UserData*)Save::GetData())->m_iStageNum == STAGE_1)
	{
		//得点情報をステージ1のランキング最下位に登録			
		((UserData*)Save::GetData())->m_iRanking_st1[iRankPosition] = ((UserData*)Save::GetData())->m_iScore;
	}
	if (((UserData*)Save::GetData())->m_iStageNum == STAGE_2)
	{
		//得点情報をステージ2のランキング最下位に登録
		((UserData*)Save::GetData())->m_iRanking_st2[iRankPosition] = ((UserData*)Save::GetData())->m_iScore;
	}
	if (((UserData*)Save::GetData())->m_iStageNum == STAGE_3)
	{
		//得点情報をステージ3のランキング最下位に登録
		((UserData*)Save::GetData())->m_iRanking_st3[iRankPosition] = ((UserData*)Save::GetData())->m_iScore;
	}
}

//更新
void CGameClear::Action()
{
	//ステージ1の得点を高い順に並び替えをする
	RankingSort(((UserData*)Save::GetData())->m_iRanking_st1);
	//ステージ2の得点を高い順に並び替えをする
	RankingSort(((UserData*)Save::GetData())->m_iRanking_st2);
	//ステージ3の得点を高い順に並び替えをする
	RankingSort(((UserData*)Save::GetData())->m_iRanking_st3);

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
	RECT_F Dst, Src;

	//切り取り位置
	RectSet(&Src, 0.0f, 0.0f, 800.0f, 600.0f);

	//描画位置
	RectSet(&Dst, 0.0f, 0.0f, WINDOW_SIZE_W, WINDOW_SIZE_H);

	//描画
	Draw::Draw(OBJ_BACK_GROUND, &Src, &Dst, m_fColor, 0.0f);

	//ゲームクリア文字表示
	Font::StrDraw(L"Game Clear", 250.0f, 10.0f, 64.0f, m_fColorS);

	//ランキング表示
	if (((UserData*)Save::GetData())->m_iStageNum == STAGE_1)
	{
		Font::StrDraw(L"ステージ1", 340.0f, 100.0f, 30.0f, m_fColorS);

		//ランキング表示
		for (int i = 0; i < MAX_RANKING - 1; i++)
		{
			wchar_t str[256];
			swprintf_s(str, L"%2d位           %12d点", i + 1, ((UserData*)Save::GetData())->m_iRanking_st1[i]);
			Font::StrDraw(str, 150, 150 + (43 * i), 30, m_fColorS);

			//自分の順位確認用矢印「←」を表示
			//探索用for文（同じ数値が2個以上並んだ時に抜けれる用）
			for (int j = 0; j < MAX_RANKING - 1; j++)
			{
				//スコアが0じゃないとき
				if (((UserData*)Save::GetData())->m_iScore != 0)
				{
					//スコアがランキング内のスコアと一緒の時
					if (((UserData*)Save::GetData())->m_iRanking_st1[j] == ((UserData*)Save::GetData())->m_iScore)
					{
						swprintf_s(str, L"← あなた");
						Font::StrDraw(str, 620, 150 + (43 * j), 30, m_fColorS);

						break;
					}
				}
			}
		}
	}
	if (((UserData*)Save::GetData())->m_iStageNum == STAGE_2)
	{
		Font::StrDraw(L"ステージ2", 140.0f, 100.0f, 32.0f, m_fColor);

		//ランキング表示
		for (int i = 0; i < MAX_RANKING - 1; i++)
		{
			wchar_t str[256];
			swprintf_s(str, L"%2d位           %12d点", i + 1, ((UserData*)Save::GetData())->m_iRanking_st2[i]);
			Font::StrDraw(str, 250, 150 + (43 * i), 30, m_fColor);

			//自分の順位確認用矢印「←」を表示
			//探索用for文（同じ数値が2個以上並んだ時に抜けれる用）
			for (int j = 0; j < MAX_RANKING - 1; j++)
			{
				//スコアが0じゃないとき
				if (((UserData*)Save::GetData())->m_iScore != 0)
				{
					//スコアがランキング内のスコアと一緒の時
					if (((UserData*)Save::GetData())->m_iRanking_st2[j] == ((UserData*)Save::GetData())->m_iScore)
					{
						swprintf_s(str, L"← あなた");
						Font::StrDraw(str, 620, 150 + (43 * j), 30, m_fColor);

						break;
					}
				}
			}
		}
	}
	if (((UserData*)Save::GetData())->m_iStageNum == STAGE_3)
	{
		Font::StrDraw(L"ステージ3", 140.0f, 100.0f, 30.0f, m_fColor);

		//ランキング表示
		for (int i = 0; i < MAX_RANKING - 1; i++)
		{
			wchar_t str[256];
			swprintf_s(str, L"%2d位           %12d点", i + 1, ((UserData*)Save::GetData())->m_iRanking_st3[i]);
			Font::StrDraw(str, 250, 150 + (43 * i), 30, m_fColor);

			//自分の順位確認用矢印「←」を表示
			//探索用for文（同じ数値が2個以上並んだ時に抜けれる用）
			for (int j = 0; j < MAX_RANKING - 1; j++)
			{
				//スコアが0じゃないとき
				if (((UserData*)Save::GetData())->m_iScore != 0)
				{
					//スコアがランキング内のスコアと一緒の時
					if (((UserData*)Save::GetData())->m_iRanking_st3[j] == ((UserData*)Save::GetData())->m_iScore)
					{
						swprintf_s(str, L"← あなた");
						Font::StrDraw(str, 620, 150 + (43 * j), 30, m_fColor);

						break;
					}
				}
			}
		}
	}
	
}