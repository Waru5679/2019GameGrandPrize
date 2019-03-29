#pragma once
#include "GameL/SceneObjManager.h"
#include "Vector.h"
using namespace GameL;

//�G�N���X
class CCharaBullet :public CObj
{
public:
	CCharaBullet(Vector vPos, Vector vMove);
	void Init();	//������
	void Action();	//�X�V
	void Draw();	//�`��
private:
	float m_fColor[4];	//�`��F
	Vector m_vPos;		//�ʒu
	Vector m_vMove;		//�ړ�
	float m_fRot;		//��]
	bool m_bInWindow;	//��ʓ����ǂ���
};