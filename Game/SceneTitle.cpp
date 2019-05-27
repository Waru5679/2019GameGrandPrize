#include "SceneTitle.h"
#include "Title.h"
#include "GameL/DrawTexture.h"
#include "GameL/Audio.h"

//������
void CSceneTitle::InitScene()
{
	//�e�N�X�`���ǂݍ���
	LoadTexture();
	
	//���y�ǂݍ���
	LoadAudio();

	//�^�C�g��Obj�쐬
	CTitle* pTitle = new CTitle();
	Objs::InsertObj(pTitle, OBJ_TITLE, 0);

	//�{�����[������
	Audio::Volume(-0.2f, 0);

	//���y�Đ�
	Audio::Start(0);
}

//�e�N�X�`���ǂݍ���
void CSceneTitle::LoadTexture()
{
	Draw::LoadImageW(L"Texture/Title.png", OBJ_BACK_GROUND, TEX_SIZE_1024);
}

//���y�ǂݍ���
void CSceneTitle::LoadAudio()
{
	Audio::LoadAudio(0, L"Audio/Title.wav", BACK_MUSIC);
}
