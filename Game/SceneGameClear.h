#pragma once

#include "GameHead.h"
#include "GameL/SceneManager.h"

using namespace GameL;

//�Q�[���I�[�o�[�V�[��
class CSceneGameClear : public CScene
{
public:
	void InitScene();	//������
	void Scene() {};	//���s��

private:
	void LoadTexture();	//�e�N�X�`���ǂݍ���
	void LoadAudio();	//���y�ǂݍ���
};