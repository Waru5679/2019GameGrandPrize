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
	//�����L���O�T���p(1��̂�)
};