#pragma once
#include "GameL/SceneObjManager.h"
#include "GameHead.h"

using namespace GameL;

//�}�b�v�N���X
class CMap :public CObj
{
public:
	CMap(int* pMap);
	void Init();	//������
	void Action();	//�X�V
	void Draw();	//�`��
	void CreateSide();	//������
	void CreateVertical();//�c����

	int m_iMapItem[MAX_ITEM];	//�}�b�v���̃A�C�e�����擾�p�z��
	int m_iMapLoop;				//�}�b�v�z��T���p�ϐ�
private:
	int m_Map[MAX_Y][MAX_X];	//�}�b�v�f�[�^
	float m_fColor[4];			//�`��F
	bool m_bScroll;				//�X�N���[���̏�Ԏ擾
};