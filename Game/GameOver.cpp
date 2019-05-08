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
	//フォントセット
	Font::SetStrTex(L"ゲームオーバー");

	//色
	ColorSet(1.0f, 1.0f, 1.0f, 1.0f, m_fColor);
}

//更新
void CGameOver::Action()
{
	//Enterでタイトルへ
	if (Input::GetTrrigerKey(VK_RETURN) == true)
	{
		if (((UserData*)Save::GetData())->m_iStageNum == STAGE_1)
		{
			//得点情報をランキング最下位に登録
			((UserData*)Save::GetData())->m_iRanking_st1[MAX_RANKING] = ((UserData*)Save::GetData())->m_iScore;

			//得点が高い順に並び替えをする
			RankingSort(((UserData*)Save::GetData())->m_iRanking_st1);

			//for (int i = 0; i < MAX_RANKING; i++)
			//{
				//ランキングの位置探索
				//if (((UserData*)Save::GetData())->m_iRanking[i] == ((UserData*)Save::GetData())->m_iScore)
				//{
					////スコアの位置が10位以上なら名前入力画面へ
					//if (((UserData*)Save::GetData())->m_iRanking[i] < MAX_RANKING)
					//{
					//	//Scene::SetScene(new);
					//	this->SetStatus(false);
					//}
					//else
					//{
			Scene::SetScene(new CSceneTitle());
			this->SetStatus(false);
			//	}
			//}
		//}
		}

		if (((UserData*)Save::GetData())->m_iStageNum == STAGE_2)
		{
			//得点情報をランキング最下位に登録
			((UserData*)Save::GetData())->m_iRanking_st2[MAX_RANKING] = ((UserData*)Save::GetData())->m_iScore;

			//得点が高い順に並び替えをする
			RankingSort(((UserData*)Save::GetData())->m_iRanking_st2);

			//for (int i = 0; i < MAX_RANKING; i++)
			//{
				//ランキングの位置探索
				//if (((UserData*)Save::GetData())->m_iRanking[i] == ((UserData*)Save::GetData())->m_iScore)
				//{
					////スコアの位置が10位以上なら名前入力画面へ
					//if (((UserData*)Save::GetData())->m_iRanking[i] < MAX_RANKING)
					//{
					//	//Scene::SetScene(new);
					//	this->SetStatus(false);
					//}
					//else
					//{
			Scene::SetScene(new CSceneTitle());
			this->SetStatus(false);
			//	}
			//}
		//}
		}

		if (((UserData*)Save::GetData())->m_iStageNum == STAGE_3)
		{
			//得点情報をランキング最下位に登録
			((UserData*)Save::GetData())->m_iRanking_st3[MAX_RANKING] = ((UserData*)Save::GetData())->m_iScore;

			//得点が高い順に並び替えをする
			RankingSort(((UserData*)Save::GetData())->m_iRanking_st3);

			//for (int i = 0; i < MAX_RANKING; i++)
			//{
				//ランキングの位置探索
				//if (((UserData*)Save::GetData())->m_iRanking[i] == ((UserData*)Save::GetData())->m_iScore)
				//{
					////スコアの位置が10位以上なら名前入力画面へ
					//if (((UserData*)Save::GetData())->m_iRanking[i] < MAX_RANKING)
					//{
					//	//Scene::SetScene(new);
					//	this->SetStatus(false);
					//}
					//else
					//{
			Scene::SetScene(new CSceneTitle());
			this->SetStatus(false);
			//	}
			//}
		//}
		}
		
	}
}

//描画
void CGameOver::Draw()
{
	Font::StrDraw(L"ゲームオーバー", 100.0f, 100.0f, 32.0f, m_fColor);
}
