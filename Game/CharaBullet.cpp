#include "CharaBullet.h"
#include "Function.h"
#include "GameHead.h"

//コンストラクタ
CCharaBullet::CCharaBullet(Vector vPos, Vector vMove)
{
	//位置
	m_vPos = vPos;

	//移動
	m_vMove = vMove;
}

//初期化
void CCharaBullet::Init()
{
	//色
	ColorSet(1.0f, 1.0f, 1.0f, 1.0f, m_fColor);

	//回転
	m_fRot = 0.0f;

	//画面内
	m_bInWindow = true;
}

//更新
void CCharaBullet::Action()
{
	//移動
	m_vPos = CVector::Add(m_vPos, m_vMove);

	//画面内か調べる
	m_bInWindow = WindowInCheck(m_vPos, CVector::Create(BULLET_SIZE, BULLET_SIZE));

	//画面外なら消す
	if (m_bInWindow == false)
	{
		this->SetStatus(false);
	}
}

//描画
void CCharaBullet::Draw()
{
	RECT_F src, dst;

	//切り取り位置
	RectSet(&src, 0.0f, 0.0f, 128.0f, 128.0f);

	//描画位置
	RectSet(&dst, m_vPos.y, m_vPos.x, ENEMY_SIZE, ENEMY_SIZE);

	//描画
	Draw::Draw(OBJ_CHARA_BULLET, &src, &dst, m_fColor, m_fRot);
}
