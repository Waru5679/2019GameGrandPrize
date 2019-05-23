#include "GameClear.h"
#include "Function.h"
#include "GameL/WinInputs.h"
#include "GameL/DrawTexture.h"
#include "GameL/DrawFont.h"
#include "GameL/SceneManager.h"
#include "GameL/UserData.h"
#include "GameHead.h"

//������
void CGameClear::Init()
{
	//�F(��)
	ColorSet(1.0f, 1.0f, 1.0f, 1.0f, m_fColor);
	//�F(���F)
	ColorSet(1.0f, 1.0f, 0.0f, 1.0f, m_fColor_Yellow);

	//�؂�ւ�������
	m_bGoTitleorName = false;

	int iRankPosition = MAX_RANKING - 1;//11-1 -> 10

	if (((UserData*)Save::GetData())->m_iStageNum == STAGE_1)
	{
		//���_�����X�e�[�W1�̃����L���O�ŉ��ʂɓo�^			
		((UserData*)Save::GetData())->m_iRanking_st1[iRankPosition] = ((UserData*)Save::GetData())->m_iScore;
		strcpy_s(((UserData*)Save::GetData())->m_RankingName_st1[10], NO_NAME);

		//�����L���O�\�[�g���ď��ʂ𒲂ׂ�
		m_iRanking = RankingSort(((UserData*)Save::GetData())->m_iRanking_st1, ((UserData*)Save::GetData())->m_RankingName_st1);
	}
	if (((UserData*)Save::GetData())->m_iStageNum == STAGE_2)
	{
		//���_�����X�e�[�W2�̃����L���O�ŉ��ʂɓo�^
		((UserData*)Save::GetData())->m_iRanking_st2[iRankPosition] = ((UserData*)Save::GetData())->m_iScore;
		strcpy_s(((UserData*)Save::GetData())->m_RankingName_st2[10], NO_NAME);

		//�����L���O�\�[�g���ď��ʂ𒲂ׂ�
		m_iRanking = RankingSort(((UserData*)Save::GetData())->m_iRanking_st2, ((UserData*)Save::GetData())->m_RankingName_st2);
	}
	if (((UserData*)Save::GetData())->m_iStageNum == STAGE_3)
	{
		//���_�����X�e�[�W3�̃����L���O�ŉ��ʂɓo�^
		((UserData*)Save::GetData())->m_iRanking_st3[iRankPosition] = ((UserData*)Save::GetData())->m_iScore;
		strcpy_s(((UserData*)Save::GetData())->m_RankingName_st3[10], NO_NAME);

		//�����L���O�\�[�g���ď��ʂ𒲂ׂ�
		m_iRanking = RankingSort(((UserData*)Save::GetData())->m_iRanking_st3, ((UserData*)Save::GetData())->m_RankingName_st3);
	}
}

