#pragma once
#include "GameL/SceneObjManager.h"

using namespace GameL;

//���W�A�C�e���N���X �ȉ��A�C�e��
class CCollectionItem : public CObj
{
public:
	CCollectionItem(int x, int y);
	void Init();	//������
	void Action();	//�X�V
	void Draw();	//�`��

	//�`��F
	float m_fColor[4];

	//�A�C�e���̈ʒu
	float m_fPos_x;
	float m_fPos_y;
};