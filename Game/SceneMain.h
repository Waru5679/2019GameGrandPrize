#pragma once

#include "GameL/SceneManager.h"

#include "BackGround.h"
using namespace GameL;

//���C���V�[��
class CSceneMain:public CScene
{
public:
	void InitScene();
	void Scene();
private:
	void LoadTexture();
	int m_Count;

	//�w�i
	CBackGround* m_pBack1;
	CBackGround* m_pBack2;

	//�X�N���[������
	bool m_bScroll;

};