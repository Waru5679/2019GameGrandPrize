#include "GameL/DrawTexture.h"
#include "GameL/HitBoxManager.h"

#include "ObjCollectionItem.h"
#include "GameHead.h"
#include "Function.h"


//�R���X�g���N�^
CCollectionItem::CCollectionItem(int x, int y)
{
	m_fPos_x = (float)x * OBJ_SIZE;
	m_fPos_y = (float)y * OBJ_SIZE;
}

//������
void CCollectionItem::Init()
{
	//�F�Z�b�g
	ColorSet(1.0f, 1.0f, 1.0f, 1.0f, m_fColor);

	//�����蔻��pHitBox�쐬
	Hits::SetHitBox(this, m_fPos_x, m_fPos_y, ITEM_SIZE, ITEM_SIZE, ELEMENT_STAR, OBJ_STAR, 1);
}

void CCollectionItem::Action()
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
void CCollectionItem::Draw()
{
	RECT_F src, dst;

	//�؂���ʒu
	RectSet(&src, 0.0f, 0.0f, 128.0f, 128.0f);

	//�`��ʒu
	RectSet(&dst, m_fPos_y, m_fPos_x, ITEM_SIZE, ITEM_SIZE);

	//�`��
	Draw::Draw(OBJ_ITEM, &src, &dst, m_fColor, 0.0f);
}