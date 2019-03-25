#include "Enemy.h"
#include "Function.h"
#include "GameHead.h"

//コンストラクタ
CEnemy::CEnemy(int x, int y)
{
	//位置
	m_vPos.x = (float)x * OBJ_SIZE;
	m_vPos.y = (float)y * OBJ_SIZE;
}

//初期化
void CEnemy::Init()
{
	//色
	ColorSet(1.0f, 1.0f, 1.0f, 1.0f, m_fColor);
}

//更新
void CEnemy::Action()
{
	//キャラクタのポインタ
	CObjMainChara* pChara = dynamic_cast<CObjMainChara*>(Objs::GetObj(OBJ_CHARA));


}

//描画
void CEnemy::Draw()
{
	RECT_F src, dst;

	//切り取り位置
	RectSet(&src, 0.0f, 0.0f, 128.0f, 128.0f);

	//描画位置
	RectSet(&dst, m_vPos.y, m_vPos.x,ENEMY_SIZE ,ENEMY_SIZE);

	//描画
	Draw::Draw(OBJ_ENEMY, &src, &dst, m_fColor, 0.0f);
}
