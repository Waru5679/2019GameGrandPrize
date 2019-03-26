#include "EnemyBullet.h"
#include "Function.h"
#include "GameHead.h"

//�R���X�g���N�^
CEnemyBullet::CEnemyBullet(Vector vPos,Vector vMove)
{
	//�ʒu
	m_vPos = vPos;
	
	//�ړ�
	m_vMove = vMove;
}

//������
void CEnemyBullet::Init()
{
	//�F
	ColorSet(1.0f, 1.0f, 1.0f, 1.0f, m_fColor);

	//��]
	m_fRot = 0.0f;

	//��ʓ�
	m_bInWindow=true;
}

//�X�V
void CEnemyBullet::Action()
{
	//�ړ�
	m_vPos = CVector::Add(m_vPos, m_vMove);

	//��ʓ������ׂ�
	m_bInWindow = WindowInCheck(m_vPos, CVector::Create(BULLET_SIZE, BULLET_SIZE));

	//��ʓ��Ȃ����
	if (m_bInWindow == false)
	{
		this->SetStatus(false);
	}
}

//�`��
void CEnemyBullet::Draw()
{
	RECT_F src, dst;

	//�؂���ʒu
	RectSet(&src, 0.0f, 0.0f, 128.0f, 128.0f);

	//�`��ʒu
	RectSet(&dst, m_vPos.y, m_vPos.x, ENEMY_SIZE, ENEMY_SIZE);

	//�`��
	Draw::Draw(OBJ_ENEMY_BULLET, &src, &dst, m_fColor, m_fRot);
}
