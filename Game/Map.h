#pragma once
#include "GameL/SceneObjManager.h"
#include "GameHead.h"

using namespace GameL;

//�}�b�v�N���X
class CMap :public CObj
{
public:
	CMap(int* pSideMap, int* pVarticalMap);
	void Init();	//������
	void Action();	//�X�V
	void Draw();	//�`��
	void CreateSide();	//������
	void CreateVertical();//�c����

	int m_iMapItem[MAX_ITEM];	//�}�b�v���̃A�C�e�����擾�p�z��
	int m_iMapLoop;				//�}�b�v�z��T���p�ϐ�
private:
	//�}�b�v�f�[�^
	int m_SideMap[SIDE_MAX_Y][SIDE_MAX_X];	
	int m_VarticalMap[VARTICAL_MAX_Y][VARTICAL_MAX_X];
	
	float m_fColor[4];			//�`��F
	bool m_bScroll;				//�X�N���[���̏�Ԏ擾
	float m_fScroll;			//�X�N���[���ړ�
};