#pragma once
//�g�p����w�b�_�[
#include "GameL/SceneObjManager.h"
#include "Vector.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F��l��
class CObjMainChara : public CObj
{
public:
	CObjMainChara() {};
	~CObjMainChara() {};

	void Init();	//�C�j�V�����C�Y

	void SideMove();		//�ړ���
	void VarticalMove();	//�ړ��c

	void SideInput();		//���̓���
	void VarticalInput();	//�c�̓���
	   
	void Action();	//�A�N�V����
	void Draw();	//�h���[

	Vector GetPos() { return m_vPos; }

private:
	Vector m_vPos;	//�ʒu
	Vector m_vMove;	//�ړ�

	float m_fDirection;	//����
	bool m_bDirection;	//���� �E����:false ������:true
	float m_fGravity;	//�d��
	bool m_bScroll;		//�X�N���[���̌���
	bool m_bHitGround;
	bool m_bBullet_FireIs;//�e�ې���

	//�`��F
	float m_fColor[4];
};