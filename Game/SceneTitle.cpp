#include "SceneTitle.h"
#include "Title.h"
#include "GameL/DrawTexture.h"

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

}

//�e�N�X�`���ǂݍ���
void CSceneTitle::LoadTexture()
{
	Draw::LoadImageW(L"Texture/Title.png", OBJ_BACK_GROUND, TEX_SIZE_1024);
}

//���y�ǂݍ���
void CSceneTitle::LoadAudio()
{

}
