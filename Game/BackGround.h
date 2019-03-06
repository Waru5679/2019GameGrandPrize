#pragma once

#include "GameL/SceneObjManager.h"

using namespace GameL;

//�w�i�N���X
class CBackGround :public CObj
{
public:
	//�R���X�g���N�^
	CBackGround(float Pos_x, float Pos_y, bool Scroll);

	void Init();	//������
	void Action();	//�X�V
	void Draw();	//�`��

	//�X�N���[���̃Z�b�g
	void SetScroll(float Pos_x, float Pos_y,bool Scroll);
private:
	//�`��F
	float m_fColor[4];	
	
	//�w�i�̈ʒu
	float m_fPos_x;	
	float m_fPos_y;

	//�X�N���[�������̊Ǘ�
	bool m_bScroll;

};