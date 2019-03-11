#include "SceneMain.h"
#include "GameL/DrawTexture.h"
#include "GameHead.h"
#include "main.h"
#include "GameL/UserData.h"

//初期化
void CSceneMain::InitScene()
{
	//テクスチャ読み込み
	LoadTexture();

	//マップ情報読み込み
	LoadMap(L"Map/TestMap.csv");

	//背景オブジェクト1
	m_pBack1 = new CBackGround(0.0f, 0.0f, SIDE);
	Objs::InsertObj(m_pBack1, OBJ_BACK_GROUND, 1);

	//背景オブジェクト2
	m_pBack2 = new CBackGround(WINDOW_SIZE_W, 0.0f, SIDE);
	Objs::InsertObj(m_pBack2, OBJ_BACK_GROUND, 1);

	//マップオブジェクト
	CMap* pMap = new CMap(m_Map);
	Objs::InsertObj(pMap, OBJ_MAP, 100);

	//カウンタ初期化
	m_Count = 0;

	//スクロール方向
	m_bScroll = SIDE;
}

//実行中
void CSceneMain::Scene()
{
	//カウンタ更新
	m_Count++;

	//debug用100回でスクロールの向きを変える
	if (m_Count > 100)
	{
		m_Count = 0;

		//スクロール方向の切り替え
		m_bScroll = !(m_bScroll);

		//背景の位置とスクロール方向の変更

		//横→縦に変更
		if (m_bScroll == VERTICAL)
		{
			m_pBack1->SetScroll(0.0f, 0.0f, VERTICAL);
			m_pBack2->SetScroll(0.0f, WINDOW_SIZE_H, VERTICAL);

		}
		//縦→横に変更
		else
		{
			m_pBack1->SetScroll(0.0f, 0.0f, SIDE);
			m_pBack2->SetScroll(WINDOW_SIZE_W, 0.0f, SIDE);
		}
	}
}

//テクスチャ読み込み
void CSceneMain::LoadTexture()
{
	//背景
	Draw::LoadImageW(L"Texture/BackGround.jpg", OBJ_BACK_GROUND, TEX_SIZE_256);	
	//穴
	Draw::LoadImageW(L"Texture/Hole.jpg", OBJ_HOLE, TEX_SIZE_256);	

}

//マップ読み込み
void CSceneMain::LoadMap(const wchar_t* Name)
{
	unique_ptr<wchar_t>p;//ポインター
	int size;            //サイズ

	//データ読み込み
	p = Save::ExternalDataOpen(Name, &size);

	int count = 1;	//読み込み用カウンタ
	int num = 0;	//数値

	//数値コピー
	for (int i = 0; i < MAX_Y; i++)
	{
		for (int j = 0; j < MAX_X; j++)
		{
			swscanf_s(&p.get()[count], L"%d", &num);
			m_Map[i][j] = num;
			count += 2;
		}
	}
}