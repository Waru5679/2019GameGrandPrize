#include "ObjClear.h"
#include "GameHead.h"
#include "Function.h"
#include "GameL/HitBoxManager.h"

//コンストラクタ
CObjClear::CObjClear(int x, int y)
{
	m_vPos.x = (float)x * OBJ_SIZE;
	m_vPos.y = (float)y * OBJ_SIZE;
}

//初期化
void CObjClear::Init()
{
	//色
	ColorSet(1.0f, 1.0f, 1.0f, 1.0f, m_fColor);

	//当たり判定
	Hits::SetHitBox(this, m_vPos.x, m_vPos.y, CLEAR_SIZE, CLEAR_SIZE, ELEMENT_STAGE, OBJ_GAME_CLEAR, 1);
}

//更新
void CObjClear::Action()
{
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
void CObjClear::Draw()
{
	RECT_F src, dst;

	//切り取り位置
	RectSet(&src, 0.0f, 0.0f, 128.0f, 128.0f);

	//描画位置
	RectSet(&dst, m_vPos.y, m_vPos.x, CLEAR_SIZE, CLEAR_SIZE);

	//描画
	Draw::Draw(OBJ_GAME_CLEAR, &src, &dst, m_fColor, 0.0f);
}