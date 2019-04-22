//�g�p����w�b�_�[�t�@�C��
#include "GameL/DrawTexture.h"
#include "GameL/WinInputs.h"
#include "GameL/SceneManager.h"
#include "GameL/HitBoxManager.h"

#include "GameHead.h"
#include "ObjMainChara.h"
#include "Function.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjMainChara::Init()
{
	//�`��J���[�Z�b�g
	ColorSet(1.0f, 1.0f, 1.0f, 1.0f, m_fColor);

	m_vPos.x = 0.0f;	//�ʒu
	m_vPos.y = WINDOW_SIZE_H - CHARA_SIZE;
	m_vMove.x = 0.0f;	//�ړ��x�N�g��
	m_vMove.y = 0.0f;
	m_bDirection = false;
	m_bHitGround = false;
	m_bBullet_FireIs = true;
	m_bFall = true;

	m_fGravity = 0.98f;

	
	//�����蔻��pHitBox�쐬
	m_pChara_Body = Hits::SetHitBox(this, m_vPos.x, m_vPos.y, CHARA_SIZE, CHARA_SIZE - 5.0f, ELEMENT_PLAYER, OBJ_CHARA, 1);
	//�n�ʂƂ̓����蔻��pHitBox�쐬
	m_pChara_Leg =  Hits::SetHitBox(this, m_vPos.x, m_vPos.y + (CHARA_SIZE - 5.0f), CHARA_SIZE, 5.0f, ELEMENT_PLAYER_LEG, OBJ_CHARA, 1);

}

//�A�N�V����
void CObjMainChara::Action()
{
	
	//�c
	if (m_bScroll == VERTICAL)
	{
		VarticalMove();
	}
	//��
	else
	{
		SideMove();
	}
			
	//�ړ��͈͐���------------------------------
	//��ʉE�[
	if (m_vPos.x > WINDOW_SIZE_W - CHARA_SIZE)
	{
		m_vPos.x = WINDOW_SIZE_W - CHARA_SIZE;
	}
	//��ʍ��[
	if (m_vPos.x < 0.0f)
	{
		m_vPos.x = 0.0f;
	}
	//��ʏ�[
	if (m_vPos.y < 0.0f)
	{
		m_vPos.y = 0.0f;
	}
	//��ʉ��[(�c�X�N���[�����̂ݗL��)
	if (m_vPos.y > WINDOW_SIZE_H - CHARA_SIZE)
	{
		m_vPos.y = WINDOW_SIZE_H - CHARA_SIZE;
		m_bHitGround = true;
	}
	//----------------------------------------------

	//�X�N���[���̏�Ԏ擾
	CSceneMain* m_pScene = dynamic_cast<CSceneMain*>(Scene::GetScene());
	m_bScroll = m_pScene->GetScroll();

	//���̏�Ԏ擾

	//HitBox�X�V(����)
	m_pChara_Body->SetPos(m_vPos.x, m_vPos.y);
	//HitBox�X�V(��)
	m_pChara_Leg->SetPos(m_vPos.x, m_vPos.y + CHARA_SIZE -5.0f);

	//Plane�Ƃ̓����蔻��
	if (m_pChara_Leg->CheckElementHit(ELEMENT_PLANE) == true && m_bFall == true)
	{
		//���̏�Ԏ擾
		CPlane* m_pPlane = dynamic_cast<CPlane*>(Objs::GetObj(OBJ_PLANE));
		m_vPlanePos = m_pPlane->GetPos();

		//�L�����̈ʒu��n�ʂ̏�ɂ���
		m_vPos.y = m_vPlanePos.y - CHARA_SIZE + 0.1f;

		//������0�ɂ���
		m_vMove.y = 0.0f;
		m_bHitGround = true;
		m_bFall = false;
	}
	//�n�ʂɏ���ĂȂ��Ƃ�
	else if(m_pChara_Leg->CheckElementHit(ELEMENT_PLANE) == false && m_bFall == false && m_vPos.y <= m_vPlanePos.y)
	{
		m_bHitGround = false;
	}
}

