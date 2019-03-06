//�g�p����w�b�_�[�t�@�C��
#include "GameL/DrawTexture.h"
#include "GameL/WinInputs.h"
#include "GameL/SceneManager.h"

#include "GameHead.h"
#include "ObjMainChara.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjMainChara::Init()
{

}

//�A�N�V����
void CObjMainChara::Action()
{

}

//�h���[
void CObjMainChara::Draw()
{
	//�`��J���[���
	float m_fc[4] = { 1.0f,1.0f,1.0f,1.0f };

	//�`�挳�؂���ʒu
	RECT_F src;
	//�`���\���ʒu
	RECT_F dst;

	//�؂���ʒu�̐ݒ�
	src.m_top	 = 0.0f;
	src.m_left	 = 0.0f;
	src.m_right	 = 65.0f;
	src.m_bottom = 90.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top    = 0.0f;
	dst.m_left	 = 0.0f;
	dst.m_right  = 64.0f;
	dst.m_bottom = 128.0f;

	//�`��
	Draw::Draw(0, &src, &dst, m_fc, 0.0f);
}