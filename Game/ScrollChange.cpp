#include "ScrollChange.h"
#include "GameHead.h"
#include "Function.h"
#include "GameL/HitBoxManager.h"

//�R���X�g���N�^
CScrollChange::CScrollChange(int x, int y,bool bScroll)
{
	m_vPos.x = (float)x * OBJ_SIZE;
	m_vPos.y = (float)y * OBJ_SIZE;

	m_bScroll = bScroll;

	//�X�N���[���̕����ɍ��킹�Ĕ���̃T�C�Y��ς���
	if (m_bScroll == SIDE)
	{
		m_vHitSize.x =  OBJ_SIZE;
		m_vHitSize.y = OBJ_SIZE * SIDE_MAX_Y;
	}
	else
	{
		m_vHitSize.x = OBJ_SIZE * VARTICAL_MAX_X;
		m_vHitSize.y = OBJ_SIZE;
	}

}

//������
void CScrollChange::Init()
{
	//�F
	ColorSet(1.0f, 1.0f, 1.0f, 1.0f, m_fColor);

	//�����蔻��
	Hits::SetHitBox(this, m_vPos.x, m_vPos.y, m_vHitSize.x, m_vHitSize.y, ELEMENT_STAGE, OBJ_SCROLL_CHANGE, 1);
}

//�X�V
void CScrollChange::Action()
{
	//�X�N���[���̏�Ԏ擾
	CSceneMain* m_pScene = dynamic_cast<CSceneMain*>(Scene::GetScene());
	m_bScroll = m_pScene->GetScroll();

	///�X�N���[�������̎����֓���
	if (m_bScroll == SIDE)
	{
		m_vPos.x -= SCROLL_SPEED;
	}
	//�c�Ȃ牺�֓���
	else
	{
		m_vPos.y += SCROLL_SPEED;
	}

	//HitBox�X�V
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_vPos.x, m_vPos.y);
	
	//�L�����Ƃ̓����蔻��
	if (hit->CheckObjNameHit(OBJ_CHARA) != nullptr)
	{
		//�X�N���[���̕ύX
		CSceneMain* m_pScene = dynamic_cast<CSceneMain*>(Scene::GetScene());
		m_pScene->ScrollChange();

		//���g�폜
		this->SetStatus(false);
		
		//HitBox�폜
		Hits::DeleteHitBox(this);
	}
}

//�`��
void CScrollChange::Draw()
{
	RECT_F src, dst;

	//�؂���ʒu
	RectSet(&src, 0.0f, 0.0f, 128.0f, 128.0f);

	//�`��ʒu
	RectSet(&dst, m_vPos.y, m_vPos.x, SCROLL_CHANGE_SIZE, SCROLL_CHANGE_SIZE);

	//�`��
	Draw::Draw(OBJ_SCROLL_CHANGE, &src, &dst, m_fColor, 0.0f);
}