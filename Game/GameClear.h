#pragma once

#include "GameL/SceneObjManager.h"

using namespace GameL;

//�Q�[���N���A�N���X
class CGameClear :public CObj
{
public:
	CGameClear() {};
	void Init();	//������
	void Action();	//�X�V
	void Draw();	//�`��

private:
	//�`��F
	float m_fColor[4];
	float m_fColor_Yellow[4];

	//���ʂ�ۑ�����p
	int m_iRanking;
};