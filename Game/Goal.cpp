#include "Goal.h"
#include "GameHead.h"
#include "Function.h"
#include "GameL/HitBoxManager.h"
#include "GameL/UserData.h"

//コンストラクタ
CGoal::CGoal(int x, int y)
{
	m_vPos.x = (float)x * OBJ_SIZE;
	m_vPos.y = (float)y * OBJ_SIZE;
}

//初期化
void CGoal::Init()
{
	//色
	ColorSet(1.0f, 1.0f, 1.0f, 1.0f, m_fColor);

	//当たり判定
	Hits::SetHitBox(this, m_vPos.x, m_vPos.y, GOAL_SIZE, GOAL_SIZE, ELEMENT_STAGE, OBJ_GOAL, 1);
}

//更新
void CGoal::Action()
{
	//スクロールの状態取得
	CSceneMain* m_pScene = dynamic_cast<CSceneMain*>(Scene::GetScene());
	m_bScroll = m_pScene->GetScroll();

	//スクロールが横の時左へ動く
	if (m_bScroll == SIDE)
	{
		m_vPos.x -= SCROLL_SPEED;
	}
	//縦なら下へ動く
	else
	{
		m_vPos.y += SCROLL_SPEED;
	}

	//主人公との当たり判定
	CHitBox* hit_b = Hits::GetHitBox(this);
	//主人公と当たればゲームクリアへ
	if (hit_b->CheckObjNameHit(OBJ_CHARA) != nullptr)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);

		//ゲームクリアへ
		Scene::SetScene(new CSceneGameClear());
	}
}

//描画
void CGoal::Draw()
{
	RECT_F src, dst;

	//切り取り位置
	RectSet(&src, 0.0f, 0.0f, 128.0f, 128.0f);

	//描画位置
	RectSet(&dst, m_vPos.y, m_vPos.x, GOAL_SIZE, GOAL_SIZE);

	//描画
	Draw::Draw(OBJ_GOAL, &src, &dst, m_fColor, 0.0f);

}