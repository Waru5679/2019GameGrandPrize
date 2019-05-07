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
	//�t�H���g�Z�b�g
	Font::SetStrTex(L"�Q�[���I�[�o�[");

	//�F
	ColorSet(1.0f, 1.0f, 1.0f, 1.0f, m_fColor);
}

//�X�V
void CGameOver::Action()
{
	//Enter�Ń^�C�g����
	if (Input::GetTrrigerKey(VK_RETURN) == true)
	{
		//���_���������L���O�ŉ��ʂɓo�^
		((UserData*)Save::GetData())->m_iRanking[MAX_RANKING] = ((UserData*)Save::GetData())->m_iScore;

		//���_���������ɕ��ёւ�������
		RankingSort(((UserData*)Save::GetData())->m_iRanking);

		for (int i = 0; i < MAX_RANKING; i++)
		{
			//�����L���O�̈ʒu�T��
			if (((UserData*)Save::GetData())->m_iRanking[i] == ((UserData*)Save::GetData())->m_iScore)
			{
				//�X�R�A�̈ʒu��10�ʈȏ�Ȃ疼�O���͉�ʂ�
				if (((UserData*)Save::GetData())->m_iRanking[i] < MAX_RANKING)
				{
					//Scene::SetScene(new);
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

//�`��
void CGameOver::Draw()
{
	Font::StrDraw(L"�Q�[���I�[�o�[", 100.0f, 100.0f, 32.0f, m_fColor);
}
