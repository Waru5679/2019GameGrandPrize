#pragma once
#include "GameL/SceneObjManager.h"
#include "Vector.h"

using namespace GameL;

//�G�㉺�N���X
class CEnemyUpDown :public CObj
{
public:
	CEnemyUpDown(int x, int y);
	void Init();	//������
	void Action();	//�X�V
	void Draw();	//�`��

private:
	float m_fColor[4];	//�`��F
	Vector m_vPos;		//�ʒu
	Vector m_vBulletMove;//�e�̌���
	float m_fvx;		//�ړ��x�N�g��
	float m_fvy;		
	int m_Count;		//�J�E���^
	int m_iBulletCount;	//�o���b�g�J�E���^
};