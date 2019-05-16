#pragma once

#include "GameL/SceneObjManager.h"

using namespace GameL;

//���O���̓N���X
class CNameInput :public CObj
{
public:
	CNameInput() {};
	void Init();	//������
	void Action();	//�X�V
	void Draw();	//�`��

	//�L�[�{�[�h���當����ǂݎ��֐�
	bool KeyInput(int number);

	//������̓��͂��I����Ă��邩(\0�����邩)���ׂ�֐�
	bool InputEndCheck();

	//������̕������Ƃ̊Ԃɔ��p�󔒂�����֐�
	void NameCpy(char name[]);

private:
	float m_fColor[4];
	float m_fColor_Red[4];

	char m_cName[6];		//���͂��ꂽ���O�̕ۑ��p
	char m_cCopy_Name[11];	//wchar_t�ɕϊ�����p�̔z��
	bool m_bFirst_Flag;		//�ŏ���1�񂾂��������Ȃ��悤�ɂ��邽�߂̃t���O
	bool m_bKey_Flag;		//�L�[���͉\�ȏ�Ԃ��ǂ�����\���t���O
	bool m_bInput_Flag;		//�L�[���͂��ꂽ���ǂ�����\���t���O
	bool m_bEnd_Flag;		//���O���͂��I�����Ă��邩�ǂ����̃t���O
	bool m_bNoname_Flag;	//�������͂�����Enter���������ꍇ�ɒ��ӕ����o�����߂̃t���O
	bool m_bTime_Flag;		//�����̓_�ŗp�t���O�@true:�\�����@false:�����Ă鎞
	int m_iInput_Count;		//���͂����񐔂̃J�E���^�[
	int m_iTime;			//�����̓_�ŗp�^�C��
};