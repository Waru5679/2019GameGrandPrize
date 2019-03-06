#pragma once
#include "GameL/SceneObjManager.h"
#include "GameHead.h"

using namespace GameL;

//�}�b�v�N���X
class CMap :public CObj
{
public:
	CMap(int map[MAX_Y][MAX_X]);
	void Init();	//������
	void Action();	//�X�V
	void Draw();	//�`��
	void Create();	//����
private:
	int m_Map[MAX_Y][MAX_X];	//�}�b�v�f�[�^
	float m_fColor[4];			//�`��F
};