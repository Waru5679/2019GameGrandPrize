#include "SceneTitle.h"
#include "Title.h"
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

}

//���y�ǂݍ���
void CSceneTitle::LoadAudio()
{

}
