//�g�p����w�b�_�[�t�@�C��
#include "GameL/DrawTexture.h"
#include "GameL/WinInputs.h"
#include "GameL/SceneManager.h"
#include "GameL/HitBoxManager.h"
#include "GameL/UserData.h"

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
	m_vPos.y = //WINDOW_SIZE_H - CHARA_SIZE;
	m_vMove.x =20.0f;	//�ړ��x�N�g��
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
	m_pLeg = Hits::SetHitBox(this, m_vPos.x, m_vPos.y + (CHARA_SIZE - 5.0f), CHARA_SIZE, 5.0f, ELEMENT_CHARA, OBJ_CHARA, 1);

}

//�A�N�V����
void CObjMainChara::Action()
{
	//�X�N���[���̏�Ԏ擾
	CSceneMain* m_pScene = dynamic_cast<CSceneMain*>(Scene::GetScene());
	m_bScroll = m_pScene->GetScroll();

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
	//----------------------------------------------

	//�c
	if (m_bScroll == VARTICAL)
	{
		VarticalMove();

		//��ʉ��[(�c�X�N���[�����̂ݗL��)
		if (m_vPos.y >= WINDOW_SIZE_H - CHARA_SIZE)
		{
			m_vPos.y = WINDOW_SIZE_H - CHARA_SIZE;
		}
	}
	//��
	else
	{
		SideMove();

		//��ʉ��[(���X�N���[�����̂ݗL��)
		if (m_vPos.y >= WINDOW_SIZE_H)
		{
			Scene::SetScene(new CSceneGameOver());
		}
	}
}

//�h���[
void CObjMainChara::Draw()
{
	RECT_F src, dst;

	if (m_bScroll == SIDE)
	{
		//�؂���ʒu�̐ݒ�
		RectSet(&src, 32.0f, 0.0f, 32.0f, 32.0f);
	}
	else
	{
		//�؂���ʒu�̐ݒ�
		RectSet(&src, 64.0f, 0.0f, 32.0f, 32.0f);
	}

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
		dst.m_left = 64.0f + m_vPos.x;
		dst.m_right = m_vPos.x;
	}
	dst.m_bottom = m_vPos.y + CHARA_SIZE;

	//�`��
	Draw::Draw(OBJ_CHARA, &src, &dst, m_fColor, 0.0f);
}


//�ړ���
void CObjMainChara::SideMove()
{
	//����
	SideInput();

	//�u���b�N�z�[���ɓ������Ă���Ƃ�
	if (m_bIsHitBlackHole == true)
	{

		//�ʒu�̍X�V
		m_vPos.x += m_vMove.x;
		m_vPos.y += m_vMove.y;

		//�ړ�������
		m_vMove.x = 0.0f;
		m_vMove.y = 0.0f;

		//HitBox�X�V
		m_pBody->SetPos(m_vPos.x, m_vPos.y);
		m_pLeg->SetPos(m_vPos.x, m_vPos.y + CHARA_SIZE - 5.0f);

		//�u���b�N�z�[���Ƃ̓����蔻�����
		m_bIsHitBlackHole = false;
		m_bHitGround = true;
	}
	//�u���b�N�z�[���ɓ������Ă��Ȃ��Ƃ�
	else
	{
		//�n�ʂɏ���ĂȂ��Ƃ�
		if (m_pLeg->CheckObjNameHit(OBJ_PLANE) == nullptr)
		{
			//���R����
			m_vMove.y += 9.8f / 16.0f;
		}

		//�ʒu�̍X�V
		m_vPos.x += m_vMove.x;
		m_vPos.y += m_vMove.y;

		//�ړ�������
		m_vMove.x = 0.0f;

		//HitBox�X�V
		m_pBody->SetPos(m_vPos.x, m_vPos.y);
		m_pLeg->SetPos(m_vPos.x, m_vPos.y + CHARA_SIZE - 5.0f);
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

	//�����蔻��̍X�V
	m_pBody->SetPos(m_vPos.x, m_vPos.y);
	m_pLeg->SetPos(m_vPos.x, m_vPos.y + CHARA_SIZE - 5.0f);

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
		m_vMove.x += -4.0f;
		m_bDirection = true;
	}

	//�u���b�N�z�[���ɐڒn���Ă���Ƃ�
	if (m_bIsHitBlackHole == true)
	{
		//��ړ�
		if (Input::GetVKey(VK_UP) == true)
		{
			m_vMove.y += -3.0f;
		}
		//���ړ�
		else if (Input::GetVKey(VK_DOWN) == true)
		{
			m_vMove.y += 3.0f;
		}

	}


	//�W�����v
	if (Input::GetTrrigerKey(VK_SPACE) == true)
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

	//�e�̔��˂��I�t�̎�
	if (m_bBullet_FireIs == false)
	{
		//�J�E���g��i�߂�
		m_fBulletFireRate++;

		//�J�E���g��0.5�b�ȏ�Ȃ�e�����Ă�悤�ɂ���
		if (m_fBulletFireRate >= 30.0f)
		{
			m_bBullet_FireIs = true;
			m_fBulletFireRate = 0.0f;
		}
 	}
	 
	//�U��
	if (Input::GetVKey(VK_SPACE)  == true)
	{   
   		if (m_bBullet_FireIs == true)
	 	{                   
  		  	//�e����             
			CCharaBullet* pBullet = new CCharaBullet(m_vPos, CVector::Create(0.0f, -3.0f));
			Objs::InsertObj(pBullet, OBJ_CHARA_BULLET, 50);
			//���˂��I�t�ɂ���
			m_bBullet_FireIs = false;
		}
	}

}

//�u���b�N�z�[���Ƃ̃q�b�g����
void CObjMainChara::HitBlackHole(Vector Vec)
{
	m_vMove = CVector::Add(m_vMove, Vec);
	m_bIsHitBlackHole = true;
}

//���Ƃ̃q�b�g
void CObjMainChara::PlaneHit(Vector vPos)
{
	//�ォ�痈�Ă�Ƃ�
	if (m_vMove.y > 0.0f)
	{
		//�L�����̈ʒu��n�ʂ̏�ɂ���
		m_vPos.y = vPos.y - CHARA_SIZE;

		//������0�ɂ���
		m_vMove.y = 0.0f;
		m_bHitGround = true;
	}
}
