#pragma once

#include "GameL/SceneManager.h"
#include "GameHead.h"

using namespace GameL;

//�^�C�g���V�[��
class CSceneTitle :public CScene
{
public:
	void InitScene();	//������
	void Scene() {};	//���s��

private:
	void LoadTexture();	//�e�N�X�`���ǂݍ���
	void LoadAudio();	//���y�ǂݍ���
};