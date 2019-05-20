#include "NameInput.h"
#include "Function.h"
#include "GameL/WinInputs.h"
#include "GameL/DrawFont.h"
#include "GameL/SceneManager.h"
#include "GameL/UserData.h"
#include "GameHead.h"

//使用するネームスペース
using namespace GameL;

//初期化
void CNameInput::Init()
{
	//フォントセット
	Font::SetStrTex(L"名前入力");
	//色セット
	ColorSet(1.0f, 1.0f, 1.0f, 1.0f, m_fColor);
	//色セット赤
	ColorSet(1.0f, 0.0f, 0.0f, 1.0f, m_fColor_Red);

	//フラグの初期化
	m_bFirst_Flag = true;
	m_bKey_Flag = false;
	m_bInput_Flag = false;
	m_bEnd_Flag = false;
	m_bNoname_Flag = false;
	m_bTime_Flag = true;

	//名前用配列の初期化
	for (int i = 0; i <= 6; i++)
	{
		m_cName[i] = ' ';//半角空白で初期化
	}

	//コピー用配列の初期化
	for (int i = 0; i <= 10; i++)
	{
		m_cCopy_Name[i] = ' ';//半角空白で初期化
	}

	m_iTime = 0;//点滅用タイムの初期化
	m_iInput_Count = 0;//名前保存用配列の要素番号初期化

	//出力させる文字のグラフィックを作成
	Font::SetStrTex((wchar_t*)L"名前を入力してください(英字5文字以内)");
	Font::SetStrTex((wchar_t*)L"最低1文字は入力してください");
	Font::SetStrTex((wchar_t*)L"Enterで入力終了");
	Font::SetStrTex((wchar_t*)L"BackSpaceでやり直し");
	Font::SetStrTex((wchar_t*)L"_");
}

//更新
void CNameInput::Action()
{
	m_iTime++;//点滅用タイムを増やす

	//10000を超えそうになったら0に戻す
	if (m_iTime >= 10000)
	{
		m_iTime = 0;
	}

	//60フレームごとにフラグを入れ替える
	if (m_iTime % 60 == 0)
	{
		m_bTime_Flag = !(m_bTime_Flag);
	}

	//初めの2回目以降
	if (m_bFirst_Flag == false)
	{
		//入力が終了していなかった場合
		if (m_bEnd_Flag == false)
		{
			//キーフラグがオンの場合
			if (m_bKey_Flag == true)
			{
				//名前を入力する
				m_bInput_Flag = KeyInput(m_iInput_Count);

				//対応ボタンのどこかが押された場合
				if (m_bInput_Flag == true)
				{
					NameCpy(m_cName);//描画用のコピーを取る
					m_bEnd_Flag = InputEndCheck();//文字列の入力が終えているかどうかを調べる
					m_bKey_Flag = false;//キーフラグをオフにする
				}
			}
			//キーフラグがオフなら
			else
			{
				//1つ前の文字と同じ文字が押されていなければ
				if (Input::GetVKey(m_cName[m_iInput_Count - 1]) == false)
				{
					m_bKey_Flag = true;	//キーフラグをオンにする
				}
			}
		}
		//入力が完了した場合
		else
		{
			//ステージ1なら
			if (((UserData*)Save::GetData())->m_iStageNum == STAGE_1)
			{
				//名前をユーザーデータにコピー
				strcpy_s(((UserData*)Save::GetData())->m_RankingName_st1[((UserData*)Save::GetData())->m_RankingPos], m_cName);//名前
		
			}
			//ステージ2なら
			else if (((UserData*)Save::GetData())->m_iStageNum == STAGE_2)
			{
				//名前をユーザーデータにコピー
				strcpy_s(((UserData*)Save::GetData())->m_RankingName_st2[((UserData*)Save::GetData())->m_RankingPos], m_cName);//名前
			}
			//ステージ3なら
			else if (((UserData*)Save::GetData())->m_iStageNum == STAGE_3)
			{
				//名前をユーザーデータにコピー
				strcpy_s(((UserData*)Save::GetData())->m_RankingName_st3[((UserData*)Save::GetData())->m_RankingPos], m_cName);//名前
			}

			//UserDataの作成(セーブ)する
			Save::Seve();

			//タイトルシーンに移動
			Scene::SetScene(new CSceneTitle());
		}
	}

	//フラグをオフにする
	m_bFirst_Flag = false;
}

