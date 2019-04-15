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

	m_vPos.x = 0.0f;		//�ʒu
	m_vPos.y = 0.0f;
	m_fvx = 0.0f;		//�ړ��x�N�g��
	m_fvy = 0.0f;
	m_bDirection = false;
	m_bHitGround = false;
	m_bBullet_FireIs = true;

	m_fGravity = 0.98f;

	//�����蔻��pHitBox�쐬
	Hits::SetHitBox(this, m_vPos.x, m_vPos.y, 64.0f, 64.0f, ELEMENT_PLAYER, OBJ_CHARA, 1);
}

//�A�N�V����
void CObjMainChara::Action()
{

	//�X�N���[���̏�Ԏ擾
	CSceneMain* m_pScene = new CSceneMain();
	m_bScroll = m_pScene->GetScroll();

	//�ړ��Ăяo��
	Move(); 

	//�W�����v
	if (m_bScroll == VERTICAL)
	{
		if (Input::GetVKey('C') == true)
		{
			if (m_bHitGround == true)
			{
				m_fvy = -15.0f;
				m_bHitGround = false;
			}
		}

		//���R����
		if (m_vPos.y <= 580.0f - 64.0f)
		{
			m_fvy += 9.8f / (16.0f);
		}
		else
		{
			m_vPos.y = 580.0f - 64.0f;
			m_bHitGround = true;
		}

	}

	//�ʒu�̍X�V
	m_vPos.x += m_fvx;
	m_vPos.y += m_fvy;


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
	//�����蔻��--------------------------------------------------

	//HitBox�X�V
	CHitBox* hit_b = Hits::GetHitBox(this);
	hit_b->SetPos(m_vPos.x, m_vPos.y);

}

//�h���[
void CObjMainChara::Draw()
{	
	RECT_F src, dst;

	//�؂���ʒu�̐ݒ�
	RectSet(&src, 64.0f, 2.0f, 32.0f, 32.0f);

	//�\���ʒu�̐ݒ�
	dst.m_top	= 0.0f + m_vPos.y;

	//���������Ȃ�摜�𔽓]����
	if (m_bDirection == false)
	{
		dst.m_left = 0.0f + m_vPos.x;
		dst.m_right = 64.0f + m_vPos.x;
	}
	else
	{
		dst.m_left = (64.0f * 1.0f) + m_vPos.x;
		dst.m_right = (64.0f - 64.0f * 1.0f) + m_vPos.x;
	}
	dst.m_bottom= 64.0f + m_vPos.y;

	//�`��
	Draw::Draw(OBJ_CHARA, &src, &dst, m_fColor, 0.0f);
}


//�ړ�
void CObjMainChara::Move()
{
	//�c�X�N���[�����̂ݗL��-----------------------
	if (m_bScroll == SIDE)
	{

		//�L�[���́@�E
		if (Input::GetVKey(VK_RIGHT) == true)
		{
			m_fvx += 0.3f;
			m_bDirection = false;
		}

		//�L�[���́@��
		if (Input::GetVKey(VK_LEFT) == true)
		{
			m_fvx -= 0.3f;
			m_bDirection = true;
		}
		//�L�[���́@��
		if (Input::GetVKey(VK_UP) == true)
		{
			m_fvy = -3.0f;
		}

		//�L�[���́@��
		if (Input::GetVKey(VK_DOWN) == true)
		{
			m_fvy = +3.0f;
		}
		
		m_fvy -= (m_fvy * 0.098f); //���C�@�c
	}
	//���X�N���[�����̂ݗL��----------------------
	else
	{
		//�L�[���́@�E
		if (Input::GetVKey(VK_RIGHT) == true)
		{
			m_fvx += 0.3f;
			m_bDirection = false;
		}

		//�L�[���́@��
		if (Input::GetVKey(VK_LEFT) == true)
		{
			m_fvx -= 0.3f;
			m_bDirection = true;
		}
	}
	//-------------------------------------------	

	//�ړ��͈͐���------------------------------
	if (m_vPos.x > 740.0f)
	{
		m_vPos.x = 740.0f;
	}
	if (m_vPos.x < 0.0f)
	{
		m_vPos.x = 0.0f;
	}
	if (m_vPos.y < 0.0f)
	{
		m_vPos.y = 0.0f;
	}
	//���C
	m_fvx -= (m_fvx * 0.098f); //���C�@��
	//----------------------------------------------
}