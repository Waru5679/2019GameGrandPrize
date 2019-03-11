#include "SceneMain.h"
#include "GameL/DrawTexture.h"
#include "GameHead.h"
#include "main.h"
#include "GameL/UserData.h"

//������
void CSceneMain::InitScene()
{
	//�e�N�X�`���ǂݍ���
	LoadTexture();

	//�}�b�v���ǂݍ���
	LoadMap(L"Map/TestMap.csv");

	//�w�i�I�u�W�F�N�g1
	m_pBack1 = new CBackGround(0.0f, 0.0f, SIDE);
	Objs::InsertObj(m_pBack1, OBJ_BACK_GROUND, 1);

	//�w�i�I�u�W�F�N�g2
	m_pBack2 = new CBackGround(WINDOW_SIZE_W, 0.0f, SIDE);
	Objs::InsertObj(m_pBack2, OBJ_BACK_GROUND, 1);

	//�}�b�v�I�u�W�F�N�g
	CMap* pMap = new CMap(m_Map);
	Objs::InsertObj(pMap, OBJ_MAP, 100);

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
	//�w�i
	Draw::LoadImageW(L"Texture/BackGround.jpg", OBJ_BACK_GROUND, TEX_SIZE_256);	
	//��
	Draw::LoadImageW(L"Texture/Hole.jpg", OBJ_HOLE, TEX_SIZE_256);	

}

//�}�b�v�ǂݍ���
void CSceneMain::LoadMap(const wchar_t* Name)
{
	unique_ptr<wchar_t>p;//�|�C���^�[
	int size;            //�T�C�Y

	//�f�[�^�ǂݍ���
	p = Save::ExternalDataOpen(Name, &size);

	int count = 1;	//�ǂݍ��ݗp�J�E���^
	int num = 0;	//���l

	//���l�R�s�[
	for (int i = 0; i < MAX_Y; i++)
	{
		for (int j = 0; j < MAX_X; j++)
		{
			swscanf_s(&p.get()[count], L"%d", &num);
			m_Map[i][j] = num;
			count += 2;
		}
	}
}