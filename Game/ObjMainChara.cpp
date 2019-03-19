//�g�p����w�b�_�[�t�@�C��
#include "GameL/DrawTexture.h"
#include "GameL/WinInputs.h"
#include "GameL/SceneManager.h"

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

	m_fpx = 0.0f;		//�ʒu
	m_fpy = 0.0f;
	m_fvx = 0.0f;		//�ړ��x�N�g��
	m_fvy = 0.0f;
	m_fposture = 1.0f;//�E����0.0f ������1.0f
}

//�A�N�V����
void CObjMainChara::Action()
{
	//�ړ��x�N�g���̔j��
	m_fvx = 0.0f;
	m_fvy = 0.0f;

	//�L�[���́@�E
	if (Input::GetVKey(VK_RIGHT) == true)
	{
		m_fvx = +1.0f;
		m_fposture = 1.0f;
	}
	
	//	�V�@�@�@��
	if (Input::GetVKey(VK_LEFT) == true)
	{
		m_fvx = -1.0f;
		m_fposture = 0.0f;
	}

	//�ʒu�̍X�V
	m_fpx += m_fvx;
	m_fpy += m_fpy;
}

//�h���[
void CObjMainChara::Draw()
{	
	RECT_F src, dst;

	//�؂���ʒu�̐ݒ�
	RectSet(&src, 0.0f, 0.0f, 65.0f, 90.0f);

	//�\���ʒu�̐ݒ�
	dst.m_top	= 0.0f + m_fpy;
	dst.m_left	= (64.0f * m_fposture)+m_fpx;
	dst.m_right	= (64.0f - 64.0f * m_fposture)+m_fpx;
	dst.m_bottom= 128.0f + m_fpy;

	//�`��
	Draw::Draw(0, &src, &dst, m_fColor, 0.0f);
}