#pragma once

#include "GameL/SceneObjManager.h"

using namespace GameL;

//�����L���O�N���X
class CRanking :public CObj
{
public:
	CRanking() {};
	void Init();	//������
	void Action();	//�X�V
	void Draw();	//�`��

private:
	//�`��F
	float m_fColor[4];
	int m_iRankChenge;		//�y�[�W�؂�ւ��p�ϐ�
	bool m_bChangeLeftIs;	//�A�Ŕ�����p��
	bool m_bChangeRightIs;	//�A�Ŕ�����p�E
};