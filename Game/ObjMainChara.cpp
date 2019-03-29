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
	m_fPosture = 1.0f;//右向き0.0f 左向き1.0f
	m_bHitGround = false;
	m_bBullet_FireIs = true;

	m_fGravity = 0.98f;

	//スクロールの状態取得
	CSceneMain* m_pScene = new CSceneMain();
	m_bScroll = m_pScene->GetScroll();
}

//アクション
void CObjMainChara::Action()
{

	Move(); //移動呼び出し

	//ジャンプ
	if (Input::GetVKey('C') == true)
	{
		if (m_bHitGround == true)
		{
			m_fvy = -15.0f;
			m_bHitGround = false;
		}
	}


	//自由落下
	if (m_vPos.y < 600.0f - 150.0f)
	{
		m_fvy += 9.8f / (16.0f);
	}
	else
	{
		m_vPos.y = 600.0f - 150.0f;
		m_bHitGround = true;
	}


	//位置の更新
	m_vPos.x += m_fvx;
	m_vPos.y += m_fvy;

	//攻撃
	if (Input::GetVKey('X') == true)
	{
		if (m_bBullet_FireIs == true)
		{
			//弾生成
			CCharaBullet* pBullet = new CCharaBullet(m_vPos, CVector::Create(0.0f, -3.0f));
			Objs::InsertObj(pBullet, OBJ_CHARA_BULLET, 10);

			m_bBullet_FireIs = false;
		}
	}
	else
	{
		m_bBullet_FireIs = true;
	}

}

//ドロー
void CObjMainChara::Draw()
{	
	RECT_F src, dst;

	//切り取り位置の設定
	RectSet(&src, 0.0f, 0.0f, 65.0f, 90.0f);

	//表示位置の設定
	dst.m_top	= 0.0f + m_vPos.y;
	dst.m_left	= (64.0f * m_fPosture)+m_vPos.x;
	dst.m_right	= (64.0f - 64.0f * m_fPosture)+m_vPos.x;
	dst.m_bottom= 128.0f + m_vPos.y;

	//描画
	Draw::Draw(OBJ_CHARA, &src, &dst, m_fColor, 0.0f);
}


//移動
void CObjMainChara::Move()
{
	//キー入力　右
	if (Input::GetVKey(VK_RIGHT) == true)
	{
		m_fvx += 1.0f;
		m_fPosture = 1.0f;
	}

	//キー入力　左
	if (Input::GetVKey(VK_LEFT) == true)
	{
		m_fvx -= 1.0f;
		m_fPosture = 0.0f;
	}

	//縦スクロール時のみ有効
	if (m_bScroll == SIDE)
	{

		//キー入力　上
		if (Input::GetVKey(VK_UP) == true)
		{
			m_fvy = -5.0f;
		}

		//キー入力　下
		if (Input::GetVKey(VK_DOWN) == true)
		{
			m_fvy = +5.0f;
		}
		
		m_fvy += -(m_fvy * 0.098); //摩擦　縦
	}
	//横スクロール時のみ有効
	else
	{
		//キー入力　右
		if (Input::GetVKey(VK_RIGHT) == true)
		{
			m_fvx = +1.0f;
			m_fPosture = 1.0f;
		}

		//キー入力　左
		if (Input::GetVKey(VK_LEFT) == true)
		{
			m_fvx = -1.0f;
			m_fPosture = 0.0f;
		}

	}

	//摩擦
	m_fvx += -(m_fvx * 0.098); //摩擦　横
	//----------------------------------------------
}