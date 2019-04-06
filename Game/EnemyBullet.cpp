#include "GameL/HitBoxManager.h"
#include "GameL/SceneManager.h"

#include "EnemyBullet.h"
#include "Function.h"
#include "GameHead.h"
#include "Function.h"

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

	m_bShot = true;

	//�����蔻��pHitBox�쐬
	Hits::SetHitBox(this, m_vPos.x, m_vPos.y, 32.0f, 32.0f, ELEMENT_ENEMY_BULLET, OBJ_ENEMY_BULLET, 1);
}

//�X�V
void CEnemyBullet::Action()
{
	//�ړ�

	if (m_bShot == true)
	{
		/*CObjMainChara* obj_chara = new CObjMainChara();

		float x = obj_chara->GetPos.x - m_vPos.x;
		float y = obj_chara->GetPos.y - m_vPos.y;
		float ar = GetAtan2Angle(x, -y);

		float br = GetAtan2Angle(m_vMove.x, m_vMove.y);

		float r = 3.14f / 180.0f;

		if (ar < br)
		{
			m_vMove.x = m_vMove.x * cos(r) - m_vMove.y * sin(r);
			m_vMove.y = m_vMove.y * cos(r) - m_vMove.x * sin(r);
		}
		else
		{
			m_vMove.x = m_vMove.x * cos(r) - m_vMove.y * sin(r);
			m_vMove.y = m_vMove.y * cos(r) - m_vMove.x * sin(r);
		}
		UnitVec(&m_vMove.x, &m_vMove.y);*/

	}

	m_vPos = CVector::Add(m_vPos, m_vMove);

	//��ʓ������ׂ�
	m_bInWindow = WindowInCheck(m_vPos, CVector::Create(BULLET_SIZE, BULLET_SIZE));

	//�����蔻��----------------------------------------------

	//Hitbox�X�V
	CHitBox* hit_b = Hits::GetHitBox(this);
	hit_b->SetPos(m_vPos.x, m_vPos.y);

	//��ʓ��Ȃ����
	if (m_bInWindow == false)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}

	//---------------------------------------------------------
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