//描画
void CNameInput::Draw()
{
	//文字の描画
	Font::StrDraw((wchar_t*)L"名前を入力してください(英字5文字以内)", 40.0f, 150.f, 40.0f, m_fColor);
	Font::StrDraw((wchar_t*)L"BackSpaceで入力のやり直し", 100.0f, WINDOW_SIZE_H - 50.0f, 30.0f, m_fColor);
	Font::StrDraw((wchar_t*)L"Enterで入力終了", WINDOW_SIZE_W - 300.0f, WINDOW_SIZE_H - 50.0f, 30.0f, m_fColor);

	wchar_t str_Name[50];

	//charからwchar_tに指定したサイズ分コピー
	size_t* size = nullptr;
	mbstowcs_s(size, str_Name, 50.0f, m_cCopy_Name, 50);
	//入力した文字を表示
	Font::StrDraw(str_Name, 300.0f, 400.0f, 50.0f, m_fColor);

	//「_」表示
	for (int i = 0; i < 5; i++)
	{
		//次の入力箇所　かつ　フラグがオフなら
		if (i == m_iInput_Count && m_bTime_Flag == false)
		{
			//' 'を表示
			Font::StrDraw((wchar_t*)L" ", 300.0f + 50.0f * i, 400.0f, 50.0f, m_fColor);
		}
		else
		{
			//'_'を表示
			Font::StrDraw((wchar_t*)L"_", 300.0f + 50.0f * i, 400.0f, 50.0f, m_fColor);
		}

	}

	if (m_bNoname_Flag == true)
	{
		Font::StrDraw((wchar_t*)L"最低1文字は入力してください", 100.0f, 300.0f, 50.0f, m_fColor_Red);
	}
}

//ネーム入力のキーボードから文字を読み取る関数
//引数 : 入力された文字を入れる配列の要素数
//戻り値 : 対応しているKeyが押されたら:true 何処も押されていなければ:false
bool CNameInput::KeyInput(int number)
{
	//EnterKeyが押されたとき
	if (Input::GetVKey(VK_RETURN) == true)
	{
		//未入力の状態なら
		if (m_cName[0] == ' ')
		{
			//入力を促す文章の追加用にフラグをオンにする
			m_bNoname_Flag = true;
		}
		else
		{
			//\0を入れる
			m_cName[number] = '\0';
			return true;
		}
	}

	//バックスペースが押されたとき
	if (Input::GetVKey(VK_BACK) == true)
	{
		for (int i = 0; i < 6; i++)
		{
			//配列の初期化
			m_cName[i] = ' ';
		}

		m_iInput_Count = 0;

		return true;
	}

	//keyの状態を調べる
	for (char key = 'A'; key <= 'Z'; key++)
	{
		if (Input::GetVKey(key) == true)
		{
			//押されたkeyを配列に保存
			m_cName[number] = key;

			//5文字目までなら
			if (m_iInput_Count < 5)
			{
				//保存位置を一文字進める
				m_iInput_Count++;

				return true;
			}
		}
	}
	return false;
}

//文字列入力が終わっているか(\0があるか)調べる関数
//戻り値:\0があれば:true　なければ:false
bool CNameInput::InputEndCheck()
{
	//配列の中身を確認していく
	for (int i = 0; i < 6; i++)
	{
		//\0があれば
		if (m_cName[i] == '\0')
		{
			return true;
		}
	}
	return false;
}

//文字列の文字ごと間に半角空白を入れる関数
void CNameInput::NameCpy(char name[])
{
	int i;
	//文字列の配列サイズになるまでループ
	for (i = 0; i < sizeof(name) * 2 + 1; i++)
	{
		//要素数が偶数なら
		if (i % 2 == 0)
		{
			//配列に入っている文字を入れる
			m_cCopy_Name[i] = m_cName[i / 2];
		}
		else
		{
			//半角空白を入れる
			m_cCopy_Name[i] = ' ';
		}
	}
	//末尾に\0を入れる
	m_cCopy_Name[i] = '\0';
}