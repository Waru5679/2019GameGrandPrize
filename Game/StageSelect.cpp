#include "StageSelect.h"
#include "Function.h"
#include "GameL/WinInputs.h"
#include "GameL/DrawFont.h"
#include "GameL/SceneManager.h"
#include "GameL/UserData.h"
#include "GameHead.h"

#define STAGE_1 1
#define STAGE_2 2
#define STAGE_3 3
#define RANKING 4

//������
void CStageSelect::Init()
{
	//�t�H���g�Z�b�g
	Font::SetStrTex(L"�X�e�[�W�Z���N�g");

	//�F
	ColorSet(1.0f, 1.0f, 1.0f, 1.0f, m_fColor);

	//�Z���N�g�p���l
	SelectNum = 1;

	//�Q�[�������s����1��̂�
	static bool m_sbInit_Point = false;
	if (m_sbInit_Point == false)
	{
		//�����L���O������
		for (int i = 0; i < MAX_RANKING; i++)
		{
			((UserData*)Save::GetData())->m_iRanking[i] = 0;

		}
		//�_����0�ɂ���
		((UserData*)Save::GetData())->m_iScore = 0;

		m_sbInit_Point = true;
	}

	//���_���������ɕ��ёւ�������
	RankingSort(((UserData*)Save::GetData())->m_iRanking);
}

//�X�V
void CStageSelect::Action()
{
	//�X�e�[�W�⃉���L���O�̏�ɗ����ꍇ�����̕\�����ł������鐔�l��ǉ�����

	if (SelectNum == STAGE_1)
	{
		if (Input::GetTrrigerKey(VK_RETURN) == true)
		{
			//�X�e�[�W�P�̓�Փx�I���V�[���ֈړ�
			Scene::SetScene(new CSceneMain);
		}
		//�E�L�[��������Stage2�ɂ���
		if (Input::GetTrrigerKey(VK_RIGHT) == true)
		{
			SelectNum = STAGE_2;
		}
		//���L�[�������ƃ����L���O�ɂ���
		if (Input::GetTrrigerKey(VK_DOWN) == true)
		{
			SelectNum = RANKING;
		}

	}
	
	if (SelectNum == STAGE_2)
	{
		if (Input::GetTrrigerKey(VK_RETURN) == true)
		{
			//�X�e�[�W2�̓�Փx�I���V�[���ֈړ�
		}
		//���L�[��������Stage1�ɂ���
		if (Input::GetTrrigerKey(VK_LEFT) == true)
		{
			SelectNum = STAGE_1;
		}
		//�E�L�[��������Stage3�ɂ���
		if (Input::GetTrrigerKey(VK_RIGHT) == true)
		{
			SelectNum = STAGE_3;
		}
		//���L�[�������ƃ����L���O�ɂ���
		if (Input::GetTrrigerKey(VK_DOWN) == true)
		{
			SelectNum = RANKING;
		}
	}

	if (SelectNum == STAGE_3)
	{
		if (Input::GetTrrigerKey(VK_RETURN) == true)
		{
			//�X�e�[�W3�̓�Փx�I���V�[���ֈړ�
		}
		//���L�[��������Stage2�ɂ���
		if (Input::GetTrrigerKey(VK_LEFT) == true)
		{
			SelectNum = STAGE_2;
		}
		//���L�[�������ƃ����L���O�ɂ���
		if (Input::GetTrrigerKey(VK_DOWN) == true)
		{
			SelectNum = RANKING;
		}
	}

	if (SelectNum == RANKING)
	{
		if (Input::GetTrrigerKey(VK_RETURN) == true)
		{
			//�����L���O�\��
			Scene::SetScene(new CSceneRanking);
		}
		//���L�[��������Stage2�ɂ���
		if (Input::GetTrrigerKey(VK_UP) == true)
		{
			SelectNum = STAGE_2;
		}
	}

}

//�`��
void CStageSelect::Draw()
{
	//SelectNum�̐��l�ɂ���ĕ�����傫������
	if (SelectNum == STAGE_1)
	{
		Font::StrDraw(L"�X�e�[�W1", 35.0f, 200.0f, 48.0f, m_fColor);
	}
	else
	{
		Font::StrDraw(L"�X�e�[�W1", 50.0f, 200.0f, 32.0f, m_fColor);
	}
	if (SelectNum == STAGE_2)
	{
		Font::StrDraw(L"�X�e�[�W2", 285.0f, 200.0f, 48.0f, m_fColor);
	}
	else
	{
		Font::StrDraw(L"�X�e�[�W2", 320.0f, 200.0f, 32.0f, m_fColor);
	}
	if (SelectNum == STAGE_3)
	{
		Font::StrDraw(L"�X�e�[�W3", 550.0f, 200.0f, 48.0f, m_fColor);
	}
	else
	{
		Font::StrDraw(L"�X�e�[�W3", 590.0f, 200.0f, 32.0f, m_fColor);
	}
	if (SelectNum == RANKING)
	{
		Font::StrDraw(L"�����L���O", 280.0f, 450.0f, 48.0f, m_fColor);
	}
	else
	{
		Font::StrDraw(L"�����L���O", 310.0f, 450.0f, 32.0f, m_fColor);
	}
}