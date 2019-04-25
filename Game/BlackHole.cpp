#include "BlackHole.h"
#include "GameHead.h"
#include "Function.h"
#include "GameL/DrawTexture.h"
#include "GameL/HitBoxManager.h"

//コンストラクタ
CBlackHole::CBlackHole(int x, int y)
{
	m_vPos.x = (float)x * OBJ_SIZE;
	m_vPos.y = (float)y * OBJ_SIZE;
}

//初期化
void CBlackHole::Init()
{
	//色
	ColorSet(1.0f, 1.0f, 1.0f, 1.0f, m_fColor);
	
	//吸引力
	m_fSuctionPower=1.2f;

	//死亡判定の位置　(オブジェクトの中心と死亡判定の中心が同じになる位置にしてる)
	m_vDeathPos.x = (m_vPos.x - (BLACK_HOLE_SIZE / 2.0f))- (HOLE_DEATH_SIZE / 2.0f);
	m_vDeathPos.y = (m_vPos.y - (BLACK_HOLE_SIZE / 2.0f)) - (HOLE_DEATH_SIZE / 2.0f);

	//吸引判定
	m_pSuction = Hits::SetHitBox(this, m_vPos.x, m_vPos.y, BLACK_HOLE_SIZE, BLACK_HOLE_SIZE, ELEMENT_STAGE, OBJ_BLACK_HOLE, 0);

	//死亡判定
	m_pDeath = Hits::SetHitBox(this, m_vDeathPos.x, m_vDeathPos.y, HOLE_DEATH_SIZE, HOLE_DEATH_SIZE, ELEMENT_DEATH, OBJ_BLACK_HOLE, 0);
}

//更新
void CBlackHole::Action()
{
	//シーンの状態取得
	CSceneMain* m_pScene = dynamic_cast<CSceneMain*>(Scene::GetScene());
	m_bScroll = m_pScene->GetScroll();
	
	//スクロールが横の時左へ動く
	if (m_bScroll == SIDE)
	{
		m_vPos.x -= SCROLL_SPEED;
	}
	//縦の時下へ動く
	else
	{
		m_vPos.y += SCROLL_SPEED;
	}
	
	//死亡判定の位置　(オブジェクトの中心と死亡判定の中心が同じになる位置にしてる)
	m_vDeathPos.x = (m_vPos.x + (BLACK_HOLE_SIZE / 2.0f)) - (HOLE_DEATH_SIZE / 2.0f);
	m_vDeathPos.y = (m_vPos.y + (BLACK_HOLE_SIZE / 2.0f))- (HOLE_DEATH_SIZE / 2.0f);

	//HitBox更新
	m_pSuction->SetPos(m_vPos.x, m_vPos.y);
	m_pDeath->SetPos(m_vDeathPos.x,m_vDeathPos.y);	
	
	//キャラに当たっているときの吸い込み判定
	if (m_pSuction->CheckObjNameHit(OBJ_CHARA) != nullptr)
	{
		//キャラの位置取得
		CObjMainChara* pChara = dynamic_cast<CObjMainChara*>(Objs::GetObj(OBJ_CHARA));
		Vector vCharaPos = pChara->GetPos();

		//キャラクターから見た穴の方向(正規化)
		Vector vHoleDir=CVector::Sub(m_vDeathPos, vCharaPos);
		vHoleDir = CVector::Normalize(vHoleDir);

		//キャラに移動ベクトル追加
		pChara->HitBlackHole(CVector::Multiply(vHoleDir,m_fSuctionPower));
	}

	//死亡判定
	if (m_pDeath->CheckObjNameHit(OBJ_CHARA) != nullptr)
	{
		//消す
		this->SetStatus(false);
		Hits::DeleteHitBox(this);

		//ゲームオーバーへ
		Scene::SetScene(new CSceneGameOver());
	}

	//穴が画面外へ出ると削除
	//画面左端
	if (m_vPos.x + (BLACK_HOLE_SIZE * 2.0f) < 0)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}
	//画面下端
	if (m_vPos.y - BLACK_HOLE_SIZE > WINDOW_SIZE_H)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}
}

//描画
void CBlackHole::Draw()
{
	RECT_F src, dst;

	//切り取り位置
	RectSet(&src, 0.0f, 0.0f, 128.0f, 128.0f);

	//描画位置
	RectSet(&dst, m_vPos.y, m_vPos.x, BLACK_HOLE_SIZE, BLACK_HOLE_SIZE);
	
	//描画
	Draw::Draw(OBJ_BLACK_HOLE, &src, &dst, m_fColor, 0.0f);
}