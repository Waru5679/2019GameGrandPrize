#pragma once
#include "GameL/SceneObjManager.h"
#include "Vector.h"
using namespace GameL;

#define SHOT_TIME 60

//�G�N���X
class CEnemy :public CObj
{
public:
	CEnemy(int x, int y) ;
	void Init();	//������
	void Action();	//�X�V
	void Draw();	//�`��
private:
	float m_fColor[4];	//�`��F
	Vector m_vPos;		//�ʒu
	int m_Count;		//�J�E���^
	Vector m_fChara;	//�L�����̈ʒu�擾�p
	Vector m_fSpeed;	//���x
};