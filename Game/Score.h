#pragma once
#include "GameL/SceneObjManager.h"

//�X�R�A�N���X
using namespace GameL;
class CScore :public CObj
{
public:
	void Init();	//������
	void Action();	//�X�V
	void Draw();	//�`��

	//�`��F
	float m_fColor[4];

	//�X�R�A�̈ʒu
	float m_fPos_x;
	float m_fPos_y;
};