//�X�V
void CGameClear::Action()
{
	//�X�e�[�W���擾 �X�e�[�W1�Ȃ�
	if (((UserData*)Save::GetData())->m_iStageNum == STAGE_1)
	{
		//�����L���O�̏�ʂ���T��
		for (int i = 0; i < MAX_RANKING - 1; i++)
		{

			//�X�R�A�ƃ����L���O���̃X�R�A�T��
			if (((UserData*)Save::GetData())->m_iScore == ((UserData*)Save::GetData())->m_iRanking_st1[i])
			{
				//�����L���O��1�ʈȊO�������X�R�A������ꍇ
				if (((UserData*)Save::GetData())->m_iRanking_st1[i] == ((UserData*)Save::GetData())->m_iRanking_st1[i - 1] && i != 0)
				{
					//�����L���O���ʕۑ�
					((UserData*)Save::GetData())->m_RankingPos = i - 1;
				}
				else
				{
					//�����L���O���ʕۑ�
					((UserData*)Save::GetData())->m_RankingPos = i;
				}

				//�X�R�A��10�ʈȓ��������ꍇ
				if (i < 10 && ((UserData*)Save::GetData())->m_iScore != 0)
				{
					//���O���͂ɂ���
					m_bGoTitleorName = true;

					//Enter�Ŗ��O���͂ֈڂ�
					if (Input::GetTrrigerKey(VK_RETURN) == true)
					{
						Scene::SetScene(new CSceneNameInput());
						this->SetStatus(false);
					}
				}
				else
				{
					//�^�C�g���ɂ���
					m_bGoTitleorName = false;

					//Enter�Ń^�C�g���ֈڂ�
					if (Input::GetTrrigerKey(VK_RETURN) == true)
					{
						Scene::SetScene(new CSceneTitle());
						this->SetStatus(false);
					}
				}
			}
		}
	}
	//�X�e�[�W���擾 �X�e�[�W2�Ȃ�
	if (((UserData*)Save::GetData())->m_iStageNum == STAGE_2)
	{
		//�����L���O�̏�ʂ���T��
		for (int i = 0; i < MAX_RANKING - 1; i++)
		{

			//�X�R�A�ƃ����L���O���̃X�R�A�T��
			if (((UserData*)Save::GetData())->m_iScore == ((UserData*)Save::GetData())->m_iRanking_st2[i])
			{

				//�����L���O��1�ʈȊO�������X�R�A������ꍇ
				if (((UserData*)Save::GetData())->m_iRanking_st2[i] == ((UserData*)Save::GetData())->m_iRanking_st2[i - 1] && i != 0)
				{
					//�����L���O���ʕۑ�
					((UserData*)Save::GetData())->m_RankingPos = i - 1;
				}
				else
				{
					//�����L���O���ʕۑ�
					((UserData*)Save::GetData())->m_RankingPos = i;
				}

				//�X�R�A��10�ʈȓ��������ꍇ
				if (i < 10 && ((UserData*)Save::GetData())->m_iScore != 0)
				{
					//���O���͂ɂ���
					m_bGoTitleorName = true;

					//Enter�Ŗ��O���͂ֈڂ�
					if (Input::GetTrrigerKey(VK_RETURN) == true)
					{
						Scene::SetScene(new CSceneNameInput());
						this->SetStatus(false);
					}
				}
				else
				{
					//�^�C�g���ɂ���
					m_bGoTitleorName = false;

					//Enter�Ń^�C�g���ֈڂ�
					if (Input::GetTrrigerKey(VK_RETURN) == true)
					{
						Scene::SetScene(new CSceneTitle());
						this->SetStatus(false);
					}
				}
			}
		}
	}
	//�X�e�[�W���擾 �X�e�[�W3�Ȃ�
	if (((UserData*)Save::GetData())->m_iStageNum == STAGE_3)
	{
		//�����L���O�̏�ʂ���T��
		for (int i = 0; i < MAX_RANKING - 1; i++)
		{

			//�X�R�A�ƃ����L���O���̃X�R�A�T��
			if (((UserData*)Save::GetData())->m_iScore == ((UserData*)Save::GetData())->m_iRanking_st3[i])
			{

				//�����L���O��1�ʈȊO�������X�R�A������ꍇ
				if (((UserData*)Save::GetData())->m_iRanking_st3[i] == ((UserData*)Save::GetData())->m_iRanking_st3[i - 1] && i != 0)
				{
					//�����L���O���ʕۑ�
					((UserData*)Save::GetData())->m_RankingPos = i - 1;
				}
				else
				{
					//�����L���O���ʕۑ�
					((UserData*)Save::GetData())->m_RankingPos = i;
				}

				//�X�R�A��10�ʈȓ��������ꍇ
				if (i < 10 && ((UserData*)Save::GetData())->m_iScore != 0)
				{
					//���O���͂ɂ���
					m_bGoTitleorName = true;

					//Enter�Ŗ��O���͂ֈڂ�
					if (Input::GetTrrigerKey(VK_RETURN) == true)
					{
						Scene::SetScene(new CSceneNameInput());
						this->SetStatus(false);
					}
				}
				else
				{
					//�^�C�g���ɂ���
					m_bGoTitleorName = false;

					//Enter�Ń^�C�g���ֈڂ�
					if (Input::GetTrrigerKey(VK_RETURN) == true)
					{
						Scene::SetScene(new CSceneTitle());
						this->SetStatus(false);
					}
				}
			}
		}
	}
}

