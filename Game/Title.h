#pragma once

#include "GameL/SceneObjManager.h"

using namespace GameL;

//�^�C�g���N���X
class CTitle :public CObj
{
public:
	CTitle() {};
	void Init();	//������
	void Action();	//�X�V
	void Draw();	//�`��
private:

	//�`��F
	float m_fColor[4];
};