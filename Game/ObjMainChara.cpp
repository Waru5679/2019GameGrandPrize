//使用するヘッダーファイル
#include "GameL/DrawTexture.h"
#include "GameL/WinInputs.h"
#include "GameL/SceneManager.h"

#include "GameHead.h"
#include "ObjMainChara.h"
#include "Function.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjMainChara::Init()
{
	//描画カラーセット
	ColorSet(1.0f, 1.0f, 1.0f, 1.0f, m_fColor);

	m_vPos.x = 0.0f;		//位置
	m_vPos.y = 0.0f;
	m_fvx = 0.0f;		//移動ベクトル
	m_fvy = 0.0f;
	m_fposture = 1.0f;//右向き0.0f 左向き1.0f
}

//アクション
void CObjMainChara::Action()
{
	//移動ベクトルの破棄
	m_fvx = 0.0f;
	m_fvy = 0.0f;

	//キー入力　右
	if (Input::GetVKey(VK_RIGHT) == true)
	{
		m_fvx = +1.0f;
		m_fposture = 1.0f;
	}
	
	//	〃　　　左
	if (Input::GetVKey(VK_LEFT) == true)
	{
		m_fvx = -1.0f;
		m_fposture = 0.0f;
	}

	//位置の更新
	m_vPos.x += m_fvx;
	m_vPos.y += m_fvy;
}

//ドロー
void CObjMainChara::Draw()
{	
	RECT_F src, dst;

	//切り取り位置の設定
	RectSet(&src, 0.0f, 0.0f, 65.0f, 90.0f);

	//表示位置の設定
	dst.m_top	= 0.0f + m_vPos.y;
	dst.m_left	= (64.0f * m_fposture)+m_vPos.x;
	dst.m_right	= (64.0f - 64.0f * m_fposture)+m_vPos.x;
	dst.m_bottom= 128.0f + m_vPos.y;

	//描画
	Draw::Draw(OBJ_CHARA, &src, &dst, m_fColor, 0.0f);
}