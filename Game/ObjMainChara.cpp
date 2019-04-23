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

	m_fGravity = 0.98f;

	//�u���b�N�z�[���������Ă��Ȃ�
	m_bIsHitBlackHole = false;
	
	//�����蔻��pHitBox�쐬
	m_pBody = Hits::SetHitBox(this, m_vPos.x, m_vPos.y, CHARA_SIZE, CHARA_SIZE - 5.0f, ELEMENT_CHARA, OBJ_CHARA, 1);
	//�n�ʂƂ̓����蔻��pHitBox�쐬
	m_pLeg =  Hits::SetHitBox(this, m_vPos.x, m_vPos.y + (CHARA_SIZE - 5.0f), CHARA_SIZE, 5.0f, ELEMENT_CHARA, OBJ_CHARA, 1);

}

//�A�N�V����
void CObjMainChara::Action()
{
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
	if (m_vPos.y >= WINDOW_SIZE_H - CHARA_SIZE)
	{
		m_vPos.y = WINDOW_SIZE_H - CHARA_SIZE;
		m_bHitGround = true;
	}
	//----------------------------------------------

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
			

	//�X�N���[���̏�Ԏ擾
	CSceneMain* m_pScene = dynamic_cast<CSceneMain*>(Scene::GetScene());
	m_bScroll = m_pScene->GetScroll();

	//���̏�Ԏ擾

	//HitBox�X�V(����)
	m_pBody->SetPos(m_vPos.x, m_vPos.y);
	//HitBox�X�V(��)
	m_pLeg->SetPos(m_vPos.x, m_vPos.y + CHARA_SIZE -5.0f);

	//�n�ʏ���Ă�Ƃ�
	if (m_pLeg->CheckObjNameHit(OBJ_PLANE) != nullptr )
	{
		//�ォ�痈�Ă�Ƃ�
		if (m_vMove.y >= 0.0f)
		{
			//���̏�Ԏ擾
			CPlane* m_pPlane = dynamic_cast<CPlane*>(Objs::GetObj(OBJ_PLANE));
			m_vPlanePos = m_pPlane->GetPos();

			//�L�����̈ʒu��n�ʂ̏�ɂ���
			m_vPos.y = m_vPlanePos.y - CHARA_SIZE + 0.1f;

			//������0�ɂ���
			m_vMove.y = 0.0f;
			m_bHitGround = true;
		}
	}
	//�n�ʂɏ���ĂȂ��Ƃ�
	else
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

	//�u���b�N�z�[���ɓ������Ă���Ƃ�
	if(m_bIsHitBlackHole==true)
	{

		//�ʒu�̍X�V
		m_vPos.x += m_vMove.x;
		m_vPos.y += m_vMove.y;

		//�ړ�������
		m_vMove.x = 0.0f;
		m_vMove.y = 0.0f;

		//�u���b�N�z�[���Ƃ̓����蔻�����
		m_bIsHitBlackHole = false;
	}
	//�u���b�N�z�[���ɓ������Ă��Ȃ��Ƃ�
	else
	{
		//���R�����@�n�ʂɂ��ĂȂ��Ƃ��͗�������
		if (m_bHitGround==false)
		{
			m_vMove.y += 9.8f / 16.0f;
		}
		//�n�ʂɂ��Ă���΃W�����v�p�̔���(m_bHitGround)��true�ɂ���
		else
		{
			m_bHitGround = true;
		}

		//�ʒu�̍X�V
		m_vPos.x += m_vMove.x;
		m_vPos.y += m_vMove.y;

		//�ړ�������
		m_vMove.x = 0.0f;
	}


}

//�ړ��c
void CObjMainChara::VarticalMove()
{
	//����
	VarticalInput();

	//�ʒu�̍X�V
	m_vPos.x += m_vMove.x;
	m_vPos.y += m_vMove.y;

	//�ړ�������
	m_vMove.x = 0.0f;
	m_vMove.y = 0.0f;

}

//���̓���
void CObjMainChara::SideInput()
{
	//�L�[���́@�E
	if (Input::GetVKey(VK_RIGHT) == true)
	{
		m_vMove.x += 3.0f;
		m_bDirection = false;
	}
	//�L�[���́@��
	else if (Input::GetVKey(VK_LEFT) == true)
	{
		m_vMove.x += -3.0f;
		m_bDirection = true;
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
		m_vMove.x += 3.0f;
		m_bDirection = false;
	}
	//�L�[���́@��
	else if (Input::GetVKey(VK_LEFT) == true)
	{
		m_vMove.x += -3.0f;
		m_bDirection = true;
	}
	

	//�L�[���́@��
	if (Input::GetVKey(VK_UP) == true)
	{
		m_vMove.y += -3.0f;
	}
	//�L�[���́@��
	else if (Input::GetVKey(VK_DOWN) == true)
	{
		m_vMove.y += 3.0f;
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

//�u���b�N�z�[���Ƃ̃q�b�g����
void CObjMainChara::HitBlackHole(Vector Vec)
{
	m_vMove = CVector::Add(m_vMove, Vec);
	m_bIsHitBlackHole = true;
}