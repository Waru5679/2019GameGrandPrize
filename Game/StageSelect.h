#pragma once

#include "GameL/SceneObjManager.h"

using namespace GameL;

//�X�e�[�W�Z���N�g�N���X
class CStageSelect : public CObj
{
public:
	CStageSelect() {};
	void Init();		//������
	void Action();		//�X�V
	void Draw();		//�`��
private:
	//�`��F
	float m_fColor[4];

	//�X�e�[�W�������L���O�Z���N�g����
	int SelectNum;
};