//�`��
void CGameClear::Draw()
{
	RECT_F Dst, Src;

	//�؂���ʒu
	RectSet(&Src, 0.0f, 0.0f, 800.0f, 600.0f);

	//�`��ʒu
	RectSet(&Dst, 0.0f, 0.0f, WINDOW_SIZE_W, WINDOW_SIZE_H);

	//�`��
	Draw::Draw(OBJ_BACK_GROUND, &Src, &Dst, m_fColor, 0.0f);

	//�^�C�g���V�[���ē��\��
	if (m_bGoTitleorName == true)
	{
		//true�Ȃ疼�O���͈ڍs�ē�
		Font::StrDraw(L"Enter �Ŗ��O����", 650.0f, 580.0f, 16.0f, m_fColor);
	}
	else
	{
		//false�Ȃ�^�C�g���ڍs�ē�
		Font::StrDraw(L"Enter �Ń^�C�g��", 650.0f, 580.0f, 16.0f, m_fColor);
	}

	//�����L���O�\��
	if (((UserData*)Save::GetData())->m_iStageNum == STAGE_1)
	{
		//�Q�[���N���A�����\��
		Font::StrDraw(L"Stage Clear", 250.0f, 10.0f, 64.0f, m_fColor_Yellow);

		//�����L���O�\��
		for (int i = 0; i < MAX_RANKING - 1; i++)
		{
			wchar_t str[256];
			
			//�����̏��ʒT��
			if (((UserData*)Save::GetData())->m_RankingPos == i && ((UserData*)Save::GetData())->m_iScore != 0)
			{
				swprintf_s(str, L"%2d��           %12d�_", i + 1, ((UserData*)Save::GetData())->m_iRanking_st1[i]);
				Font::StrDraw(str, 110.0f, 150.0f + (43.0f * i), 40.0f, m_fColor_Yellow);
			}
			else
			{
				swprintf_s(str, L"%2d��           %12d�_", i + 1, ((UserData*)Save::GetData())->m_iRanking_st1[i]);
				Font::StrDraw(str, 110.0f, 150.0f + (43.0f * i), 40.0f, m_fColor);
			}

			//���O�\��
			wchar_t str_name[256];
			char name[6];
			strcpy_s(name, ((UserData*)Save::GetData())->m_RankingName_st1[i]);

			//char����wchar_t�Ɏw�肵���T�C�Y���R�s�[
			size_t* size = nullptr;
			mbstowcs_s(size, str_name, 12, name, 12);

			Font::StrDraw(str_name, 330.0f, 150.0f + (43.0f * i), 40.0f, m_fColor);

		}
	}
	if (((UserData*)Save::GetData())->m_iStageNum == STAGE_2)
	{
		//�Q�[���N���A�����\��
		Font::StrDraw(L"Stage Clear", 250.0f, 10.0f, 64.0f, m_fColor_Yellow);

		wchar_t str[256];

		//�����L���O�\��
		for (int i = 0; i < MAX_RANKING - 1; i++)
		{
			//�����̏��ʒT��
			if (((UserData*)Save::GetData())->m_RankingPos == i && ((UserData*)Save::GetData())->m_iScore != 0)
			{
				swprintf_s(str, L"%2d��           %12d�_", i + 1, ((UserData*)Save::GetData())->m_iRanking_st2[i]);
				Font::StrDraw(str, 110.0f, 150.0f + (43.0f * i), 40.0f, m_fColor_Yellow);
			}
			else
			{
				swprintf_s(str, L"%2d��           %12d�_", i + 1, ((UserData*)Save::GetData())->m_iRanking_st2[i]);
				Font::StrDraw(str, 110.0f, 150.0f + (43.0f * i), 40.0f, m_fColor);
			}

			//���O�\��
			wchar_t str_name[256];
			char name[6];
			strcpy_s(name, ((UserData*)Save::GetData())->m_RankingName_st2[i]);

			//char����wchar_t�Ɏw�肵���T�C�Y���R�s�[
			size_t* size = nullptr;
			mbstowcs_s(size, str_name, 12, name, 12);

			Font::StrDraw(str_name, 330.0f, 150.0f + (43.0f * i), 40.0f, m_fColor);

		}
	}
	if (((UserData*)Save::GetData())->m_iStageNum == STAGE_3)
	{
		//�Q�[���N���A�����\��
		Font::StrDraw(L"Game Clear", 250.0f, 10.0f, 64.0f, m_fColor_Yellow);

		wchar_t str[256];

		//�����L���O�\��
		for (int i = 0; i < MAX_RANKING - 1; i++)
		{
			//�����̏��ʒT��
			if (((UserData*)Save::GetData())->m_RankingPos == i && ((UserData*)Save::GetData())->m_iScore != 0)
			{
				swprintf_s(str, L"%2d��           %12d�_", i + 1, ((UserData*)Save::GetData())->m_iRanking_st3[i]);
				Font::StrDraw(str, 110.0f, 150.0f + (43.0f * i), 40.0f, m_fColor_Yellow);
			}
			else
			{
				swprintf_s(str, L"%2d��           %12d�_", i + 1, ((UserData*)Save::GetData())->m_iRanking_st3[i]);
				Font::StrDraw(str, 110.0f, 150.0f + (43.0f * i), 40.0f, m_fColor);
			}

			//���O�\��
			wchar_t str_name[256];
			char name[6];
			strcpy_s(name, ((UserData*)Save::GetData())->m_RankingName_st3[i]);

			//char����wchar_t�Ɏw�肵���T�C�Y���R�s�[
			size_t* size = nullptr;
			mbstowcs_s(size, str_name, 12, name, 12);

			Font::StrDraw(str_name, 330.0f, 150.0f + (43.0f * i), 40.0f, m_fColor);

		}
	}
	
}