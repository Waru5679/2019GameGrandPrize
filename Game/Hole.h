#pragma once

#include "GameL/SceneObjManager.h"

using namespace GameL;

//���N���X
class CHole :public CObj
{
public:
	CHole(int y, int x);
	void Init();	//������
	void Action();	//�X�V
	void Draw();	//�`��
private:
	
	//�`��F
	float m_fColor[4];

	//�w�i�̈ʒu
	float m_fPos_x;
	float m_fPos_y;

};