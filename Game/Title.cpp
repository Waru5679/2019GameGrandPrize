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

	//色(白)
	ColorSet(1.0f, 1.0f, 1.0f, 1.0f, m_fColor);
	//色(黄色)
	ColorSet(1.0f, 0.0f, 1.0f, 1.0f, m_fColor_Yellow);

	//点滅用タイムの初期化
	m_iTime = 0;
	//点滅用フラグの初期化
	m_bTime_Flag = true;

	//名前用配列の初期化
	for (int i = 0; i <= 6; i++)
	{
		m_cName[i] = ' ';//半角空白で初期化
	}

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
	//点滅用タイムを増やす
	m_iTime++;

	//10000超えそうになったら0に戻す
	if (m_iTime >= 10000)
	{
		m_iTime = 0;
	}
	//40フレームごとにフラグを入れ替える
	if (m_iTime % 40 == 0)
	{
		m_bTime_Flag = !(m_bTime_Flag);
	}

	//Enterでメインへ
	if (Input::GetTrrigerKey(VK_RETURN) == true)
	{
		Scene::SetScene(new CSceneStageSelect());
		this->SetStatus(false);
	}

	if (Input::GetTrrigerKey(VK_BACK) == true)
	{
		//ランキング初期化
		for (int i = 0; i < MAX_RANKING - 1; i++)
		{
			((UserData*)Save::GetData())->m_iRanking_st1[i] = 0;
			((UserData*)Save::GetData())->m_iRanking_st2[i] = 0;
			((UserData*)Save::GetData())->m_iRanking_st3[i] = 0;


			strcpy_s(((UserData*)Save::GetData())->m_RankingName_st1[i],"+++++");
			strcpy_s(((UserData*)Save::GetData())->m_RankingName_st2[i], "+++++");
			strcpy_s(((UserData*)Save::GetData())->m_RankingName_st3[i], "+++++");
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
	

	//点滅用フラグがオフなら次画面案内を非表示
	if (m_bTime_Flag == false)
	{
		
	}
	else
	{
		//次画面案内表示
		Font::StrDraw(L"Push Enter", 240.0f, 520.0f, 50.0f, m_fColor_Yellow);
	}
}
