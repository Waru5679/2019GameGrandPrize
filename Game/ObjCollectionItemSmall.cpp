#include "GameL/DrawTexture.h"
#include "GameL/HitBoxManager.h"

#include "ObjCollectionItemSmall.h"
#include "GameHead.h"
#include "Function.h"


//�R���X�g���N�^
CCollectionItemSmall::CCollectionItemSmall(int x, int y)
{
	m_fPos_x = (float)x * OBJ_SIZE;
	m_fPos_y = (float)y * OBJ_SIZE;
}

//������
void CCollectionItemSmall::Init()
{
	//�F�Z�b�g
	ColorSet(1.0f, 1.0f, 1.0f, 1.0f, m_fColor);


	//�����蔻��pHitBox�쐬
	Hits::SetHitBox(this, m_fPos_x, m_fPos_y, ITEM_SMALL_SIZE, ITEM_SMALL_SIZE, ELEMENT_ITEM_SMALL, OBJ_ITEM_SMALL, 1);

}

void CCollectionItemSmall::Action()
{
	//HitBox�X�V
	CHitBox* hit_b = Hits::GetHitBox(this);
	hit_b->SetPos(m_fPos_x, m_fPos_y);

	//��l���ɓ�����Ə���
	if (hit_b->CheckElementHit(ELEMENT_PLAYER) == true)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}

}

//�`��
void CCollectionItemSmall::Draw()
{
	RECT_F src, dst;

	//�؂���ʒu
	RectSet(&src, 0.0f, 0.0f, 128.0f, 128.0f);

	//�`��ʒu
	RectSet(&dst, m_fPos_y, m_fPos_x, ITEM_SMALL_SIZE, ITEM_SMALL_SIZE);

	//�`��
	Draw::Draw(OBJ_ITEM_BIG, &src, &dst, m_fColor, 0.0f);
}