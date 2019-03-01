#include "SceneMain.h"
#include "GameL/DrawTexture.h"
#include "BackGround.h"
#include "GameHead.h"
#include "main.h"

//������
void CSceneMain::InitScene()
{
	//�e�N�X�`���ǂݍ���
	LoadTexture();

	//�w�i�I�u�W�F�N�g1
	m_pBack1 = new CBackGround(0.0f, 0.0f, SIDE);
	Objs::InsertObj(m_pBack1, OBJ_BACK_GROUND, 100);

	//�w�i�I�u�W�F�N�g2
	m_pBack2 = new CBackGround(WINDOW_SIZE_W, 0.0f, SIDE);
	Objs::InsertObj(m_pBack2, OBJ_BACK_GROUND, 100);

	//�J�E���^������
	m_Count = 0;

	//�X�N���[������
	m_bScroll = SIDE;
}

//���s��
void CSceneMain::Scene()
{
	//�J�E���^�X�V
	m_Count++;

	//debug�p100��ŃX�N���[���̌�����ς���
	if (m_Count > 100)
	{
		m_Count = 0;

		//�X�N���[�������̐؂�ւ�
		m_bScroll = !(m_bScroll);

		//�w�i�̈ʒu�ƃX�N���[�������̕ύX

		//�����c�ɕύX
		if (m_bScroll == VERTICAL)
		{
			m_pBack1->SetScroll(0.0f, 0.0f, VERTICAL);
			m_pBack2->SetScroll(0.0f, WINDOW_SIZE_H, VERTICAL);

		}
		//�c�����ɕύX
		else
		{
			m_pBack1->SetScroll(0.0f, 0.0f, SIDE);
			m_pBack2->SetScroll(WINDOW_SIZE_W, 0.0f, SIDE);
		}
	}
}

//�e�N�X�`���ǂݍ���
void CSceneMain::LoadTexture()
{
	Draw::LoadImageW(L"Texture/BackGround.jpg", OBJ_BACK_GROUND, TEX_SIZE_256);	//�w�i
}