#include "CharaBullet.h"
#include "Function.h"
#include "GameHead.h"

//�R���X�g���N�^
CCharaBullet::CCharaBullet(Vector vPos, Vector vMove)
{
	//�ʒu
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
}

//�X�V
void CCharaBullet::Action()
{
	//�ړ�
	m_vPos = CVector::Add(m_vPos, m_vMove);

	//��ʓ������ׂ�
	m_bInWindow = WindowInCheck(m_vPos, CVector::Create(BULLET_SIZE, BULLET_SIZE));

	//��ʊO�Ȃ����
	if (m_bInWindow == false)
	{
		this->SetStatus(false);
	}
}

//�`��
void CCharaBullet::Draw()
{
	RECT_F src, dst;

	//�؂���ʒu
	RectSet(&src, 0.0f, 0.0f, 128.0f, 128.0f);

	//�`��ʒu
	RectSet(&dst, m_vPos.y, m_vPos.x, ENEMY_SIZE, ENEMY_SIZE);

	//�`��
	Draw::Draw(OBJ_CHARA_BULLET, &src, &dst, m_fColor, m_fRot);
}
