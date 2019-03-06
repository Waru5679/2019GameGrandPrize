#include "BackGround.h"
#include "GameL/DrawTexture.h"
#include "Function.h"
#include "main.h"
#include "GameHead.h"

//�R���X�g���N�^
CBackGround::CBackGround(float Pos_x, float Pos_y, bool Scroll)
{
	//�ʒu
	m_fPos_x = Pos_x;
	m_fPos_y = Pos_y;

	//�X�N���[��
	m_bScroll = Scroll;
}

//������
void CBackGround::Init()
{
	//�F
	ColorSet(1.0f, 1.0f, 1.0f, 1.0f, m_fColor);
}

//�X�V
void CBackGround::Action()
{
	//���X�N���[��
	if (m_bScroll == SIDE)
	{
		//�ʒu
		m_fPos_x += -5.0f;
		m_fPos_y += 0.0f;

		//�w�i�̉E�[����ʍ��ɍs���Ɩ߂�
		if (m_fPos_x + WINDOW_SIZE_W < 0.0f)
			m_fPos_x = WINDOW_SIZE_W;
	}

	//�c�X�N���[��
	else
	{
		//�ʒu
		m_fPos_x += 0.0f;
		m_fPos_y += -5.0f;

		//�w�i�̉��[����ʏ�ɍs���Ɩ߂�
		if (m_fPos_y + WINDOW_SIZE_H < 0.0f )
			m_fPos_y = WINDOW_SIZE_H;
	}
}

//�`��
void CBackGround::Draw()
{
	//�؂���ʒu�ݒ�
	RECT_F src, dst;
	RectSet(&src, 0.0f, 0.0f, 256.0f, 256.0f);

	//�`��ʒu�ݒ�
	RectSet(&dst, m_fPos_y,m_fPos_x, WINDOW_SIZE_W, WINDOW_SIZE_H);

	//�`��
	Draw::Draw(OBJ_BACK_GROUND, &src, &dst, m_fColor, 0.0f);
}

//�X�N���[���̃Z�b�g
void CBackGround::SetScroll(float Pos_x, float Pos_y, bool Scroll)
{
	//�ʒu
	m_fPos_x = Pos_x;
	m_fPos_y = Pos_y;

	//�X�N���[��
	m_bScroll = Scroll;
}