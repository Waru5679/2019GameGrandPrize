#pragma once

#include "GameL/SceneManager.h"
#include "GameHead.h"

using namespace GameL;

//���C���V�[��
class CSceneMain:public CScene
{
public:
	void InitScene();	//������
	void Scene();		//���s��

	bool GetScroll() { return m_bScroll; }
private:
	void LoadTexture();	//�e�N�X�`���ǂݍ���
	int m_Count;	//�^�C���J�E���^

	//�}�b�v�|�C���^
	int* m_pMap;

	//�w�i�|�C���^
	CBackGround* m_pBack1;
	CBackGround* m_pBack2;

	//�X�N���[������
	bool m_bScroll;
};