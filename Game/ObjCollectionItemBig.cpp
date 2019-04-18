#include "GameL/DrawTexture.h"
#include "GameL/HitBoxManager.h"
#include "GameL/UserData.h"

#include "ObjCollectionItemBig.h"
#include "GameHead.h"
#include "Function.h"
#include "Map.h"


//�R���X�g���N�^
CCollectionItemBig::CCollectionItemBig(int x, int y,int number)
{
	m_fPos_x = (float)x * OBJ_SIZE;
	m_fPos_y = (float)y * OBJ_SIZE;

	m_iPosition = number;
}

//������
void CCollectionItemBig::Init()
{
	//�F�Z�b�g
	ColorSet(1.0f, 1.0f, 1.0f, 1.0f, m_fColor);
	
	//�X�R�A������

	//�����蔻��pHitBox�쐬
	Hits::SetHitBox(this, m_fPos_x, m_fPos_y, ITEM_BIG_SIZE, ITEM_BIG_SIZE, ELEMENT_ITEM_BIG, OBJ_ITEM_BIG, 1);

}

void CCollectionItemBig::Action()
{
	//HitBox�X�V
	CHitBox* hit_b = Hits::GetHitBox(this);
	hit_b->SetPos(m_fPos_x, m_fPos_y);
	
	//��l���ɓ�����Ə���
	if (hit_b->CheckElementHit(ELEMENT_PLAYER) == true)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);

		//�X�R�A��+1000���Z����
		((UserData*)Save::GetData())->m_iScore += SCORE_BIG;

		//Map�擾
		CMap* m_pMap = dynamic_cast<CMap*>(Objs::GetObj(OBJ_MAP));
		//Map����m_iMapItem[]�̒��g�̍��̐��l��0�ɂ���
		m_pMap->m_iMapItem[m_iPosition] = ITEM_NONE;
		//Map.cpp����m_iMapItem[]�ɍ��̐��l-1���Ē��O�̐��l��0�Ȃ�{�[�i�X���Z
		if (m_pMap->m_iMapItem[m_iPosition - 1] == ITEM_NONE)
		{
			((UserData*)Save::GetData())->m_iScore += SCORE_BONUS;
		}

	}

}

//�`��
void CCollectionItemBig::Draw()
{
	RECT_F src, dst;

	//�؂���ʒu
	RectSet(&src, 0.0f, 0.0f, 128.0f, 128.0f);

	//�`��ʒu
	RectSet(&dst, m_fPos_y, m_fPos_x, ITEM_BIG_SIZE, ITEM_BIG_SIZE);

	//�`��
	Draw::Draw(OBJ_ITEM_BIG, &src, &dst, m_fColor, 0.0f);
}