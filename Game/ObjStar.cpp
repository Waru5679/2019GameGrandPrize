#include "GameL/DrawTexture.h"
#include "GameL/HitBoxManager.h"

#include "ObjStar.h"
#include "GameHead.h"
#include "Function.h"


//コンストラクタ
CStar::CStar(int x, int y)
{
	m_vPos.x = (float)x * OBJ_SIZE;
	m_vPos.y = (float)y * OBJ_SIZE;
}

//初期化
void CStar::Init()
{
	//色セット
	ColorSet(1.0f, 1.0f, 1.0f, 1.0f, m_fColor);
	
	//当たり判定用HitBox作成
	Hits::SetHitBox(this, m_vPos.x , m_vPos.y, STAR_SIZE / 2.0f, STAR_SIZE / 2.0f, ELEMENT_STAR, OBJ_STAR, 1);
}

//更新
void CStar::Action()
{
	//スクロールの状態取得
	CSceneMain* m_pScene = dynamic_cast<CSceneMain*>(Scene::GetScene());
	m_bScroll = m_pScene->GetScroll();

	//スクロールが横の時左へ動く
	if (m_bScroll = SIDE)
	{
		m_vPos.x -= SCROLL_SPEED;
	}
	//縦なら下へ動く
	else
	{
		m_vPos.y += SCROLL_SPEED;
	}

	//HitBox更新
	CHitBox* hit_b = Hits::GetHitBox(this);

	//当たり判定の位置を星の中に収めるように移動
	hit_b->SetPos( m_vPos.x + (STAR_SIZE / 4.0f), m_vPos.y + (STAR_SIZE / 4.0f));

	//キャラクターに当たったればゲームオーバーへ
	if (hit_b->CheckObjNameHit(OBJ_CHARA) != nullptr)
	{
		//消す
		this->SetStatus(false);
		Hits::DeleteHitBox(this);

		//ゲームオーバーへ
		Scene::SetScene(new CSceneGameOver());
	}
}

//描画
void CStar::Draw()
{
	RECT_F src, dst;

	//切り取り位置
	RectSet(&src, 0.0f, 0.0f, 128.0f, 128.0f);

	//描画位置
	RectSet(&dst, m_vPos.y, m_vPos.x, STAR_SIZE, STAR_SIZE);

	//描画
	Draw::Draw(OBJ_STAR, &src, &dst, m_fColor, 0.0f);
}