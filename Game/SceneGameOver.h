#pragma once

#include "GameL/SceneManager.h"
#include "GameHead.h"

using namespace GameL;

//�Q�[���I�[�o�[�V�[��
class CSceneGameOver :public CScene
{
public:
	void InitScene();	//������
	void Scene() {};	//���s��

private:
	void LoadTexture();	//�e�N�X�`���ǂݍ���
	void LoadAudio();	//���y�ǂݍ���
}; 
