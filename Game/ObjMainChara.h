#pragma once
//�g�p����w�b�_�[
#include "GameL/SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F��l��
class CObjMainChara : public CObj
{
	public:
		CObjMainChara() {};
		~CObjMainChara() {};
		void Init();	//�C�j�V�����C�Y
		void Action();	//�A�N�V����
		void Draw();	//�h���[
	private:
		float m_fpx;	//�ʒu
		float m_fpy;
		float m_fvx;	//�ړ��x�N�g��
		float m_fvy;
		float m_fposture;	//����

		//�`��F
		float m_fColor[4];
};