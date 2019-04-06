#pragma once
#include "GameL/SceneObjManager.h"
#include "Vector.h"
using namespace GameL;

//�G�e�ۃN���X
class CEnemyBullet :public CObj
{
public:
	CEnemyBullet(Vector vPos, Vector vMove);
	void Init();
	void Action();
	void Draw();
private:
	float m_fColor[4];	//�`��F
	Vector m_vPos;		//�ʒu
	Vector m_vMove;		//�ړ�
	float m_fRot;		//��]
	bool m_bInWindow;	//��ʓ����ǂ���
	bool m_bShot;		//���ˊǗ�
	float m_fvx;
	float m_fvy;
};