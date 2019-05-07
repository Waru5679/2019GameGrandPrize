#include "NameInput.h"
#include "Function.h"
#include "GameL/WinInputs.h"
#include "GameL/DrawFont.h"
#include "GameL/SceneManager.h"
#include "GameL/UserData.h"
#include "GameHead.h"

//初期化
void CNameInput::Init()
{
	//フォントセット
	Font::SetStrTex(L"名前入力");

	//色
	ColorSet(1.0f, 1.0f, 1.0f, 1.0f, m_fColor);
}

//更新
void CNameInput::Action()
{

}

//描画
void CNameInput::Draw()
{

}