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

	//2019-05-13  
	int iRankPosition = MAX_RANKING - 1;//11-1 -> 10

	if (((UserData*)Save::GetData())->m_iStageNum == STAGE_1)
	{
		//���_�����X�e�[�W1�̃����L���O�ŉ��ʂɓo�^			
		((UserData*)Save::GetData())->m_iRanking_st1[iRankPosition] = ((UserData*)Save::GetData())->m_iScore;
	}
	if (((UserData*)Save::GetData())->m_iStageNum == STAGE_2)
	{
		//���_�����X�e�[�W2�̃����L���O�ŉ��ʂɓo�^
		((UserData*)Save::GetData())->m_iRanking_st2[iRankPosition] = ((UserData*)Save::GetData())->m_iScore;
	}
	if (((UserData*)Save::GetData())->m_iStageNum == STAGE_3)
	{
		//���_�����X�e�[�W3�̃����L���O�ŉ��ʂɓo�^
		((UserData*)Save::GetData())->m_iRanking_st3[iRankPosition] = ((UserData*)Save::GetData())->m_iScore;
	}
}

//�X�V
void CGameOver::Action()
{
	//�X�e�[�W1�̓��_���������ɕ��ёւ�������
	RankingSort(((UserData*)Save::GetData())->m_iRanking_st1);
	//�X�e�[�W2�̓��_���������ɕ��ёւ�������
	RankingSort(((UserData*)Save::GetData())->m_iRanking_st2);
	//�X�e�[�W3�̓��_���������ɕ��ёւ�������
	RankingSort(((UserData*)Save::GetData())->m_iRanking_st3);

	//Enter�Ń^�C�g�������O���͂ֈڂ�
	if (Input::GetTrrigerKey(VK_RETURN) == true)
	{
		//�X�e�[�W���擾
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

					//�X�R�A��10�ʈȓ��������ꍇ
					if (i < 10)
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

	//�����L���O�\��
	if (((UserData*)Save::GetData())->m_iStageNum == STAGE_1)
	{
		Font::StrDraw(L"�X�e�[�W1", 140.0f, 100.0f, 32.0f, m_fColor);

		//�����L���O�\��
		for (int i = 0; i < MAX_RANKING - 1; i++)
		{
			wchar_t str[256];
			swprintf_s(str, L"%2d��           %12d�_", i + 1, ((UserData*)Save::GetData())->m_iRanking_st1[i]);
			Font::StrDraw(str, 50, 150 + (30 * i), 20, m_fColor);

			//�����̏��ʊm�F�p���u���v��\��
			//�T���pfor���i�������l��2�ȏ���񂾎��ɔ������p�j
			for (int j = 0; j < MAX_RANKING - 1; j++)
			{
				//�X�R�A��0����Ȃ��Ƃ�
				if (((UserData*)Save::GetData())->m_iScore != 0)
				{
					//�X�R�A�������L���O���̃X�R�A�ƈꏏ�̎�
					if (((UserData*)Save::GetData())->m_iRanking_st1[j] == ((UserData*)Save::GetData())->m_iScore)
					{
						swprintf_s(str, L"�� ���Ȃ�");
						Font::StrDraw(str, 350, 150 + (30 * j), 20, m_fColor);

						break;
					}
				}
			}
		}
	}
	if (((UserData*)Save::GetData())->m_iStageNum == STAGE_2)
	{
		Font::StrDraw(L"�X�e�[�W2", 140.0f, 100.0f, 32.0f, m_fColor);

		//�����L���O�\��
		for (int i = 0; i < MAX_RANKING - 1; i++)
		{
			wchar_t str[256];
			swprintf_s(str, L"%2d��           %12d�_", i + 1, ((UserData*)Save::GetData())->m_iRanking_st2[i]);
			Font::StrDraw(str, 50, 150 + (30 * i), 20, m_fColor);

			//�����̏��ʊm�F�p���u���v��\��
			//�T���pfor���i�������l��2�ȏ���񂾎��ɔ������p�j
			for (int j = 0; j < MAX_RANKING - 1; j++)
			{
				//�X�R�A��0����Ȃ��Ƃ�
				if (((UserData*)Save::GetData())->m_iScore != 0)
				{
					//�X�R�A�������L���O���̃X�R�A�ƈꏏ�̎�
					if (((UserData*)Save::GetData())->m_iRanking_st2[j] == ((UserData*)Save::GetData())->m_iScore)
					{
						swprintf_s(str, L"�� ���Ȃ�");
						Font::StrDraw(str, 350, 150 + (30 * j), 20, m_fColor);

						break;
					}
				}
			}
		}
	}
	if (((UserData*)Save::GetData())->m_iStageNum == STAGE_3)
	{
		Font::StrDraw(L"�X�e�[�W3", 140.0f, 100.0f, 32.0f, m_fColor);

		//�����L���O�\��
		for (int i = 0; i < MAX_RANKING - 1; i++)
		{
			wchar_t str[256];
			swprintf_s(str, L"%2d��           %12d�_", i + 1, ((UserData*)Save::GetData())->m_iRanking_st3[i]);
			Font::StrDraw(str, 50, 150 + (30 * i), 20, m_fColor);

			//�����̏��ʊm�F�p���u���v��\��
			//�T���pfor���i�������l��2�ȏ���񂾎��ɔ������p�j
			for (int j = 0; j < MAX_RANKING - 1; j++)
			{
				//�X�R�A��0����Ȃ��Ƃ�
				if (((UserData*)Save::GetData())->m_iScore != 0)
				{
					//�X�R�A�������L���O���̃X�R�A�ƈꏏ�̎�
					if (((UserData*)Save::GetData())->m_iRanking_st3[j] == ((UserData*)Save::GetData())->m_iScore)
					{
						swprintf_s(str, L"�� ���Ȃ�");
						Font::StrDraw(str, 350, 150 + (30 * j), 20, m_fColor);

						break;
					}
				}
			}
		}
	}
}
