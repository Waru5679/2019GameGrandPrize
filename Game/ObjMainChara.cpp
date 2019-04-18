//使用するヘッダーファイル
#include "GameL/DrawTexture.h"
#include "GameL/WinInputs.h"
#include "GameL/SceneManager.h"
#include "GameL/HitBoxManager.h"

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

	m_vPos.x = 0.0f;	//位置
	m_vPos.y = WINDOW_SIZE_H - CHARA_SIZE;
	m_vMove.x = 0.0f;	//移動ベクトル
	m_vMove.y = 0.0f;
	m_bDirection = false;
	m_bHitGround = false;
	m_bBullet_FireIs = true;

	m_fGravity = 0.98f;

	//当たり判定用HitBox作成
	Hits::SetHitBox(this, m_vPos.x, m_vPos.y, CHARA_SIZE, CHARA_SIZE, ELEMENT_PLAYER, OBJ_CHARA, 1);
}

//アクション
void CObjMainChara::Action()
{
	//スクロールの状態取得
	CSceneMain* m_pScene = dynamic_cast<CSceneMain*>(Scene::GetScene());
	m_bScroll = m_pScene->GetScroll();

	//縦
	if (m_bScroll == VERTICAL)
	{
		VarticalMove();
	}
	//横
	else
	{
		SideMove();
	}
			
	//移動範囲制御------------------------------
	//画面右端
	if (m_vPos.x > WINDOW_SIZE_W - CHARA_SIZE)
	{
		m_vPos.x = WINDOW_SIZE_W - CHARA_SIZE;
	}
	//画面左端
	if (m_vPos.x < 0.0f)
	{
		m_vPos.x = 0.0f;
	}
	//画面上端
	if (m_vPos.y < 0.0f)
	{
		m_vPos.y = 0.0f;
	}
	//画面下端(縦スクロール時のみ有効)
	if (m_vPos.y > WINDOW_SIZE_H - CHARA_SIZE)
	{
		m_vPos.y = WINDOW_SIZE_H - CHARA_SIZE;
	}
	//----------------------------------------------

	//HitBox更新
	CHitBox* hit_b = Hits::GetHitBox(this);
	hit_b->SetPos(m_vPos.x, m_vPos.y);

}

//ドロー
void CObjMainChara::Draw()
{
	RECT_F src, dst;

	//切り取り位置の設定
	RectSet(&src, 64.0f, 2.0f, 32.0f, 32.0f);

	//表示位置の設定
	dst.m_top = m_vPos.y;

	//向きが右なら画像を反転する
	if (m_bDirection == false)
	{
		dst.m_left = m_vPos.x;
		dst.m_right = m_vPos.x + CHARA_SIZE;
	}
	//向きが左なら読み取った時の状態にする
	else
	{
		dst.m_left = (64.0f * 1.0f) + m_vPos.x;
		dst.m_right =m_vPos.x;
	}
	dst.m_bottom =m_vPos.y + CHARA_SIZE;

	//描画
	Draw::Draw(OBJ_CHARA, &src, &dst, m_fColor, 0.0f);
}


//移動横
void CObjMainChara::SideMove()
{
	//入力
	VarticalInput();
	
	//位置の更新
	m_vPos.x += m_vMove.x;
	m_vPos.y += m_vMove.y;

}

//移動縦
void CObjMainChara::VarticalMove()
{
	//入力
	SideInput();

	//自由落下　地面についてないときは落下する
	if (m_vPos.y <= 585.0f - CHARA_SIZE)
	{
		m_vMove.y += 9.8f / 16.0f;
	}
	//地面についていればジャンプ用の判定(m_bHitGround)をtrueにする
	else
	{
		m_bHitGround = true;
	}
	
	//位置の更新
	m_vPos.x += m_vMove.x;
	m_vPos.y += m_vMove.y;

}

//横の入力
void CObjMainChara::SideInput()
{
	//キー入力　右
	if (Input::GetVKey(VK_RIGHT) == true)
	{
		m_vMove.x = 3.0f;
		m_bDirection = false;
	}
	//キー入力　左
	else if (Input::GetVKey(VK_LEFT) == true)
	{
		m_vMove.x = -3.0f;
		m_bDirection = true;
	}
	else
	{
		m_vMove.x = 0.0f;
	}

	//ジャンプ
	if (Input::GetVKey('C') == true)
	{
		//地面に接地してるとき(m_bHitGround == true)の時のみ飛ぶ
		if (m_bHitGround == true)
		{
			m_vMove.y = -15.0f;
			m_bHitGround = false;
		}
	}
}

//縦の入力
void CObjMainChara::VarticalInput()
{
	//キー入力　右
	if (Input::GetVKey(VK_RIGHT) == true)
	{
		m_vMove.x = 3.0f;
		m_bDirection = false;
	}
	//キー入力　左
	else if (Input::GetVKey(VK_LEFT) == true)
	{
		m_vMove.x = -3.0f;
		m_bDirection = true;
	}
	else
	{
		m_vMove.x = 0.0f;
	}

	//キー入力　上
	if (Input::GetVKey(VK_UP) == true)
	{
		m_vMove.y = -3.0f;
	}
	//キー入力　下
	else if (Input::GetVKey(VK_DOWN) == true)
	{
		m_vMove.y =  3.0f;
	}
	else
	{
		m_vMove.y = 0.0f;
	}

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