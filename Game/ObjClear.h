#pragma once
#include "GameL/SceneObjManager.h"
#include "Vector.h"

using namespace GameL;

//�N���A�A�C�e���N���X
class CObjClear :public CObj
{
public:
	CObjClear(int x, int y);

	void Init();	//������
	void Action();	//�X�V
	void Draw();	//�`��

private:
	Vector m_vPos;	//�ʒu

	//�`��F
	float m_fColor[4];
};