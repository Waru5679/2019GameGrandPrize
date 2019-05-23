#include "Ranking.h"
#include "Function.h"
#include "GameL/WinInputs.h"
#include "GameL/DrawFont.h"
#include "GameL/SceneManager.h"
#include "GameL/UserData.h"
#include "GameHead.h"

#define Page_1 0
#define Page_2 1
#define Page_3 2

//������
void CRanking::Init()
{
	//�t�H���g�Z�b�g
	Font::SetStrTex(L"�����L���O");

	//�F
	ColorSet(1.0f, 1.0f, 1.0f, 1.0f, m_fColor);
	
	m_iRankChenge = Page_1;
	m_bChangeRightIs = false;
	m_bChangeLeftIs = false;
}

//�X�V
void CRanking::Action()
{
	//Enter�Ń��j���[��ʂɖ߂�
	if (Input::GetTrrigerKey(VK_RETURN) == true)
	{
		Scene::SetScene(new CSceneStageSelect());
		this->SetStatus(false);
	}

	if (Input::GetTrrigerKey(VK_RIGHT) == true)
	{
		if (m_bChangeRightIs == true)
		{
			if (m_iRankChenge == Page_1)
			{
				m_iRankChenge = Page_2;
			}
			else if (m_iRankChenge == Page_2)
			{
				m_iRankChenge = Page_3;
			}
			m_bChangeRightIs = false;
		}
	}
	else
	{
		m_bChangeRightIs = true;
	}

	if (Input::GetTrrigerKey(VK_LEFT) == true)
	{
		if (m_bChangeLeftIs == true)
		{
			if (m_iRankChenge == Page_2)
			{
				m_iRankChenge = Page_1;
			}
			else if (m_iRankChenge == Page_3)
			{
				m_iRankChenge = Page_2;
			}
		}
		m_bChangeLeftIs = false;
	}
	else
	{
		m_bChangeLeftIs = true;
	}

}

//�`��
void CRanking::Draw()
{
	Font::StrDraw(L"�����L���O", 230.0f, 0.0f, 64.0f, m_fColor);

	//�Z���N�g�V�[���߂�p�ē��\��
	Font::StrDraw(L"Enter �Ŗ߂�",700.0f,580.0f,16.0f,m_fColor);

	if (m_iRankChenge == Page_1)
	{
		Font::StrDraw(L"�X�e�[�W1", 320.0f, 80.0f, 32.0f, m_fColor);

		//���y�[�W�ē��p
		Font::StrDraw(L"����Stage2", 700.0f, 560.0f, 16.0f, m_fColor);

		//�����L���O�\��
		for (int i = 0; i < MAX_RANKING - 1; i++)
		{
			wchar_t str[256];
			swprintf_s(str, L"%2d��                 %12d�_", i + 1, ((UserData*)Save::GetData())->m_iRanking_st1[i]);
			Font::StrDraw(str, 100.0f, 150.0f + (45.0f * i), 32.0f, m_fColor);

			//���O�\��
			wchar_t str_name[256];
			char name[6];
			strcpy_s(name,((UserData*)Save::GetData())->m_RankingName_st1[i]);

			//char����wchar_t�Ɏw�肵���T�C�Y���R�s�[
			size_t* size = nullptr;
			mbstowcs_s(size, str_name, 12, name, 12);

			Font::StrDraw(str_name, 350.0f, 150.0f + (45.0f * i), 32.0f, m_fColor);

		}
	}
	if (m_iRankChenge == Page_2)
	{
		Font::StrDraw(L"�X�e�[�W2", 320.0f, 80.0f, 32.0f, m_fColor);

		//���y�[�W�ē��p
		Font::StrDraw(L"����Stage3", 700.0f, 560.0f, 16.0f, m_fColor);
		//�O�y�[�W�ē��p
		Font::StrDraw(L"����Stage1", 700.0f, 540.0f, 16.0f, m_fColor);

		//�����L���O�\��
		for (int i = 0; i < MAX_RANKING - 1; i++)
		{
			wchar_t str[256];
			swprintf_s(str, L"%2d��                 %12d�_", i + 1, ((UserData*)Save::GetData())->m_iRanking_st2[i]);
			Font::StrDraw(str, 100.0f, 150.0f + (45.0f * i), 32.0f, m_fColor);

			//���O�\��
			wchar_t str_name[256];
			char name[6];
			strcpy_s(name, ((UserData*)Save::GetData())->m_RankingName_st2[i]);

			//char����wchar_t�Ɏw�肵���T�C�Y���R�s�[
			size_t* size = nullptr;
			mbstowcs_s(size, str_name, 12, name, 12);

			Font::StrDraw(str_name, 350.0f, 150.0f + (45.0f * i), 32.0f, m_fColor);
		}
	}
	if (m_iRankChenge == Page_3)
	{
		Font::StrDraw(L"�X�e�[�W3", 320.0f, 80.0f, 32.0f, m_fColor);

		//�O�y�[�W�ē��p
		Font::StrDraw(L"����Stage2", 700.0f, 540.0f, 16.0f, m_fColor);

		//�����L���O�\��
		for (int i = 0; i < MAX_RANKING - 1; i++)
		{
			wchar_t str[256];
			swprintf_s(str, L"%2d��                 %12d�_", i + 1, ((UserData*)Save::GetData())->m_iRanking_st3[i]);
			Font::StrDraw(str, 100.0f, 150.0f + (45.0f * i), 32.0f, m_fColor);

			//���O�\��
			wchar_t str_name[256];
			char name[6];
			strcpy_s(name, ((UserData*)Save::GetData())->m_RankingName_st3[i]);

			//char����wchar_t�Ɏw�肵���T�C�Y���R�s�[
			size_t* size = nullptr;
			mbstowcs_s(size, str_name, 12, name, 12);

			Font::StrDraw(str_name, 350.0f, 150.0f + (45.0f * i), 32.0f, m_fColor);
		}
	}
}