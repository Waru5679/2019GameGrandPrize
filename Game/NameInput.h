#pragma once

#include "GameL/SceneObjManager.h"

using namespace GameL;

//���O���̓N���X
class CNameInput :public CObj
{
public:
	CNameInput() {};
	void Init();	//������
	void Action();	//�X�V
	void Draw();	//�`��
private:
	float m_fColor[4];
};