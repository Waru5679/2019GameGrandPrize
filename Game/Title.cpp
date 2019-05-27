#include "Title.h"
#include "Function.h"
#include "GameL/WinInputs.h"
#include "GameL/DrawFont.h"
#include "GameL/SceneManager.h"
#include "GameL/UserData.h"
#include "GameHead.h"

//������
void CTitle::Init()
{
	//�t�H���g�Z�b�g
	Font::SetStrTex(L"�^�C�g��");

	//�F(��)
	ColorSet(1.0f, 1.0f, 1.0f, 1.0f, m_fColor);
	//�F(���F)
	ColorSet(1.0f, 1.0f, 0.0f, 1.0f, m_fColor_Yellow);

	//���O�p�z��̏�����
	for (int i = 0; i <= 6; i++)
	{
		m_cName[i] = ' ';//���p�󔒂ŏ�����
	}

	//�Q�[�������s����1��̂ݍ쓮����
	static bool m_sbInit_Point = true;
	if (m_sbInit_Point == true)
	{
		//�����L���O������
		for (int i = 0; i < MAX_RANKING; i++)
		{
			((UserData*)Save::GetData())->m_iRanking_st1[i] = 0;
		}
		for (int i = 0; i < MAX_RANKING; i++)
		{
			((UserData*)Save::GetData())->m_iRanking_st2[i] = 0;
		}
		for (int i = 0; i < MAX_RANKING; i++)
		{
			((UserData*)Save::GetData())->m_iRanking_st3[i] = 0;
		}

		//���[�h
		Save::Open();

		//�_����0�ɂ���
		((UserData*)Save::GetData())->m_iScore = 0;

		m_sbInit_Point = false;
	}
	
	//�Q�[�����s2��ڈȍ~�����L���O�Z�[�u
	if (m_sbInit_Point == false)
	{
		Save::Seve();
	}

}

//�X�V
void CTitle::Action()
{
	//Enter�Ń��C����
	if (Input::GetTrrigerKey(VK_RETURN) == true)
	{
		Scene::SetScene(new CSceneStageSelect());
		this->SetStatus(false);
	}

	if (Input::GetTrrigerKey(VK_BACK) == true)
	{
		//�����L���O������
		for (int i = 0; i < MAX_RANKING - 1; i++)
		{
			((UserData*)Save::GetData())->m_iRanking_st1[i] = 0;
			((UserData*)Save::GetData())->m_iRanking_st2[i] = 0;
			((UserData*)Save::GetData())->m_iRanking_st3[i] = 0;


			strcpy_s(((UserData*)Save::GetData())->m_RankingName_st1[i],"+++++");
			strcpy_s(((UserData*)Save::GetData())->m_RankingName_st2[i], "+++++");
			strcpy_s(((UserData*)Save::GetData())->m_RankingName_st3[i], "+++++");
		}
	}
}

//�`��
void CTitle::Draw()
{
	RECT_F Src, Dst;

	//�؂���
	RectSet(&Src, 0.0f, 0.0f, 800.0f, 600.0f);

	//�`��ʒu
	RectSet(&Dst, 0.0f, 0.0f, WINDOW_SIZE_W, WINDOW_SIZE_H);

	//�`��
	Draw::Draw(OBJ_BACK_GROUND, &Src, &Dst, m_fColor, 0.0f);

	//����ʈē��\��
	Font::StrDraw(L"Push Enter", 270.0f, 510.0f, 32.0f, m_fColor_Yellow);

}
