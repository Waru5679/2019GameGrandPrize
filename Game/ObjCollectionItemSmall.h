#pragma once
#include "GameL/SceneObjManager.h"

using namespace GameL;

//���W�A�C�e���N���X �ȉ��A�C�e��
class CCollectionItemSmall : public CObj
{
public:
	CCollectionItemSmall(int x, int y,int number);
	void Init();	//������
	void Action();	//�X�V
	void Draw();	//�`��

private:
	//�`��F
	float m_fColor[4];

	//�A�C�e���̈ʒu
	float m_fPos_x;
	float m_fPos_y;

	//�X�R�A�̏ꏊ�T���p
	int m_iPosition;

	//�X�N���[���̌���
	bool m_bScroll;
};