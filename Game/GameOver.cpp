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
}

//�X�V
void CGameOver::Action()
{
	//Enter�Ń^�C�g����
	if (Input::GetTrrigerKey(VK_RETURN) == true)
	{
		if (((UserData*)Save::GetData())->m_iStageNum == STAGE_1)
		{
			//���_���������L���O�ŉ��ʂɓo�^
			((UserData*)Save::GetData())->m_iRanking_st1[MAX_RANKING] = ((UserData*)Save::GetData())->m_iScore;

			//���_���������ɕ��ёւ�������
			RankingSort(((UserData*)Save::GetData())->m_iRanking_st1);

			//for (int i = 0; i < MAX_RANKING; i++)
			//{
				//�����L���O�̈ʒu�T��
				//if (((UserData*)Save::GetData())->m_iRanking[i] == ((UserData*)Save::GetData())->m_iScore)
				//{
					////�X�R�A�̈ʒu��10�ʈȏ�Ȃ疼�O���͉�ʂ�
					//if (((UserData*)Save::GetData())->m_iRanking[i] < MAX_RANKING)
					//{
					//	//Scene::SetScene(new);
					//	this->SetStatus(false);
					//}
					//else
					//{
			Scene::SetScene(new CSceneTitle());
			this->SetStatus(false);
			//	}
			//}
		//}
		}

		if (((UserData*)Save::GetData())->m_iStageNum == STAGE_2)
		{
			//���_���������L���O�ŉ��ʂɓo�^
			((UserData*)Save::GetData())->m_iRanking_st2[MAX_RANKING] = ((UserData*)Save::GetData())->m_iScore;

			//���_���������ɕ��ёւ�������
			RankingSort(((UserData*)Save::GetData())->m_iRanking_st2);

			//for (int i = 0; i < MAX_RANKING; i++)
			//{
				//�����L���O�̈ʒu�T��
				//if (((UserData*)Save::GetData())->m_iRanking[i] == ((UserData*)Save::GetData())->m_iScore)
				//{
					////�X�R�A�̈ʒu��10�ʈȏ�Ȃ疼�O���͉�ʂ�
					//if (((UserData*)Save::GetData())->m_iRanking[i] < MAX_RANKING)
					//{
					//	//Scene::SetScene(new);
					//	this->SetStatus(false);
					//}
					//else
					//{
			Scene::SetScene(new CSceneTitle());
			this->SetStatus(false);
			//	}
			//}
		//}
		}

		if (((UserData*)Save::GetData())->m_iStageNum == STAGE_3)
		{
			//���_���������L���O�ŉ��ʂɓo�^
			((UserData*)Save::GetData())->m_iRanking_st3[MAX_RANKING] = ((UserData*)Save::GetData())->m_iScore;

			//���_���������ɕ��ёւ�������
			RankingSort(((UserData*)Save::GetData())->m_iRanking_st3);

			//for (int i = 0; i < MAX_RANKING; i++)
			//{
				//�����L���O�̈ʒu�T��
				//if (((UserData*)Save::GetData())->m_iRanking[i] == ((UserData*)Save::GetData())->m_iScore)
				//{
					////�X�R�A�̈ʒu��10�ʈȏ�Ȃ疼�O���͉�ʂ�
					//if (((UserData*)Save::GetData())->m_iRanking[i] < MAX_RANKING)
					//{
					//	//Scene::SetScene(new);
					//	this->SetStatus(false);
					//}
					//else
					//{
			Scene::SetScene(new CSceneTitle());
			this->SetStatus(false);
			//	}
			//}
		//}
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

}
