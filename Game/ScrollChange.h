#pragma once
#include "GameL/SceneObjManager.h"
#include "Vector.h"

using namespace GameL;

//�X�N���[���̐؂�ւ��N���X
class CScrollChange :public CObj
{
public:
	CScrollChange(int x, int y);
	
	void Init();	//������
	void Action();	//�X�V
	void Draw();	//�`��

private:
	Vector m_vPos;	//�ʒu
	
	//�`��F
	float m_fColor[4];
};