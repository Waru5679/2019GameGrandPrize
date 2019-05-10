#pragma once

#include "GameL/SceneManager.h"
#include "GameHead.h"

using namespace GameL;

//���C���V�[��
class CSceneMain:public CScene
{
public:
	CSceneMain(int iStageNum);
	void InitScene();	//������
	void Scene();		//���s��

	bool GetScroll() { return m_bScroll; }

	//�X�N���[���؂�ւ�
	void ScrollChange();

private:
	void LoadTexture();	//�e�N�X�`���ǂݍ���
	void LoadAudio();	//���y�ǂݍ���
	int m_Count;	//�^�C���J�E���^

	//�}�b�v�|�C���^
	int* m_pVarticalMap;
	int* m_pSideMap;

	//�w�i�|�C���^
	CBackGround* m_pBack1;
	CBackGround* m_pBack2;

	//�X�N���[������
	bool m_bScroll;

	//�c�����̏���ǂݍ��ݔ���
	bool m_bFirstVertical;

	//�X�e�[�W�ԍ��ǂݎ��
	int m_iStageNum;
};