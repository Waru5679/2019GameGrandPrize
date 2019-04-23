#pragma once
//�g�p����w�b�_�[
#include "GameL/SceneObjManager.h"
#include "GameL/HitBoxManager.h"

#include "Vector.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F��l��
class CObjMainChara : public CObj
{
public:

	void Init();	//�C�j�V�����C�Y

	void SideMove();		//�ړ���
	void VarticalMove();	//�ړ��c

	void SideInput();		//���̓���
	void VarticalInput();	//�c�̓���
	   
	void Action();	//�A�N�V����
	void Draw();	//�h���[

	Vector GetPos() { return m_vPos; }

	//���Ƃ̃q�b�g
	void PlaneHit(Vector vPos);

	//�u���b�N�z�[���Ƃ̃q�b�g����
	void HitBlackHole(Vector Vec);

private:
	Vector m_vPos;			//�ʒu
	Vector m_vMove;			//�ړ�
	Vector m_vPlanePos;		//�n�ʂ̈ʒu

	float m_fDirection;		//����
	bool m_bDirection;		//���� �E����:false ������:true
	float m_fGravity;		//�d��
	bool m_bScroll;			//�X�N���[���̌���
	bool m_bHitGround;
	bool m_bBullet_FireIs;	//�e�ې���

	bool m_bIsHitBlackHole;//�u���b�N�z�[���q�b�g����

	//�`��F
	float m_fColor[4];

	CHitBox* m_pBody;	//�L�����̓����蔻�蓷�̗p
	CHitBox* m_pLeg;	//�L�����̓����蔻�葫�p
};