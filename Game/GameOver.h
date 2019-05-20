#pragma once

#include "GameL/SceneObjManager.h"

using namespace GameL;

//�Q�[���I�[�o�[�N���X
class CGameOver :public CObj
{
public:
	CGameOver() {};
	void Init();	//������
	void Action();	//�X�V
	void Draw();	//�`��

	
private:

	//�`��F
	float m_fColor[4];
	//�`��F(���F)
	float m_fColor_Yellow[4];
	//�`��F(��)
	float m_fColor_Red[4];
	//���ʂ�ۑ�����p
	int m_iRanking;
	//���[�v�p
	int m_iLoop;
};