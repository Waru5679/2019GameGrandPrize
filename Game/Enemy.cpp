#include "Enemy.h"
#include "Function.h"
#include "GameHead.h"

//�R���X�g���N�^
CEnemy::CEnemy(int x, int y)
{
	//�ʒu
	m_vPos.x = (float)x * OBJ_SIZE;
	m_vPos.y = (float)y * OBJ_SIZE;
}

//������
void CEnemy::Init()
{
	//�F
	ColorSet(1.0f, 1.0f, 1.0f, 1.0f, m_fColor);
}

//�X�V
void CEnemy::Action()
{
	//�L�����N�^�̃|�C���^
	CObjMainChara* pChara = dynamic_cast<CObjMainChara*>(Objs::GetObj(OBJ_CHARA));


}

//�`��
void CEnemy::Draw()
{
	RECT_F src, dst;

	//�؂���ʒu
	RectSet(&src, 0.0f, 0.0f, 128.0f, 128.0f);

	//�`��ʒu
	RectSet(&dst, m_vPos.y, m_vPos.x,ENEMY_SIZE ,ENEMY_SIZE);

	//�`��
	Draw::Draw(OBJ_ENEMY, &src, &dst, m_fColor, 0.0f);
}
