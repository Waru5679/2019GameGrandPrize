#pragma once
#include "GameL/SceneObjManager.h"
#include "GameHead.h"
using namespace GameL;

//�G�N���X
class CEnemy :public CObj
{
public:
	CEnemy(int x, int y) ;
	void Init();	//������
	void Action();	//�X�V
	void Draw();	//�`��
private:
	float m_fColor[4];
	Vector m_vPos;
};