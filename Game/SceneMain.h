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
private:
	void LoadTexture();	//�e�N�X�`���ǂݍ���
	void LoadMap(const wchar_t* Name);		//�}�b�v�ǂݍ���

	int m_Count;	//�^�C���J�E���^

	//�}�b�v
	int m_Map[MAX_Y][MAX_X];

	//�w�i�|�C���^
	CBackGround* m_pBack1;
	CBackGround* m_pBack2;

	//�X�N���[������
	bool m_bScroll;


};