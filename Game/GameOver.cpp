#include "GameOver.h"
#include "Function.h"
#include "GameL/WinInputs.h"
#include "GameL/DrawFont.h"
#include "GameL/SceneManager.h"
#include "GameL/UserData.h"
#include "GameHead.h"


//������
void CGameOver::Init()
{
	//�F
	ColorSet(1.0f, 1.0f, 1.0f, 1.0f, m_fColor);
	//�F(��)
	ColorSet(0.8f, 0.0f, 0.0f, 1.0f, m_fColor_Red);
	//�F(���F)
	ColorSet(1.0f, 1.0f, 0.0f, 1.0f, m_fColor_Yellow);

	//���[�v������
	m_iLoop = 0;


	//2019-05-13  
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
void CGameOver::Action()
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
				//�����L���O���ʕۑ�
				((UserData*)Save::GetData())->m_RankingPos = i;

				//Enter�Ń^�C�g�������O���͂ֈڂ�
				if (Input::GetTrrigerKey(VK_RETURN) == true)
				{
					//�X�R�A��10�ʈȓ��������ꍇ
					if (i < 10 && ((UserData*)Save::GetData())->m_iScore != 0)
					{
						Scene::SetScene(new CSceneNameInput());
						this->SetStatus(false);
					}
					else
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

				//�����L���O���ʕۑ�
				((UserData*)Save::GetData())->m_RankingPos = i;

				//Enter�Ń^�C�g�������O���͂ֈڂ�
				if (Input::GetTrrigerKey(VK_RETURN) == true)
				{
					//�X�R�A��10�ʈȓ��������ꍇ
					if (i < 10 && ((UserData*)Save::GetData())->m_iScore != 0)
					{
						Scene::SetScene(new CSceneNameInput());
						this->SetStatus(false);
					}
					else
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

				//�����L���O���ʕۑ�
				((UserData*)Save::GetData())->m_RankingPos = i;

				//Enter�Ń^�C�g�������O���͂ֈڂ�
				if (Input::GetTrrigerKey(VK_RETURN) == true)
				{
					//�X�R�A��10�ʈȓ��������ꍇ
					if (i < 10 && ((UserData*)Save::GetData())->m_iScore != 0)
					{
						Scene::SetScene(new CSceneNameInput());
						this->SetStatus(false);
					}
					else
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
void CGameOver::Draw()
{

	RECT_F Dst, Src;

	//�؂���ʒu
	RectSet(&Src,0.0f, 0.0f, 800.0f, 600.0f);

	//�`��ʒu
	RectSet(&Dst, 0.0f, 0.0f, WINDOW_SIZE_W, WINDOW_SIZE_H);

	//�`��
	Draw::Draw(OBJ_BACK_GROUND, &Src, &Dst, m_fColor, 0.0f);

	Font::StrDraw(L"GAME OVER", 200.0f, 30.0f, 90.0f, m_fColor_Red);


	//��ʉE�Ɏ����̓��_�\��
	wchar_t str_score[256];
	Font::StrDraw(L"Your Score", 460.0f, 200.0f, 40.0f, m_fColor_Yellow);

	swprintf_s(str_score, L"%12d�_", ((UserData*)Save::GetData())->m_iScore);
	Font::StrDraw(str_score, 400.0f, 250.0f, 32.0f, m_fColor_Yellow);

	//�����L���O�\��
	if (((UserData*)Save::GetData())->m_iStageNum == STAGE_1)
	{
		//�����L���O�\��
		for (int i = 0; i < MAX_RANKING - 1; i++)
		{

			//�����̏��ʂ������Ă��Ă����if�łƂ��ĕ\������
			wchar_t str[256];

			//�����̏��ʒT��
			if (((UserData*)Save::GetData())->m_RankingPos == i)
			{
				//�����X�R�A������łȂ��ꍇ
				if (((UserData*)Save::GetData())->m_iRanking_st1[i] != ((UserData*)Save::GetData())->m_iRanking_st1[i - 1])
				{
					swprintf_s(str, L"%2d��%12d�_", i + 1, ((UserData*)Save::GetData())->m_iRanking_st1[i]);
					Font::StrDraw(str, 10, 150 + (45 * i), 32, m_fColor_Yellow);
				}
				//�����X�R�A������ł���ꍇ
				else
				{
					swprintf_s(str, L"%2d��%12d�_", i, ((UserData*)Save::GetData())->m_iRanking_st1[i]);
					Font::StrDraw(str, 10, 150 + (45 * (i-1)), 32, m_fColor_Yellow);

					swprintf_s(str, L"%2d��%12d�_", i + 1, ((UserData*)Save::GetData())->m_iRanking_st1[i]);
					Font::StrDraw(str, 10, 150 + (45 * i), 32, m_fColor);
				}
			}
			else
			{
				swprintf_s(str, L"%2d��%12d�_", i + 1, ((UserData*)Save::GetData())->m_iRanking_st1[i]);
				Font::StrDraw(str, 10, 150 + (45 * i), 32, m_fColor);
			}
			
			//���O�\��
			wchar_t str_name[256];
			char name[6];
			strcpy_s(name, ((UserData*)Save::GetData())->m_RankingName_st1[i]);

			//char����wchar_t�Ɏw�肵���T�C�Y���R�s�[
			size_t* size = nullptr;
			mbstowcs_s(size, str_name, 12, name, 12);

			Font::StrDraw(str_name, 100.0f, 150.0f + (45.0f * i), 32.0f, m_fColor);

		}
	}
	if (((UserData*)Save::GetData())->m_iStageNum == STAGE_2)
	{
		//�����L���O�\��
		for (int i = 0; i < MAX_RANKING - 1; i++)
		{
			wchar_t str[256];
			swprintf_s(str, L"%2d��           %12d�_", i + 1, ((UserData*)Save::GetData())->m_iRanking_st2[i]);
			Font::StrDraw(str, 50, 150 + (30 * i), 20, m_fColor);

			//�����̏��ʒT��
			if (((UserData*)Save::GetData())->m_RankingPos == i)
			{
				//�����X�R�A������łȂ��ꍇ
				if (((UserData*)Save::GetData())->m_iRanking_st2[i] != ((UserData*)Save::GetData())->m_iRanking_st2[i - 1])
				{
					swprintf_s(str, L"%2d��%12d�_", i + 1, ((UserData*)Save::GetData())->m_iRanking_st2[i]);
					Font::StrDraw(str, 10, 150 + (45 * i), 32, m_fColor_Yellow);
				}
				//�����X�R�A������ł���ꍇ
				else
				{
					swprintf_s(str, L"%2d��%12d�_", i, ((UserData*)Save::GetData())->m_iRanking_st2[i]);
					Font::StrDraw(str, 10, 150 + (45 * (i - 1)), 32, m_fColor_Yellow);

					swprintf_s(str, L"%2d��%12d�_", i + 1, ((UserData*)Save::GetData())->m_iRanking_st2[i]);
					Font::StrDraw(str, 10, 150 + (45 * i), 32, m_fColor);
				}
			}
			else
			{
				swprintf_s(str, L"%2d��%12d�_", i + 1, ((UserData*)Save::GetData())->m_iRanking_st2[i]);
				Font::StrDraw(str, 10, 150 + (45 * i), 32, m_fColor);
			}
		}
	}
	if (((UserData*)Save::GetData())->m_iStageNum == STAGE_3)
	{
		//�����L���O�\��
		for (int i = 0; i < MAX_RANKING - 1; i++)
		{
			wchar_t str[256];
			swprintf_s(str, L"%2d��           %12d�_", i + 1, ((UserData*)Save::GetData())->m_iRanking_st3[i]);
			Font::StrDraw(str, 50, 150 + (30 * i), 20, m_fColor);

			//�����̏��ʒT��
			if (((UserData*)Save::GetData())->m_RankingPos == i)
			{
				//�����X�R�A������łȂ��ꍇ
				if (((UserData*)Save::GetData())->m_iRanking_st3[i] != ((UserData*)Save::GetData())->m_iRanking_st3[i - 1])
				{
					swprintf_s(str, L"%2d��%12d�_", i + 1, ((UserData*)Save::GetData())->m_iRanking_st3[i]);
					Font::StrDraw(str, 10, 150 + (45 * i), 32, m_fColor_Yellow);
				}
				//�����X�R�A������ł���ꍇ
				else
				{
					swprintf_s(str, L"%2d��%12d�_", i, ((UserData*)Save::GetData())->m_iRanking_st3[i]);
					Font::StrDraw(str, 10, 150 + (45 * (i - 1)), 32, m_fColor_Yellow);

					swprintf_s(str, L"%2d��%12d�_", i + 1, ((UserData*)Save::GetData())->m_iRanking_st3[i]);
					Font::StrDraw(str, 10, 150 + (45 * i), 32, m_fColor);
				}
			}
			else
			{
				swprintf_s(str, L"%2d��%12d�_", i + 1, ((UserData*)Save::GetData())->m_iRanking_st3[i]);
				Font::StrDraw(str, 10, 150 + (45 * i), 32, m_fColor);
			}
		}
	}
}
