#include "NameInput.h"
#include "Function.h"
#include "GameL/WinInputs.h"
#include "GameL/DrawFont.h"
#include "GameL/SceneManager.h"
#include "GameL/UserData.h"
#include "GameHead.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//������
void CNameInput::Init()
{
	//�t�H���g�Z�b�g
	Font::SetStrTex(L"���O����");
	//�F�Z�b�g
	ColorSet(1.0f, 1.0f, 1.0f, 1.0f, m_fColor);
	//�F�Z�b�g��
	ColorSet(1.0f, 0.0f, 0.0f, 1.0f, m_fColor_Red);

	//�t���O�̏�����
	m_bFirst_Flag = true;
	m_bKey_Flag = false;
	m_bInput_Flag = false;
	m_bEnd_Flag = false;
	m_bNoname_Flag = false;
	m_bTime_Flag = true;

	//���O�p�z��̏�����
	for (int i = 0; i <= 6; i++)
	{
		m_cName[i] = ' ';//���p�󔒂ŏ�����
	}

	//�R�s�[�p�z��̏�����
	for (int i = 0; i <= 10; i++)
	{
		m_cCopy_Name[i] = ' ';//���p�󔒂ŏ�����
	}

	m_iTime = 0;//�_�ŗp�^�C���̏�����
	m_iInput_Count = 0;//���O�ۑ��p�z��̗v�f�ԍ�������

	//�o�͂����镶���̃O���t�B�b�N���쐬
	Font::SetStrTex((wchar_t*)L"���O����͂��Ă�������(�p��5�����ȓ�)");
	Font::SetStrTex((wchar_t*)L"�Œ�1�����͓��͂��Ă�������");
	Font::SetStrTex((wchar_t*)L"Enter�œ��͏I��");
	Font::SetStrTex((wchar_t*)L"BackSpace�ł�蒼��");
	Font::SetStrTex((wchar_t*)L"_");
}

//�X�V
void CNameInput::Action()
{
	m_iTime++;//�_�ŗp�^�C���𑝂₷

	//10000�𒴂������ɂȂ�����0�ɖ߂�
	if (m_iTime >= 10000)
	{
		m_iTime = 0;
	}

	//60�t���[�����ƂɃt���O�����ւ���
	if (m_iTime % 60 == 0)
	{
		m_bTime_Flag = !(m_bTime_Flag);
	}

	//���߂�2��ڈȍ~
	if (m_bFirst_Flag == false)
	{
		//���͂��I�����Ă��Ȃ������ꍇ
		if (m_bEnd_Flag == false)
		{
			//�L�[�t���O���I���̏ꍇ
			if (m_bKey_Flag == true)
			{
				//���O����͂���
				m_bInput_Flag = KeyInput(m_iInput_Count);

				//�Ή��{�^���̂ǂ����������ꂽ�ꍇ
				if (m_bInput_Flag == true)
				{
					NameCpy(m_cName);//�`��p�̃R�s�[�����
					m_bEnd_Flag = InputEndCheck();//������̓��͂��I���Ă��邩�ǂ����𒲂ׂ�
					m_bKey_Flag = false;//�L�[�t���O���I�t�ɂ���
				}
			}
			//�L�[�t���O���I�t�Ȃ�
			else
			{
				//1�O�̕����Ɠ���������������Ă��Ȃ����
				if (Input::GetVKey(m_cName[m_iInput_Count - 1]) == false)
				{
					m_bKey_Flag = true;	//�L�[�t���O���I���ɂ���
				}
			}
		}
		//���͂����������ꍇ
		else
		{
			//�X�e�[�W1�Ȃ�
			if (((UserData*)Save::GetData())->m_iStageNum == STAGE_1)
			{
				//���O�����[�U�[�f�[�^�ɃR�s�[
				strcpy_s(((UserData*)Save::GetData())->m_RankingName_st1[((UserData*)Save::GetData())->m_RankingPos], m_cName);//���O
		
			}
			//�X�e�[�W2�Ȃ�
			else if (((UserData*)Save::GetData())->m_iStageNum == STAGE_2)
			{
				//���O�����[�U�[�f�[�^�ɃR�s�[
				strcpy_s(((UserData*)Save::GetData())->m_RankingName_st2[((UserData*)Save::GetData())->m_RankingPos], m_cName);//���O
			}
			//�X�e�[�W3�Ȃ�
			else if (((UserData*)Save::GetData())->m_iStageNum == STAGE_3)
			{
				//���O�����[�U�[�f�[�^�ɃR�s�[
				strcpy_s(((UserData*)Save::GetData())->m_RankingName_st3[((UserData*)Save::GetData())->m_RankingPos], m_cName);//���O
			}

			//UserData�̍쐬(�Z�[�u)����
			Save::Seve();

			//�^�C�g���V�[���Ɉړ�
			Scene::SetScene(new CSceneTitle());
		}
	}

	//�t���O���I�t�ɂ���
	m_bFirst_Flag = false;
}

