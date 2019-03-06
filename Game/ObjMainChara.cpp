//使用するヘッダーファイル
#include "GameL/DrawTexture.h"
#include "GameL/WinInputs.h"
#include "GameL/SceneManager.h"

#include "GameHead.h"
#include "ObjMainChara.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjMainChara::Init()
{

}

//アクション
void CObjMainChara::Action()
{

}

//ドロー
void CObjMainChara::Draw()
{
	//描画カラー情報
	float m_fc[4] = { 1.0f,1.0f,1.0f,1.0f };

	//描画元切り取り位置
	RECT_F src;
	//描画先表示位置
	RECT_F dst;

	//切り取り位置の設定
	src.m_top	 = 0.0f;
	src.m_left	 = 0.0f;
	src.m_right	 = 65.0f;
	src.m_bottom = 90.0f;

	//表示位置の設定
	dst.m_top    = 0.0f;
	dst.m_left	 = 0.0f;
	dst.m_right  = 64.0f;
	dst.m_bottom = 128.0f;

	//描画
	Draw::Draw(0, &src, &dst, m_fc, 0.0f);
}