#include "GameL/HitBoxManager.h"

#include "CharaBullet.h"
#include "Function.h"
#include "GameHead.h"

//�R���X�g���N�^
CCharaBullet::CCharaBullet(Vector vPos, Vector vMove)
{
	//�ʒux
	m_vPos = vPos;

	//�ړ�
	m_vMove = vMove;
}

//������
void CCharaBullet::Init()
{
	//�F
	ColorSet(1.0f, 1.0f, 1.0f, 1.0f, m_fColor);

	//��]
	m_fRot = 0.0f;

	//��ʓ�
	m_bInWindow = true;

	//�����蔻��pHitBox�쐬
	Hits::SetHitBox(this, m_vPos.x, m_vPos.y, BULLET_SIZE, BULLET_SIZE, ELEMENT_CHARA, OBJ_CHARA_BULLET,1);
}

//�X�V
void CCharaBullet::Action()
{
	//�ړ�
	m_vPos = CVector::Add(m_vPos, m_vMove);

	//��ʓ������ׂ�
	m_bInWindow = WindowInCheck(m_vPos, CVector::Create(BULLET_SIZE, BULLET_SIZE));

	//�����蔻��------------------------------------------------

	//HitBox�X�V
	CHitBox* hit_b = Hits::GetHitBox(this);
	hit_b->SetPos(m_vPos.x+15.0f, m_vPos.y);

	//�G�ɓ�����Ə���
	if (hit_b->CheckObjNameHit(OBJ_ENEMY) != nullptr)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}

	//��ʊO�Ȃ����
	if (m_bInWindow == false)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}

	//----------------------------------------------------------
}

//�`��
void CCharaBullet::Draw()
{
	RECT_F src, dst;

	//�؂���ʒu
	RectSet(&src, 0.0f, 0.0f, 128.0f, 128.0f);

	//�`��ʒu
	RectSet(&dst, m_vPos.y, m_vPos.x+15.0f, BULLET_SIZE, BULLET_SIZE);

	//�`��
	Draw::Draw(OBJ_CHARA_BULLET, &src, &dst, m_fColor, m_fRot);
}