//�`��
void CNameInput::Draw()
{
	//�����̕`��
	Font::StrDraw((wchar_t*)L"���O����͂��Ă�������(�p��5�����ȓ�)", 40.0f, 150.f, 40.0f, m_fColor);
	Font::StrDraw((wchar_t*)L"BackSpace�œ��͂̂�蒼��", 100.0f, WINDOW_SIZE_H - 50.0f, 30.0f, m_fColor);
	Font::StrDraw((wchar_t*)L"Enter�œ��͏I��", WINDOW_SIZE_W - 300.0f, WINDOW_SIZE_H - 50.0f, 30.0f, m_fColor);

	wchar_t str_Name[50];

	//char����wchar_t�Ɏw�肵���T�C�Y���R�s�[
	size_t* size = nullptr;
	mbstowcs_s(size, str_Name, 50.0f, m_cCopy_Name, 50);
	//���͂���������\��
	Font::StrDraw(str_Name, 300.0f, 400.0f, 50.0f, m_fColor);

	//�u_�v�\��
	for (int i = 0; i < 5; i++)
	{
		//���̓��͉ӏ��@���@�t���O���I�t�Ȃ�
		if (i == m_iInput_Count && m_bTime_Flag == false)
		{
			//' '��\��
			Font::StrDraw((wchar_t*)L" ", 300.0f + 50.0f * i, 400.0f, 50.0f, m_fColor);
		}
		else
		{
			//'_'��\��
			Font::StrDraw((wchar_t*)L"_", 300.0f + 50.0f * i, 400.0f, 50.0f, m_fColor);
		}

	}

	if (m_bNoname_Flag == true)
	{
		Font::StrDraw((wchar_t*)L"�Œ�1�����͓��͂��Ă�������", 100.0f, 300.0f, 50.0f, m_fColor_Red);
	}
}

//�l�[�����͂̃L�[�{�[�h���當����ǂݎ��֐�
//���� : ���͂��ꂽ����������z��̗v�f��
//�߂�l : �Ή����Ă���Key�������ꂽ��:true ������������Ă��Ȃ����:false
bool CNameInput::KeyInput(int number)
{
	//EnterKey�������ꂽ�Ƃ�
	if (Input::GetVKey(VK_RETURN) == true)
	{
		//�����͂̏�ԂȂ�
		if (m_cName[0] == ' ')
		{
			//���͂𑣂����͂̒ǉ��p�Ƀt���O���I���ɂ���
			m_bNoname_Flag = true;
		}
		else
		{
			//\0������
			m_cName[number] = '\0';
			return true;
		}
	}

	//�o�b�N�X�y�[�X�������ꂽ�Ƃ�
	if (Input::GetVKey(VK_BACK) == true)
	{
		for (int i = 0; i < 6; i++)
		{
			//�z��̏�����
			m_cName[i] = ' ';
		}

		m_iInput_Count = 0;

		return true;
	}

	//key�̏�Ԃ𒲂ׂ�
	for (char key = 'A'; key <= 'Z'; key++)
	{
		if (Input::GetVKey(key) == true)
		{
			//�����ꂽkey��z��ɕۑ�
			m_cName[number] = key;

			//5�����ڂ܂łȂ�
			if (m_iInput_Count < 5)
			{
				//�ۑ��ʒu���ꕶ���i�߂�
				m_iInput_Count++;

				return true;
			}
		}
	}
	return false;
}

//��������͂��I����Ă��邩(\0�����邩)���ׂ�֐�
//�߂�l:\0�������:true�@�Ȃ����:false
bool CNameInput::InputEndCheck()
{
	//�z��̒��g���m�F���Ă���
	for (int i = 0; i < 6; i++)
	{
		//\0�������
		if (m_cName[i] == '\0')
		{
			return true;
		}
	}
	return false;
}

//������̕������ƊԂɔ��p�󔒂�����֐�
void CNameInput::NameCpy(char name[])
{
	int i;
	//������̔z��T�C�Y�ɂȂ�܂Ń��[�v
	for (i = 0; i < sizeof(name) * 2 + 1; i++)
	{
		//�v�f���������Ȃ�
		if (i % 2 == 0)
		{
			//�z��ɓ����Ă��镶��������
			m_cCopy_Name[i] = m_cName[i / 2];
		}
		else
		{
			//���p�󔒂�����
			m_cCopy_Name[i] = ' ';
		}
	}
	//������\0������
	m_cCopy_Name[i] = '\0';
}