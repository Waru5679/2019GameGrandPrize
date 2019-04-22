#include "GameL/DrawTexture.h"
#include "GameL/HitBoxManager.h"
#include "GameL/UserData.h"

#include "ObjCollectionItemSmall.h"
#include "GameHead.h"
#include "Function.h"


//�R���X�g���N�^
CCollectionItemSmall::CCollectionItemSmall(int x, int y,int number)
{
	m_fPos_x = (float)x * OBJ_SIZE;
	m_fPos_y = (float)y * OBJ_SIZE;
	m_iPosition = number;
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
	//�V�[���̏�Ԏ擾
	CSceneMain* m_pScene = dynamic_cast<CSceneMain*>(Scene::GetScene());
	m_bScroll = m_pScene->GetScroll();
	
	//�X�N���[�������̎����֓���
	if (m_bScroll == SIDE)
	{
		m_fPos_x -= SCROLL_SPEED;
	}
	//�c�Ȃ牺�֓���
	else
	{
		m_fPos_y += SCROLL_SPEED;
	}

	//HitBox�X�V
	CHitBox* hit_b = Hits::GetHitBox(this);
	hit_b->SetPos(m_fPos_x, m_fPos_y);

	//��l���ɓ�����Ə���
	if (hit_b->CheckElementHit(ELEMENT_PLAYER) == true)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);

		//�X�R�A��+500����
		((UserData*)Save::GetData())->m_iScore += SCORE_SMALL;

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

	//�A�C�e��(��)�I�u�W�F�N�g����ʊO�֏o��ƍ폜����
	//��ʍ��[
	if (m_fPos_x + ITEM_SMALL_SIZE < 0)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}
	//��ʉ��[
	if (m_fPos_y > WINDOW_SIZE_H)
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