//�h���[
void CObjMainChara::Draw()
{
	RECT_F src, dst;

	//�؂���ʒu�̐ݒ�
	RectSet(&src, 64.0f, 0.0f, 32.0f, 32.0f);

	//�\���ʒu�̐ݒ�
	dst.m_top = m_vPos.y;

	//�������E�Ȃ�摜�𔽓]����
	if (m_bDirection == false)
	{
		dst.m_left = m_vPos.x;
		dst.m_right = m_vPos.x + CHARA_SIZE;
	}
	//���������Ȃ�ǂݎ�������̏�Ԃɂ���
	else
	{
		dst.m_left = (64.0f * 1.0f) + m_vPos.x;
		dst.m_right =m_vPos.x;
	}
	dst.m_bottom =m_vPos.y + CHARA_SIZE;

	//�`��
	Draw::Draw(OBJ_CHARA, &src, &dst, m_fColor, 0.0f);
}


//�ړ���
void CObjMainChara::SideMove()
{
	//����
	SideInput();

	//���R�����@�n�ʂɂ��ĂȂ��Ƃ��͗�������
	if (m_bHitGround == false)
	{
		m_vMove.y += 9.8f / 16.0f;
		//�������Ȃ痎�������true�ɂ���
		if (m_vMove.y > 0)
		{
			m_bFall = true;
		}
	}
	//�n�ʂɂ��Ă���΃W�����v�p�̔���(m_bHitGround)��true�ɂ���
	else
	{
		//�������Ă��Ȃ��Ƃ��i�n�ʁA���j�͗��������false�ɂ���
		m_bFall = false;
	}

	//�ʒu�̍X�V
	m_vPos.x += m_vMove.x;
	m_vPos.y += m_vMove.y;

}

//�ړ��c
void CObjMainChara::VarticalMove()
{
	//����
	VarticalInput();

	//�ʒu�̍X�V
	m_vPos.x += m_vMove.x;
	m_vPos.y += m_vMove.y;

}

//���̓���
void CObjMainChara::SideInput()
{
	//�L�[���́@�E
	if (Input::GetVKey(VK_RIGHT) == true)
	{
		m_vMove.x = 3.0f;
		m_bDirection = false;
	}
	//�L�[���́@��
	else if (Input::GetVKey(VK_LEFT) == true)
	{
		m_vMove.x = -3.0f;
		m_bDirection = true;
	}
	else
	{
		m_vMove.x = 0.0f;
	}

	//�W�����v
	if (Input::GetVKey('C') == true)
	{
		//�n�ʂɐڒn���Ă�Ƃ�(m_bHitGround == true)�̎��̂ݔ��
		if (m_bHitGround == true)
		{
			m_vMove.y = -15.0f;
			m_bHitGround = false;
		}
	}
}

//�c�̓���
void CObjMainChara::VarticalInput()
{
	
	//�L�[���́@�E
	if (Input::GetVKey(VK_RIGHT) == true)
	{
		m_vMove.x = 3.0f;
		m_bDirection = false;
	}
	//�L�[���́@��
	else if (Input::GetVKey(VK_LEFT) == true)
	{
		m_vMove.x = -3.0f;
		m_bDirection = true;
	}
	else
	{
		m_vMove.x = 0.0f;
	}

	//�L�[���́@��
	if (Input::GetVKey(VK_UP) == true)
	{
		m_vMove.y = -3.0f;
	}
	//�L�[���́@��
	else if (Input::GetVKey(VK_DOWN) == true)
	{
		m_vMove.y = 3.0f;
	}
	else
	{
		m_vMove.y = 0.0f;
	}

	//�U��
	if (Input::GetVKey('X') == true)
	{
		if (m_bBullet_FireIs == true)
		{
			//�e����
			CCharaBullet* pBullet = new CCharaBullet(m_vPos, CVector::Create(0.0f, -3.0f));
			Objs::InsertObj(pBullet, OBJ_CHARA_BULLET, 10);

			m_bBullet_FireIs = false;
		}
	}
	else
	{
		m_bBullet_FireIs = true;
	}
}