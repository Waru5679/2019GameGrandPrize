#pragma once

#include "GameL/SceneObjManager.h"
#include "Vector.h"

using namespace GameL;

//���N���X
class CHole :public CObj
{
public:
	CHole(int x, int y);
	void Init();	//������
	void Action();	//�X�V
	void Draw();	//�`��
private:
	
	//�`��F
	float m_fColor[4];

	//�ʒu
	Vector m_vPos;

};