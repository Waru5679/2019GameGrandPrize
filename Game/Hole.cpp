#include "Hole.h"
#include "GameHead.h"
#include "Function.h"
#include "GameL/DrawTexture.h"
#include "GameL/HitBoxManager.h"

//コンストラクタ
CHole::CHole(int y, int x)
{
	m_vPos.x = 400.0f;// (float)y * OBJ_SIZE;
	m_vPos.y = 400.0f;//(float)x * OBJ_SIZE;

}

//初期化
void CHole::Init()
{
	//色
	ColorSet(1.0f, 1.0f, 1.0f, 1.0f, m_fColor);

	//HitBoxセット
	Hits::SetHitBox(this, m_vPos.x- HOLE_SIZE, m_vPos.y-HOLE_SIZE, HOLE_SIZE*3.0f, HOLE_SIZE*3.0f, ELEMENT_HOLE, OBJ_HOLE, 0);
}

//更新
void CHole::Action()
{
	//シーンの状態取得
	CSceneMain* m_pScene = dynamic_cast<CSceneMain*>(Scene::GetScene());
	m_bScroll = m_pScene->GetScroll();

	//コメントアウトするとスクロールの向き次第で左か下へ動く-----
	////スクロールが横の時左へ動く
	//if (m_bScroll == SIDE)
	//{
	//	m_vPos.x -= SCROLL_SPEED;
	//}
	////縦の時下へ動く
	//else
	//{
	//	m_vPos.y += SCROLL_SPEED;
	//}
	//------------------------------------------------------------

	//HitBox更新
	CHitBox* hit_b = Hits::GetHitBox(this);
	hit_b->SetPos(m_vPos.x - HOLE_SIZE, m_vPos.y -HOLE_SIZE);

	//プレイヤーが当たっているとき
	if (hit_b->CheckObjNameHit(OBJ_CHARA) != nullptr)
	{
		//キャラの位置取得
		CObjMainChara* pChara = dynamic_cast<CObjMainChara*>(Objs::GetObj(OBJ_CHARA));
		Vector vCharaPos = pChara->GetPos();

		//キャラクターから見た穴の方向(正規化)
		Vector vHoleDir=CVector::Sub(m_vPos, vCharaPos);
		vHoleDir = CVector::Normalize(vHoleDir);

		//キャラに移動ベクトル追加
		pChara->SetMove(vHoleDir);
	}

	//穴が画面外へ出ると削除
	//
	if (m_vPos.x + (HOLE_SIZE * 2.0f) < 0)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}
	//画面下端
	if (m_vPos.y - HOLE_SIZE > WINDOW_SIZE_H)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}
}

//描画
void CHole::Draw()
{
	RECT_F src, dst;

	//切り取り位置
	RectSet(&src, 0.0f, 0.0f, 128.0f, 128.0f);

	//描画位置
	RectSet(&dst, m_vPos.y, m_vPos.x, HOLE_SIZE, HOLE_SIZE);
	
	//描画
	Draw::Draw(OBJ_HOLE, &src, &dst, m_fColor, 0.0f);

}