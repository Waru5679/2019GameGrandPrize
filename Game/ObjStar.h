#pragma once
#include "GameL/SceneObjManager.h"

using namespace GameL;

//���N���X
class CStar :public CObj
{
public:
	CStar(int x, int y);
	void Init();	//������
	void Action();	//�X�V
	void Draw();	//�`��

	//�`��F
	float m_fColor[4];

	//���̈ʒu
	float m_fPos_x;
	float m_fPos_y;
};