#pragma once

#include "GameL/SceneObjManager.h"
#include "Vector.h"
#include "GameL/HitBoxManager.h"

using namespace GameL;

//�u���b�N�z�[���N���X
class CBlackHole :public CObj
{
public:
	CBlackHole(int x, int y);
	void Init();	//������
	void Action();	//�X�V
	void Draw();	//�`��
private:
	
	//�`��F
	float m_fColor[4];

	//�ʒu
	Vector m_vPos;
	Vector m_vDeathPos;	//���S����̈ʒu

	//�z����
	float m_fSuctionPower;

	//�X�N���[���̌���
	bool m_bScroll;

	CHitBox* m_pSuction;	//�z������
	CHitBox* m_pDeath;		//���S����	
};